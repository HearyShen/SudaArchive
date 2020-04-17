/*******************
	E21
	1427405017
	沈家赟
	2015-6-6  14:38
********************/
#include <iostream>
#include <string>

using namespace std;

class CPerson
{
private:
	string m_name;	// 姓名
	int m_age;		// 年龄
	char m_sex;		// 性别 ‘M’表示男性 ‘F’表示女性
public:
	CPerson(string& name, int age, char sex)
	{
		m_name = name;
		m_age = age;
		m_sex = sex;
	}
	CPerson()
	{
		m_name = "无名";
		m_age = 18;
		m_sex = 'M';
	}
	void print()
	{
		cout<<"\n 姓名："<<m_name<<"\n 年龄："<<m_age<<"\n";
		if (m_sex == 'M')
			cout<<"性别： 男"<<endl;
		else
			cout<<"性别： 女"<<endl;
	}
};

class CStudent : public CPerson		//以CPerson 类为基类定义一个派生类CStudent
{
private:
	string m_university;
	int m_grade;

public:
	CStudent();		// 以{”无名”、18 岁、男性、“苏州大学”、1 年级}为默认值的无参构造函数；
	CStudent(string name, int , char, string collageName, int grade); // 带参数的构造函数
	void print();	 // 显示学生类对象的所有信息

};

CStudent::CStudent():CPerson(),m_university("苏州大学")	// 以{”无名”、18 岁、男性、“苏州大学”、1 年级}为默认值的无参构造函数
{
	m_grade = 1;
}

CStudent::CStudent(string name, int age, char sex, string collageName, int grade):CPerson(name,age,sex),m_university(collageName)	 // 带参数的构造函数
{
	m_grade = grade;
}

void CStudent::print()	 // 显示学生类对象的所有信息
{
	CPerson::print();
	cout<<"学校："<<m_university<<endl;
	cout<<"年级："<<m_grade<<endl;
}

void main()
{
	CStudent student1;
	student1.print();

	CStudent student2("Liming",21,'M',"苏州大学",1);
	student2.print();
}