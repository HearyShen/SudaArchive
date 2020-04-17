#include <stdio.h>
#include <math.h>

void main()
{
	double a,b,c,p,q,delta,x1,x2;
	printf("请依次输入方程的系数a,b,c\n");
	scanf("%lf%lf%lf",&a,&b,&c);

	delta=b*b-4.0*a*c;
	p=-b/(2.0*a);//在主函数中准备好p,便于直接调用

	if(delta<0)//方程无实数解的情况
	{
		q=sqrt(-delta)/(2.0*a);//delta<0时，q需要单独计算
		
		printf("x1=%lf+%lfi	x2=%lf-%lfi",p,q,p,q);//在printf中做出虚数表示形式
	}
	
	else//方程有实数解的情况
	{
		if(delta==0)//两根相等
		{
			printf("x1=x2=%lf",p);
		}
		else//两根不等
		{
			q=sqrt(delta)/(2.0*a);
			
			x1=p+q;
			x2=p-q;
			
			printf("x1=%lf	x2=%lf",x1,x2);
		}
	}
	printf("\n");
}