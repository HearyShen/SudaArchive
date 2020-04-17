/********************************
	1427405017
	沈家赟
	E42
	2014-12-10 11:09
*********************************/
#include <stdio.h>
#include <string.h>

void JudgeReverse(char C[],char Judge[]);				//声明回文判断函数

void main()
{
	char c[1000],judge[100];

	printf("请输入一个字符串：\n 1.若字符为回文，则显示TRUE，否则显示FALSE\n 2.英文字符不区分大小写\n");
	gets(c);

	JudgeReverse(c,judge);								//调用回文判断函数
	puts(judge);
}

void JudgeReverse(char C[],char Judge[])				//定义回文判断函数
{
	int i;
	int j;
	int l;
	int mid;

	l=strlen(C);
	//printf("l=%d\n",l);
	for(i=0;i<l;i++)										//在判断前先处理好字符串
	{
		if(C[i]>='A'&&C[i]<='Z')								//大写转小写
		{
			C[i]=C[i]-('A'-'a');
		}
		else if(C[i]>='a'&&C[i]<='z')							//小写跳过
		{
			continue;
		}
		else													//其他字符一概去除
		{
			for(j=i;j<l-1;j++)
			{
				C[j]=C[j+1];
			}
			i--;													//“原地踏步”
			C[l-1]='\0';											
			l--;													//去除后字符数组长度减1
		}
	}
	//puts(C);
	
	if(l>=1)												//实际字符不少于2个，符合比较条件
	{
		mid=(int)(l/2);
	
		for(i=0;i<mid;i++)
		{
			if(C[i] != C[l-1-i])								//一旦不等，则必不为回文
			{
				strcpy(Judge,"FALSE");
				return;
			}
		}
		strcpy(Judge,"TRUE");
	}
	else													//实际字符不足2个，不符合回文条件
	{
		strcpy(Judge,"FALSE");
	}
}