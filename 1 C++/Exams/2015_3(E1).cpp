#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

class CPerson
{
private:
	int 	m_id;		//员工工号
	string 	m_name;		//员工姓名
	int	 	m_sex;		//员工性别  0 代表男  1   代表女

public:
	CPerson (int, const string&, bool);
	friend ostream& operator<<(ostream&, const CPerson &);
//员工名称、员工编号和员工性别的显示格式都要求为占10列、左对齐
//其中性别需要显示为 男或女 而不是  0或1
};

CPerson::CPerson(int ID, const string& Name, bool Sex):m_name(Name)
{
	m_id = ID;
	m_sex = Sex;
}

ostream& operator<<(ostream& out, const CPerson &A)
{
	out<<left<<setw(10)<<A.m_name;
	out<<left<<setw(10)<<A.m_id;
	if(A.m_sex)
	{
		out<<left<<setw(10)<<"女";	
	}
	else
	{
		out<<left<<setw(10)<<"男";
	}
	return out;
}

class CEngineer : public CPerson
{
private:
	float m_salary;
	int m_grade;
public:
	CEngineer(int ID=1001, const string& Name="未知", bool Sex=true, float Salary=2400.00, int Grade=1);
	float GetSalary()const;		//d)获取工程师工资的成员函数GetSalary；
	int GetGrade()const;			//e)获取工程师等级的成员函数GetGrade；
	friend CEngineer& operator++(CEngineer &A);		//前自增运算符重载函数
	friend CEngineer operator++(CEngineer &A, int);	//后自增运算符重载函数
	friend ostream& operator<<(ostream& out,const CEngineer& A);	//流输出符“<<”重载函数
};

CEngineer::CEngineer(int ID, const string& Name, bool Sex, float Salary, int Grade):CPerson(ID,Name,Sex)
{
	m_salary = Salary;
	m_grade = Grade;
}

float CEngineer::GetSalary()const		//d)获取工程师工资的成员函数GetSalary；
{
	return m_salary;
}

int CEngineer::GetGrade()const			//e)获取工程师等级的成员函数GetGrade；
{
	return m_grade;
}

CEngineer& operator++(CEngineer &A)		//前自增运算符重载函数
{
	if(A.m_grade<=2)
	{
		A.m_grade++;
	}
	return A;
}

CEngineer operator++(CEngineer &A, int)	//后自增运算符重载函数
{
	CEngineer T(A);

	if(A.m_grade<=2)
	{
		A.m_grade++;
	}
	return T;
}

ostream& operator<<(ostream& out,const CEngineer& A)	//流输出符“<<”重载函数
{
	out<<CPerson(A)<<right<<setw(10)<<A.m_salary<<setw(10)<<A.m_grade;

	return out;
}

void ReadInfo(vector<CEngineer> &workers,const string& FName);
void ShowInfo(const vector<CEngineer> &workers);
CEngineer GetMaxFemal(const vector<CEngineer> &workers);

void main()
{

	CEngineer temp;
	cout<<endl<<"工程师对象的初始值为"<<endl<<temp<<endl;

	vector<CEngineer> workers;
	ReadInfo(workers,"f:\\Info.txt");
	cout<<"读取完成后的向量为"<<endl;
	ShowInfo(workers);

	temp=GetMaxFemal(workers);
	cout<<endl<<"工资等级比例最高的为"<<endl<<temp<<endl;

	cout<<endl<<"工资等级比例最高的工程师进行自增运算结果分别如下:"<<endl;
	cout<<temp++<<endl;
	cout<<temp<<endl;

	cout<<++temp<<endl;
	cout<<temp<<endl;
}

void ReadInfo(vector<CEngineer> &workers,const string& FName)
{
	ifstream fin(FName);
	if(fin == NULL)
	{
		cout<<"打开文件失败！"<<endl;
		exit(0);
	}

	int t_ID;
	string t_Name;
	bool t_Sex;
	float t_Salary;
	int t_Grade;

	while(fin.eof() != true)
	{
		if(fin>>t_ID>>t_Name>>t_Sex>>t_Salary>>t_Grade)
		{
			CEngineer T(t_ID,t_Name,t_Sex,t_Salary,t_Grade);
			workers.push_back(T);
		}
	}
	fin.close();

	//for(string s;getline(fin,s);)
	//{
	//	istringstream iss(s);
	//	if(iss>>t_ID>>t_Name>>t_Sex>>t_Salary>>t_Grade)
	//	{
	//		CEngineer T(t_ID,t_Name,t_Sex,t_Salary,t_Grade);
	//		workers.push_back(T);
	//	}
	//}
}

void ShowInfo(const vector<CEngineer> &workers)
{
	for(int i=0;i<workers.size();i++)
	{
		cout<<workers[i]<<endl;
	}
}

CEngineer GetMaxFemal(const vector<CEngineer> &workers)
{
	double max = (workers[0].GetSalary()/workers[0].GetGrade());
	int max_inx = 0;
	
	double t;
	for(int i=1;i<workers.size();i++)
	{
		t = (workers[i].GetSalary()/workers[i].GetGrade());
		if(t > max)
		{
			max = t;
			max_inx = i;
		}
	}
	return workers[max_inx];
}