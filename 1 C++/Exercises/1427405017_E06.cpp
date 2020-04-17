/*********************
	E06
	1427405017
	沈家赟
	2015-3-25 8:31
*********************/
#include <iostream>

using namespace std;

int math(int a,int b,int &GCD,int &LCM);	//声明自定义函数math

void main()
{
	int a,b,GCD,LCM;				//GCD(greatest common divider),LCM(least common multiple)

	cout<<"请输入两个整数："<<endl;
	cin>>a>>b;
	if(math(a,b,GCD,LCM)==1)			//返回值正常，即被调函数正常运行
	{
		cout<<"最大公约数为："<<GCD<<endl;
		cout<<"最小公倍数为："<<LCM<<endl;
	}
	else										//返回值错误则提供提示
	{
		cout<<"输入值有误，请按提示修改重试。"<<endl;
	}
}

int math(int a,int b,int &GCD,int &LCM)	//定义自定义函数math
{
	if(a>0 && b>0)		//输入值符合要求
	{
		int i;

		for(i=a;i>0;i--)		//循环计算最大公约数
		{
			if(a%i==0 && b%i==0)
			{
				GCD=i;
				break;
			}
		}
		for(i=a;i<=a*b;i++)	//循环计算最小公倍数
		{
			if(i%a==0 && i%b==0)
			{
				LCM=i;
				break;
			}
		}
		return 1;
	}
	else		//输入值不符合要求
	{
		cout<<"请输入非负整数！"<<endl;
		return 0;
	}
}