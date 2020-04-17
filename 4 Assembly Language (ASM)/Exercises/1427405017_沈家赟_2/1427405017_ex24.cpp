/*********************
	ex24
	1427405017
	沈家赟
	2016/3/17 19:00
*********************/
/********************************************************
2.7   假设有一个无符号字符型（字节、8位）数组，存放有20个数据。
	如果把2个连续的字节数据视作为1个16位数据，那么就有10个字数据；
	如果把4个连续的字节数据视作为1个32位数据，那么就有5个双字数据。
	请编写程序ex24实现如下功能：
		将这些数据作为10个16位整数，统计正数的个数；
		将这些数据作为5个32位整数，统计负数的个数；
		显示输出统计结果。

	说明：可以在定义数组时初始化好这20个数据；
		也可以通过调用生成随机数函数产生。
*********************************************************/
#include <stdio.h>
#include <stdlib.h>

void main()
{
	char arr[20];
	int positive_in_16bit = 0, negative_in_32bit = 0;

	for(int i=0;i<20;i++)
	{
		arr[i] = rand()%256;		//initialize
		printf("%d 0x%02X \n",arr[i],arr[i]);
	}
	printf("\n");

	_asm
	{
		LEA ESI, arr;
		MOV ECX, 10;	//主循环计数器ECX
		MOV EAX, 0;		//index
		LEA EDI, positive_in_16bit;
		MOV [EDI], 0;
MAIN_LOOP1:
		CMP WORD PTR[ESI+EAX*2], 0;
		JG POSITIVE;
		JMP ELSE1;
POSITIVE:
		INC EAX;		//index++
		INC [EDI];		//正数计数器++
		DEC ECX;		//主循环计数器--
		JNZ MAIN_LOOP1;
		JZ OVER1;
ELSE1:
		INC EAX;		//index++
		DEC ECX;		//主循环计数器--
		JNZ MAIN_LOOP1;
		JZ OVER1;
OVER1:
	}
	printf("16位整数中，正数个数为：%d\n",positive_in_16bit);

	_asm
	{
		LEA ESI, arr;
		MOV ECX, 5;		//主循环计数器
		MOV EAX, 0;		//index
		LEA EDI, negative_in_32bit;
		MOV [EDI], 0;
MAIN_LOOP2:
		CMP DWORD PTR[EDI+EAX*4], 0;
		JL NEGATIVE;
		JMP ELSE2;
NEGATIVE:
		INC EAX;		//index++
		INC [EDI];		//负数计数器++
		DEC ECX;		//主循环计数器--
		JNZ MAIN_LOOP2;
		JZ OVER2;
ELSE2:
		INC EAX;		//index++
		DEC ECX;		//主循环计数器--
		JNZ MAIN_LOOP2;
		JZ OVER2;
OVER2:
	}
	printf("32位整数中，负数个数为：%d\n",negative_in_32bit);
}