/*********************
	ex25
	1427405017
	沈家赟
	2016/3/17 19:52
*********************/
/********************************************************
2.8   请编写程序ex25实现如下功能：
	统计某个字符型（字节、8位）数组中10个数据之累加和。
	可以认为数组元素中的数据是无符号数，也可以是有符号数。
	请分别按无符号数和有符号数情形，
	计算它们的累加和（至少用16位表示），并显示输出。

	说明：可以在定义数组时初始化好这10个数据；
		也可以通过调用生成随机数函数产生。

*********************************************************/
#include <stdio.h>
#include <stdlib.h>

void main()
{
	char arr[10];
	unsigned int unsigned_sum = 0;
	signed int signed_sum = 0;

	for(int i=0;i<10;i++)
	{
		arr[i] = rand()%256;
		printf("%d 0x%02x \n",arr[i],arr[i]);
	}
	printf("\n");

	_asm
	{
		LEA ESI, arr;
		MOV ECX, 10;	//主循环计数器
		MOV EAX, 0;		//index
		LEA EDI, unsigned_sum;
		MOV [EDI], 0;
MAIN_LOOP1:
		MOV EBX, 0;
		MOV BL, [ESI+EAX*1];
		ADD [EDI], EBX;
		INC EAX;		//index++
		DEC ECX;		//主循环计数器--
		JNZ MAIN_LOOP1;
		JZ OVER1;
OVER1:

	}
	printf("作无符号数处理时，累加和为：0x%X %d\n",unsigned_sum,unsigned_sum);

	_asm
	{
		LEA ESI, arr;
		MOV ECX, 10;	//主循环计数器
		MOV EAX, 0;		//index
		LEA EDI, signed_sum;
		MOV [EDI], 0;
MAIN_LOOP2:
		SUB [ESI+EAX*1], 0;
		JS SIGNED;
		JNS ELSE;
SIGNED:
		MOV EBX, 0xFFFFFFFF;
		MOV BL, [ESI+EAX*1];
		ADD [EDI], EBX;
		INC EAX;		//index++
		DEC ECX;		//主循环计数器--
		JNZ MAIN_LOOP2;
		JZ OVER2;
ELSE:
		MOV EBX, 0;
		MOV BL, [ESI+EAX*1];
		ADD [EDI], EBX;
		INC EAX;		//index++
		DEC ECX;		//主循环计数器--
		JNZ MAIN_LOOP2;
		JZ OVER2;
OVER2:
	}
	printf("作有符号数处理时，累加和为：0x%X %d\n",signed_sum,signed_sum);
}