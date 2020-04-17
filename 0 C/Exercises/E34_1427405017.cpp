/**************************
	1427405017
	����S
	E34
	2014-11-20 16:52
**************************/
#include <stdio.h>
#include <string.h>
#include <math.h>

int Judge(char c[]);			//���������жϺ���
int Coefficient(char c);		//����ϵ������
int Transform(char c[]);		//�����ַ���ת��������

void main()
{
	char str[50];

	printf("������һ����'0'-'9'��10�����ַ����ɵ��ַ�����\n");
	gets(str);					//�����ַ���

	if(Judge(str)==1)			//��������
	{
		printf("���������Ϊ��%d\n",Transform(str));	//�����ַ���ת������������ʾ
	}
	else						//������������������
	{
		printf("�������ֵ������Ҫ�������Ҫ���������룡\n");
	}
}

int Judge(char c[])				//���������жϺ���
{
	int i;
	
	for(i=0;i<strlen(c);i++)
	{
		if(c[i]<'0'||c[i]>'9')
		{
			return(0);
		}
	}
	return(1);
}

int Coefficient(char c)			//����ϵ������
{
	int z;

	z=(int)c-((int)'1'-1);
	return(z);
}

int Transform(char c[])			//�����ַ���ת��������
{
	double Sum;			//����Ϊdouble������pow����
	int i;
	double n;			//����Ϊdouble������pow����
	
	Sum=0;
	for(i=0;i<strlen(c);i++)
	{
		n=strlen(c)-i-1;
		Sum=Sum + Coefficient(c[i])*pow(10.0,n);
	}
	return((int)Sum);			//�����Ҫ���������������
}