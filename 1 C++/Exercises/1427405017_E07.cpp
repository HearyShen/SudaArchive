/*********************
	E07
	1427405017
	����S
	2015-3-25 9:07
*********************/
#include <iostream>
#include <string>

using namespace std;

int width(string s);		//�����������غ���
int width(char c);
int width(long long int a);

void main()
{
	string s;
	char c;
	long long int a;

	cout<<"������һ���ַ�����"<<endl;
	cin>>s;
	cout<<"��ʾ���Ϊ��"<<width(s)<<endl;

	cout<<"������һ���ַ���"<<endl;
	cin>>c;
	cout<<"��ʾ���Ϊ��"<<width(c)<<endl;

	cout<<"������һ��������"<<endl;
	cin>>a;
	cout<<"��ʾ���Ϊ��"<<width(a)<<endl;
}

int width(string s)			//����string��
{
	return s.size();
}

int width(char c)			//����char��
{
	return 1;
}

int width(long long int a)			//����int��
{
	int flag;					//���帺����ʶflag

	if(a<0)					//�����ʼֵ
	{
		flag=1;
		a=-a;
	}
	else if(a==0)
	{
		return 1;
	}
	else
	{
		flag=0;
	}
		
	int n;
	for(n=1;;n++)			//ѭ���жϾ���ֵλ��
	{
		if(a>=pow(10.0,n-1) && a<pow(10.0,n))
		{
			break;
		}
	}
	
	if(flag==1)				//��Ϊ�����������һ������λ
	{
		n++;
	}
	return n;
}