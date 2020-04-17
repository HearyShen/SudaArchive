/*********************
	ex24
	1427405017
	����S
	2016/3/17 19:00
*********************/
/********************************************************
2.7   ������һ���޷����ַ��ͣ��ֽڡ�8λ�����飬�����20�����ݡ�
	�����2���������ֽ���������Ϊ1��16λ���ݣ���ô����10�������ݣ�
	�����4���������ֽ���������Ϊ1��32λ���ݣ���ô����5��˫�����ݡ�
	���д����ex24ʵ�����¹��ܣ�
		����Щ������Ϊ10��16λ������ͳ�������ĸ�����
		����Щ������Ϊ5��32λ������ͳ�Ƹ����ĸ�����
		��ʾ���ͳ�ƽ����

	˵���������ڶ�������ʱ��ʼ������20�����ݣ�
		Ҳ����ͨ�������������������������
*********************************************************/
#include <stdio.h>
#include <stdlib.h>

void main()
{
	char arr[20];
	int positive_in_16bit = 0, negative_in_32bit = 0;

	for(int i=0;i<20;i++)
	{
		arr[i] = rand()%256;		//initialize
		printf("%d 0x%02X \n",arr[i],arr[i]);
	}
	printf("\n");

	_asm
	{
		LEA ESI, arr;
		MOV ECX, 10;	//��ѭ��������ECX
		MOV EAX, 0;		//index
		LEA EDI, positive_in_16bit;
		MOV [EDI], 0;
MAIN_LOOP1:
		CMP WORD PTR[ESI+EAX*2], 0;
		JG POSITIVE;
		JMP ELSE1;
POSITIVE:
		INC EAX;		//index++
		INC [EDI];		//����������++
		DEC ECX;		//��ѭ��������--
		JNZ MAIN_LOOP1;
		JZ OVER1;
ELSE1:
		INC EAX;		//index++
		DEC ECX;		//��ѭ��������--
		JNZ MAIN_LOOP1;
		JZ OVER1;
OVER1:
	}
	printf("16λ�����У���������Ϊ��%d\n",positive_in_16bit);

	_asm
	{
		LEA ESI, arr;
		MOV ECX, 5;		//��ѭ��������
		MOV EAX, 0;		//index
		LEA EDI, negative_in_32bit;
		MOV [EDI], 0;
MAIN_LOOP2:
		CMP DWORD PTR[EDI+EAX*4], 0;
		JL NEGATIVE;
		JMP ELSE2;
NEGATIVE:
		INC EAX;		//index++
		INC [EDI];		//����������++
		DEC ECX;		//��ѭ��������--
		JNZ MAIN_LOOP2;
		JZ OVER2;
ELSE2:
		INC EAX;		//index++
		DEC ECX;		//��ѭ��������--
		JNZ MAIN_LOOP2;
		JZ OVER2;
OVER2:
	}
	printf("32λ�����У���������Ϊ��%d\n",negative_in_32bit);
}