/*********************
	E07
	1427405017
	沈家赟
	2015-3-25 9:07
*********************/
#include <iostream>
#include <string>

using namespace std;

int width(string s);		//声明三个重载函数
int width(char c);
int width(long long int a);

void main()
{
	string s;
	char c;
	long long int a;

	cout<<"请输入一个字符串："<<endl;
	cin>>s;
	cout<<"显示宽度为："<<width(s)<<endl;

	cout<<"请输入一个字符："<<endl;
	cin>>c;
	cout<<"显示宽度为："<<width(c)<<endl;

	cout<<"请输入一个整数："<<endl;
	cin>>a;
	cout<<"显示宽度为："<<width(a)<<endl;
}

int width(string s)			//定义string型
{
	return s.size();
}

int width(char c)			//定义char型
{
	return 1;
}

int width(long long int a)			//定义int型
{
	int flag;					//定义负数标识flag

	if(a<0)					//处理初始值
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
	for(n=1;;n++)			//循环判断绝对值位数
	{
		if(a>=pow(10.0,n-1) && a<pow(10.0,n))
		{
			break;
		}
	}
	
	if(flag==1)				//若为负数，则加上一个负号位
	{
		n++;
	}
	return n;
}