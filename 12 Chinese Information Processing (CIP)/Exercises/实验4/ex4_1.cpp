/**
	CIP - ex4_1
	ex4_1.cpp
	1427405017
	沈家赟
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

void main()
{
	unsigned short inputNum;
	int i;
	char buffer;

	printf("请输入一个无符号短整数：");
	scanf("%hud", &inputNum);

	printf("二进制输出如下：\n");

	for (i = 15; i >= 0; i--)
	{
		printf("%d", (inputNum>>i)&0x1 );
	}
	printf("\n\n\n");
}
