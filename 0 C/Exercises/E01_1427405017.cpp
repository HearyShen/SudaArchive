#include <stdio.h>

void main()
{
	int a,b,q,r;//定义a,b的同时，定义q,r，分别作为商和余数

	printf("请输入两个正整数\n");
	scanf("%d%d",&a,&b);
	
	q=a/b;
	r=a%b;

	printf("商为%d\n余数为%d\n",q,r);
}