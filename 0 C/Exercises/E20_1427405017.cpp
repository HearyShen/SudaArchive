/***********************
	1427405017
	沈家赟
	E20
	2014-10-30 16:16
************************/

#include <stdio.h>

void main()
{
	int a[100],i,j,flag,count;	//依次定义数组、赋值用i、判断质数用j、质数标记flag、换行变量count

	printf("下面将显示1-100内的质数：\n");
	count=0;
	for(i=1;i<=100;i++)		//外层循环依次给100以内的自然数赋值
	{
		a[i-1]=i;	//数组首项下标是0
		
		flag=1;		//默认其为质数
		if(i==1)	//值为1的情况
		{
			flag=0;
		}
		else if(i==2)	//值为2的情况
		{
		}
		
		else
		{
			for(j=2;j<a[i-1];j++)	//循环判断其它值是否为质数
			{
				if(a[i-1]%j==0)
				{
					flag=0;	//一旦被小于该值的数整除，则不为质数
					break;
				}
			}
		
		}
		
		if(flag==1)		//在循环内将质数输出
		{
			printf("%5d",a[i-1]);
			count++;
			if(count%5==0)	//换行
			{
				printf("\n");
			}
		}
	}
	printf("\n");
}