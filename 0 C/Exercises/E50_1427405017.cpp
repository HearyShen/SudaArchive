/**************************
	1427405017
	����S
	E50
	2015-1-9 19:34
***************************/
#include <stdio.h>
#include <stdlib.h>

void Conj(FILE *fp1,FILE *fp2);				//�����ļ����Ӻ���Conj

void main()
{
	FILE *fp1,*fp2;

	fp1 = fopen("1.txt","a");				//�򿪵�һ���ļ�
	if(fp1 == NULL)
	{
		printf("�򿪵�һ���ļ�����\n");
		exit(0);
	}

	fp2 = fopen("2.txt","r");				//�򿪵ڶ����ļ�
	if(fp2 == NULL)
	{
		printf("�򿪵ڶ����ļ�����\n");
		exit(0);
	}

	Conj(fp1,fp2);							//�����ļ����Ӻ���Conj
	printf("�ļ��������ӽ���\n");
}

void Conj(FILE *fp1,FILE *fp2)				//�����ļ����Ӻ���Conj
{
	char ch;

	while(1)		//�������ϵ�֪����feof����EOF��־������Ϊ�ļ������ˣ����ɷ���0��ֱ������EOF����һ���ַ��ŷ���1����ʱ����Ϊ���ļ��������������ַ������\0���������ļ�ʱ����������һ��EOF���ʲ�����feof
	{
		ch = fgetc(fp2);
		if(ch != EOF)						//ֱ����fgetc�õ���ʵʱ�ַ����н����ж�
		{
			fputc(ch,fp1);
		}
		else								//һ������EOF,�����Conj����
		{
			return;
		}
	}
}