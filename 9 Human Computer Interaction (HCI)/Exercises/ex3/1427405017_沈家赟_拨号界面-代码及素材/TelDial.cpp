/***********************************
	实验三 - 拨号界面的设计与实现
	1427405017
	沈家赟
************************************/
#include "TelDial.h"

TelDial::TelDial(char *fileurl)
{
	surface = IMG_Load(fileurl);
	if(!surface) {
		printf("IMG_Load: %s\n", IMG_GetError());
		//exit(0);
	}
	setRect();	// init Rect with default paras
	texture = NULL;
	angle=0;
}

double TelDial::getAngle()
{
	return angle;
}

SDL_Rect* TelDial::setRect(int new_x, int new_y, int new_h, int new_w)
{
	rect.x = new_x;
	rect.y = new_y;
	rect.h = new_h;
	rect.w = new_w;

	return &rect;
}

void TelDial::renderCopyRotate(SDL_Renderer *renderer, double new_angle)
{
	angle = new_angle;
	if(texture == NULL)
	{
		texture = getTexture(renderer);	// refresh texture
	}
	SDL_RenderCopyEx(renderer, texture, NULL, &rect, angle, NULL, SDL_FLIP_NONE);
}

bool TelDial::isInDial(int x, int y)
{
	int cir_x = rect.x+rect.w/2;		// circle center x
	int cir_y = rect.y+rect.h/2;		// circle center y
	double r2;									// r squared

	r2 = pow(x-cir_x, 2.0) + pow(y-cir_y,2.0);
	if( r2 <= pow(rect.h/2, 2.0) )
		return true;
	return false;
}

double TelDial::cacuAngle(int x, int y)
{
	int cir_x = rect.x+rect.w/2;
	int cir_y = rect.y+rect.h/2;

	double rel_x, rel_y;		// x, y relative to circle center
	rel_x = x-cir_x;
	rel_y = (y-cir_y);	// transform to normal 

	double t_tan = rel_y/rel_x;
	double radius = atan(t_tan);		// range from [-PI/2] to [PI/2]
	//printf("(rel_x, rel_y) =(%d, %d)\n", rel_x, rel_y);
	//printf("t_tan = %f, rad = %f\n", t_tan, radius);
	if(rel_x>0)
	{
		if(rel_y<0)
		{
			radius += 2*M_PI;		// defined in math.h (#define M_PI       3.14159265358979323846)
		}
	}
	else if(rel_x == 0)
	{
		if(rel_y>0)
			return 90;
		else
			return 270;
	}
	else
	{
			radius += M_PI;
	}

	double angle = (radius/(2*M_PI))*360;
	//printf("radius %f\nangle %f\n", radius, angle);
	return angle;
}

char TelDial::getNum(double angle)
{
	if(330<=angle && angle<360)
		return '1';
	else if(300<=angle && angle<330)
		return '2';
	else if(270<=angle && angle<300)
		return '3';
	else if(240<=angle && angle<270)
		return '4';
	else if(210<=angle && angle<240)
		return '5';
	else if(180<=angle && angle<210)
		return '6';
	else if(150<=angle && angle<180)
		return '7';
	else if(120<=angle && angle<150)
		return '8';
	else if(90<=angle && angle<120)
		return '9';
	else if(60<=angle && angle<90)
		return '0';
	else 
		return NULL;
}

/*
	int handleEvents()
	return : 0 - quit
				  1 - mousedown
				  2 - mouseup
*/
int TelDial::handleEvents(int old_state, int &x, int &y)
{
	/* detect events */
	SDL_Event e;
	int nothing_to_do = 1;
	if (SDL_PollEvent(&e) ) 
	{
		nothing_to_do = 0;
		//printf("x = %d, y = %d\n" ,e.motion.x, e.motion.y);
		x = e.motion.x;
		y = e.motion.y;

		switch (e.type)
		{
		case SDL_MOUSEBUTTONDOWN:
			if( isInDial(e.motion.x, e.motion.y) )		// if mouse click within the dial's circle area
			{
				//double new_angle= 0;
				//new_angle = dial.cacuAngle(e.motion.x, e.motion.y);
				//dial.renderCopyRotate(renderer, new_angle);
				SDL_Log("button down!\n");
				return 2;
			}
			
			break;

		case SDL_MOUSEBUTTONUP:
			SDL_Log("button up!\n");
			return 1;
			break;

		case SDL_QUIT:
			SDL_Log("Quit!\n");
			return 0;
			break;
		}
	}
	return old_state;
}