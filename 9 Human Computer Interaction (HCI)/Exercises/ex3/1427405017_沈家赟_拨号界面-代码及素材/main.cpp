/***********************************
	实验三 - 拨号界面的设计与实现
	1427405017
	沈家赟
************************************/
#include <iostream>
#include <math.h>
#include <string>
#include "SDL.h"
#include "SDL_surface.h"
#include "SDL_image.h"
#include "SDL_mixer.h"
#include "TelBase.h"
#include "TelDial.h"

#define WINDOW_WIDTH 512
#define WINDOW_HEIGHT 512

using namespace std;

int Sound_Init()
{
        const int    TMP_FREQ = MIX_DEFAULT_FREQUENCY;
        const Uint16 TMP_FORMAT = MIX_DEFAULT_FORMAT;
        const int    TMP_CHAN = 2;
        const int    TMP_CHUNK_SIZE = 512;
        return Mix_OpenAudio(TMP_FREQ,TMP_FORMAT,TMP_CHAN,TMP_CHUNK_SIZE);
}       

void back(int old_state, bool chosen, double pin_angle, TelDial &tel_dial, Mix_Music *back_music, string &tel_num, SDL_Renderer *renderer)
{
	if(old_state == 2)
			{
				Mix_HaltMusic();
				Mix_PlayMusic(back_music,-1);
			}
			if(old_state == 2 && chosen)
			{
				char num = tel_dial.getNum(pin_angle);
				tel_num.append(1, num);
				cout<<"NUM : "<<tel_num<<endl;
			}
			double old_angle = tel_dial.getAngle();
			if(old_angle > 0)
			{
				tel_dial.renderCopyRotate(renderer, int(old_angle-9*pow(0.995, old_angle)));	// rate : 0.995- a result of several test and tuning
			}
			else
			{
				tel_dial.renderCopyRotate(renderer, 0);
				Mix_HaltMusic();
			}
}

void forward(int old_state, int x, int y, bool &chosen, double &base_angle, double &bias_angle, double &angle, double &pin_angle, 
	double &rotate_angle, double &old_bias_angle, TelDial &tel_dial, Mix_Music *forward_music, SDL_Renderer *renderer )
{
	if(old_state == 1)		// new dial motion
	{
		pin_angle = tel_dial.cacuAngle(x, y);
		old_bias_angle = pin_angle;
		rotate_angle = 0;
		base_angle = 0;
		chosen = false;
		Mix_PlayMusic(forward_music,-1);
	}
			
	/* cacu bias_angle */
	bias_angle = tel_dial.cacuAngle(x, y);
	/* cacu base_angle : solving base angle problem */
	if(bias_angle - old_bias_angle < -300 && !chosen)	// detect angle shrink in boundary condition(360->0)
		base_angle += 360;
	else if(bias_angle - old_bias_angle > 300)	// detect angle explosion in boundary condition(0->360)
		base_angle -= 360;

	/* angle = bias_angle + base_angle */
	angle = bias_angle + base_angle;
	rotate_angle = angle - pin_angle;
			
	if(rotate_angle >= 360-(pin_angle-30))		// stop on edge and validate the dial number
	{
		rotate_angle = 360-(pin_angle-30);
		chosen = true;
		Mix_PauseMusic();
	}
	else
	{
		Mix_ResumeMusic();
	}
	//printf("pin_angle, base_angle, bias_angle, angle, rotate angle  = %f, %f, %f, %f, %f\n", pin_angle, base_angle, bias_angle, angle, rotate_angle);
	tel_dial.renderCopyRotate(renderer, rotate_angle);
			
	old_bias_angle = bias_angle;		// store current bias_angle for next turn use
}

int main(int argc, char *argv[])
{
	int state = 1,old_state=1, x=0, y=0;
	SDL_Window *window;
	SDL_Renderer *renderer;
	char *file_tel_base = "rotary_tel_base.png";
	char *file_tel_dial = "dial.png";
	char *file_tel_limit = "limit.png";
	int i=0;
	double base_angle=0, bias_angle=0, angle=0, pin_angle=0, rotate_angle=0, old_bias_angle =0;		// angle = base_angle + bias_angle;  rotate_angle = angle - pin_angle;
	bool chosen = false;
	string tel_num;
	Mix_Music *forward_music, *back_music;

	/* init sound */
	Sound_Init();
    forward_music = Mix_LoadMUS("forward.mp3");
	back_music = Mix_LoadMUS("back.mp3");

	/* create window and renderer */
	SDL_CreateWindowAndRenderer(WINDOW_WIDTH, WINDOW_HEIGHT, 0, &window, &renderer);

	TelBase tel_base(file_tel_base);
	tel_base.setRect();	// with default para.s
	tel_base.renderCopy(renderer);

	TelDial tel_dial = TelDial(file_tel_dial);
	tel_dial.setRect(160, 300);	// with default para.s, while x=160, y=300
	tel_dial.renderCopy(renderer);

	TelBase tel_limit(file_tel_limit);
	tel_limit.setRect(281, 420, 26, 28);	// with x=281, y=420, h=26, w=28
	tel_limit.renderCopy(renderer);

	while(state)
	{
		tel_base.renderCopy(renderer);		// copy background tel_base to renderer first
		old_state = state;
		state =  tel_dial.handleEvents(old_state, x, y);	// tel_dial handles events and return current state num

		if(state == 1)		// mouseup(undown)	- recover to initial position
		{
			back(old_state, chosen, pin_angle, tel_dial, back_music, tel_num, renderer);
		}
		if(state == 2)		// mousedown - follow mouse motion position
		{	
			forward(old_state, x, y, chosen, base_angle, bias_angle, angle, pin_angle, rotate_angle, old_bias_angle, tel_dial, forward_music, renderer);
		}
		
		/* render present all contents */
		tel_limit.renderCopy(renderer);	// limit bar
		SDL_RenderPresent(renderer);		// present all graphics
		SDL_Delay(20);		// limit fps up to 50fps - (keep balance between consumption and performance)
		SDL_RenderClear(renderer);			// clear the renderer for next turn
	}

	return 0;
}