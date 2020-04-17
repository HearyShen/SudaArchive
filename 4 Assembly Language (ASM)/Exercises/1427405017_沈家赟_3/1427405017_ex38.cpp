/******************
	ex38
	1427405017
	����S
	2015/4/16
******************/
/*************************************************
3.14   ���д����ex38ʵ�����¹��ܣ�
	���û��Ӽ�������һ��ʮ�������ַ�����
	Ȼ�󣬰Ѹ�ʮ�������ַ���ת���ɶ�Ӧ����ֵ��
	���ţ��Ѹ���ֵת���ɶ�Ӧ��ʮ���������ַ�����
	������ʮ���������ַ�����

	������ӳ���ʵ�ְ�ʮ�������ַ���ת��Ϊ��Ӧ����ֵ��
	������ӳ���ʵ�ְ�һ����ֵת��Ϊ��Ӧ��ʮ���������ַ�����

	��������ֻ�ܲ����ַ�����ʽ��
	���������ڣ�scanf(��%d��,&x);  printf(��%x��,x);
	����������ֻ���á�%s����ʽ��
**************************************************/
#include <stdio.h>

#define MAX_LENGTH 30

char str_in[MAX_LENGTH];
int num = 0;
char str_hex[10];

int main()
{
	printf("Ƕ�������ex38\n");
	printf("������һ��ֻ��ʮ���������ַ�����\n");
	gets(str_in);

	_asm{
		LEA ESI, str_in;
		CALL CONVERT_STR_TO_INT;
		MOV num, EAX;
		LEA EDI, str_hex;
		CALL CONVERT_INT_TO_HEX;
	}

	printf("���ַ���Ӧ��ʮ�������� %d\n���ַ���Ӧ��ʮ���������ַ��� %s\n",num,str_hex);
	
	return 0;

//	�ӳ���������ڱ�ţ���CONVERT_STR_TO_INT
//	���ܣ���ESI�д�ŵĵ�ַָ��������������ת����ת��Ϊʮ��������
//	��ڲ�������1��������������ַ��ͨ�üĴ���ESI
//	���ڲ�������1���洢ת�������int�ͱ���EAX
//	����˵������1���˶κ�������ò�Ӱ��ECX,EAX,EDX��ֵ
	_asm{
CONVERT_STR_TO_INT:
		PUSH EBX;	//��ջ�����������߱���Ĵ���
		PUSH EDI;
		MOV ECX, 0;	//ECXΪ��ջ����������
		MOV BX, 10;
STR_LENGTH:
		MOV AL, [ESI+ECX];
		CMP AL, 0;
		JE STR_TO_INT;	//����'\0'��������

		MOVZX AX, AL;
		PUSH AX;
		INC ECX;
		JMP STR_LENGTH;
STR_TO_INT:
		MOV EDX, 0;
		MOV EAX, 0;
		MOV EDI, 0;		//EDX��Ϊ��ʱ��ͼĴ�������ʼ������
ADD_LOOP:
		CMP EDX, ECX;	//ջ������ȫ��ȡ������ӷ�ѭ��������������ADD_FIN
		JE ADD_FIN;
		POP AX;			//����POPȡ������
		SUB AX, '0';	//POP�����ַ���תΪʮ������ֵ

		PUSH EDX;	//�����ջ����EDX
	MUL_LOOP:
		CMP EDX, 0;		//��EDXΪ��ջ������i��Ԫ�غ�10��i�Σ�i��0��ʼ��
		JE MUL_FIN;
		PUSH EDX;
		MUL BX;			//AX��BX��ˣ��˷���������DX:AX��
		POP EDX;
		DEC EDX;

		JMP MUL_LOOP;
	MUL_FIN:
		POP EDX;	//��ԭ��ջ����EDX
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


//	�ӳ���������ڱ�ţ���CONVERT_INT_TO_HEX
//	���ܣ���EAX�д�ŵ���ֵת��Ϊʮ�������ַ���
//	��ڲ�������1�������ֵ��ͨ�üĴ���EAX
//			��2�����ת����������ַ��ͨ�üĴ���EDI
//	���ڲ�������1��ͨ�üĴ���EDI��ָ����ַ������ֵ
//	����˵������1���˶κ�������ò�Ӱ��ECX,EAX,EBX,EDX��ֵ
	_asm{
CONVERT_INT_TO_HEX:
		MOV ECX, 0;		//ECX��Ϊ��ջ��������������ʼ������
		MOV BX, 16;
		
DIV_PUSH:
		MOVZX EAX, AX;
		ROL EAX, 16;	//��ѭ����16λ��ʹ��16λλ��AX
		MOV DX, AX;		//��16λ��AX����DX
		ROR EAX, 16;	//�ָ�

		DIV BX;			//�̣�AX��������DX
		PUSH DX;
		INC ECX;
		
		CMP AX, 0;		//��Ϊ0�����ٳ�������������ѭ��
		JE PRE_POP;
		JMP DIV_PUSH;
PRE_POP:
		MOV EBX, 0;		//EBX��Ϊ��ջ��������������ʼ������
POP_LOOP:
		POP DX;			//ȡ�����ֽ�����
		CMP DL, 9;
		JA ALPHA;
		JNA NUM;
NUM:	//DL<=9
		ADD DL, '0';	//��ֵת�ַ�
		JMP WRITE_MEM;
ALPHA:	//10<=DL
		ADD DL, 55;		//'A'=65��DL = DL + ('A'-10)
		JMP WRITE_MEM;
WRITE_MEM:
		MOV [EDI+EBX], DL;	//����Ч�ĵ��ֽڲ������������е��������
		INC EBX;		//��������1
		
		CMP EBX, ECX;
		JE POP_END;
		JMP POP_LOOP;
POP_END:
		MOV [EDI+EBX], 0;	//�ַ������β�벹'\0'
		RET;
	}
}