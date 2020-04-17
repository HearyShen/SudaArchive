/*********************
	1427405017
	����S
	E32
	2014-11-20 15:17
*********************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 7		//�궨��N�������޸�

int Max(int Array[],int Num);		//�������ֵ����
void Create(int Array[],int Num);	//�����������ʼ�����麯��
void Display(int Array[],int Num);	//����������ʾ����

void main()
{
	int x[N],max;

	printf("���������ʼ����%d����������Ϊ��\n",N);
	Create(x,N);			//�����������ʼ�����麯��Create
	Display(x,N);			//����������ʾ����Display
	printf("\n");

	max=Max(x,N);			//����Max����
	printf("�������е����ֵΪ��%d\n",max);
	printf("\n");
}

void Create(int Array[],int Num)		//����������������麯��Create
{
	int i;

	srand(time(0));
	for(i=0;i<N;i++)
	{
		Array[i]=rand();
	}
}

void Display(int Array[],int Num)		//����������ʾ����Display
{
	int i;
	
	for(i=0;i<N;i++)
	{
		printf("%8d",Array[i]);
	}
}

int Max(int Array[],int Num)		//����Max����
{
	int i;
	int max;

	max=Array[0];					//�������ֵΪArray[0]
	for(i=1;i<Num;i++)
	{
		if(max<Array[i])
		{
			max=Array[i];
		}
	}
	return (max);
}