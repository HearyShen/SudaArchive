#include <stdio.h>

void main()
{
	int a,b,c,min,med,max;//依次定义三个待输入整数，以及最小值，中间值，最大值
	printf("请依次输入任意三个整数a b c\n");
	scanf("%d%d%d",&a,&b,&c);

	if(a<b)//先判断两个数的大小关系
	{
		if(c<a)//再加入第三个数进行比较
		{
			min=c;
			med=a;
			max=b;
		}
		else if(c>b)
		{
			min=a;
			med=b;
			max=c;
		}
		else
		{
			min=a;
			med=c;
			max=b;
		}
	}
	else
	{
		if(c<b)
		{
			min=c;
			med=b;
			max=a;
		}
		else if(c>a)
		{
			min=b;
			med=a;
			max=c;
		}
		else
		{
			min=b;
			med=c;
			max=a;
		}
	}

	printf("三个整数从小到大依次为%d %d %d\n",min,med,max);
}