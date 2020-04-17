/*********************
	ex23
	1427405017
	沈家赟
	2016/3/15 9:42
*********************/
/********************************************************
2.6   请编写程序ex23实现如下功能：
	假设有一个字符型（字节、8位）数组，含有10个整数，
	统计这些整数中正数和负数的个数，并显示输出统计结果。
	
	说明：可以在定义数组时初始化好这10个数据；
		也可以通过调用生成随机数函数产生。
*********************************************************/
#include <stdio.h>

void main()
{
	char c[10] = {0,1,-2,3,-4,5,-6,7,-8,9};
	int above_0 = 0, below_0 = 0;

	for(int i=0;i<10;i++)
	{
		printf("%d ",c[i]);
	}
	printf("\n");

	_asm
	{
		MOV ECX, 10;
		MOV EAX, 0;
		LEA ESI, c;		//ESI存放字符数组地址
		LEA EBX, above_0;	//正数计数器
		MOV [EBX], 0;
		LEA EDX, below_0;	//负数计数器
		MOV [EDX], 0;
MAIN_LOOP:
		SUB [ESI + EAX*1], 0;	//逐项访问字符数组数据
		JZ ZERO;		//先判断是否为0
		JS SIGNED;		//有符号数，即负数
		JNS UNSIGNED;	//无符号数，即正数
ZERO:
		INC EAX;		//index++，访问数组下一项
		DEC ECX;		//主循环计数器减1
		JNZ MAIN_LOOP;		//若主循环计数器不为0，则继续主循环，否则结束
		JZ OVER;			//若主循环计数器为0，则跳过SIGNED / UNSIGNED 句段，直接调至OVER句段
SIGNED:
		INC EAX;		//index++，访问数组下一项
		INC [EDX];	//负数计数器++
		DEC ECX;		//主循环计数器减1
		JNZ MAIN_LOOP;		//若主循环计数器不为0，则继续主循环，否则结束
		JZ OVER;			//若主循环计数器为0，则跳过SIGNED / UNSIGNED 句段，直接调至OVER句段
UNSIGNED:
		INC EAX;		//index++，访问数组下一项
		INC [EBX];	//正数计数器++
		DEC ECX;		//主循环计数器减1
		JNZ MAIN_LOOP;		//若主循环计数器不为0，则继续主循环，否则结束
		JZ OVER;			//若主循环计数器为0，则跳过SIGNED / UNSIGNED 句段，直接调至OVER句段
OVER:
	}

	printf("正数个数：%d\n",above_0);
	printf("负数个数：%d\n",below_0);
}