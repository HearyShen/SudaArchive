/******************
	ex34
	1427405017
	沈家赟
	2015/4/12
******************/
/*************************************************
3.10   请编写程序ex34实现如下功能：
	由用户从键盘输入一个字符串；
	然后，测量字符串长度；
	最后，输出字符串长度。
	(输出只能采用字符串形式，
	如：printf(“%s”,……);)
**************************************************/
#include <stdio.h>

#define MAX_LENGTH 100

char str_in[MAX_LENGTH];
char str_out[8];

int main()
{
	printf("嵌入汇编程序ex34\n");
	printf("请输入一个字符串：\n");
	
	gets_s(str_in);

	_asm{
		LEA ESI, str_in;
		MOV ECX, 0;				//CX设为输入字符串下标
		LEA EDI, str_out;
MAIN_LOOP:			//MAIN_LOOP测长度，字符串长度 = CX
		CMP [ESI+ECX*1], '\0';
		JE END_LOOP;
		INC ECX;					//读到非NULL有效值，则ECX++
		JMP MAIN_LOOP;
END_LOOP:			//END_LOOP取得字符串长度，放入AX，待除
		MOV AX, CX;
		MOV ECX, 0;				//ECX置为0，将作为写出字符数组下标
		MOV BL, 10;
DIV_PUSH:			//DIV_PUSH通过循环除10取余并入栈，商数再除，来从低到高逐位入栈
		DIV BL;				//商：AL  余数：AH
		CALL PUSH_BYTE;
		INC ECX;				//入栈余数个数计数器ECX++

		CMP AL, 0;			//商为0，则结束DIV循环
		JE PREPARE_POP;

		MOVZX AX, AL;		//商不为0，则准备下一次DIV
		JMP DIV_PUSH;
PREPARE_POP:		//PREPARE_POP将EBX写出计数器置0，准备POP_OUT循环
		MOV EBX, 0;
POP_OUT:			//POP_OUT通过循环读出栈中的num（从高位到地位），并转位ASCII码写出
		CALL POP_BYTE;
		ADD AH, 48;			//num转char
		MOV [EDI + EBX*1], AH;
		INC EBX;

		CMP EBX, ECX;
		JNE POP_OUT;
END:
		MOV [EDI + EBX*1], '\0';
	}
	printf("%s\n",str_out);

	return 0;
	
	_asm{
PUSH_BYTE:				//自定义逐字节PUSH，统一来源AH
		POP EDX;			//保护PC
		DEC ESP;
		MOV [ESP+1], AH;
		PUSH EDX;
		RET;
POP_BYTE:				//自定义逐字节POP，统一目标AH
		POP EDX;			//保护PC
		MOV AH, [ESP+1];
		INC ESP;
		PUSH EDX;
		RET;
	}
}