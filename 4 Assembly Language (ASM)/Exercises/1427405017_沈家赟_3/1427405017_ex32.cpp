/******************
	ex32
	1427405017
	沈家赟
	2015/3/29 9:30
******************/
/*************************************************
3.8   请编写程序ex32实现如下功能：
	由用户从键盘输入一个字符串；
	然后，分别统计字符串中英文字母的个数和数字符的个数；
	最后，输出统计结果。
	请采用子程序判断字符是否为英文字母。
	请采用子程序判断字符是否为数字符（0-9）。
**************************************************/
#include <stdio.h>

char str[100];

int main()
{
	int alpha_count = 0;
	int num_count = 0;
	printf("嵌入汇编程序ex32\n");
	printf("请输入一个字符串：\n");
	gets(str);
	//scanf("%s",&str);

	_asm{
		LEA ESI, str;
		LEA EBX, alpha_count;
		LEA EDX, num_count;
		MOV ECX, 0;
MAIN_LOOP:
		MOV AL, [ESI+ECX*1];
		CMP AL, '\0';
		JE END_LOOP;
		CALL COUNT_ALPHABET;
		CALL COUNT_NUMBER;
		INC ECX;
		JMP MAIN_LOOP;
END_LOOP:

	}

	printf("英文字母个数：%d\n数字符个数：%d\n",alpha_count,num_count);
	return 0;

	_asm{
COUNT_ALPHABET:	//检查英文字母
		CMP AL, 'A';
		JB EXCLUSION;
		CMP AL, 'Z';
		JNA ALPHABET;
		CMP AL, 'z';
		JA EXCLUSION;
		CMP AL, 'a';
		JNB ALPHABET;
		RET;

ALPHABET:				//检查到英文字母
		INC [EBX];
		RET;

COUNT_NUMBER:		//检查数字符
		CMP AL, '0';
		JB EXCLUSION;
		CMP AL, '9';
		JA EXCLUSION;
		INC [EDX];
		RET;

EXCLUSION:			//例外情况
		RET;
	}
}