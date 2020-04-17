/******************
	ex42
	1427405017
	沈家赟
	2015/5/8
******************/
/*************************************************
4.7   请编写程序ex42实现如下功能：
	由用户从键盘输入两个字符串str1和str2；
	然后，确定str2在str1中出现的起始位置
	（如果不出现，则起始位置是-1）；
	最后，显示输出起始位置。

	充分利用字符串指令和重复前缀
**************************************************/
#include <stdio.h>

#define MAX_LEN 50

int main()
{
	char str1[MAX_LEN];
	char str2[MAX_LEN];
	int index=0, str1_len=0, str2_len=0;
	
	printf("嵌入汇编程序ex42\n");
	printf("请输入一个最长为%d的字符串str1：\n",MAX_LEN);
	gets(str1);
	printf("请输入一个最长为%d的字符串str2：\n",MAX_LEN);
	gets(str2);

	_asm{

		LEA EDI, str2;
		CALL GET_STR_LEN;
		MOV str2_len, ECX;

		LEA EDI, str1;
		CALL GET_STR_LEN;
		MOV str1_len, ECX;

		LEA EDI, str1;
FIND_START:
		LEA ESI, str2;
		LODSB;			// BYTE PTR[ESI] -> AL，此处会改变ESI（ESI++）！
		DEC ESI;
		MOV ECX, -1;
		REPNE SCASB;	// CMP AL, BYTE PTR[EDI], EDI++，寻找可能的起始地址
		DEC EDI;
		PUSH EDI;		//保存可能的起始位置EDI

	/*判断str2在str1上是否越界*/
		ADD EDI, str2_len;
		LEA EBX, str1;
		ADD EBX, str1_len;
		CMP EDI, EBX;
		JA NO_RESULT; 

		POP EDI;
		PUSH EDI;
		//INC EDI;
		MOV ECX, str2_len;
		INC ECX;		//比较长度为str2_len时，实际会比较到str2_len + 1次
		REPE CMPSB;		//字符串逐字节比较
		CMP ECX, 0;		//若完整比较完了str2，则str2在str1中出现
		POP EDI;		//不论找没找到，都需要恢复起始位置EDI：1）找到，则用EDI求偏移量 2）没找到，则用EDI求下一次查找开始位置
		JNE NOT_GET;	//否则，str2不存在于当前起始地址后

		LEA EAX, str1;
		SUB EDI, EAX;
		MOV index, EDI;
		JMP OVER;
NOT_GET:
		INC EDI;		//从上次的起始位置的下一个字节开始，重新寻找起始位置
		JMP FIND_START;
NO_RESULT:
		POP EDI;
		MOV index, -1;
OVER:

	}

	printf("str2在str1中的起始位置为%d\n",index);
	printf("str1_len = %d\nstr2_len = %d\n",str1_len, str2_len);

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