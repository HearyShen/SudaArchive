/******************
	ex32
	1427405017
	����S
	2015/3/29 9:30
******************/
/*************************************************
3.8   ���д����ex32ʵ�����¹��ܣ�
	���û��Ӽ�������һ���ַ�����
	Ȼ�󣬷ֱ�ͳ���ַ�����Ӣ����ĸ�ĸ��������ַ��ĸ�����
	������ͳ�ƽ����
	������ӳ����ж��ַ��Ƿ�ΪӢ����ĸ��
	������ӳ����ж��ַ��Ƿ�Ϊ���ַ���0-9����
**************************************************/
#include <stdio.h>

char str[100];

int main()
{
	int alpha_count = 0;
	int num_count = 0;
	printf("Ƕ�������ex32\n");
	printf("������һ���ַ�����\n");
	gets(str);
	//scanf("%s",&str);

	_asm{
		LEA ESI, str;
		LEA EBX, alpha_count;
		LEA EDX, num_count;
		MOV ECX, 0;
MAIN_LOOP:
		MOV AL, [ESI+ECX*1];
		CMP AL, '\0';
		JE END_LOOP;
		CALL COUNT_ALPHABET;
		CALL COUNT_NUMBER;
		INC ECX;
		JMP MAIN_LOOP;
END_LOOP:

	}

	printf("Ӣ����ĸ������%d\n���ַ�������%d\n",alpha_count,num_count);
	return 0;

	_asm{
COUNT_ALPHABET:	//���Ӣ����ĸ
		CMP AL, 'A';
		JB EXCLUSION;
		CMP AL, 'Z';
		JNA ALPHABET;
		CMP AL, 'z';
		JA EXCLUSION;
		CMP AL, 'a';
		JNB ALPHABET;
		RET;

ALPHABET:				//��鵽Ӣ����ĸ
		INC [EBX];
		RET;

COUNT_NUMBER:		//������ַ�
		CMP AL, '0';
		JB EXCLUSION;
		CMP AL, '9';
		JA EXCLUSION;
		INC [EDX];
		RET;

EXCLUSION:			//�������
		RET;
	}
}