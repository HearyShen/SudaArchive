/*********************
	1427405017
	沈家赟
	E32
	2014-11-20 15:17
*********************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 7		//宏定义N，便于修改

int Max(int Array[],int Num);		//声明最大值函数
void Create(int Array[],int Num);	//声明随机数初始化数组函数
void Display(int Array[],int Num);	//声明数组显示函数

void main()
{
	int x[N],max;

	printf("用随机数初始化的%d项整形数组为：\n",N);
	Create(x,N);			//调用随机数初始化数组函数Create
	Display(x,N);			//调用数组显示函数Display
	printf("\n");

	max=Max(x,N);			//调用Max函数
	printf("该数组中的最大值为：%d\n",max);
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

void Display(int Array[],int Num)		//定义数组显示函数Display
{
	int i;
	
	for(i=0;i<N;i++)
	{
		printf("%8d",Array[i]);
	}
}

int Max(int Array[],int Num)		//定义Max函数
{
	int i;
	int max;

	max=Array[0];					//假设最大值为Array[0]
	for(i=1;i<Num;i++)
	{
		if(max<Array[i])
		{
			max=Array[i];
		}
	}
	return (max);
}