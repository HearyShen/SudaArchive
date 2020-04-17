/*******************
	E18
	1427405017
	沈家赟
	2015-5-18 17:20
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

void main()
{
	string n="C++程序设计", a="王涛", pub="苏州大学出版社";

	CBook b1;
	cout<<b1<<endl;
	b1.SetName(n);
	b1.print();
	b1.SetName("VB");
	cout<<b1<<endl;

	CBook b2=b1;
	cout<<b2<<endl;

	CBook b3(n,a,35.0,pub);
	cout<<b3<<endl;

	CBook *b4=new CBook("VC++", "李国", 45.0, "清华大学出版社");
	cout<<*b4<<endl;
	delete b4;
}