/**
	CIP - ex4_2
	ex4_2.cpp
	1427405017
	沈家赟
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include "base64.h"

#define STR_SIZE 200
#define BUFFER_SIZE 300

void main()
{
	char str_in[STR_SIZE];
	char base64[BUFFER_SIZE];
	char str_decode[STR_SIZE];

	/* 
		get str_in from input
	*/
	printf("Please input a string:\n");
	scanf("%s", str_in);

	/*
		encode str_in to base64
	*/
	encodeStrToBase64(str_in, base64);
	printf("\nBase64 encode result:\n%s\n", base64);


	/*
		decode base64 to str_decode
	*/
	decodeBase64ToStr(base64, str_decode);
	printf("\nBase64 decode result:\n%s\n", str_decode);
}

