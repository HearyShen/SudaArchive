/**
	CIP - ex4_1
	ex4_1.cpp
	1427405017
	����S
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

void main()
{
	unsigned short inputNum;
	int i;
	char buffer;

	printf("������һ���޷��Ŷ�������");
	scanf("%hud", &inputNum);

	printf("������������£�\n");

	for (i = 15; i >= 0; i--)
	{
		printf("%d", (inputNum>>i)&0x1 );
	}
	printf("\n\n\n");
}
