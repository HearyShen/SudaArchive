/**
	CIP - ex1_3
	Created:	2017.9.19 Tue
	Modified:	2017.9.25 Mon

	1427405017
	����S
*/

#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

void numToFile(const char txtfname[], const char binfname[]);

/*
	main
	��������������
		��10��1~100֮������������д���ı��ļ��Ͷ������ļ�

	���룺��
	�����д�����ݵ��ı��ļ��Ͷ������ļ�
*/
void main()
{
	char txtf[] = "text.txt", binf[] = "bin.dat";

	printf("д�뿪ʼ��\n�ı��ļ���%s\n�������ļ�%s\n", txtf, binf);
	numToFile(txtf, binf);
	printf("д����ɣ�\n");

	puts("\n��������˳�\n");
	getchar();
}


/*
	numToFile
	�����������ı��ļ��Ͷ������ļ�����10��1~100֮������������д���������ļ�

	���룺�����ı��ļ����������ļ����ļ�������·����
	�����д�����ݵ��ı��ļ��Ͷ������ļ�
*/
void numToFile(const char txtfname[], const char binfname[])
{
	FILE *fptxt, *fpbin;
	int randNum, count;

	fptxt = fopen(txtfname, "w");
	if(fptxt == NULL)
	{
		printf("�ļ�%s��ʧ�ܣ�\n", txtfname);
		exit(0);
	}

	fpbin = fopen(binfname, "wb");
	if(fpbin == NULL)
	{
		printf("�ļ�%s��ʧ�ܣ�\n", binfname);
		exit(0);
	}

	for(count=0; count<10; count++)
	{
		randNum = rand()%100+1;	// ����1~100֮�������

		fprintf(fptxt, "%d\n", randNum);
		fwrite(&randNum, sizeof(int), 1, fpbin);
	}

	fclose(fptxt);
	fclose(fpbin);
}

#endif // !_CRT_SECURE_NO_WARNINGS