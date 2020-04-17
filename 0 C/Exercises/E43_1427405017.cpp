/********************************
	1427405017
	沈家赟
	E43
	2014-12-10 11:52
*********************************/
#include <stdio.h>
#include <string.h>

void delchar(char *p,int k,int n);			//声明字符串删除函数

void main()
{
	char s[1000];
	int k,n,l;

	printf("请输入一个字符串：\n");			//输入各项数据
	gets(s);
	printf("程序将去除字符串从第k个字符开始的n个字符。请分别输入相应的k和n：\n");
	printf("k=");
	scanf("%d",&k);
	printf("n=");
	scanf("%d",&n);

	l=strlen(s);
	if(k>=1 && n>=0 && (k+n-1)<=l)			//判断条件符合
	{
		delchar(s,k,n);						//调用字符串删除函数
		printf("处理完成后的字符串为：\n");		//显示结果
		puts(s);
	}
	else									//判断条件不符合
	{
		printf("您输入的k或n不符合要求！\n k为正整数，n为整数，且删除范围不应越界！\n");
	}
}

void delchar(char *p,int k,int n)			//定义字符串删除函数
{
	int i;
	int l;

	l=strlen(p);
	for(i=k-1;i<l-n;i++)						//删去相应字符，向前紧缩排列
	{
		p[i]=p[i+n];
	}
	p[i]='\0';									//p[l-n]赋值'\0'，此处起结束字符串
}