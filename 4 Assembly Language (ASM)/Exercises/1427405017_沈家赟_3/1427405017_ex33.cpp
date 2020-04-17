/******************
	ex33
	1427405017
	沈家赟
	2015/3/29 
******************/
/*************************************************
3.9   请编写程序ex33实现如下功能：
	由用户从键盘输入一个字符串；
	然后，删除字符串中的所有非英文字母和非10进制数字符，形成新的字符串；
	最后输出新的字符串。
**************************************************/
#include <stdio.h>

#define MAX_LENGTH 100

char str_in[MAX_LENGTH];
char str_out[MAX_LENGTH];

int main()
{
	printf("嵌入汇编程序ex33\n");
	printf("请输入一个字符串：\n");
	
	gets(str_in);

	_asm{
		LEA ESI, str_in;
		MOV ECX, 0;			//输入数组下标计数器
		LEA EDI, str_out;
		MOV EDX, 0;			//输出数组下标计数器
MAIN_LOOP:
		MOV AL, [ESI+ECX*1];
		CMP AL, '\0';
		JE END_LOOP;
		//PUSH AL;			//字符数值入栈
		CALL DELETE_ELEMENT;

		//MOV [ESI+ECX*1], AL;
		INC ECX;
		JMP MAIN_LOOP;

DELETE_ELEMENT:
		PUSH EBP;
		MOV EBP, ESP;		//建立堆栈框架

		CMP AL, '0';
		JB RET_CALL;
		CMP AL, '9';
		JNA MOV_OUT;	//符合条件，则跳转至MOV_OUT写出

		CMP AL,'A';
		JB RET_CALL;
		CMP AL,'Z';
		JNA MOV_OUT;	//符合条件，则跳转至MOV_OUT写出

		CMP AL,'a';
		JB RET_CALL;
		CMP AL,'z';
		JNA MOV_OUT		//符合条件，则跳转至MOV_OUT写出
		JA RET_CALL;	//最后一次判断，不符合则结束，不可执行到MOV_OUT段干扰写出结果

	MOV_OUT:
		MOV [EDI+EDX*1], AL;	//根据输出数组下标，写入数值
		INC EDX;

	RET_CALL:				//撤销堆栈框架
		POP EBP;
		RET;

END_LOOP:

	}
	printf("新的字符串（删去非英文字母和10进制数字符）：\n%s\n",str_out);

	return 0;

}