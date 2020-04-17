#ifndef PIXEL_H
#define PIXEL_H

#include <iostream>
using namespace std;

struct Pixel
{
	char pixel;
	int weight;
	//int HuffmanCode[8];
	char hfcode;

	Pixel& operator=(Pixel &other)
	{
		pixel = other.pixel;
		weight = other.weight;
		/*for(int i=0;i<8;i++)
			HuffmanCode[i] = other.HuffmanCode[i];*/
		hfcode = 0;
		return *this;
	}
};

char getHuffmanCode(char pixel, Pixel *sorted_pixels, int n)		//pixel -> huffman_code
{
	for(int i=0;i<n;i++)
	{
		if(pixel == sorted_pixels[i].pixel)
		{
			/*char hfcode = 0;
			for(int j=0;j<8;j++)
			{
				hfcode = hfcode + sorted_pixels[i].HuffmanCode[j]*pow(2.0,7-j);
			}*/
			return sorted_pixels[i].hfcode;
		}
	}
	return NULL;
}

char getBMPpixel(char hfcode,Pixel *sorted_pixels,int n)			//huffman_code -> pixel
{
	for(int i=0;i<n;i++)
	{
		if(hfcode == sorted_pixels[i].hfcode)
		{
			return sorted_pixels[i].pixel;
		}
	}
	return NULL;
}
#endif