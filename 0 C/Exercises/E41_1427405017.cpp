/********************************
	1427405017
	沈家赟
	E41
	2014-12-8 16:00
*********************************/
#include <stdio.h>
#include <string.h>
#include <math.h>

void Max_Min(char C[],int L,int *Max,int *Min);							//声明最大最小整数函数

void main()
{
	char c[1000];
	int i,flag,l,max,min;

	flag=1;
	printf("请输入由数字符构成的一个字符串（字符串长度小于5）：\n");
	gets(c);
	
	l=strlen(c);
	if(l>=5)															//字符串超长时
	{
		printf("你输入的字符串长度超过了4个！请确保字符串长度小于5。\n");
		flag=0;
	}
	else
	{
		for(i=0;i<l;i++)
		{
			if(c[i]<'0'||c[i]>'9')										//字符串长度符合但出现 非数字符
			{
				printf("第%d个字符不是数字符！请输入 数字符 构成的字符串！\n",i+1);
				flag=0;
			}
		}
	}

	if(flag==1)															//满足要求时
	{
		Max_Min(c,l,&max,&min);											//调用最大最小整数函数
		printf("这些字符可构成的最大整数为：%d\n这些字符可构成的最小整数为：%d\n",max,min);
	}
}

void Max_Min(char C[],int L,int *Max,int *Min)							//定义最大最小整数函数
{
	int temp[4];
	int i;
	int j;
	int t;

	for(i=0;i<L;i++)													//把字符数组化为整型数组
	{
		temp[i]=(int)C[i]+(0-(int)'0');
	}

	for(i=0;i<L-1;i++)													//冒泡法排序
	{
		for(j=0;j<L-1-i;j++)
		{
			if(temp[j]>temp[j+1])											
			{
				t=temp[j];
				temp[j]=temp[j+1];
				temp[j+1]=t;
			}
		}
	}

	*Min=0;
	*Max=0;
	for(i=0;i<L;i++)													//循环计算最大整数、最小整数
	{
		*Min=*Min + temp[i]*pow(10.0,L-1-i);
		*Max=*Max + temp[L-1-i]*pow(10.0,L-1-i);
	}
}