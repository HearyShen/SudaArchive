/***********************
	1427405017
	沈家赟
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
	int x[N];							//定义空数组

	Create(x,N);						//调用随机数创建数组函数Create
	printf("用随机数初始化的%d项数组为：\n",N);
	Display(x,N);						//调用数组显示函数Display
	printf("\n");
	
	printf("上述数组排序后为：\n");
	Sort(x,N);							//调用数组排序函数Sort
	Display(x,N);						//调用数组显示函数Display
	printf("\n");
}

void Create(int Array[],int Num)		//定义随机数创建数组函数Create
{
	int i;

	srand(time(0));
	for(i=0;i<N;i++)
	{
		Array[i]=rand();
	}
}

void Sort(int Array[],int Num)			//定义数组排序函数Sort(选择法排序)
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

void Display(int Array[],int Num)		//定义数组显示函数Display
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