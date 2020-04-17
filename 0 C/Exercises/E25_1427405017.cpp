/**********************
	1427405017
	沈家赟
	E25
	2014-11-10 11:23
**********************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 5		//宏定义常量N

void main()
{
	int i,j,S,s;		//定义 行标i,列标j,正对角线之和S,负对角线之和s
	int x[N][N];		//定义数组

	srand(time(0));		//随机数根因时而变

	printf("下面是用随机数定义的一个%d*%d的矩阵：\n",N,N);
	for(i=0;i<N;i++)			//外层循环行
	{
		for(j=0;j<N;j++)		//内层循环列
		{
			x[i][j]=rand();		//用随机数输入数组
			printf("%d  ",x[i][j]);			//循环输入数组的同时，显示数组
		}
		printf("\n");			//换行
	}
	printf("\n");				//每个语句块后换行，使程序显示清晰
	
	S=0;
	for(i=0;i<N;i++)			//计算正对角线之和
	{
		S=S+x[i][i];
	}

	s=0;
	for(i=0;i<N;i++)			//计算负对角线之和
	{
		j=N-1-i;
		s=s+x[i][j];
	}

	printf("正对角线上元素之和为%d\n负对角线上元素之和为%d\n",S,s);
}