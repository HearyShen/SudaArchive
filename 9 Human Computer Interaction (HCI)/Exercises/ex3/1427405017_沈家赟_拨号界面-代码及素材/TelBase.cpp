/***********************************
	实验三 - 拨号界面的设计与实现
	1427405017
	沈家赟
************************************/
#include "TelBase.h"

TelBase::TelBase()
{
	surface = NULL;
	texture = NULL;
}

TelBase::TelBase(char *fileurl)
{
	surface = IMG_Load(fileurl);
	if(!surface) {
		printf("IMG_Load: %s\n", IMG_GetError());
		//exit(0);
	}
	setRect();	// init Rect with default paras
	texture = NULL;
}

SDL_Rect* TelBase::setRect(int new_x, int new_y, int new_h, int new_w)
{
	rect.x = new_x;
	rect.y = new_y;
	rect.h = new_h;
	rect.w = new_w;

	return &rect;
}

SDL_Rect* TelBase::getRect()
{
	return &rect;
}

SDL_Texture* TelBase::getTexture(SDL_Renderer *renderer)
{
	texture = SDL_CreateTextureFromSurface(renderer, surface);
	return texture;
}

SDL_Surface* TelBase::getSurface()
{
	return surface;
}

void TelBase::renderCopy(SDL_Renderer *renderer)
{
	if(texture == NULL)
	{
		texture = getTexture(renderer);	// refresh texture
	}
	SDL_RenderCopy(renderer, texture, NULL, &rect);
}

TelBase::~TelBase()
{
	SDL_FreeSurface(surface);		// free memory in OOP's way
}