/********************
	1427405017
	沈家赟
	E22
	2014-11-5 11:30
********************/
#include <stdio.h>

void main()
{
	int x[10]={13,24,35,46,57,68,79,88,93},n,i,j,k;	//依次定义数组 待输入数n 数组下标i,i,k

	printf("请输入一个整数\n");
	scanf("%d",&n);

	for(i=0;i<10;i++)
	{
		if(n<x[i])		//数字n比数组某一数字小的情况
		{
			for(j=9;j>i;j--)		//数组中比n大的数字全部后移一位
			{
				x[j]=x[j-1];
			}
			x[i]=n;		//把n放到腾出来的x[i]里
			break;
		}
		if(n>=x[8])		//数字n不小于数组中全部数字的情况
		{
			x[9]=n;
			break;
		}
	}

	printf("加入该数字后，该数组从小到大为：\n");
	for(k=0;k<10;k++)		//输出结果
	{
		printf("%d ",x[k]);
	}
	printf("\n");
}