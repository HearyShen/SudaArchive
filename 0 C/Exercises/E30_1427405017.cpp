/******************
	1427405017
	����S
	E30
	2014-11-13 16:39
*******************/
#include <stdio.h>

int GCD(int x,int y);			//GCD = Greatest Common Divisor	(���Լ��)
int LCM(int x,int y);			//LCM = Least Common Multiple	(��С������)

void main()
{
	int a,b;
	
	printf("����������������\n");
	scanf("%d%d",&a,&b);

	printf("���������������Լ��Ϊ%d\n",GCD(a,b));	//�������Լ������
	printf("��������������С������Ϊ%d\n",LCM(a,b));	//������С����������
}

int GCD(int x,int y)			//���������Լ���ĺ���
{
	int z;

	z=x;
	for(;z>0;z--)
	{
		if(x%z==0&&y%z==0)
		{
			return(z);
		}
	}
}

int LCM(int x,int y)			//��������С�������ĺ���
{
	int z;

	z=y;
	for(;z<=x*y;z++)
	{
		if(z%x==0&&z%y==0)
		{
			return(z);
		}
	}
}