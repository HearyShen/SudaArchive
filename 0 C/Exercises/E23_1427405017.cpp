/************************
	1427405017
	����S
	E23
	2014-11-7 12:13
************************/
#include <stdio.h>

void main()
{
	int x[]={35,46,57,13,24,35,99,68,13,79,88,46},i,j,t,k,n,count;	//���ζ���ԭʼ���飬���� ȥ�������i,j,t,k����ʾ�����n,count

	printf("���½���ʾ��С����������ȥ�ص�����\n");
	for(i=0;i<11;i++)		//���������ݷ���С��������
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
	for(j=0;j<11-count;j++)		//�����ظ����֣���ȥ�ء�ÿ���ҳ�һ���ظ������������������һλ����Ҫѭ���жϵ����־���һ��,��11-count
	{
		if(x[j]==x[j+1])
		{
			for(k=j+1;k<11-count;k++)		//ÿȥ��һ���ظ������������������һ������11-count
			{
				x[k]=x[k+1];
			}
			count++;
		}
	}

	for(n=0;n<(12-count);n++)		//��ʾ��С����������ȥ�ص����ݣ���ʱ����������鳤��Ϊ12-count
	{
		printf("%5d",x[n]);
	}
	printf("\n");
}