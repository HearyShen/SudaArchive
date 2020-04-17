/******************
	ex44
	1427405017
	沈家赟
	2015/5/9
******************/
/*************************************************
4.9   请充分运用字符串操作指令编写程序ex44实现如下功能：
	由用户从键盘输入一个字符串；
	然后，过滤掉其中可能出现的标点符号；
	最后，显示输出过滤后的字符串。

	可以自行假设哪些标点符号
**************************************************/
#include <stdio.h>

#define MAX_LEN 50

int main()
{
	char str1[MAX_LEN];
	char str2[] = ",，.。!！?？;；:：'‘’\"“”()（）[]【】{}<>《》·";	// 自定义的标点符号参照数组
	int str1_index=0, str1_len=0, str2_len=0;
	
	printf("嵌入汇编程序ex44\n本程序将过滤字符串中的标点符号\n");
	printf("请输入一个最长为%d的字符串str1：\n",MAX_LEN);
	gets(str1);

	_asm{
		LEA EDI, str1;
		CALL GET_STR_LEN;
		MOV str1_len, ECX;

		LEA EDI, str2;
		CALL GET_STR_LEN;
		MOV str2_len, ECX;

		LEA ESI, str1;
		LEA EDI, str2;
FIND_NEXT:
		LODSB;					// 从ESI中取出一字节存入AL，ESI++
		CMP AL, 0;
		JE OVER;				// 遇结束符，则停止搜索
		MOV ECX, -1;
		REPNE SCASB;
		DEC EDI;
		MOV ECX, EDI;
		LEA EDI, str2;
		SUB ECX, EDI;			// 求出已在str2中比较的长度ECX
		CMP ECX, str2_len;		// 与str2_len长度比较，若ECX>str2_len，则说明该字节未出现在str2中，否则，左移此后的字符串以去除该标点符号
		JA NOT_EXISTED;
		JNA REMOVE_BYTE;
REMOVE_BYTE:
		MOV ECX, str1_len;
		SUB ECX, str1_index;
		INC ECX;				// 计算需要移动字节个数，设置为LOOP计数器ECX
		XOR EAX, EAX;
	MOVE_LEFT:
		MOV DL, BYTE PTR[ESI+EAX];
		MOV BYTE PTR[ESI+EAX-1], DL;
		INC EAX;
		LOOP MOVE_LEFT;
		DEC ESI;
		JMP FIND_NEXT;
NOT_EXISTED:
		INC str1_index;
		JMP FIND_NEXT;
OVER:

	}

	printf("过滤标点符号后的字符串为：%s\n",str1);

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