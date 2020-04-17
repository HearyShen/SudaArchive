/******************
	ex37
	1427405017
	沈家赟
	2015/4/15
******************/
/*************************************************
3.13   请编写程序ex37实现如下功能：
	由用户从键盘输入一个十进制数（值）；
	然后，把该数（值）转换成对应十六进制数的字符串；
	最后输出字符串。
	请采用子程序实现把一个数值转换为对应的十六进制数字符串。

	(输出  只能采用字符串形式，如：printf(“%s”,……);)
**************************************************/
#include <stdio.h>

int num_in;
char str_hex[10];

int main()
{
	printf("嵌入汇编程序ex37\n");
	printf("请输入一个十进制数值：\n");
	
	scanf("%d",&num_in);

	_asm{
		LEA EDI, str_hex;
		MOV EAX, num_in;
		CALL CONVERT_INT_TO_HEX;
	}

	printf("该字符对应的十六进制数字符串 %s\n",str_hex);
	
	return 0;

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