/******************
	ex44
	1427405017
	����S
	2015/5/9
******************/
/*************************************************
4.9   ���������ַ�������ָ���д����ex44ʵ�����¹��ܣ�
	���û��Ӽ�������һ���ַ�����
	Ȼ�󣬹��˵����п��ܳ��ֵı����ţ�
	�����ʾ������˺���ַ�����

	�������м�����Щ������
**************************************************/
#include <stdio.h>

#define MAX_LEN 50

int main()
{
	char str1[MAX_LEN];
	char str2[] = ",��.��!��?��;��:��'����\"����()����[]����{}<>������";	// �Զ���ı����Ų�������
	int str1_index=0, str1_len=0, str2_len=0;
	
	printf("Ƕ�������ex44\n�����򽫹����ַ����еı�����\n");
	printf("������һ���Ϊ%d���ַ���str1��\n",MAX_LEN);
	gets(str1);

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
		LODSB;					// ��ESI��ȡ��һ�ֽڴ���AL��ESI++
		CMP AL, 0;
		JE OVER;				// ������������ֹͣ����
		MOV ECX, -1;
		REPNE SCASB;
		DEC EDI;
		MOV ECX, EDI;
		LEA EDI, str2;
		SUB ECX, EDI;			// �������str2�бȽϵĳ���ECX
		CMP ECX, str2_len;		// ��str2_len���ȱȽϣ���ECX>str2_len����˵�����ֽ�δ������str2�У��������ƴ˺���ַ�����ȥ���ñ�����
		JA NOT_EXISTED;
		JNA REMOVE_BYTE;
REMOVE_BYTE:
		MOV ECX, str1_len;
		SUB ECX, str1_index;
		INC ECX;				// ������Ҫ�ƶ��ֽڸ���������ΪLOOP������ECX
		XOR EAX, EAX;
	MOVE_LEFT:
		MOV DL, BYTE PTR[ESI+EAX];
		MOV BYTE PTR[ESI+EAX-1], DL;
		INC EAX;
		LOOP MOVE_LEFT;
		DEC ESI;
		JMP FIND_NEXT;
NOT_EXISTED:
		INC str1_index;
		JMP FIND_NEXT;
OVER:

	}

	printf("���˱����ź���ַ���Ϊ��%s\n",str1);

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