/******************
	ex36
	1427405017
	沈家赟
	2015/4/15
******************/
/*************************************************
3.12   请编写程序ex36实现如下功能：
	由用户从键盘输入一个字符；
	输出对应ASCII码的二进制值。
	（把ASCII码值转换成对应的二进制数的字符串，然后输出）

	(输出  只能采用字符串形式，如：printf(“%s”,……);)
**************************************************/
#include <stdio.h>

char c_in;
char bin[9];

int main()
{
	printf("嵌入汇编程序ex36\n");
	printf("请输入一个字符：\n");
	
	scanf("%c",&c_in);

	_asm{
		LEA ESI, bin;
		MOV AL, c_in;
		MOV ECX, 8;	//1个字节8个位，循环移位须执行8次
		MOV EBX, 0;	//字符数组写出计数器置零
MAIN_LOOP:
		SHL AL, 1;	//逻辑左移后，最高位出现在CF中
		LAHF;		//AH中8位从高到低依次为SF ZF 0 AF 0 PF 1 CF
		AND AH, 1;	//只保留CF
		ADD AH, '0';
		MOV [ESI+EBX], AH;
		INC EBX;
		LOOP MAIN_LOOP;
		MOV [ESI+EBX], 0;
	}

	printf("该字符对应的ASCII码值的二进制表示 %s\n",bin);
	
	return 0;
}