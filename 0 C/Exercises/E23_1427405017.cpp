/************************
	1427405017
	沈家赟
	E23
	2014-11-7 12:13
************************/
#include <stdio.h>

void main()
{
	int x[]={35,46,57,13,24,35,99,68,13,79,88,46},i,j,t,k,n,count;	//依次定义原始数组，排序 去重所需的i,j,t,k，显示所需的n,count

	printf("以下将显示从小到大排序，且去重的数组\n");
	for(i=0;i<11;i++)		//先利用起泡法从小到大排序
	{
		for(j=0;j<11-i;j++)
		{
			if(x[j]>x[j+1])
			{
				t=x[j];
				x[j]=x[j+1];
				x[j+1]=t;
			}
		}
	}
	
	count=0;
	for(j=0;j<11-count;j++)		//查找重复数字，并去重。每次找出一个重复数，后面的数往左移一位，需要循环判断的数字就少一个,故11-count
	{
		if(x[j]==x[j+1])
		{
			for(k=j+1;k<11-count;k++)		//每去除一个重复数，有意义的数就少一个，故11-count
			{
				x[k]=x[k+1];
			}
			count++;
		}
	}

	for(n=0;n<(12-count);n++)		//显示从小到大排序，且去重的数据，这时有意义的数组长度为12-count
	{
		printf("%5d",x[n]);
	}
	printf("\n");
}