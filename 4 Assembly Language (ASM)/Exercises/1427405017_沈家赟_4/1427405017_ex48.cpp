/******************
	ex48
	1427405017
	沈家赟
	2015/5/21
******************/
/*************************************************
4.13   请编写程序ex48实现如下功能：
	由用户从键盘分别输入两个十六进制数值；
	然后，求它们的和与差；
	最后，采用十六进制数的形式分别输出结果。
	请采用合适的子程序。

	假设结果采用64位表示
	输入和输出只能采用字符串形式
**************************************************/
#include <stdio.h>

#define SIZE 9		// 8*8=64位，加1字节结束标志'\0'

int main()
{
	char in_x[SIZE], in_y[SIZE], out_sub[SIZE], out_add[SIZE];
	int num_x=0, num_y=0;
	
	printf("嵌入汇编程序ex48\n");
	printf("请输入十六进制数x（字母大写，高位无需补0，程序自适应字符串长度）：\n");
	gets(in_x);
	printf("请输入十六进制数y（字母大写，高位无需补0，程序自适应字符串长度）：\n");
	gets(in_y);

	_asm{
		LEA ESI, in_x;
		CALL StrToHex;		// 调用ASCII字符串转数值子程序StrToHex
		MOV num_x, EDX;
		LEA ESI, in_y;
		CALL StrToHex;		// 调用ASCII字符串转数值子程序StrToHex
		MOV num_y, EDX;


		MOV EDX, num_x;
		ADD EDX, num_y;		// add

		LEA EDI, out_add;
		CALL HexToStr;		// 调用十六进制转换ASCII子程序HexToStr


		MOV EDX, num_x;
		SUB EDX, num_y;		//	sub

		LEA EDI, out_sub;
		CALL HexToStr;		// 调用十六进制转换ASCII子程序HexToStr
	}

	printf("x+y = %s（转换成的ASCII字符串）\n",out_add);
	printf("x-y = %s（转换成的ASCII字符串）\n",out_sub);

	return 0;

//	子程序名（入口标号）：StrToHex
//	功能：把一个十六进制字符串转换成对应的数值
//	入口参数：（1）存放十六进制字符串地址的通用寄存器ESI
//	出口参数：（1）存储转换数值结果的通用寄存器EDX
//	其他说明：（1）此段函数会调用并影响ECX,EAX,EDX的值
	_asm{
StrToHex:
		XOR EDX, EDX;
		MOV EDI, ESI;
		CALL GET_STR_LEN;	// 入口参数EDI，出口参数（长度）在ECX中
BY_BYTE:
		XOR EAX, EAX;
		MOV AL, BYTE PTR[ESI];
		INC ESI;
		CMP AL, 'A';
		JB NUM_STH;
		SUB AL, 55;		// A~F
		JMP PRE_SHIFT;
NUM_STH:
		SUB AL, 48;		// 0~9

/* 内层循环负责移位，并装载入EDX对应位段 */
PRE_SHIFT:
		PUSH ECX;
		DEC ECX;		// 循环移位计数
		CMP ECX, 0;
		JE LOAD_IN;
SHIFT_LEFT:
		SHL EAX, 4;
		LOOP SHIFT_LEFT;
LOAD_IN:
		ADD EDX, EAX;	// 累加入EDX
		POP ECX;
/* 内层循环结束 */

		LOOP BY_BYTE;

		RET;
	}

//	子程序名（入口标号）：HexToStr
//	功能：把一位十六进制数转换成对应字符ASCII码的子程序HexToStr
//	入口参数：（1）存放十六进制数值的通用寄存器EDX
//	出口参数：（1）存储转换ASCII结果的字符串地址的通用寄存器EDI
//	其他说明：（1）此段函数会调用并影响ECX,EAX的值
	_asm{
HexToStr:
		PUSH EBX;
		PUSH EDX;
		XOR EAX, EAX;
		BSR EAX, EDX;	// EAX存储位号，EDX存储位串

		SHR EAX, 2;		// 除4
		INC EAX;		// EAX此时为十六进制位个数

		MOV ECX, EAX;	// ECX循环计数器，初值为十六进制位的个数EAX
		ADD EDI, EAX;
		MOV BYTE PTR[EDI], 0;	//字符串尾置0
		DEC EDI;
GET_HEX:
		MOV BL, 00FH;
		AND BL, DL;		// 提取低4位入BL
		SHR EDX, 4;		// 右移4位，准备下一次取
		CMP BL, 00AH;
		JB NUM_HTS;
		ADD BL, 55;
		JMP STORE;
NUM_HTS:
		ADD BL, 48;
STORE:
		MOV BYTE PTR[EDI], BL;	// 从十六进制数值的低位到高位存入字符串数组（字符串的高位到地位）
		DEC EDI;

		LOOP GET_HEX;
		
		POP EDX;
		POP EBX;
		RET;
	}

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