#include <stdio.h>

void main()
{
	int a,b,c,min,med,max;//���ζ��������������������Լ���Сֵ���м�ֵ�����ֵ
	printf("����������������������a b c\n");
	scanf("%d%d%d",&a,&b,&c);

	if(a<b)//���ж��������Ĵ�С��ϵ
	{
		if(c<a)//�ټ�������������бȽ�
		{
			min=c;
			med=a;
			max=b;
		}
		else if(c>b)
		{
			min=a;
			med=b;
			max=c;
		}
		else
		{
			min=a;
			med=c;
			max=b;
		}
	}
	else
	{
		if(c<b)
		{
			min=c;
			med=b;
			max=a;
		}
		else if(c>a)
		{
			min=b;
			med=a;
			max=c;
		}
		else
		{
			min=b;
			med=c;
			max=a;
		}
	}

	printf("����������С��������Ϊ%d %d %d\n",min,med,max);
}