/***********************************
	实验三 - 拨号界面的设计与实现
	1427405017
	沈家赟
************************************/
#include <iostream>
#include "SDL.h"
#include "SDL_surface.h"
#include "SDL_image.h"
#include "TelBase.h"	// father class

#ifndef TEL_DIAL_H
#define TEL_DIAL_H

#define TELDIAL_HEIGHT 165
#define TELDIAL_WIDTH 164
#define TELDIAL_X 160
#define TELDIAL_Y 300

using namespace std;

class TelDial : public TelBase{
protected:
	double angle;
	static const int height = 165;
	static const int width = 164;
public:
	TelDial(char *fileurl);
	double getAngle();
	SDL_Rect* TelDial::setRect(int new_x=0, int new_y=0, int new_h=height, int new_w=width);
	void renderCopyRotate(SDL_Renderer *renderer,  double angle);
	bool isInDial(int x, int y);
	double cacuAngle(int x, int y);
	char getNum(double angle);
	int handleEvents(int old_state, int &x, int &y);
};



#endif