/******************
	ex45
	1427405017
	����S
	2015/5/10
******************/
/*************************************************
4.10   ���������ַ�������ָ����ظ�ǰ׺��д����ex45ʵ�����¹��ܣ�
	���û��Ӽ������������ַ�����
	Ȼ�󣬰������ַ����ϲ���һ��
	�����ʾ����ϲ�����ַ�����
	������ӳ���ʵ�������ַ����ĺϲ���
**************************************************/
#include <stdio.h>

#define MAX_LEN 50

int main()
{
	char str1[MAX_LEN];
	char str2[MAX_LEN];
	char str_out[2*MAX_LEN];
	int str1_index=0, str1_len=0, str2_len=0;
	
	printf("Ƕ�������ex45\n");
	printf("������һ���Ϊ%d���ַ���str1��\n",MAX_LEN);
	gets(str1);
	printf("������һ���Ϊ%d���ַ���str2��\n",MAX_LEN);
	gets(str2);

	_asm{
		LEA EDI, str1;
		CALL GET_STR_LEN;		// ��str2����
		MOV str1_len, ECX;

		LEA EDI, str2;
		CALL GET_STR_LEN;		// ��str2����
		MOV str2_len, ECX;

		LEA EDI, str_out;
		LEA ESI, str1;
		MOV ECX, str1_len;
		REP MOVSB;				// �ƶ�str1

		LEA ESI, str2;
		MOV ECX, str2_len;
		REP MOVSB;				// �ƶ�str1
		MOV BYTE PTR[EDI], 0;	//	��\0
OVER:

	}

	printf("�ϲ�����ַ���Ϊ��%s\n",str_out);

	return 0;

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