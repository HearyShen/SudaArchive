/******************************
	1427405017
	����S
	E36
	2014-12-4 15:31
*******************************/
#include <stdio.h>

void GCD_LCM(int x,int y,int *ptr_GCD,int *ptr_LCM);	//������������

void main()
{
	int n,m,gcd,lcm;

	printf("����������������n,m��\n");
	scanf("%d%d",&n,&m);
	if(n>0&&m>0)
	{
		GCD_LCM(n,m,&gcd,&lcm);							//���ú���
		printf("���Լ��Ϊ��%d\n��С������Ϊ��%d\n",gcd,lcm);
	}
	else												//�������������������ʾ
	{
		printf("�����ֵ����������������������\n");
	}
	
}

void GCD_LCM(int x,int y,int *ptr_GCD,int *ptr_LCM)		//���屻������
{
	int GCD;
	int LCM;

	for(GCD=x;GCD>0;GCD--)
	{
		if(x%GCD==0&&y%GCD==0)
		{
			*ptr_GCD=GCD;								//����������������Լ����ֵ���β�ָ����ָ���󣬼���������gcd
			break;										//��ʱ�������Է�����ѭ��
		}
	}

	for(LCM=x;LCM<=x*y;LCM++)
	{
		if(LCM%x==0&&LCM%y==0)
		{
			*ptr_LCM=LCM;								//���������������С��������ֵ���β�ָ����ָ���󣬼��������е�lcm
			return;										//��ʱ�������Է�����ѭ��
		}
	}
}