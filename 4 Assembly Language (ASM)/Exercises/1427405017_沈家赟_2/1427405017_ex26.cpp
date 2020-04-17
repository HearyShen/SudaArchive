/*********************
	ex26
	1427405017
	沈家赟
	2016/3/17 20:46
*********************/
/********************************************************
2.9   请编写程序EX26实现如下功能：
	假设有一个整型（双字，32位）数组，
	存放有13个无符号整数，
	计算“奇数之和”与“偶数之和”之差的绝对值，
	并显示输出。

	说明：可以在定义数组时初始化好这13个整数；
		也可以通过调用生成随机数函数产生。
*********************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void main()
{
	unsigned int arr[13];
	unsigned int odd_sum = 0;	//奇数odd
	unsigned int even_sum = 0;	//偶数even
	int delta_abs = 0;

	for(int i=0;i<13;i++)
	{
		arr[i] = (unsigned)rand()%1024;
		printf("%d 0x%02x \n",arr[i],arr[i]);
	}
	printf("\n");

	_asm
	{
		LEA ESI, arr;
		MOV ECX, 13;	//主循环计数器
		MOV EAX, 0;		//index
		LEA EDI, odd_sum;
		LEA EDX, even_sum;
MAIN_LOOP:
		MOV EBX, [ESI+EAX*4];
		AND EBX, 1;		//取出的数值与1做 与运算
		JNZ ODD_SUM;	//与运算结果不为0，则为奇数
		JZ EVEN_SUM;	//与运算结果为0，则为偶数
ODD_SUM:
		MOV EBX, [ESI+EAX*4];
		ADD [EDI], EBX;
		INC EAX;		//index++
		DEC ECX;		//主循环计数器--
		JNZ MAIN_LOOP;
		JZ OVER;
EVEN_SUM:
		MOV EBX, [ESI+EAX*4];
		ADD [EDX], EBX;
		INC EAX;		//index++
		DEC ECX;		//主循环计数器--
		JNZ MAIN_LOOP;
		JZ OVER;
OVER:					//奇数之和，偶数之和计算完毕
		MOV EAX, [EDI];
		MOV EBX, [EDX];
		SUB EAX, EBX;
		JS ABS;			//若差值为负，则跳转至ABS句块转正
		JNS END;		//若差值不为负，则跳转至END
ABS:
		IMUL EAX,  -1;
END:					//奇数之和与偶数之和之差的绝对值计算完毕
		MOV delta_abs, EAX;
	}
	printf("奇数之和为：%d 0x%02x\n",odd_sum,odd_sum);
	printf("偶数之和为：%d 0x%02x\n",even_sum,even_sum);
	printf("奇数之和与偶数之和的绝对值为：%d 0x%02x\n",delta_abs,delta_abs);
}