/********************************
	1427405017
	����S
	E41
	2014-12-8 16:00
*********************************/
#include <stdio.h>
#include <string.h>
#include <math.h>

void Max_Min(char C[],int L,int *Max,int *Min);							//���������С��������

void main()
{
	char c[1000];
	int i,flag,l,max,min;

	flag=1;
	printf("�����������ַ����ɵ�һ���ַ������ַ�������С��5����\n");
	gets(c);
	
	l=strlen(c);
	if(l>=5)															//�ַ�������ʱ
	{
		printf("��������ַ������ȳ�����4������ȷ���ַ�������С��5��\n");
		flag=0;
	}
	else
	{
		for(i=0;i<l;i++)
		{
			if(c[i]<'0'||c[i]>'9')										//�ַ������ȷ��ϵ����� �����ַ�
			{
				printf("��%d���ַ��������ַ��������� ���ַ� ���ɵ��ַ�����\n",i+1);
				flag=0;
			}
		}
	}

	if(flag==1)															//����Ҫ��ʱ
	{
		Max_Min(c,l,&max,&min);											//���������С��������
		printf("��Щ�ַ��ɹ��ɵ��������Ϊ��%d\n��Щ�ַ��ɹ��ɵ���С����Ϊ��%d\n",max,min);
	}
}

void Max_Min(char C[],int L,int *Max,int *Min)							//���������С��������
{
	int temp[4];
	int i;
	int j;
	int t;

	for(i=0;i<L;i++)													//���ַ����黯Ϊ��������
	{
		temp[i]=(int)C[i]+(0-(int)'0');
	}

	for(i=0;i<L-1;i++)													//ð�ݷ�����
	{
		for(j=0;j<L-1-i;j++)
		{
			if(temp[j]>temp[j+1])											
			{
				t=temp[j];
				temp[j]=temp[j+1];
				temp[j+1]=t;
			}
		}
	}

	*Min=0;
	*Max=0;
	for(i=0;i<L;i++)													//ѭ�����������������С����
	{
		*Min=*Min + temp[i]*pow(10.0,L-1-i);
		*Max=*Max + temp[L-1-i]*pow(10.0,L-1-i);
	}
}