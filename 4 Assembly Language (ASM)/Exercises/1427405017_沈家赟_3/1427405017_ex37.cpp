/******************
	ex37
	1427405017
	����S
	2015/4/15
******************/
/*************************************************
3.13   ���д����ex37ʵ�����¹��ܣ�
	���û��Ӽ�������һ��ʮ��������ֵ����
	Ȼ�󣬰Ѹ�����ֵ��ת���ɶ�Ӧʮ�����������ַ�����
	�������ַ�����
	������ӳ���ʵ�ְ�һ����ֵת��Ϊ��Ӧ��ʮ���������ַ�����

	(���  ֻ�ܲ����ַ�����ʽ���磺printf(��%s��,����);)
**************************************************/
#include <stdio.h>

int num_in;
char str_hex[10];

int main()
{
	printf("Ƕ�������ex37\n");
	printf("������һ��ʮ������ֵ��\n");
	
	scanf("%d",&num_in);

	_asm{
		LEA EDI, str_hex;
		MOV EAX, num_in;
		CALL CONVERT_INT_TO_HEX;
	}

	printf("���ַ���Ӧ��ʮ���������ַ��� %s\n",str_hex);
	
	return 0;

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