/******************
	ex43
	1427405017
	沈家赟
	2015/5/9
******************/
/*************************************************
4.8   请编写程序ex43实现如下功能：
	由用户从键盘输入两个字符串str1和str2；
	然后，确定str1中的首个没有在str2中出现的字符位置
	（如果都出现，则位置为-1）；
	最后，显示输出位置。

	充分利用字符串指令和位操作指令
**************************************************/
#include <stdio.h>

#define MAX_LEN 50

int main()
{
	char str1[MAX_LEN];
	char str2[MAX_LEN];
	int str1_index=0, str1_len=0, str2_len=0;
	
	printf("嵌入汇编程序ex43\n");
	printf("请输入一个最长为%d的字符串str1：\n",MAX_LEN);
	gets(str1);
	printf("请输入一个最长为%d的字符串str2：\n",MAX_LEN);
	gets(str2);

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
		LODSB;					// 从ESI（str1）中取出一字节存入AL，ESI++
		CMP AL, 0;
		JE ALL_EXISTED;			// 遇结束符，则停止搜索
		MOV ECX, -1;
		REPNE SCASB;			// 在str2中寻找str1中取出的元素
		DEC EDI;
		MOV ECX, EDI;
		LEA EDI, str2;
		SUB ECX, EDI;			// 求出已在str2中比较的长度ECX
		CMP ECX, str2_len;		// 与str2_len长度比较，若ECX>str2_len，则说明该字节未出现在str2中，否则，比较str1中下一字节
		JA NOT_EXISTED;
		INC str1_index;
		JNA FIND_NEXT;
ALL_EXISTED:
		MOV str1_index, -1;
NOT_EXISTED:

	}

	printf("str1中的首个没有在str2中出现的字符位置(字符串下标)为%d\n",str1_index);

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