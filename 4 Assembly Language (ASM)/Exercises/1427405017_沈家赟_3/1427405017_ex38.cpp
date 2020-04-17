/******************
	ex38
	1427405017
	沈家赟
	2015/4/16
******************/
/*************************************************
3.14   请编写程序ex38实现如下功能：
	由用户从键盘输入一个十进制数字符串；
	然后，把该十进制数字符串转换成对应的数值；
	接着，把该数值转换成对应的十六进制数字符串；
	最后，输出十六进制数字符串。

	请采用子程序实现把十进制数字符串转换为对应的数值。
	请采用子程序实现把一个数值转换为对应的十六进制数字符串。

	输入和输出只能采用字符串形式。
	需求类似于：scanf(“%d”,&x);  printf(“%x”,x);
	但输入和输出只能用“%s”格式。
**************************************************/
#include <stdio.h>

#define MAX_LENGTH 30

char str_in[MAX_LENGTH];
int num = 0;
char str_hex[10];

int main()
{
	printf("嵌入汇编程序ex38\n");
	printf("请输入一个只含十进制数的字符串：\n");
	gets(str_in);

	_asm{
		LEA ESI, str_in;
		CALL CONVERT_STR_TO_INT;
		MOV num, EAX;
		LEA EDI, str_hex;
		CALL CONVERT_INT_TO_HEX;
	}

	printf("该字符对应的十进制数字 %d\n该字符对应的十六进制数字符串 %s\n",num,str_hex);
	
	return 0;

//	子程序名（入口标号）：CONVERT_STR_TO_INT
//	功能：对ESI中存放的地址指向的数字数组遍历转换，转换为十进制数字
//	入口参数：（1）存放数字数组地址的通用寄存器ESI
//	出口参数：（1）存储转换结果的int型变量EAX
//	其他说明：（1）此段函数会调用并影响ECX,EAX,EDX的值
	_asm{
CONVERT_STR_TO_INT:
		PUSH EBX;	//用栈保护被调用者保存寄存器
		PUSH EDI;
		MOV ECX, 0;	//ECX为入栈个数计数器
		MOV BX, 10;
STR_LENGTH:
		MOV AL, [ESI+ECX];
		CMP AL, 0;
		JE STR_TO_INT;	//读到'\0'，则跳出

		MOVZX AX, AL;
		PUSH AX;
		INC ECX;
		JMP STR_LENGTH;
STR_TO_INT:
		MOV EDX, 0;
		MOV EAX, 0;
		MOV EDI, 0;		//EDX作为临时求和寄存器，初始化置零
ADD_LOOP:
		CMP EDX, ECX;	//栈中数据全部取出，则加法循环结束并跳出至ADD_FIN
		JE ADD_FIN;
		POP AX;			//否则，POP取出数据
		SUB AX, '0';	//POP出的字符须转为十进制数值

		PUSH EDX;	//保存出栈序数EDX
	MUL_LOOP:
		CMP EDX, 0;		//设EDX为出栈序数，i号元素和10乘i次（i从0开始）
		JE MUL_FIN;
		PUSH EDX;
		MUL BX;			//AX与BX相乘，乘法运算结果在DX:AX中
		POP EDX;
		DEC EDX;

		JMP MUL_LOOP;
	MUL_FIN:
		POP EDX;	//还原出栈序数EDX
		INC EDX;
		MOVZX EAX, AX;
		ADD EDI, EAX;

		JMP ADD_LOOP;
ADD_FIN:
		MOV EAX, EDI;
		POP EDI;
		POP EBX;
		RET;
	}


//	子程序名（入口标号）：CONVERT_INT_TO_HEX
//	功能：将EAX中存放的数值转换为十六进制字符串
//	入口参数：（1）存放数值的通用寄存器EAX
//			（2）存放转换结果输出地址的通用寄存器EDI
//	出口参数：（1）通用寄存器EDI所指向的字符数组的值
//	其他说明：（1）此段函数会调用并影响ECX,EAX,EBX,EDX的值
	_asm{
CONVERT_INT_TO_HEX:
		MOV ECX, 0;		//ECX作为入栈个数计数器，初始化置零
		MOV BX, 16;
		
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
		CMP DL, 9;
		JA ALPHA;
		JNA NUM;
NUM:	//DL<=9
		ADD DL, '0';	//数值转字符
		JMP WRITE_MEM;
ALPHA:	//10<=DL
		ADD DL, 55;		//'A'=65，DL = DL + ('A'-10)
		JMP WRITE_MEM;
WRITE_MEM:
		MOV [EDI+EBX], DL;	//将有效的低字节部分移入主存中的输出数组
		INC EBX;		//计数器加1
		
		CMP EBX, ECX;
		JE POP_END;
		JMP POP_LOOP;
POP_END:
		MOV [EDI+EBX], 0;	//字符数组结尾须补'\0'
		RET;
	}
}