/***********************
	1427405017
	����S
	E33
	2014-11-20 15:40
***********************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 7

void Create(int Array[],int Num);
void Sort(int Array[],int Num);
void Display(int Array[],int Num);

void main()
{
	int x[N];							//���������

	Create(x,N);						//����������������麯��Create
	printf("���������ʼ����%d������Ϊ��\n",N);
	Display(x,N);						//����������ʾ����Display
	printf("\n");
	
	printf("�������������Ϊ��\n");
	Sort(x,N);							//��������������Sort
	Display(x,N);						//����������ʾ����Display
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

void Sort(int Array[],int Num)			//��������������Sort(ѡ������)
{
	int i;
	int j;
	int temp;

	for(i=0;i<Num;i++)
	{
		for(j=i+1;j<Num;j++)
		{
			if(Array[i]>Array[j])
			{
				temp=Array[i];
				Array[i]=Array[j];
				Array[j]=temp;
			}
		}
	}
}

void Display(int Array[],int Num)		//����������ʾ����Display
{
	int i;
	int count;
	
	count=0;
	for(i=0;i<N;i++)
	{
		printf("%8d",Array[i]);
		count++;
		if(count%5==0)
		{
			printf("\n");
		}
	}
}