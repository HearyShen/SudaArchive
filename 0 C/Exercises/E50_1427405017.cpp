/**************************
	1427405017
	沈家赟
	E50
	2015-1-9 19:34
***************************/
#include <stdio.h>
#include <stdlib.h>

void Conj(FILE *fp1,FILE *fp2);				//声明文件连接函数Conj

void main()
{
	FILE *fp1,*fp2;

	fp1 = fopen("1.txt","a");				//打开第一个文件
	if(fp1 == NULL)
	{
		printf("打开第一个文件出错！\n");
		exit(0);
	}

	fp2 = fopen("2.txt","r");				//打开第二个文件
	if(fp2 == NULL)
	{
		printf("打开第二个文件出错！\n");
		exit(0);
	}

	Conj(fp1,fp2);							//调用文件连接函数Conj
	printf("文件内容连接结束\n");
}

void Conj(FILE *fp1,FILE *fp2)				//定义文件连接函数Conj
{
	char ch;

	while(1)		//查阅资料得知，当feof读到EOF标志并不认为文件结束了，依旧返回0，直到读到EOF的下一个字符才返回1，这时才认为是文件结束。（类似字符数组的\0），复制文件时会产生多余的一个EOF，故不采用feof
	{
		ch = fgetc(fp2);
		if(ch != EOF)						//直接用fgetc得到的实时字符进行结束判断
		{
			fputc(ch,fp1);
		}
		else								//一旦读到EOF,则结束Conj函数
		{
			return;
		}
	}
}