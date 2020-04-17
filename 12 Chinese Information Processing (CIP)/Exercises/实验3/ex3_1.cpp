/**
	CIP - ex3_1
	1427405017
	Éò¼ÒÚS
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>

#define BUFFER_SIZE	2
void main(char* args[])
{
	unsigned int counter;
	WCHAR wideChar;
	CHAR gb[BUFFER_SIZE] = {0,0};
	BOOL isDefaultCharUsed = false;

	FILE *fp;
	int ret;

	fp = fopen("map.txt", "w");
	if (fp == NULL)
	{
		printf("ERROR: can not open/create file!\n");
		return;
	}


	/*
		Unicode ==> GB2312(code page 936)
	*/
	for (counter = 0x0000; counter <= 0xFFFF; counter++)
	{
		wideChar = counter;

		WideCharToMultiByte(
			936,				// CodePage 936¼´GB2312±àÂë(MSDN)
			0,					// dwFlags
			&wideChar,			// lpWideCharStr
			1,					// cchWideChar
			gb,					// lpMultiByteStr
			BUFFER_SIZE,		// cbMultiByte
			NULL,				// lpDefaultChar
			&isDefaultCharUsed	// lpUsedDefaultChar
		);

		ret = fprintf(fp, "%2X%2X\n", (unsigned char)gb[0], (unsigned char)gb[1]);
		if (ret <= 0)
		{
			printf("ERROR: can not write data to file!\n");
			break;
		}

		printf("Unicode:0x%4X\tGB:0x%2X%2X\n", wideChar, (unsigned char)gb[1], (unsigned char)gb[0]);
		gb[0] = 0;
		gb[1] = 0;
	}

	fclose(fp);

	getchar();
}