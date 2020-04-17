/*****************************
	1427405017
	沈家赟
	E38
	2014-12-4 18:36
*****************************/
#include <stdio.h>
#include <math.h>

void Binary(int x,int Arr[],int *Bit);		//声明十进制转二进制函数

void main()
{
	int input,a[100],bit,i;					//定义输入整数，二进制存放数组，二进制所占位数，循环变量i

	printf("请输入一个正整数：\n");
	scanf("%d",&input);
	
	if(input>0)
	{
		Binary(input,a,&bit);					//定义十进制转二进制函数
	
		printf("该整数的二进制形式为：\n");
		for(i=bit;i>=0;i--)
		{
			printf("%d",a[i]);
		}
		printf("\n");
	}
	else
	{
		printf("输入值不符合条件，请查验后重试\n");
	}
}

void Binary(int x,int Arr[],int *Bit)		//定义十进制转二进制函数Binary
{
	int i;
	int n;
	int temp;

	for(i=0;pow(2.0,i)<=x;i++)				//求比x小的最大2的幂的指数，pow函数可使用(double,int)形式
	{
	}
	n=i-1;
	*Bit=n;

	for(i=n;i>=0;i--)
	{
		temp=pow(2.0,i);					//pow函数可使用(double,int)形式
		if(x>=temp)							//填1的情况
		{
			Arr[i]=1;
			x=x-temp;
		}
		else								//填0的情况
		{
			Arr[i]=0;
		}
	}
}

