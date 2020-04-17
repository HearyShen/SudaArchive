/******************************
	1427405017
	沈家赟
	E36
	2014-12-4 15:31
*******************************/
#include <stdio.h>

void GCD_LCM(int x,int y,int *ptr_GCD,int *ptr_LCM);	//被调函数声明

void main()
{
	int n,m,gcd,lcm;

	printf("请输入两个正整数n,m：\n");
	scanf("%d%d",&n,&m);
	if(n>0&&m>0)
	{
		GCD_LCM(n,m,&gcd,&lcm);							//调用函数
		printf("最大公约数为：%d\n最小公倍数为：%d\n",gcd,lcm);
	}
	else												//不合条件的情况予以提示
	{
		printf("输入的值不符合条件，请查验后重试\n");
	}
	
}

void GCD_LCM(int x,int y,int *ptr_GCD,int *ptr_LCM)		//定义被调函数
{
	int GCD;
	int LCM;

	for(GCD=x;GCD>0;GCD--)
	{
		if(x%GCD==0&&y%GCD==0)
		{
			*ptr_GCD=GCD;								//符合条件，则把最大公约数赋值给形参指针所指对象，即主函数中gcd
			break;										//及时跳出，以防额外循环
		}
	}

	for(LCM=x;LCM<=x*y;LCM++)
	{
		if(LCM%x==0&&LCM%y==0)
		{
			*ptr_LCM=LCM;								//符合条件，则把最小公倍数赋值给形参指针所指对象，即主函数中的lcm
			return;										//及时结束，以防额外循环
		}
	}
}