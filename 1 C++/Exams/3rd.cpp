#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>
#include <sstream>

using namespace std;

class CGoods
{
private:
	int m_num;	//商品编号
	string m_name;	//商品名称
	float m_price;	//商品价格

public:
	CGoods (int num, const string& name, float price);
	friend ostream& operator<<(ostream& out, const CGoods& c);  //商品名称、商品编号和商品价格的显示格式都要求为占10列、右对齐
};

class CRouter:public CGoods
{
private:
	float snr;//路由器信号频率
	int nop;//路由器端口数量
public:
	CRouter(int num=1,const string& name="M8",float price=100.0,float SNR=2.4,int NOP=8):CGoods(num,name,price)//有默认值的有参构造函数
	{
		CGoods::CGoods(num,name,price);
		snr=SNR;
		nop=NOP;
	}
	float GetFrequency();//获取路由器信号频率
	int GetChannels();//获取路由器端口数量
	friend CRouter& operator++(CRouter& c);//前自增运算符重载函数，实现端口数量加1的操作
	friend CRouter operator++(CRouter& c,int);//后自增运算符重载函数，实现端口数量加1的操作
	friend ostream& operator<<(ostream& out,const CRouter& c);//流输出符“<<”重载函数，实现对路由器商品全部信息的显示，基类部分成员的显示格式要求与CGoods类部分相同，信号频率和端口数量的显示格式都要求为占10列、右对齐
};

CGoods::CGoods (int num, const string& name, float price)
{
	m_num=num;
	m_name=name;
	m_price=price;
}

ostream& operator<<(ostream& out, const CGoods& c)
{
	return out<<setw(10)<<c.m_num<<right<<setw(10)<<c.m_name<<right<<setw(10)<<c.m_price<<right;
}

float CRouter::GetFrequency()//获取路由器信号频率
{
	return snr;
}

int CRouter::GetChannels()//获取路由器端口数量
{
	return nop;
}

CRouter& operator++(CRouter& c)//前自增运算符重载函数，实现端口数量加1的操作
{
	c.nop++;

	return c;
}

CRouter operator++(CRouter& c,int)//后自增运算符重载函数，实现端口数量加1的操作
{
	CRouter b(c);

	c.nop++;

	return b;
}

ostream& operator<<(ostream& out,const CRouter& c)//流输出符“<<”重载函数
{
	return out<<CGoods(c)<<setw(10)<<c.snr<<right<<setw(10)<<c.nop<<right<<endl;
}

void ReadData(vector<CRouter> &s,string FName);//从文本文件中读取数量未知个路由器商品数据，构成一个向量
void DisplayData(vector<CRouter> &s);//显示向量中所有路由器商品数据，每条数据占1行
CRouter FindMax(vector<CRouter> &s);//查找到向量中“端口数量和信号频率的乘积”最大的那个元素

void ReadData(vector<CRouter> &s,string FName)//从文本文件中读取数量未知个路由器商品数据，构成一个向量
{
	int num,NOP;
	string name;
	float price,SNR;
	s.clear();

	ifstream in(FName);

	if(in==NULL)
	{
		cout<<"can't open the file!!"<<endl;
		exit(0);
	}

	while(in.eof()!=true)
	{
		in>>num>>name>>price>>SNR>>NOP;
		CRouter b(num,name,price,SNR,NOP);

		if(in!=NULL)
		{
			s.push_back(b);
		}
	}
	in.close();
}

void DisplayData(vector<CRouter> &s)//显示向量中所有路由器商品数据，每条数据占1行
{
	for(int i=0;i<s.size();i++)
	{
		cout <<CRouter(s[i])<<endl;
	}
}

CRouter FindMax(vector<CRouter> &s)//查找到向量中“端口数量和信号频率的乘积”最大的那个元素
{
	CRouter c=s[0];

	for(int i=0;i<s.size();i++)
	{

		if(s[i].GetChannels()*s[i].GetFrequency()>c.GetChannels()*c.GetFrequency())
		{
			c=s[i];
		}
	}

	return c;
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