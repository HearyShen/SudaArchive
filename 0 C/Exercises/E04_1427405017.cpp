#include <stdio.h>

void main()
{
	int r,a,b,c,s;//a,b,c分别为该三位数的百位，十位，个位，s为需要求的三数之和

	printf("请输入一个3位正整数\n");
	scanf("%d",&r);

	c=r%10;//原数据除以10取余数，得到个位数
	b=((r-c)%100)/10;//原数据减去个位数后，除以100取余数，再除以10，得到十位数
	a=(r-b-c)/100;//原数据减去十位数和个位数，再除100，得到百位数

	s=a+b+c;

	printf("该3位正整数的3个数字的和为%d\n",s);
}