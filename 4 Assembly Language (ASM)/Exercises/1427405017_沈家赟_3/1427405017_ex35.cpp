/******************
	ex35
	1427405017
	沈家赟
	2015/4/13
******************/
/*************************************************
3.11   请编写程序ex35实现如下功能：
	由用户从键盘输入一个字符串；
	然后，分别统计字符串中 英文字母的个数和数字符的个数；
	最后，分别输出统计结果。

	请采用子程序实现一项统计功能。
	请采用子程序实现把数值转换为对应十进制数的字符串。

	(输出  只能采用字符串形式，如：printf(“%s”,……);)
**************************************************/
#include <stdio.h>

#define MAX_LENGTH 100

char str_in[MAX_LENGTH];
char en_count[10];
char num_count[10];

int main()
{
	printf("嵌入汇编程序ex35\n");
	printf("请输入一个字符串：\n");
	
	gets_s(str_in);

	_asm{
		LEA ESI, str_in;

		CALL COUNT_ALPHABET;		//EAX中存储统计出的英文字符个数
		LEA EDI, en_count;
		CALL CONVERT_INT_TO_STR;	//数值转字符串输出

		CALL COUNT_NUM;				//EAX中存储统计出的数字符个数
		LEA EDI, num_count;
		CALL CONVERT_INT_TO_STR;	//数值转字符串输出
	}

	printf("英文字符个数 = %s\n数字符个数 = %s\n",en_count,num_count);
	
	return 0;

//	子程序名（入口标号）：COUNT_ALPHABET
//	功能：对ESI所存地址的字符数组进行遍历检查，统计英文字母的个数
//	入口参数：（1）存放字符数组地址的通用寄存器ESI
//	出口参数：（1）存放统计结果（数组中英文字符个数）的通用寄存器EAX
//	其他说明：（1）此段函数会调用并影响ECX的值
	_asm{
COUNT_ALPHABET:
		MOV ECX, 0;		//数组访问index置零
		MOV EAX, 0;		//英文字符计数器置零
LOOP_ALPHA:
		MOV DL, [ESI+ECX];		//将当前字符单元缓存进寄存器，为多次比较优化
		INC ECX;

		CMP DL, 0;
		JE ALPHA_END;	//遇'\0'，则数组结束

		CMP DL, 'A';
		JB LOOP_ALPHA;	//字符<'A'
		CMP DL, 'Z';
		JNA INC_ALPHA;	//'A'<=字符<='Z'
		CMP DL, 'a';
		JB LOOP_ALPHA;	//'Z'<字符<'a'
		CMP DL, 'z';
		JNA INC_ALPHA;	//'a'<=字符<='z'
		JMP LOOP_ALPHA;	//'z'<字符
INC_ALPHA:
		INC EAX;
		JMP LOOP_ALPHA;
ALPHA_END:
		RET;
	}


//	子程序名（入口标号）：COUNT_NUM
//	功能：对ESI所存地址的字符数组进行遍历检查，统计数字符的个数
//	入口参数：（1）存放字符数组地址的通用寄存器ESI
//	出口参数：（1）存放统计结果（数组中数字符个数）的通用寄存器EAX
//	其他说明：（1）此段函数会调用并影响ECX的值
	_asm{
COUNT_NUM:
		MOV ECX, 0;		//数组访问index置零
		MOV EAX, 0;		//数字符计数器置零
LOOP_NUM:
		MOV DL, [ESI+ECX];		//将当前字符单元缓存进寄存器，为多次比较优化
		INC ECX;

		CMP DL, 0;
		JE NUM_END;	//遇'\0'，则数组结束
		
		CMP DL, '0';
		JB LOOP_NUM;	//字符<'0'
		CMP DL, '9';
		JNA INC_NUM;	//'0'<字符<'9'
		JMP LOOP_NUM;	//'9'<字符
INC_NUM:
		INC EAX;
		JMP LOOP_NUM;
NUM_END:
		RET;
	}


//	子程序名（入口标号）：CONVERT_INT_TO_STR
//	功能：将EAX中存放的数值转换为十进制字符串
//	入口参数：（1）存放数值的通用寄存器EAX
//			（2）存放转换结果输出地址的通用寄存器EDI
//	出口参数：（1）通用寄存器EDI所指向的字符数组的值
//	其他说明：（1）此段函数会调用并影响ECX,EAX,EDX的值
	_asm{
CONVERT_INT_TO_STR:
		PUSH EBX;
		MOV ECX, 0;		//ECX作为入栈个数计数器，初始化置零
		MOV BX, 10;
		
DIV_PUSH:
		MOVZX EAX, AX;
		ROL EAX, 16;	//左循环移16位，使高16位位于AX
		MOV DX, AX;		//高16位从AX移入DX
		ROR EAX, 16;	//恢复

		DIV BX;			//商：AX，余数：DX
		PUSH DX;
		INC ECX;
		
		CMP AX, 0;		//商为0，则不再除，跳出除运算循环
		JE PRE_POP;
		JMP DIV_PUSH;
PRE_POP:
		MOV EBX, 0;		//EBX作为出栈个数计数器，初始化置零
POP_LOOP:
		POP DX;			//取出两字节数据
		ADD DL, '0';	//数值转字符
		MOV [EDI+EBX], DL;	//将有效的低字节部分移入主存中的输出数组
		INC EBX;		//计数器加1
		
		CMP EBX, ECX;
		JE POP_END;
		JMP POP_LOOP;
POP_END:
		MOV [EDI+EBX], 0;	//字符数组结尾须补'\0'
		POP EBX;
		RET;
	}

}