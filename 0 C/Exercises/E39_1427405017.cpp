/********************************
	1427405017
	沈家赟
	E39
	2014-12-4 22:48
*********************************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void Display(int Arr[],int N);												//声明数组显示函数
void Sort(int *p,int n);													//声明数组排序函数

void main()
{
	int x[100],num,k;

	printf("请输入待输入的整型元素个数：\n");								//输入初始数组
	scanf("%d",&num);
	printf("请输入任意个整型元素：\n");
	for(k=0;k<num;k++)
	{
		scanf("%d",&x[k]);
	}
	
	Sort(x,num);															//后排序
	printf("排序后的数组为：\n");
	Display(x,num);
}

void Display(int Arr[],int N)												//定义数组显示函数
{
	int i;

	for(i=0;i<N;i++)
	{
		printf("%8d",Arr[i]);
		if((i+1)%8==0)														//及时换行，格式美观
		{
			printf("\n");
		}
	}
	printf("\n");
}

void Sort(int *p,int n)														//定义数组排序函数
{
	int i;
	int j;
	int t;

	for(i=0;i<n-1;i++)														//冒泡法排序
	{
		for(j=0;j<n-1-i;j++)
		{
			if(*(p+j)>*(p+j+1))												//指针访问数组元素
			{
				t=*(p+j);
				*(p+j)=*(p+j+1);
				*(p+j+1)=t;
			}
		}
	}
}