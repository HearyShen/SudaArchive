/******************
	ex33
	1427405017
	����S
	2015/3/29 
******************/
/*************************************************
3.9   ���д����ex33ʵ�����¹��ܣ�
	���û��Ӽ�������һ���ַ�����
	Ȼ��ɾ���ַ����е����з�Ӣ����ĸ�ͷ�10�������ַ����γ��µ��ַ�����
	�������µ��ַ�����
**************************************************/
#include <stdio.h>

#define MAX_LENGTH 100

char str_in[MAX_LENGTH];
char str_out[MAX_LENGTH];

int main()
{
	printf("Ƕ�������ex33\n");
	printf("������һ���ַ�����\n");
	
	gets(str_in);

	_asm{
		LEA ESI, str_in;
		MOV ECX, 0;			//���������±������
		LEA EDI, str_out;
		MOV EDX, 0;			//��������±������
MAIN_LOOP:
		MOV AL, [ESI+ECX*1];
		CMP AL, '\0';
		JE END_LOOP;
		//PUSH AL;			//�ַ���ֵ��ջ
		CALL DELETE_ELEMENT;

		//MOV [ESI+ECX*1], AL;
		INC ECX;
		JMP MAIN_LOOP;

DELETE_ELEMENT:
		PUSH EBP;
		MOV EBP, ESP;		//������ջ���

		CMP AL, '0';
		JB RET_CALL;
		CMP AL, '9';
		JNA MOV_OUT;	//��������������ת��MOV_OUTд��

		CMP AL,'A';
		JB RET_CALL;
		CMP AL,'Z';
		JNA MOV_OUT;	//��������������ת��MOV_OUTд��

		CMP AL,'a';
		JB RET_CALL;
		CMP AL,'z';
		JNA MOV_OUT		//��������������ת��MOV_OUTд��
		JA RET_CALL;	//���һ���жϣ������������������ִ�е�MOV_OUT�θ���д�����

	MOV_OUT:
		MOV [EDI+EDX*1], AL;	//������������±꣬д����ֵ
		INC EDX;

	RET_CALL:				//������ջ���
		POP EBP;
		RET;

END_LOOP:

	}
	printf("�µ��ַ�����ɾȥ��Ӣ����ĸ��10�������ַ�����\n%s\n",str_out);

	return 0;

}