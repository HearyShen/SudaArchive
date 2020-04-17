/*****************
	E20
	1427405017
	沈家赟
	2015-5-20 9:47
******************/
#include <iostream>

using namespace std;

class CContry
{
private:
	char *name;		//国家名称
	char *caption;		//首都名称
	double area;		//国家面积，单位万平方公里
	double person_num;		//人口数量，单位 万
public:
	CContry()		//无参构造函数
	{
		name = new char[100];
		strcpy(name,"中国");
		caption = new char[100];
		strcpy(caption,"北京");
		area = 960;
		person_num = 130000.00;
	}
	CContry(const CContry&);		//拷贝构造函数
	CContry(char* ,char* ,double ,double);	//带参数的构造函数
	CContry& operator=(const CContry&);
	~CContry();		//析构函数
	void set(char*,char*,double ,double );		//设置属性的成员函数
	void print()const;		//在屏幕上输出CContry对象的信息
};
CContry::CContry(const CContry& A)		//拷贝构造函数
{
	name = new char[100];
	strcpy(name,A.name);
	caption = new char[100];
	strcpy(caption,A.caption);
	area = A.area;
	person_num = A.person_num;
}
CContry::CContry(char* Name, char* Caption, double Area, double Person_num)	//带参数的构造函数
{
	name = new char[100];
	strcpy(name,Name);
	caption = new char[100];
	strcpy(caption,Caption);
	area = Area;
	person_num = Person_num;
}
CContry& CContry::operator=(const CContry& A)
{
	strcpy(name,A.name);
	strcpy(caption,A.caption);
	area = A.area;
	person_num = A.person_num;

	return *this;
}
CContry::~CContry()		//析构函数
{
	cout<<name<<"对象被析构了！"<<endl;

	delete [] name;
	delete [] caption;
}
void CContry::set(char* Name,char* Caption,double Area,double Person_num)		//设置属性的成员函数
{
	strcpy(name,Name);
	strcpy(caption,Caption);
	area = Area;
	person_num = Person_num;
}
void CContry::print()const		//在屏幕上输出CContry对象的信息
{
	cout<<"国家名称："<<name<<endl;
	cout<<"首都名称："<<caption<<endl;
	cout<<"面积："<<area<<endl;
	cout<<"人口数量："<<person_num<<endl;
}

void main()
{
	CContry Ch;
	Ch.print();
	cout<<endl<<endl;

	CContry Jap("日本","东京",37.835,12665.9683);
	Jap.print();
	cout<<endl<<endl;
}