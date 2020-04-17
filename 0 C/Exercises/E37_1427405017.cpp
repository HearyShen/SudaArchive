/*****************************
	1427405017
	沈家赟
	E37
	2014-12-4 16:21
*****************************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define Num 10

void Create(int Arr[],int N);												//声明随机数组函数
void Display(int Arr[],int N);												//声明数组显示函数
void ArrayMath(int Arr[],int N,int *Sum,int *Max,int *Min,double *Ave);		//声明数组处理函数

void main()
{
	int a[Num],sum,max,min;
	double ave;																//平均值为浮点数

	Create(a,Num);
	printf("该%d项随机数组为：\n",Num);
	Display(a,Num);
	ArrayMath(a,Num,&sum,&max,&min,&ave);									//调用数组处理函数

	printf("数组中所有元素总和为：%d\n最大值为：%d\n最小值为：%d\n平均值为：%lf\n",sum,max,min,ave);
}

void Create(int Arr[],int N)												//定义随机数创建函数
{
	int i;

	srand(time(0));

	for(i=0;i<N;i++)
	{
		Arr[i]=rand();
	}
}

void Display(int Arr[],int N)												//定义数组显示函数
{
	int i;

	for(i=0;i<N;i++)
	{
		printf("%8d",Arr[i]);
		if((i+1)%8==0)															//及时换行，格式美观
		{
			printf("\n");
		}
	}
	printf("\n");
}

void ArrayMath(int Arr[],int N,int *Sum,int *Max,int *Min,double *Ave)			//定义数组处理函数
{
	int i;

	*Sum=0;
	*Max=Arr[0];																//最大值默认为数组0号元素
	*Min=Arr[0];																//最小值默认为数组0号元素
	for(i=0;i<N;i++)
	{
		*Sum=*Sum+Arr[i];														//总和累加
		if(*Max<Arr[i])
		{
			*Max=Arr[i];														//循环内比较寻找最大值
		}
		if(*Min>Arr[i])
		{
			*Min=Arr[i];														//循环内比较寻找最小值
		}
	}

	*Ave=(double)*Sum/N;														//求浮点型平均值
}
