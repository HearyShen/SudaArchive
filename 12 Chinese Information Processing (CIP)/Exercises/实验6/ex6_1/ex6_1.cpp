/**
	ex6_1
	ex6_1.cpp
	1427405017
	Shen Jiayun
	2017.12.10
*/

#define _CRT_SECURE_NO_WARNINGS
#include "ex6_utility.h"

void main()
{
	unsigned char words[MAX_COUNT * 2 + 1];
	unsigned int addr;
	FILE *fp;

	fp = fopen("HZK16", "rb");
	if (fp == NULL)
	{
		printf("ERROR: can't open file %s\n");
	}

	printf("Please input chinese-only words: ");
	scanf("%s", words);

	for(int count = 0; count < strlen((char *)words)/2; count++)
	{
		unsigned char *word;

		word = &words[count * 2];
		addr = gb2312ToAddr((unsigned char *)word);

		// printChinese(fp, addr);	// default output
		printChinese(fp, addr, '*', 2);	// bi-width output
	}

	fclose(fp);
}