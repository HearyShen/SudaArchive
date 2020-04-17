/*****************
	2014_3
	1427405017
	沈家赟
	2015-6-17  9:12
******************/
#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

class CGoods
{
private:
	int m_num;	//商品编号
	string m_name;	//商品名称
	float m_price;	//商品价格

public:
	CGoods (int, const string&, float);
	friend ostream& operator<<(ostream&, const CGoods&);
	//商品名称、商品编号和商品价格的显示格式都要求为占10列、右对齐
};

CGoods::CGoods(int Num, const string& Name, float Price):m_name(Name)
{
	m_num = Num;
	m_price = Price;
}
ostream& operator<<(ostream& out, const CGoods& A)
{
	cout<<setw(10)<<A.m_name<<setw(10)<<A.m_num<<setw(10)<<A.m_price;

	return out;
}

class CRouter:public CGoods
{
private:
	float frequency;	//用于表示路由器信号频率的变量，float类型
	int channels;		//用于表示路由器端口数量的变量，int类型

public:
	CRouter(int Num=1, const string& Name="M8", float Price=100.0, float Frequency=2.4, int Channels=8);	//有参构造函数
	int GetChannels();		//获取路由器端口数量的成员函数GetChannels
	float GetFrequency();	//获取路由器信号频率的成员函数GetFrequency
	friend CRouter& operator++(CRouter& A);	//前自增运算符重载函数，实现端口数量加1的操作
	friend CRouter operator++(CRouter& A,int);	//后自增运算符重载函数，实现端口数量加1的操作
	friend ostream& operator<<(ostream& out, const CRouter& A);		//流输出符“<<”重载函数

};

CRouter::CRouter(int Num, const string& Name, float Price, float Frequency, int Channels)	:CGoods(Num,Name,Price)//有参构造函数
{
	frequency = Frequency;
	channels = Channels;
}
int CRouter::GetChannels()		//获取路由器端口数量的成员函数GetChannels
{
	return channels;
}
float CRouter::GetFrequency()	//获取路由器信号频率的成员函数GetFrequency
{
	return frequency;
}
CRouter& operator++(CRouter& A)	//前自增运算符重载函数，实现端口数量加1的操作
{
	A.channels++;

	return A;
}
CRouter operator++(CRouter& A,int)	//后自增运算符重载函数，实现端口数量加1的操作
{
	CRouter T(A);

	A.channels++;

	return T;
}
ostream& operator<<(ostream& out, const CRouter& A)	//流输出符“<<”重载函数
{
	cout<<(CGoods)A<<setw(10)<<A.frequency<<setw(10)<<A.channels;

	return out;
}

void ReadData(vector<CRouter> &s,const string FName)		//从文本文件中读取数量未知个路由器商品数据，构成一个向量
{
	ifstream fin(FName);
	try
	{
		if(fin == NULL)
		{
			throw FName;
		}
	}
	catch(string FN)
	{
		cerr<<"文件"<<FN<<"打开失败！"<<endl;
		exit(0);
	}

	int t_num;	//商品编号
	string t_name;	//商品名称
	float t_price;	//商品价格
	float t_frequency;	//用于表示路由器信号频率的变量，float类型
	int t_channels;		//用于表示路由器端口数量的变量，int类型

	for(string t_s; getline(fin,t_s);)		//file流 --> string
	{
		istringstream t_iss(t_s);			//string -->string流

		t_iss>>t_num>>t_name>>t_price>>t_frequency>>t_channels;		//string流 -->各个变量
		CRouter T(t_num,t_name,t_price,t_frequency,t_channels);			//构造临时对象
		s.push_back(T);		//加入向量容器
	}
	fin.close();
}

void DisplayData(const vector<CRouter>& s)		//显示向量中所有路由器商品数据
{
	for(int i=0;i<s.size();i++)
	{
		cout<<s[i]<<endl;
	}
}

CRouter& FindMax(vector<CRouter>& s)		//查找到向量中“端口数量和信号频率的乘积”最大的那个元素
{
	int max_inx = 0;
	for(int i=1;i<s.size();i++)
	{
		if(s[i].GetChannels()*s[i].GetFrequency() > s[max_inx].GetChannels()*s[max_inx].GetFrequency())
		{
			max_inx = i;
		}
	}

	return s[max_inx];
}

void main()
{
	vector<CRouter> s;

	ReadData(s,"D:\\Data.txt");
	cout<<"读取完成后的向量为"<<endl;
	DisplayData(s);

	CRouter t;
	cout<<endl<<"路由器对象的初始值为"<<endl<<t<<endl;

	t=FindMax(s);
	cout<<endl<<"乘积最大的向量元素为"<<endl<<t<<endl;

	cout<<endl<<"乘积最大的向量元素进行自增运算结果分别如下:"<<endl;
	cout<<t++<<endl;
	cout<<t<<endl;

	cout<<++t<<endl;
	cout<<t<<endl;
}
