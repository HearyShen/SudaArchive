/*******************
	E22
	1427405017
	沈家赟
	2015-6-6 14:38
*******************/
#include <iostream>
#include <string>

using namespace std;

class CBook
{
private:
	string name;
	string author;
	double price;
	string publisher;
public:
	CBook(){name = "无"; author="无"; price = 0.0; publisher = "无";}
	CBook(const CBook &); // 拷贝构造函数
	CBook(string , string, double, string); // 带参数的构造函数
	CBook(char*, char*, double, char*); // 带参数的构造函数
	~CBook(); // 析构函数
	void SetName(char*); // 设置书名的成员函数
	void SetName(string&); // 设置书名的成员函数
	void print()const; // 在屏幕上显示书的信息的成员函数
	friend ostream & operator<<(ostream& out, const CBook &); // 输出操作符的重载函数
};

CBook::CBook(const CBook &A)	// 拷贝构造函数
{
	name = A.name;
	author = A.author;
	price = A.price;
	publisher = A.publisher;
}
CBook::CBook(string Name, string Author, double Price, string Publisher)		// 带参数的构造函数
{
	name = Name;
	author = Author;
	price = Price;
	publisher = Publisher;
}
CBook::CBook(char* Name, char* Author, double Price, char* Publisher)	 // 带参数的构造函数
{
	name = Name;
	author = Author;
	price = Price;
	publisher = Publisher;
}
CBook::~CBook()		 // 析构函数
{
	cout<<name<<"对象被析构了！"<<endl;
}
void CBook::SetName(char* Name)		 // 设置书名的成员函数
{
	name = Name;
}
void CBook::SetName(string& Name)	 // 设置书名的成员函数
{
	name = Name;
}
void CBook::print()const	 // 在屏幕上显示书的信息的成员函数
{
	cout<<"书名："<<name<<endl;
	cout<<"作者："<<author<<endl;
	cout<<"价格："<<price<<endl;
	cout<<"出版社："<<publisher<<endl;
}
ostream & operator<<(ostream& out, const CBook &A) // 输出操作符的重载函数
{
	out<<"书名："<<A.name<<endl;
	out<<"作者："<<A.author<<endl;
	out<<"价格："<<A.price<<endl;
	out<<"出版社："<<A.publisher<<endl;
	
	return out;
}


class CComputerBook:public CBook
{
private:
	string field;
	string type;

public:
	CComputerBook();	//a) 无参构造函数
	CComputerBook(string Name, string Author, double Price, string Publisher, string Field, string Type);	//b) 带参数的构造函数
	~CComputerBook();	//c) 析构函数
	friend ostream& operator<<(ostream& out,const CComputerBook A);	//d) 流输出符重载函数

};

CComputerBook::CComputerBook():CBook(),field("无"),type("无")		//a) 无参构造函数
{
}

CComputerBook::CComputerBook(string Name, string Author, double Price, string Publisher, string Field, string Type):CBook(Name,Author,Price,Publisher),field(Field),type(Type)	//b) 带参数的构造函数
{
}

CComputerBook::~CComputerBook()		//c) 析构函数
{
	cout<<"CComputerBook 类对象被析构了!"<<endl;
}

ostream& operator<<(ostream& out,const CComputerBook A)	//d) 流输出符重载函数
{
	out<<(CBook)A<<"领域："<<A.field<<"\n类别："<<A.type<<endl;

	return out;
}

void main()
{
	CComputerBook *p = new CComputerBook("C程序设计教程","王涛",35.0,"清华大学出版社","程序设计","教材");

	cout<<*p<<endl;

	delete p;
}