/******************
	ex310
	1427405017
	����S
	2015/4/17
******************/
/*************************************************
3.16   ���д����ex310ʵ�����¹��ܣ�
	���û��Ӽ��̷ֱ�����������Ȼ����
	Ȼ�󣬼��������������̺�������
	��������
	����ú��ʵ��ӳ���

	��������ֻ�ܲ����ַ�����ʽ��
	���Լ������32λ��ʾ��
**************************************************/
#include <stdio.h>

#define MAX_LENGTH 30

char str_x[MAX_LENGTH];
char str_y[MAX_LENGTH];
int num_x = 0;
int num_y = 0;
char str_quotient[10];
char str_remainder[10];

int main()
{
	printf("Ƕ�������ex310\n");
	printf("������һ��ֻ��ʮ������Ȼ�����ַ���x��\n");
	gets(str_x);
	printf("������һ��ֻ��ʮ������Ȼ�����ַ���y��\n");
	gets(str_y);

	_asm{
		LEA ESI, str_x;
		CALL CONVERT_STR_TO_INT;
		MOV num_x, EAX;
		LEA ESI, str_y;
		CALL CONVERT_STR_TO_INT;
		MOV num_y, EAX;

		MOV EAX, num_x;
		MOV EBX, num_y;
		MOV EDX, 0;//������ΪEDX:EAX����32λ����
		DIV EBX;		//�����㣺����EAX��������EDX
		PUSH EDX;		//������ʱ��EDXֵ
		
		LEA EDI, str_quotient;
		CALL CONVERT_INT_TO_STR;	//EAX��Ϊ�̣��˴�ת��Ϊ�ַ���
		
		POP EDX;		//�ָ�������������EDXֵ
		MOV EAX, EDX;
		LEA EDI, str_remainder;
		CALL CONVERT_INT_TO_STR;	//EAX��Ϊ�࣬�˴�ת��Ϊ�ַ���
	}

	printf("���ַ���Ӧ��ʮ��������x = %d  y = %d\n",num_x,num_y);
	printf("x��y ֮�̣�%s\n",str_quotient);
	printf("x��y ֮�ࣺ%s\n",str_remainder);

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


//	�ӳ���������ڱ�ţ���CONVERT_INT_TO_STR
//	���ܣ���EAX�д�ŵ���ֵת��Ϊʮ�����ַ���
//	��ڲ�������1�������ֵ��ͨ�üĴ���EAX
//			��2�����ת����������ַ��ͨ�üĴ���EDI
//	���ڲ�������1��ͨ�üĴ���EDI��ָ����ַ������ֵ
//	����˵������1���˶κ�������ò�Ӱ��ECX,EAX,EDX��ֵ
	_asm{
CONVERT_INT_TO_STR:
		PUSH EBX;
		MOV ECX, 0;		//ECX��Ϊ��ջ��������������ʼ������
		MOV BX, 10;
		
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
		ADD DL, '0';	//��ֵת�ַ�
		MOV [EDI+EBX], DL;	//����Ч�ĵ��ֽڲ������������е��������
		INC EBX;		//��������1
		
		CMP EBX, ECX;
		JE POP_END;
		JMP POP_LOOP;
POP_END:
		MOV [EDI+EBX], 0;	//�ַ������β�벹'\0'
		POP EBX;
		RET;
	}
}