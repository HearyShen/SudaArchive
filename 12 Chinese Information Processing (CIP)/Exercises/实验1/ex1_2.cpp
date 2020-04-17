/**
	CIP - ex1_2
	Created:	2017.9.19 Tue
	Modified:	2017.9.25 Mon

	1427405017
	沈家赟
*/

#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

#define SIZE 20

void displayStrInDec(const char chs[]);


/*
	main
	描述：主函数
		实现汉字区位码的查看程序

	输入：标准输入，键盘输入汉字字符或字符串
	输出：标准输出，控制台显示区位码数值
*/
void main()
{
	char chs[SIZE];

	while(true)
	{
		printf("请输入汉字或字符：\n");
		scanf("%s", chs);

		printf("对应的十进制编码：\n");
		displayStrInDec(chs);

		printf("\n\n");
	}
}


/*
	displayStrInDec
	描述：显示字符串各字节的汉字区位码（十进制数值）

	输入：字符串（数组）地址
	输出：控制台显示输出十进制区位码数值
*/
void displayStrInDec(const char chs[])
{
	int i;

	for (i = 0; i < strlen(chs); i++)
	{
		printf("%4d", unsigned char(chs[i] - 0xA0));
	}
	printf("\n");
}

#endif