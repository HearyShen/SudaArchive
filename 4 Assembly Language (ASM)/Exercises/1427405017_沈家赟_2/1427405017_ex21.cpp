/*********************
	ex21
	1427405017
	����S
	2016/3/15 8:15
*********************/
/********************************************************
2.4  ���д����ex21ʵ�����¹��ܣ�
	���û��Ӽ�������4���ֽ����ݣ�8λ���������ݣ��ַ��ͣ���
	����4���ֽ�������Ϊ�޷��������ֱ�ƴ�ӳ�2�������ݣ�
	��ƴ�ӳ�1��˫�����ݣ�
	��ʾ�����2�������ݺ�1��˫�����ݡ�
*********************************************************/
#include <stdio.h>

void main()
{
	char input[4];
	unsigned short word1, word2;
	unsigned int dword1;

	printf("�������ĸ��ַ���\n");
	scanf("%c %c %c %c",&input[0],&input[1],&input[2],&input[3]);

	printf("0x%02X 0x%02X 0x%02X 0x%02X\n",input[0],input[1],input[2],input[3]);

	_asm
	{
		LEA ESI, input;
		MOV AX, WORD PTR [ESI];
		MOV BX, WORD PTR [ESI+2];
		MOV ECX, DWORD PTR [ESI];
		MOV word1, AX;
		MOV word2, BX;
		MOV dword1, ECX;
	}
	printf("word1:0x%02x\n",word1);
	printf("word2:0x%02x\n",word2);
	printf("dword:0x%02x\n",dword1);
}