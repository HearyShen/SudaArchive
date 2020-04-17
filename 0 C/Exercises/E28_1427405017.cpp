/*************************
	1427405017
	E28
	沈家赟
	2014-11-12 23:30
*************************/
#include <stdio.h>

#define N 100

void main()
{
	char s1[N],s2[N];				//依次定义数组s1,s2
	int i,j,L1,L2,l,k,flag,tempi;	//依次定义s1下标i，s2下标j，s1长度L1，s2长度L2，相等字符串长度l，内循环限制条件k，相等标识flag，临时存储i的tempi

	printf("请输入字符串s1：\n");
	scanf("%s",s1);
	printf("请输入字符串s2：\n");
	scanf("%s",s2);

	for(i=0;i<N;i++)				//求出s1的长度
	{
		if(s1[i]=='\0')
		{
			L1=i;
			break;
		}
	}
	for(i=0;i<N;i++)				//求出s2的长度
	{
		if(s2[i]=='\0')
		{
			L2=i;
			break;
		}
	}

	i=0;
	j=0;
	flag=0;
	while(i<=L1-L2+1)					//外层循环开始
	{
		l=0;								//默认相等字符串长度为0
		if(s1[i]==s2[j])				//一.找到相等项
		{
			tempi=i;							//用tempi临时存放使s1[i]=s2[0]的i，为找不全s2的情况做准备
			k=j+L2;
			l++;
			for(;j<k;)							//从相等项开始，向后比对
			{
				i++;
				j++;
				if(s1[i]==s2[j])			//1.若继续相等，则相等字符串长度增加1
				{
					l++;
					if(l==L2)					//一旦相等字符串长度l和s2长度相等，那么s1中就存在s2
					{
						flag=1;
						break;
					}
				}
				else						//2.若不再相等，则相等字符串长度归零，i跳过tempi，跳出内循环，重新从s2[0]开始比对
				{
					i=tempi+1;
					j=-1;
					l=0;
					break;
				}
			}
		}
		
		else							//二.还没找到相等项
		{
			i++;
			j=-1;
		}
		j++;
	}

	if(flag==1)
	{
		printf("字符串s1中存在字符串s2\n");
	}
	else
	{
		printf("字符串s1中不存在字符串s2\n");
	}
}