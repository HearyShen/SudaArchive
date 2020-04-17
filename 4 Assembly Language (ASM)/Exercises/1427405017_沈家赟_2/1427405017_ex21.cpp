/*********************
	ex21
	1427405017
	沈家赟
	2016/3/15 8:15
*********************/
/********************************************************
2.4  请编写程序ex21实现如下功能：
	由用户从键盘输入4个字节数据（8位二进制数据，字符型）；
	把这4个字节数据作为无符号数，分别拼接成2个字数据；
	还拼接成1个双字数据；
	显示输出这2个字数据和1个双字数据。
*********************************************************/
#include <stdio.h>

void main()
{
	char input[4];
	unsigned short word1, word2;
	unsigned int dword1;

	printf("请输入四个字符：\n");
	scanf("%c %c %c %c",&input[0],&input[1],&input[2],&input[3]);

	printf("0x%02X 0x%02X 0x%02X 0x%02X\n",input[0],input[1],input[2],input[3]);

	_asm
	{
		LEA ESI, input;
		MOV AX, WORD PTR [ESI];
		MOV BX, WORD PTR [ESI+2];
		MOV ECX, DWORD PTR [ESI];
		MOV word1, AX;
		MOV word2, BX;
		MOV dword1, ECX;
	}
	printf("word1:0x%02x\n",word1);
	printf("word2:0x%02x\n",word2);
	printf("dword:0x%02x\n",dword1);
}