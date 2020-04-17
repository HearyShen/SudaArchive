/**
	ex6_1
	ex6_utility.h
	1427405017
	Shen Jiayun
	2017.12.10
*/

#ifndef EX6_UTILITY
#define EX6_UTILITY

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COUNT 100
#define BUFFER_SIZE 1000
#define BYTE_BITS 8


/*
	DECLARATIONS
*/

/*
* @method:	gb2312ToAddr
* @param:	gnEncode[0:1] carries GB2312 encode data of a Chinese word
			rowCount/colCount - bits count of bitmap data in row/col
* @return:	address of the GB2312 encode word in the 16*16 bitmap datafile
*/
unsigned int gb2312ToAddr(const unsigned char gbEncode[],
	const unsigned int rowCount = 16,
	const unsigned int colCount = 16);

/*
* @method:	printChinese
* @param:	fp - FILE pointer of opened 16*16 bitmap datafile
			startAddr - the start address of target Chinese word bits
			fillCh/fillCount - fill fillCh for fillCount times when bit equals one
			rowCount/colCount - bits count of bitmap data in row/col
* @return:	print 16*16 bitmap of Chinese word
*/
void printChinese(FILE *fp,
	const unsigned int startAddr,
	const char fillCh = '*',
	const unsigned int fillCount = 1,
	const unsigned int rowCount = 16,
	const unsigned int colCount = 16);


#endif
