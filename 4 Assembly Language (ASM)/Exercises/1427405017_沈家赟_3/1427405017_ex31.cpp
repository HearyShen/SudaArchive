/******************
	ex31
	1427405017
	沈家赟
	2015/3/29 8:51
******************/
/*************************************************
3.7   请编写程序ex31实现如下功能：
	由用户从键盘输入一个字符串；
	然后，把字符串中的所有大写字母转换为小写字母；
	最后输出字符串。
	请采用子程序实现把一个可能的大写字母转换为对应的小写字母。
**************************************************/
#include <stdio.h>
#include <string>

char str[100];

int main()
{
	printf("嵌入汇编程序ex31\n");
	printf("请输入一个字符串：\n");
	gets(str);
	//scanf("%s",&str);

	_asm{
		LEA ESI, str;
		MOV ECX, 0;
MAIN_LOOP:
		MOV AL, [ESI+ECX*1];
		CMP AL, 0;			//检测结束符 ‘\0’
		JE END_LOOP;		// 遇'\0'则结束主循环
		CALL TO_LOWER;	//调用转小写函数TO_LOWER(入口变量AL, 出口变量AL)
		MOV [ESI+ECX*1], AL;
		INC ECX;
		JMP MAIN_LOOP;

END_LOOP:

	}

	printf("%s\n",str);
	return 0;

	_asm{
TO_LOWER:
		CMP AL, 'A';
		JB EXCLUSION;
		CMP AL, 'Z';
		JA EXCLUSION;
		ADD AL, 32;		//'A'<=AL<='Z',则+32转小写
		RET;
EXCLUSION:
		RET;
	}
}