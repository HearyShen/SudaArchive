/******************
	ex34
	1427405017
	����S
	2015/4/12
******************/
/*************************************************
3.10   ���д����ex34ʵ�����¹��ܣ�
	���û��Ӽ�������һ���ַ�����
	Ȼ�󣬲����ַ������ȣ�
	�������ַ������ȡ�
	(���ֻ�ܲ����ַ�����ʽ��
	�磺printf(��%s��,����);)
**************************************************/
#include <stdio.h>

#define MAX_LENGTH 100

char str_in[MAX_LENGTH];
char str_out[8];

int main()
{
	printf("Ƕ�������ex34\n");
	printf("������һ���ַ�����\n");
	
	gets_s(str_in);

	_asm{
		LEA ESI, str_in;
		MOV ECX, 0;				//CX��Ϊ�����ַ����±�
		LEA EDI, str_out;
MAIN_LOOP:			//MAIN_LOOP�ⳤ�ȣ��ַ������� = CX
		CMP [ESI+ECX*1], '\0';
		JE END_LOOP;
		INC ECX;					//������NULL��Чֵ����ECX++
		JMP MAIN_LOOP;
END_LOOP:			//END_LOOPȡ���ַ������ȣ�����AX������
		MOV AX, CX;
		MOV ECX, 0;				//ECX��Ϊ0������Ϊд���ַ������±�
		MOV BL, 10;
DIV_PUSH:			//DIV_PUSHͨ��ѭ����10ȡ�ಢ��ջ�������ٳ������ӵ͵�����λ��ջ
		DIV BL;				//�̣�AL  ������AH
		CALL PUSH_BYTE;
		INC ECX;				//��ջ��������������ECX++

		CMP AL, 0;			//��Ϊ0�������DIVѭ��
		JE PREPARE_POP;

		MOVZX AX, AL;		//�̲�Ϊ0����׼����һ��DIV
		JMP DIV_PUSH;
PREPARE_POP:		//PREPARE_POP��EBXд����������0��׼��POP_OUTѭ��
		MOV EBX, 0;
POP_OUT:			//POP_OUTͨ��ѭ������ջ�е�num���Ӹ�λ����λ������תλASCII��д��
		CALL POP_BYTE;
		ADD AH, 48;			//numתchar
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
PUSH_BYTE:				//�Զ������ֽ�PUSH��ͳһ��ԴAH
		POP EDX;			//����PC
		DEC ESP;
		MOV [ESP+1], AH;
		PUSH EDX;
		RET;
POP_BYTE:				//�Զ������ֽ�POP��ͳһĿ��AH
		POP EDX;			//����PC
		MOV AH, [ESP+1];
		INC ESP;
		PUSH EDX;
		RET;
	}
}