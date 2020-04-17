/******************
	ex51_c
	1427405017
	沈家赟
	2015/6/9
******************/
/*************************************************
5.4  基于VC2010集成开发环境，编写一个实现如下功能的程序：
由用户从键盘输入一个十进制正整数，然后输出其各个因子。
其他要求：输入和输出只能采用字符串形式（只能使用格式符“%s”）；
应该设计合适的函数。

请在编译选项“大小最小化”和“速度最大化”的情况下，
生成汇编格式的目标代码，并对照源程序分析目标代码。
**************************************************/

#include <stdio.h>
#include <stdlib.h>

#define MAX_LENGTH 20

int main()
{
	char str_in[MAX_LENGTH], str_out[MAX_LENGTH][10];
	unsigned int num = 0, factors_count = 0;
	puts("ex51_c\n请输入一个十进制数：");
	gets_s(str_in);

	num = atoi(str_in);
	for (int i=num; i > 0; i--)
	{
		if (num%i == 0)
		{
			itoa(i, str_out[factors_count++], 10);
		}
	}

	puts("该十进制数值的因子为：");
	for (unsigned int i = 0; i < factors_count; i++)
	{
		printf("%s ", str_out[i]);
	}
	printf("\n");

	return 0;
}