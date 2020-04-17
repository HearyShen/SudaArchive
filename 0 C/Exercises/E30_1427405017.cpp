/******************
	1427405017
	沈家赟
	E30
	2014-11-13 16:39
*******************/
#include <stdio.h>

int GCD(int x,int y);			//GCD = Greatest Common Divisor	(最大公约数)
int LCM(int x,int y);			//LCM = Least Common Multiple	(最小公倍数)

void main()
{
	int a,b;
	
	printf("请输入两个整数：\n");
	scanf("%d%d",&a,&b);

	printf("这两个整数的最大公约数为%d\n",GCD(a,b));	//调用最大公约数函数
	printf("这两个整数的最小公倍数为%d\n",LCM(a,b));	//调用最小公倍数函数
}

int GCD(int x,int y)			//定义求最大公约数的函数
{
	int z;

	z=x;
	for(;z>0;z--)
	{
		if(x%z==0&&y%z==0)
		{
			return(z);
		}
	}
}

int LCM(int x,int y)			//定义求最小公倍数的函数
{
	int z;

	z=y;
	for(;z<=x*y;z++)
	{
		if(z%x==0&&z%y==0)
		{
			return(z);
		}
	}
}