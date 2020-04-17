#include <stdio.h>

void main()
{
	int a,b,c,sum,max,min;
	double ave;//平均值不一定为整数
	
	printf("请输入三个整数\n");
	scanf("%d%d%d",&a,&b,&c);

	ave=(a+b+c)/3.0;//除数需用3.0
	sum=a+b+c;

	if(a>b)//先比较a和b，得出最大值、最小值
	{
		max=a;
		min=b;
	}
	else 
	{
		max=b;
		min=a;
	}
	
	if(max<c)//再和c比较，得出最终的最大值、最小值
	{
		max=c;
	}
	if(min>c)
	{
		min=c;
	}
	
	printf("Ave=%f\nSum=%d\nMax=%d\nMin=%d\n",ave,sum,max,min);
}