/******************
	ex48
	1427405017
	����S
	2015/5/21
******************/
/*************************************************
4.13   ���д����ex48ʵ�����¹��ܣ�
	���û��Ӽ��̷ֱ���������ʮ��������ֵ��
	Ȼ�������ǵĺ���
	��󣬲���ʮ������������ʽ�ֱ���������
	����ú��ʵ��ӳ���

	����������64λ��ʾ
	��������ֻ�ܲ����ַ�����ʽ
**************************************************/
#include <stdio.h>

#define SIZE 9		// 8*8=64λ����1�ֽڽ�����־'\0'

int main()
{
	char in_x[SIZE], in_y[SIZE], out_sub[SIZE], out_add[SIZE];
	int num_x=0, num_y=0;
	
	printf("Ƕ�������ex48\n");
	printf("������ʮ��������x����ĸ��д����λ���貹0����������Ӧ�ַ������ȣ���\n");
	gets(in_x);
	printf("������ʮ��������y����ĸ��д����λ���貹0����������Ӧ�ַ������ȣ���\n");
	gets(in_y);

	_asm{
		LEA ESI, in_x;
		CALL StrToHex;		// ����ASCII�ַ���ת��ֵ�ӳ���StrToHex
		MOV num_x, EDX;
		LEA ESI, in_y;
		CALL StrToHex;		// ����ASCII�ַ���ת��ֵ�ӳ���StrToHex
		MOV num_y, EDX;


		MOV EDX, num_x;
		ADD EDX, num_y;		// add

		LEA EDI, out_add;
		CALL HexToStr;		// ����ʮ������ת��ASCII�ӳ���HexToStr


		MOV EDX, num_x;
		SUB EDX, num_y;		//	sub

		LEA EDI, out_sub;
		CALL HexToStr;		// ����ʮ������ת��ASCII�ӳ���HexToStr
	}

	printf("x+y = %s��ת���ɵ�ASCII�ַ�����\n",out_add);
	printf("x-y = %s��ת���ɵ�ASCII�ַ�����\n",out_sub);

	return 0;

//	�ӳ���������ڱ�ţ���StrToHex
//	���ܣ���һ��ʮ�������ַ���ת���ɶ�Ӧ����ֵ
//	��ڲ�������1�����ʮ�������ַ�����ַ��ͨ�üĴ���ESI
//	���ڲ�������1���洢ת����ֵ�����ͨ�üĴ���EDX
//	����˵������1���˶κ�������ò�Ӱ��ECX,EAX,EDX��ֵ
	_asm{
StrToHex:
		XOR EDX, EDX;
		MOV EDI, ESI;
		CALL GET_STR_LEN;	// ��ڲ���EDI�����ڲ��������ȣ���ECX��
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

/* �ڲ�ѭ��������λ����װ����EDX��Ӧλ�� */
PRE_SHIFT:
		PUSH ECX;
		DEC ECX;		// ѭ����λ����
		CMP ECX, 0;
		JE LOAD_IN;
SHIFT_LEFT:
		SHL EAX, 4;
		LOOP SHIFT_LEFT;
LOAD_IN:
		ADD EDX, EAX;	// �ۼ���EDX
		POP ECX;
/* �ڲ�ѭ������ */

		LOOP BY_BYTE;

		RET;
	}

//	�ӳ���������ڱ�ţ���HexToStr
//	���ܣ���һλʮ��������ת���ɶ�Ӧ�ַ�ASCII����ӳ���HexToStr
//	��ڲ�������1�����ʮ��������ֵ��ͨ�üĴ���EDX
//	���ڲ�������1���洢ת��ASCII������ַ�����ַ��ͨ�üĴ���EDI
//	����˵������1���˶κ�������ò�Ӱ��ECX,EAX��ֵ
	_asm{
HexToStr:
		PUSH EBX;
		PUSH EDX;
		XOR EAX, EAX;
		BSR EAX, EDX;	// EAX�洢λ�ţ�EDX�洢λ��

		SHR EAX, 2;		// ��4
		INC EAX;		// EAX��ʱΪʮ������λ����

		MOV ECX, EAX;	// ECXѭ������������ֵΪʮ������λ�ĸ���EAX
		ADD EDI, EAX;
		MOV BYTE PTR[EDI], 0;	//�ַ���β��0
		DEC EDI;
GET_HEX:
		MOV BL, 00FH;
		AND BL, DL;		// ��ȡ��4λ��BL
		SHR EDX, 4;		// ����4λ��׼����һ��ȡ
		CMP BL, 00AH;
		JB NUM_HTS;
		ADD BL, 55;
		JMP STORE;
NUM_HTS:
		ADD BL, 48;
STORE:
		MOV BYTE PTR[EDI], BL;	// ��ʮ��������ֵ�ĵ�λ����λ�����ַ������飨�ַ����ĸ�λ����λ��
		DEC EDI;

		LOOP GET_HEX;
		
		POP EDX;
		POP EBX;
		RET;
	}

//	�ӳ���������ڱ�ţ���GET_STR_LEN
//	���ܣ���EDI�д�ŵĵ�ַָ����ַ�����������ó��ַ������ȣ�������\0��
//	��ڲ�������1��������������ַ��ͨ�üĴ���EDI
//	���ڲ�������1���洢ת�������int�ͱ���ECX
//	����˵������1���˶κ�������ò�Ӱ��ECX,EAX��ֵ
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
		SUB ECX, EDI;	// ECX�洢str�ĳ���

		RET;
	}
}