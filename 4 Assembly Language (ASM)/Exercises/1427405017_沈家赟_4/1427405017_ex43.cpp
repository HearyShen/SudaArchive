/******************
	ex43
	1427405017
	����S
	2015/5/9
******************/
/*************************************************
4.8   ���д����ex43ʵ�����¹��ܣ�
	���û��Ӽ������������ַ���str1��str2��
	Ȼ��ȷ��str1�е��׸�û����str2�г��ֵ��ַ�λ��
	����������֣���λ��Ϊ-1����
	�����ʾ���λ�á�

	��������ַ���ָ���λ����ָ��
**************************************************/
#include <stdio.h>

#define MAX_LEN 50

int main()
{
	char str1[MAX_LEN];
	char str2[MAX_LEN];
	int str1_index=0, str1_len=0, str2_len=0;
	
	printf("Ƕ�������ex43\n");
	printf("������һ���Ϊ%d���ַ���str1��\n",MAX_LEN);
	gets(str1);
	printf("������һ���Ϊ%d���ַ���str2��\n",MAX_LEN);
	gets(str2);

	_asm{
		LEA EDI, str1;
		CALL GET_STR_LEN;
		MOV str1_len, ECX;

		LEA EDI, str2;
		CALL GET_STR_LEN;
		MOV str2_len, ECX;

		LEA ESI, str1;
		LEA EDI, str2;
FIND_NEXT:
		LODSB;					// ��ESI��str1����ȡ��һ�ֽڴ���AL��ESI++
		CMP AL, 0;
		JE ALL_EXISTED;			// ������������ֹͣ����
		MOV ECX, -1;
		REPNE SCASB;			// ��str2��Ѱ��str1��ȡ����Ԫ��
		DEC EDI;
		MOV ECX, EDI;
		LEA EDI, str2;
		SUB ECX, EDI;			// �������str2�бȽϵĳ���ECX
		CMP ECX, str2_len;		// ��str2_len���ȱȽϣ���ECX>str2_len����˵�����ֽ�δ������str2�У����򣬱Ƚ�str1����һ�ֽ�
		JA NOT_EXISTED;
		INC str1_index;
		JNA FIND_NEXT;
ALL_EXISTED:
		MOV str1_index, -1;
NOT_EXISTED:

	}

	printf("str1�е��׸�û����str2�г��ֵ��ַ�λ��(�ַ����±�)Ϊ%d\n",str1_index);

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