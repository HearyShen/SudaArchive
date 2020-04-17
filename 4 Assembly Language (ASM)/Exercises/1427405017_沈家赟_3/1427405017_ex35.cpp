/******************
	ex35
	1427405017
	����S
	2015/4/13
******************/
/*************************************************
3.11   ���д����ex35ʵ�����¹��ܣ�
	���û��Ӽ�������һ���ַ�����
	Ȼ�󣬷ֱ�ͳ���ַ����� Ӣ����ĸ�ĸ��������ַ��ĸ�����
	��󣬷ֱ����ͳ�ƽ����

	������ӳ���ʵ��һ��ͳ�ƹ��ܡ�
	������ӳ���ʵ�ְ���ֵת��Ϊ��Ӧʮ���������ַ�����

	(���  ֻ�ܲ����ַ�����ʽ���磺printf(��%s��,����);)
**************************************************/
#include <stdio.h>

#define MAX_LENGTH 100

char str_in[MAX_LENGTH];
char en_count[10];
char num_count[10];

int main()
{
	printf("Ƕ�������ex35\n");
	printf("������һ���ַ�����\n");
	
	gets_s(str_in);

	_asm{
		LEA ESI, str_in;

		CALL COUNT_ALPHABET;		//EAX�д洢ͳ�Ƴ���Ӣ���ַ�����
		LEA EDI, en_count;
		CALL CONVERT_INT_TO_STR;	//��ֵת�ַ������

		CALL COUNT_NUM;				//EAX�д洢ͳ�Ƴ������ַ�����
		LEA EDI, num_count;
		CALL CONVERT_INT_TO_STR;	//��ֵת�ַ������
	}

	printf("Ӣ���ַ����� = %s\n���ַ����� = %s\n",en_count,num_count);
	
	return 0;

//	�ӳ���������ڱ�ţ���COUNT_ALPHABET
//	���ܣ���ESI�����ַ���ַ�������б�����飬ͳ��Ӣ����ĸ�ĸ���
//	��ڲ�������1������ַ������ַ��ͨ�üĴ���ESI
//	���ڲ�������1�����ͳ�ƽ����������Ӣ���ַ���������ͨ�üĴ���EAX
//	����˵������1���˶κ�������ò�Ӱ��ECX��ֵ
	_asm{
COUNT_ALPHABET:
		MOV ECX, 0;		//�������index����
		MOV EAX, 0;		//Ӣ���ַ�����������
LOOP_ALPHA:
		MOV DL, [ESI+ECX];		//����ǰ�ַ���Ԫ������Ĵ�����Ϊ��αȽ��Ż�
		INC ECX;

		CMP DL, 0;
		JE ALPHA_END;	//��'\0'�����������

		CMP DL, 'A';
		JB LOOP_ALPHA;	//�ַ�<'A'
		CMP DL, 'Z';
		JNA INC_ALPHA;	//'A'<=�ַ�<='Z'
		CMP DL, 'a';
		JB LOOP_ALPHA;	//'Z'<�ַ�<'a'
		CMP DL, 'z';
		JNA INC_ALPHA;	//'a'<=�ַ�<='z'
		JMP LOOP_ALPHA;	//'z'<�ַ�
INC_ALPHA:
		INC EAX;
		JMP LOOP_ALPHA;
ALPHA_END:
		RET;
	}


//	�ӳ���������ڱ�ţ���COUNT_NUM
//	���ܣ���ESI�����ַ���ַ�������б�����飬ͳ�����ַ��ĸ���
//	��ڲ�������1������ַ������ַ��ͨ�üĴ���ESI
//	���ڲ�������1�����ͳ�ƽ�������������ַ���������ͨ�üĴ���EAX
//	����˵������1���˶κ�������ò�Ӱ��ECX��ֵ
	_asm{
COUNT_NUM:
		MOV ECX, 0;		//�������index����
		MOV EAX, 0;		//���ַ�����������
LOOP_NUM:
		MOV DL, [ESI+ECX];		//����ǰ�ַ���Ԫ������Ĵ�����Ϊ��αȽ��Ż�
		INC ECX;

		CMP DL, 0;
		JE NUM_END;	//��'\0'�����������
		
		CMP DL, '0';
		JB LOOP_NUM;	//�ַ�<'0'
		CMP DL, '9';
		JNA INC_NUM;	//'0'<�ַ�<'9'
		JMP LOOP_NUM;	//'9'<�ַ�
INC_NUM:
		INC EAX;
		JMP LOOP_NUM;
NUM_END:
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