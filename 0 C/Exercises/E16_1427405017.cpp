/*******************************************
	1427405017
	沈家赟
	E16
	2014-10-29 22:35:00
*******************************************/
#include <stdio.h>
#include <math.h>

void main()
{
	int a,n,p,s,S;	//依次定义待输入的整数a,n,用于表示10的幂的p,每一项的值s,总共的值S
	double i;	//定义循环变量i为浮点变量，用于下面的pow函数
	printf("请输入数字a，和个数n\n");
	scanf("%d%d",&a,&n);

	s=0;
	S=0;

	for(i=1;i<=n;i++)
	{
		p=pow(10.0,(i-1.0));	//pow函数中，底数和指数须为浮点数
		s=s+a*p;	//s是每一个项
		S=S+s;	//S为递加后的和
	}
	printf("Sn的值为%d\n",S);
}