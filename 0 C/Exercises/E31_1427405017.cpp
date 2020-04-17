/******************
	1427405017
	沈家赟
	E31
	2014-11-13 16:55
********************/
#include <stdio.h>

int JudgePrime(int x);			//声明素数判断函数

void main()
{
	int n,count;				//定义整数n，质数计次器count

	printf("1000以内的所有质数显示如下：\n");
	count=0;
	for(n=1;n<=1000;n++)		//循环判断1000内的正整数
	{
		if(JudgePrime(n)==1)	//调用素数判断函数
		{
			printf("%5d",n);
			count++;
			if(count%8==0)
			{
				printf("\n");
			}
		}
	}
	printf("\n");				//功能块结束后隔开一行，使结果显示清晰
}

int JudgePrime(int x)			//定义素数判断函数
{
	int i;
	
	if(x==1)					//1不为素数
	{
		return(0);
	}
	else if(x==2)				//2为素数
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