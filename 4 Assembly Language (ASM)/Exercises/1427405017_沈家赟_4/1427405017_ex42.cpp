/******************
	ex42
	1427405017
	����S
	2015/5/8
******************/
/*************************************************
4.7   ���д����ex42ʵ�����¹��ܣ�
	���û��Ӽ������������ַ���str1��str2��
	Ȼ��ȷ��str2��str1�г��ֵ���ʼλ��
	����������֣�����ʼλ����-1����
	�����ʾ�����ʼλ�á�

	��������ַ���ָ����ظ�ǰ׺
**************************************************/
#include <stdio.h>

#define MAX_LEN 50

int main()
{
	char str1[MAX_LEN];
	char str2[MAX_LEN];
	int index=0, str1_len=0, str2_len=0;
	
	printf("Ƕ�������ex42\n");
	printf("������һ���Ϊ%d���ַ���str1��\n",MAX_LEN);
	gets(str1);
	printf("������һ���Ϊ%d���ַ���str2��\n",MAX_LEN);
	gets(str2);

	_asm{

		LEA EDI, str2;
		CALL GET_STR_LEN;
		MOV str2_len, ECX;

		LEA EDI, str1;
		CALL GET_STR_LEN;
		MOV str1_len, ECX;

		LEA EDI, str1;
FIND_START:
		LEA ESI, str2;
		LODSB;			// BYTE PTR[ESI] -> AL���˴���ı�ESI��ESI++����
		DEC ESI;
		MOV ECX, -1;
		REPNE SCASB;	// CMP AL, BYTE PTR[EDI], EDI++��Ѱ�ҿ��ܵ���ʼ��ַ
		DEC EDI;
		PUSH EDI;		//������ܵ���ʼλ��EDI

	/*�ж�str2��str1���Ƿ�Խ��*/
		ADD EDI, str2_len;
		LEA EBX, str1;
		ADD EBX, str1_len;
		CMP EDI, EBX;
		JA NO_RESULT; 

		POP EDI;
		PUSH EDI;
		//INC EDI;
		MOV ECX, str2_len;
		INC ECX;		//�Ƚϳ���Ϊstr2_lenʱ��ʵ�ʻ�Ƚϵ�str2_len + 1��
		REPE CMPSB;		//�ַ������ֽڱȽ�
		CMP ECX, 0;		//�������Ƚ�����str2����str2��str1�г���
		POP EDI;		//������û�ҵ�������Ҫ�ָ���ʼλ��EDI��1���ҵ�������EDI��ƫ���� 2��û�ҵ�������EDI����һ�β��ҿ�ʼλ��
		JNE NOT_GET;	//����str2�������ڵ�ǰ��ʼ��ַ��

		LEA EAX, str1;
		SUB EDI, EAX;
		MOV index, EDI;
		JMP OVER;
NOT_GET:
		INC EDI;		//���ϴε���ʼλ�õ���һ���ֽڿ�ʼ������Ѱ����ʼλ��
		JMP FIND_START;
NO_RESULT:
		POP EDI;
		MOV index, -1;
OVER:

	}

	printf("str2��str1�е���ʼλ��Ϊ%d\n",index);
	printf("str1_len = %d\nstr2_len = %d\n",str1_len, str2_len);

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