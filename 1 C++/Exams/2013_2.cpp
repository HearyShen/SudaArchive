/***************
	1427405017
	沈家赟
	2013_2
	2015-6-3  8:56
***************/
//=============================================
// 串口类的测试程序
//=============================================
#include <iostream>
#include <string>

using namespace std;

class CSerialPort
{
private:
	string Name;
	int Speed;
	int BufferLength;
	static int ComCounts;

public:
	CSerialPort(const string &name="com1", int speed=9600,int bufferlength=500);	//带有默认参数值的构造函数
	CSerialPort(const CSerialPort &A);		//拷贝构造函数
	static int GetComCounts();		//获取当前串口对象个数的静态数据成员的接口函数
	CSerialPort& operator++();			//前自增运算符重载函数，函数功能实现对串口通信速率自增1
	CSerialPort operator++(int);		//后自增运算符重载函数，函数功能实现对串口通信速率自增1
	friend ostream& operator<<(ostream &out,const CSerialPort &A);
	~CSerialPort();			//析构函数
};

int CSerialPort::ComCounts = 0;

CSerialPort::CSerialPort(const string &name, int speed,int bufferlength)	//带有默认参数值的构造函数
{
	Name = name;
	Speed = speed;
	BufferLength = bufferlength;

	ComCounts++;
}

CSerialPort::CSerialPort(const CSerialPort &A)		//拷贝构造函数
{
	Name = A.Name;
	Speed = A.Speed;
	BufferLength = A.BufferLength;

	ComCounts++;
}

int CSerialPort::GetComCounts()		//获取当前串口对象个数的静态数据成员的接口函数
{
	return ComCounts;
}

CSerialPort& CSerialPort::operator++()		//前自增运算符重载函数，函数功能实现对串口通信速率自增1
{
	Speed++;

	return *this;
}

CSerialPort CSerialPort::operator++(int)		//后自增运算符重载函数，函数功能实现对串口通信速率自增1
{
	CSerialPort Temp(*this);			//创建临时对象用于返回

	Speed++;

	return Temp;
}

ostream& operator<<(ostream &out,const CSerialPort &A)
{
	out<<"串口名称："<<A.Name<<endl;
	out<<"串口通信速率："<<A.Speed<<endl;

	return out;
}

CSerialPort::~CSerialPort()		//析构函数
{
	ComCounts--;
}

int main()
{
	CSerialPort  portA;
	cout<<"串口portA为: \n"<<portA;
	cout<<"当前创建的串口个数为: "<<CSerialPort::GetComCounts()<<"\n"<<endl;
	
	CSerialPort portB("com5",4800, 1024);
	cout<<"串口portB为: \n"<<portB;
	cout<<"当前创建的串口个数为: "<<CSerialPort::GetComCounts()<<"\n"<<endl;
	
	++(++portB);    // 连续前自增操作
	cout<<"两次前自增后，串口portB为: \n"<<portB;
	cout<<"当前创建的串口个数为: "<<CSerialPort::GetComCounts()<<"\n"<<endl;

	cout<<"一次后自增后，串口portB为: \n"<<portB++;
	cout<<"一次后自增后，串口portB为: \n"<<portB;
	cout<<"当前创建的串口个数为: "<<CSerialPort::GetComCounts()<<"\n"<<endl;

	CSerialPort  *ptr_portC = new CSerialPort;
	cout<<"串口portC为:\n"<<*ptr_portC;
	cout<<"当前创建的串口个数为: "<<CSerialPort::GetComCounts()<<"\n"<<endl;

	delete ptr_portC;
	cout<<"删除串口portC后，当前创建的串口个数为: "<<CSerialPort::GetComCounts()<<"\n"<<endl;

	return 0;
}