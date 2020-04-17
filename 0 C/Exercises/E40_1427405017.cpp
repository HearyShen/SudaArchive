/********************************
	1427405017
	沈家赟
	E40
	2014-12-6 15:54
*********************************/
#include <stdio.h>

void Sort(int *p,int n);
void Insert(int Arr[],int N,int In);
void Display(int Arr[],int N);

void main()
{
	int x[1000],num,k,in;

	printf("请输入待输入的初始数组的整型元素个数：\n");						//输入初始数组
	scanf("%d",&num);
	printf("请输入任意个整型元素（按空格键隔开）：\n");
	for(k=0;k<num;k++)
	{
		scanf("%d",&x[k]);
	}

	Sort(x,num);															//调用初始数组排序函数
	printf("排序后的数组为：\n");
	Display(x,num);

	printf("请输入插入数组的某一整数：\n");									//输入插入整数
	scanf("%d",&in);
	num++;																	//数组中有效元素数多一个

	Insert(x,num,in);														//调用插入函数
	printf("插入后的有序数组为：\n");
	Display(x,num);
}

void Sort(int *p,int n)														//定义数组排序函数
{
	int i;
	int j;
	int t;

	for(i=0;i<n-1;i++)														//冒泡法排序
	{
		for(j=0;j<n-1-i;j++)
		{
			if(*(p+j)>*(p+j+1))												//指针访问数组元素
			{
				t=*(p+j);
				*(p+j)=*(p+j+1);
				*(p+j+1)=t;
			}
		}
	}
}

void Insert(int Arr[],int N,int In)											//定义插入函数
{
	int i;
	int j;
	
	N=N-1;																	//主函数中Insert函数前考虑到插入一个数，做了num++操作
	for(i=0;i<N;i++)
	{
		if(Arr[i]>In)														//若数组中有比插入数大的元素
		{
			for(j=N-1;j>=i;j--)
			{
				Arr[j+1]=Arr[j];											//则相关元素往后移
			}
			Arr[i]=In;
			return;
		}
	}
	Arr[N]=In;																//若数组中各元素都比插入元素小
}

void Display(int Arr[],int N)												//定义数组显示函数
{
	int i;

	for(i=0;i<N;i++)
	{
		printf("%6d",Arr[i]);
		if((i+1)%8==0)														//及时换行，格式美观
		{
			printf("\n");
		}
	}
	printf("\n");
}