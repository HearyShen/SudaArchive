/**************************
	1427405017
	沈家赟
	E34
	2014-11-20 16:52
**************************/
#include <stdio.h>
#include <string.h>
#include <math.h>

int Judge(char c[]);			//声明条件判断函数
int Coefficient(char c);		//声明系数函数
int Transform(char c[]);		//声明字符串转整数函数

void main()
{
	char str[50];

	printf("请输入一个由'0'-'9'这10个数字符构成的字符串：\n");
	gets(str);					//输入字符串

	if(Judge(str)==1)			//符合条件
	{
		printf("输出的整数为：%d\n",Transform(str));	//调用字符串转整数函数以显示
	}
	else						//不符合条件，则提醒
	{
		printf("您输入的值不符合要求，请查验要求，重新输入！\n");
	}
}

int Judge(char c[])				//定义条件判断函数
{
	int i;
	
	for(i=0;i<strlen(c);i++)
	{
		if(c[i]<'0'||c[i]>'9')
		{
			return(0);
		}
	}
	return(1);
}

int Coefficient(char c)			//定义系数函数
{
	int z;

	z=(int)c-((int)'1'-1);
	return(z);
}

int Transform(char c[])			//定义字符串转整数函数
{
	double Sum;			//定义为double，用于pow函数
	int i;
	double n;			//定义为double，用于pow函数
	
	Sum=0;
	for(i=0;i<strlen(c);i++)
	{
		n=strlen(c)-i-1;
		Sum=Sum + Coefficient(c[i])*pow(10.0,n);
	}
	return((int)Sum);			//结果按要求以整数类型输出
}