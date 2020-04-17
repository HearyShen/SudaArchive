#include <stdio.h>
#include <math.h>
#include "SDL.h"
#include "SDL_surface.h"

#define LIGHT_HEIGHT 319
#define LIGHT_WIDTH 213

#define WINDOW_HEIGHT (319+100)
#define WINDOW_WIDTH 213

#define TRACK_X 40
#define TRACK_Y (LIGHT_HEIGHT+20)
#define TRACK_HEIGHT 35
#define TRACK_WIDTH (LIGHT_WIDTH-TRACK_X*2)

#define SLIDER_X 40
#define SLIDER_Y (LIGHT_HEIGHT+20-2)
#define SLIDER_HEIGHT (TRACK_HEIGHT+4)
#define SLIDER_WIDTH (LIGHT_WIDTH/4)


static SDL_Texture *texture_on, *texture_off ;
static int sprite_w, sprite_h;
static SDL_Rect pos_light, pos_track, pos_slider;

SDL_Window *window;
SDL_Surface *temp_off, *temp_on;
char *file_off = "light_off.bmp", *file_on = "light_on.bmp";
int i = 0;
SDL_Renderer *renderer;
int done = 0;
int nothing_to_do;
int step;
int delta;
int pre_x;
bool on;
bool buttondown;
bool buttonup;
SDL_Event e;

/* Call this instead of exit(), so we can clean up SDL: atexit() is evil. */
static void
quit(int rc)
{
    exit(rc);
}


/* ʵ�ְ�������������� */
void loop()
{
    SDL_Event event;

    /* Check for events */
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT || event.type == SDL_KEYDOWN) {
            done = 1;
        }
    }
    //MoveSprites(renderer, sprite);
#ifdef __EMSCRIPTEN__
    if (done) {
        emscripten_cancel_main_loop();
    }
#endif
}

void holdon()
{
	/* ʵ�ְ�������������� */
	done = 0;
	#ifdef __EMSCRIPTEN__
	emscripten_set_main_loop(loop, 0, 1);
	#else
		while (!done) {
			loop();
		}
	#endif
}



SDL_Rect* setRect(SDL_Rect *rect, int new_x, int new_y, int new_h, int new_w)
{
	rect->x = new_x;
	rect->y = new_y;
	rect->h = new_h;
	rect->w = new_w;

	return rect;
}

/* ���ƣ���Ⱦ���ƻ��� */
void lighton()
{
	/* light_on */
	temp_on = SDL_LoadBMP(file_on);
	texture_on = SDL_CreateTextureFromSurface(renderer, temp_on);
	/* Draw the background */
	SDL_RenderCopy(renderer, texture_on, NULL, &pos_light);
	//SDL_RenderPresent(renderer);
	//SDL_FreeSurface(temp_on);
}

/* �صƣ���Ⱦ�صƻ��� */
void lightoff()
{
	/* light_off */
	temp_off = SDL_LoadBMP(file_off);
	texture_off = SDL_CreateTextureFromSurface(renderer, temp_off);
	/* Draw the background */
	SDL_RenderCopy(renderer, texture_off, NULL, &pos_light);
	//SDL_RenderPresent(renderer);
	//SDL_FreeSurface(temp_off);
}



/* ��������ʼ */
int main(int argc, char *argv[])
{
	on = false;
	step = 0;
	buttondown = false;
	buttonup = false;
	nothing_to_do = 1;
	pre_x = SLIDER_X;

	/* init position and size of light bubble */
	setRect(&pos_light, 0, 0, LIGHT_HEIGHT, LIGHT_WIDTH);
	setRect(&pos_track, TRACK_X, TRACK_Y, TRACK_HEIGHT, TRACK_WIDTH);
	setRect(&pos_slider, SLIDER_X, SLIDER_Y, SLIDER_HEIGHT, SLIDER_WIDTH);

	/* ����window��renderer */
	SDL_CreateWindowAndRenderer(WINDOW_WIDTH, WINDOW_HEIGHT, 0, &window, &renderer);


	while( !done )
	{
		

		//if (SDL_SetWindowHitTest(window, hitTest, NULL) == -1) 
		//{
		//	SDL_Log("Enabling hit-testing failed!\n");
		//	SDL_Quit();
		//	return 1;
		//}  || (TRACK_X+i) <= (TRACK_X+TRACK_WIDTH-SLIDER_WIDTH)
		/* event listener */

            
		/* init: init the black background color and clear renderer */
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		SDL_RenderClear(renderer);

		if( !on )
		{
			/* light off */
			lightoff();
		}
		else
		{
			lighton();
		} 

		//holdon();

		/* render the track */
		SDL_SetRenderDrawColor(renderer, 64, 64, 64, 255);
		SDL_RenderFillRects(renderer, &pos_track, 1);
		//SDL_RenderPresent(renderer);

		//holdon();

		/* ����slider��λ�� */
		
		//if(buttondown && buttonup)  // if clicked
		//{
		//	setRect(&pos_slider, SLIDER_X+step, SLIDER_Y, SLIDER_HEIGHT, SLIDER_WIDTH);
		//	step = (pow((i-TRACK_WIDTH/7), 3.0) + pow(TRACK_WIDTH/7, 3.0))/200;
		//	//step = i;
		//	printf("i = %d, step = %d\n", i, step);
		//	if( !on )
		//	{
		//		i++;
		//	}
		//	else
		//	{
		//		i--;
		//	}

		//	if((TRACK_X+step) > (TRACK_X+TRACK_WIDTH-SLIDER_WIDTH))
		//	{
		//		on = true;
		//		buttondown = false;
		//		buttonup = false;
		//		SDL_Log("reaching on_border!\n");
		//		//i = 0;
		//		nothing_to_do = 1;
		//	}
		//	if((TRACK_X+step) < TRACK_X)
		//	{
		//		on = false;
		//		buttondown = false;
		//		buttonup = false;
		//		SDL_Log("reaching off_border!\n");
		//		//i = 0;
		//		nothing_to_do = 1;
		//	}
		//}

		if(buttondown && buttonup)  // if clicked
		{
			
			
			if(SLIDER_X+step >= SLIDER_X && SLIDER_X+step <= (TRACK_X+TRACK_WIDTH-SLIDER_WIDTH))	// ֹͣ�϶�ʱ���Զ����ر߽�
			{
				step = (pow((step-(TRACK_WIDTH-SLIDER_WIDTH)/3), 3.0))/200;
			}
			else if(SLIDER_X+step < SLIDER_X)		// ������߽粢���조�ص���Ч��
			{
				step = 0;
				buttondown = false;
				buttonup = false;
			}
			else if(SLIDER_X+step > (TRACK_X+TRACK_WIDTH-SLIDER_WIDTH))	// �����ұ߽粢���조�ص���Ч��
			{
				step = TRACK_WIDTH - SLIDER_WIDTH;
				buttondown = false;
				buttonup = false;
			}

			setRect(&pos_slider, SLIDER_X+step, SLIDER_Y, SLIDER_HEIGHT, SLIDER_WIDTH);

			if((SLIDER_X+step) > (TRACK_X+TRACK_WIDTH-SLIDER_WIDTH-20))		// ���鿪����ֵ
			{
				on = true;
			}
			else if((SLIDER_X+step) < (TRACK_X+20))		// ����ص���ֵ
			{
				on = false;
			}
		}

		if(buttondown && !buttonup) // if slides
		{
			//SDL_Delay(50);
			if(SLIDER_X+step >= SLIDER_X && SLIDER_X+step <= (TRACK_X+TRACK_WIDTH-SLIDER_WIDTH))
			{
				delta = e.motion.x - pre_x;
				step = step + delta;

				if(SLIDER_X+step < SLIDER_X+50 || SLIDER_X+step > (TRACK_X+TRACK_WIDTH-SLIDER_WIDTH)-50) // �ٱ߽�ʱ���٣����조������������
				{
					step = step + pow(delta, 3.0)/50;
				}

				pre_x = e.motion.x;
				
			}
			else if(SLIDER_X+step < SLIDER_X)		// ������߽粢���조�ص���Ч��
			{
				step = 0;
			}
			else if(SLIDER_X+step > (TRACK_X+TRACK_WIDTH-SLIDER_WIDTH))	// �����ұ߽粢���조�ص���Ч��
			{
				step = TRACK_WIDTH - SLIDER_WIDTH;
			}

			setRect(&pos_slider, SLIDER_X+step , SLIDER_Y, SLIDER_HEIGHT, SLIDER_WIDTH);
			//setRect(&pos_slider, SLIDER_X+step, SLIDER_Y, SLIDER_HEIGHT, SLIDER_WIDTH);

			if((SLIDER_X+step) > (TRACK_X+TRACK_WIDTH-SLIDER_WIDTH-20))		// ���鿪����ֵ
			{
				on = true;
			}
			else if((SLIDER_X+step) < (TRACK_X+20))		// ����ص���ֵ
			{
				on = false;
			}

			if(!on)
			{
				SDL_SetRenderDrawColor(renderer, 255-50, 255-50, 240-50, 255);	//�ص�ʱ���鱻���µ���ɫ�������׼Ӱ�
			}
			else
			{
				SDL_SetRenderDrawColor(renderer, 255-50, 255-50, 0, 255);		//����ʱ���鱻���µ���ɫ���ƼӰ�
			}
			/* render the slider */
			SDL_RenderFillRects(renderer, &pos_slider, 1);
			//SDL_RenderPresent(renderer);
		}
		else
		{
			if(!on)
			{
				SDL_SetRenderDrawColor(renderer, 255, 255, 240, 255);	//�ص�ʱ������ɫ��������
			}
			else
			{
				SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255);		//����ʱ������ɫ����
			}
			/* render the slider */
			SDL_RenderFillRects(renderer, &pos_slider, 1);
			//SDL_RenderPresent(renderer);
		}


		/* render all contents */
		SDL_RenderPresent(renderer);


		/* detect events */
		nothing_to_do = 1;
		if (SDL_PollEvent(&e) ) 
		{
			nothing_to_do = 0;
			printf("%d - x = %d, y = %d\n", i,e.motion.x, e.motion.y);

            switch (e.type)
            {
                case SDL_MOUSEBUTTONDOWN:
					
					if(e.motion.x >= SLIDER_X+step && e.motion.x <= SLIDER_X+step+SLIDER_WIDTH
						&& e.motion.y >= SLIDER_Y && e.motion.y <= SLIDER_Y+SLIDER_HEIGHT)		// click down on slider button
					{
						printf("click DOWN!\n");
						pre_x = e.motion.x;
						buttonup = false;
						buttondown = true;
					}
					SDL_Log("button down!\n");
                    break;

                case SDL_MOUSEBUTTONUP:
					if(e.motion.x >= SLIDER_X+step && e.motion.x <= SLIDER_X+step+SLIDER_WIDTH
						&& e.motion.y >= SLIDER_Y && e.motion.y <= SLIDER_Y+SLIDER_HEIGHT)		// click up on slider button
					{
						printf("click UP!\n");
						//buttondown = true;
						buttonup = true;
					}
					buttonup = true;
					//step++;
                    SDL_Log("button up!\n");
                    break;

                case SDL_QUIT:
                    done = 1;
                    break;
            }
		}
		
		if(nothing_to_do)	// �����¼�����
		{
			SDL_Delay(20);  // �������FPS������50��������Դ���ĺ������ȵ�ƽ��
		}
		else
		{
			SDL_Delay(5);	// �������ˢ���ٶȣ����⡰����ʽ�����ļ�����Դ
		}

		
	}
	printf("END WHILE!\n");


	SDL_FreeSurface(temp_on);
	SDL_FreeSurface(temp_off);
	//holdon();

	//quit(0);

	return 0;
}