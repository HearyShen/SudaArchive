/***********************************
	实验三 - 拨号界面的设计与实现
	1427405017
	沈家赟
************************************/
#include <iostream>
#include "SDL.h"
#include "SDL_surface.h"
#include "SDL_image.h"

#ifndef TEL_BASE_H
#define TEL_BASE_H

#define TELBASE_HEIGHT 512
#define TELBASE_WIDTH 512

using namespace std;

class TelBase{
protected:
	SDL_Surface *surface;
	SDL_Texture *texture;
	SDL_Rect rect;
	static const  int height = 512;
	static const int width = 512;
public:
	TelBase();
	TelBase(char *fileurl);
	SDL_Rect* setRect(int new_x=0, int new_y=0, int new_h=height, int new_w=width);
	SDL_Rect* getRect();
	SDL_Texture* getTexture(SDL_Renderer *renderer);
	SDL_Surface* getSurface();
	void renderCopy(SDL_Renderer *renderer);
	~TelBase();
};

#endif