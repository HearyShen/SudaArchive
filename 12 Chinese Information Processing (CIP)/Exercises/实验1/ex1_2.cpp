/**
	CIP - ex1_2
	Created:	2017.9.19 Tue
	Modified:	2017.9.25 Mon

	1427405017
	����S
*/

#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

#define SIZE 20

void displayStrInDec(const char chs[]);


/*
	main
	������������
		ʵ�ֺ�����λ��Ĳ鿴����

	���룺��׼���룬�������뺺���ַ����ַ���
	�������׼���������̨��ʾ��λ����ֵ
*/
void main()
{
	char chs[SIZE];

	while(true)
	{
		printf("�����뺺�ֻ��ַ���\n");
		scanf("%s", chs);

		printf("��Ӧ��ʮ���Ʊ��룺\n");
		displayStrInDec(chs);

		printf("\n\n");
	}
}


/*
	displayStrInDec
	��������ʾ�ַ������ֽڵĺ�����λ�루ʮ������ֵ��

	���룺�ַ��������飩��ַ
	���������̨��ʾ���ʮ������λ����ֵ
*/
void displayStrInDec(const char chs[])
{
	int i;

	for (i = 0; i < strlen(chs); i++)
	{
		printf("%4d", unsigned char(chs[i] - 0xA0));
	}
	printf("\n");
}

#endif