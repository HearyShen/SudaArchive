/******************
	1427405017
	����S
	E31
	2014-11-13 16:55
********************/
#include <stdio.h>

int JudgePrime(int x);			//���������жϺ���

void main()
{
	int n,count;				//��������n�������ƴ���count

	printf("1000���ڵ�����������ʾ���£�\n");
	count=0;
	for(n=1;n<=1000;n++)		//ѭ���ж�1000�ڵ�������
	{
		if(JudgePrime(n)==1)	//���������жϺ���
		{
			printf("%5d",n);
			count++;
			if(count%8==0)
			{
				printf("\n");
			}
		}
	}
	printf("\n");				//���ܿ���������һ�У�ʹ�����ʾ����
}

int JudgePrime(int x)			//���������жϺ���
{
	int i;
	
	if(x==1)					//1��Ϊ����
	{
		return(0);
	}
	else if(x==2)				//2Ϊ����
	{
		return(1);
	}
	else
	{
		for(i=2;i<x;i++)
		{
			if(x%i==0)
			{
				return(0);
			}
		}
		return(1);
	}
}