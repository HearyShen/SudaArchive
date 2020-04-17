/******************
	ex46
	1427405017
	沈家赟
	2015/5/10
******************/
/*************************************************
4.11   请编写程序ex46实现如下功能：
	由用户从键盘分别输入一个字符ch和一个数值n；
	然后，生成一个由字符ch构成的n个字符的字符串；
	最后，显示输出该字符串。
	请采用子程序实现生成一个字符串的操作。

	充分利用字符串操作指令和重复前缀
**************************************************/
#include <stdio.h>

#define MAX_LEN 50

int main()
{
	int n;
	char c;
	
	printf("嵌入汇编程序ex46\n");
	printf("请输入一个字符ch：\n",MAX_LEN);
	scanf("%c",&c);
	printf("请输入个数n：\n",MAX_LEN);
	scanf("%d",&n);

	char *str = new char[n+1];	// 根据长度需求动态申请n+1长度堆空间，留一位补\0

	_asm{
		MOV EDI, str;
		MOV AL, c;
		MOV ECX, n;
		REP STOSB;				// 循环n次，存入字符c

		MOV BYTE PTR[EDI], 0;	//	补\0
OVER:

	}

	printf("生成的一个由字符ch构成的n个字符的字符串为：\n%s\n",str);

	return 0;
}