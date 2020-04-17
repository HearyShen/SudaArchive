/******************
	ex41
	1427405017
	沈家赟
	2015/5/8
******************/
/*************************************************
4.6   请编写程序ex41实现如下功能：
	由用户从键盘输入一个字符串；
	然后，统计该字符串中各个英文字母出现的个数；
	最后，输出这些统计结果。

	充分利用字符串指令
**************************************************/
#include <stdio.h>

#define MAX_LEN 50

int main()
{
	char str_in[MAX_LEN];
	char en[52];
	int count_en = 0;
	for(int i=0;i<26;i++)
	{
		en[i] = 'a'+i;
	}
	for(int i=26;i<52;i++)
	{
		en[i] = 'A'+i-26;
	}
	printf("嵌入汇编程序ex41\n");
	printf("请输入一个最长为%d的字符串：\n",MAX_LEN);
	gets(str_in);

	_asm{
		LEA ESI, str_in;
		LEA EDI, en;
		MOV count_en, 0;
		CLD;
PRE_SCAN:
		MOV ECX, 52;	// 26*2
		LODSB;			// BYTE PTR[ESI] -> AL
		CMP AL, 0;
		JE OVER;
		PUSH EDI;		//SCASB会改变EDI，提前保存以便下一循环恢复
SCAN_EN:
		SCASB;
		LOOPNE SCAN_EN;
		JNZ NEXT;
FOUND:
		INC count_en; 
NEXT:
		POP EDI;		//恢复EDI
		JMP PRE_SCAN;
OVER:
	}
		
	printf("英文字母出现%d次\n",count_en);

	return 0;
}