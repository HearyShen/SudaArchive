/******************
	ex45
	1427405017
	沈家赟
	2015/5/10
******************/
/*************************************************
4.10   请充分运用字符串操作指令和重复前缀编写程序ex45实现如下功能：
	由用户从键盘输入两个字符串；
	然后，把两个字符串合并到一起；
	最后，显示输出合并后的字符串。
	请采用子程序实现两个字符串的合并。
**************************************************/
#include <stdio.h>

#define MAX_LEN 50

int main()
{
	char str1[MAX_LEN];
	char str2[MAX_LEN];
	char str_out[2*MAX_LEN];
	int str1_index=0, str1_len=0, str2_len=0;
	
	printf("嵌入汇编程序ex45\n");
	printf("请输入一个最长为%d的字符串str1：\n",MAX_LEN);
	gets(str1);
	printf("请输入一个最长为%d的字符串str2：\n",MAX_LEN);
	gets(str2);

	_asm{
		LEA EDI, str1;
		CALL GET_STR_LEN;		// 求str2长度
		MOV str1_len, ECX;

		LEA EDI, str2;
		CALL GET_STR_LEN;		// 求str2长度
		MOV str2_len, ECX;

		LEA EDI, str_out;
		LEA ESI, str1;
		MOV ECX, str1_len;
		REP MOVSB;				// 移动str1

		LEA ESI, str2;
		MOV ECX, str2_len;
		REP MOVSB;				// 移动str1
		MOV BYTE PTR[EDI], 0;	//	补\0
OVER:

	}

	printf("合并后的字符串为：%s\n",str_out);

	return 0;

//	子程序名（入口标号）：GET_STR_LEN
//	功能：对EDI中存放的地址指向的字符数组遍历，得出字符串长度（不包含\0）
//	入口参数：（1）存放数字数组地址的通用寄存器EDI
//	出口参数：（1）存储转换结果的int型变量ECX
//	其他说明：（1）此段函数会调用并影响ECX,EAX的值
	_asm{
GET_STR_LEN:
		XOR AL, AL;
		MOV ECX, -1;
		PUSH EDI;

		CLD;
		REPNE SCASB;
		DEC EDI;
		MOV ECX, EDI;
		POP EDI;
		SUB ECX, EDI;	// ECX存储str的长度

		RET;
	}
}