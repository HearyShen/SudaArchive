/*****************************
	1427405017
	����S
	E37
	2014-12-4 16:21
*****************************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define Num 10

void Create(int Arr[],int N);												//����������麯��
void Display(int Arr[],int N);												//����������ʾ����
void ArrayMath(int Arr[],int N,int *Sum,int *Max,int *Min,double *Ave);		//�������鴦����

void main()
{
	int a[Num],sum,max,min;
	double ave;																//ƽ��ֵΪ������

	Create(a,Num);
	printf("��%d���������Ϊ��\n",Num);
	Display(a,Num);
	ArrayMath(a,Num,&sum,&max,&min,&ave);									//�������鴦����

	printf("����������Ԫ���ܺ�Ϊ��%d\n���ֵΪ��%d\n��СֵΪ��%d\nƽ��ֵΪ��%lf\n",sum,max,min,ave);
}

void Create(int Arr[],int N)												//�����������������
{
	int i;

	srand(time(0));

	for(i=0;i<N;i++)
	{
		Arr[i]=rand();
	}
}

void Display(int Arr[],int N)												//����������ʾ����
{
	int i;

	for(i=0;i<N;i++)
	{
		printf("%8d",Arr[i]);
		if((i+1)%8==0)															//��ʱ���У���ʽ����
		{
			printf("\n");
		}
	}
	printf("\n");
}

void ArrayMath(int Arr[],int N,int *Sum,int *Max,int *Min,double *Ave)			//�������鴦����
{
	int i;

	*Sum=0;
	*Max=Arr[0];																//���ֵĬ��Ϊ����0��Ԫ��
	*Min=Arr[0];																//��СֵĬ��Ϊ����0��Ԫ��
	for(i=0;i<N;i++)
	{
		*Sum=*Sum+Arr[i];														//�ܺ��ۼ�
		if(*Max<Arr[i])
		{
			*Max=Arr[i];														//ѭ���ڱȽ�Ѱ�����ֵ
		}
		if(*Min>Arr[i])
		{
			*Min=Arr[i];														//ѭ���ڱȽ�Ѱ����Сֵ
		}
	}

	*Ave=(double)*Sum/N;														//�󸡵���ƽ��ֵ
}
