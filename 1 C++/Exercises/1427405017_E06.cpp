/*********************
	E06
	1427405017
	����S
	2015-3-25 8:31
*********************/
#include <iostream>

using namespace std;

int math(int a,int b,int &GCD,int &LCM);	//�����Զ��庯��math

void main()
{
	int a,b,GCD,LCM;				//GCD(greatest common divider),LCM(least common multiple)

	cout<<"����������������"<<endl;
	cin>>a>>b;
	if(math(a,b,GCD,LCM)==1)			//����ֵ������������������������
	{
		cout<<"���Լ��Ϊ��"<<GCD<<endl;
		cout<<"��С������Ϊ��"<<LCM<<endl;
	}
	else										//����ֵ�������ṩ��ʾ
	{
		cout<<"����ֵ�����밴��ʾ�޸����ԡ�"<<endl;
	}
}

int math(int a,int b,int &GCD,int &LCM)	//�����Զ��庯��math
{
	if(a>0 && b>0)		//����ֵ����Ҫ��
	{
		int i;

		for(i=a;i>0;i--)		//ѭ���������Լ��
		{
			if(a%i==0 && b%i==0)
			{
				GCD=i;
				break;
			}
		}
		for(i=a;i<=a*b;i++)	//ѭ��������С������
		{
			if(i%a==0 && i%b==0)
			{
				LCM=i;
				break;
			}
		}
		return 1;
	}
	else		//����ֵ������Ҫ��
	{
		cout<<"������Ǹ�������"<<endl;
		return 0;
	}
}