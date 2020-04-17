/*********************
	E12
	1427405017
	沈家赟
	2015-4-22 10:32
*********************/
#include <iostream>

using namespace std;

class CAount			//定义CAount类
{
private:
	double m_Money;
	int year,month,day;
	static double m_InterestRate;
public:
	static void SetInterestRate(const double Interest);		//声明静态成员函数（设置利率）
	static double GetInterestRate();						//声明静态成员函数（获取利率）
	bool SaveMoney(const double &Money,const int &Year,const int &Month,const int &Day);		//声明成员函数（存款）
	bool LendMoney(const double &Money,const int &Year,const int &Month,const int &Day);		//声明成员函数（取款）
	double CalcInterest(const int &Year,const int &Month,const int &Day);						//声明成员函数（计算利息）
	double CalcInterest(const double &Money,const int &Year,const int &Month,const int &Day);	//声明重载成员函数（计算定额利息）
	bool SaveInterest(const int &Year,const int &Month,const int &Day);							//声明成员函数（结算利息）
	bool SaveInterest(const double &Money,const int &Year,const int &Month,const int &Day);		//声明成员函数（结算定额利息）
	void Print()const;																			//声明常成员函数（显示账户信息）
};

double CAount::m_InterestRate = 0;		//静态成员m_InterestRate赋初值

/****************************成员函数定义起************************************/
void CAount::SetInterestRate(const double Interest)		//定义静态成员函数（设置利率）
{
	m_InterestRate = Interest;
}
double CAount::GetInterestRate()						//定义静态成员函数（获取利率）
{
	return m_InterestRate;
}

bool CAount::SaveMoney(const double &Money,const int &Year,const int &Month,const int &Day)		//定义成员函数（存款）
{
	if(Month>=1 && Month<=12 && Day>=1 && Day<=30)		//对存款日期进行合法性判断
	{
		m_Money =  Money;

		year = Year;
		month = Month;
		day = Day;

		return true;
	}
	else
	{
		return false;
	}
}
bool CAount::LendMoney(const double &Money,const int &Year,const int &Month,const int &Day)		//定义成员函数（取款）
{
	if((m_Money - Money) >= 0)		//对取款额度进行合法性判断
	{
		m_Money = m_Money - Money;
		return true;
	}
	else
	{
		return false;
	}
}

double CAount::CalcInterest(const int &Year,const int &Month,const int &Day)		//定义成员函数（计算利息）
{
	int days;

	days = (Year-year)*360 + (Month-month)*30 + (Day-day+1);			//计算累计天数（当日也算在内）

	return (m_Money*m_InterestRate/360)*days;
}
double CAount::CalcInterest(const double &Money,const int &Year,const int &Month,const int &Day)	//定义重载成员函数（计算定额利息）
{
	int days;

	days = (Year-year)*360 + (Month-month)*30 + (Day-day+1);			//计算累计天数（当日也算在内）

	return (Money*m_InterestRate/360)*days;
}

bool CAount::SaveInterest(const int &Year,const int &Month,const int &Day)		//定义成员函数（结算利息）
{
	int days;

	if(Month>=1 && Month<=12 && Day>=1 && Day<=30)						//对存款日期进行合法性判断
	{
		days = (Year-year)*360 + (Month-month)*30 + (Day-day+1);
		m_Money = m_Money + (m_Money*m_InterestRate/360)*days;

		year = Year;							//完整结算利息，重新设置存款日期
		month = Month;
		day = Day;

		return true;
	}
	else
	{
		return false;
	}
}
bool CAount::SaveInterest(const double &Money,const int &Year,const int &Month,const int &Day)		//定义成员函数（结算定额利息）
{
	int days;

	if(Month>=1 && Month<=12 && Day>=1 && Day<=30)		//对存款日期进行合法性判断
	{
		days = (Year-year)*360 + (Month-month)*30 + (Day-day+1);
		m_Money = m_Money + (Money*m_InterestRate/360)*days;

		return true;
	}
	else
	{
		return false;
	}
}

void CAount::Print()const							//定义常成员函数（显示账户信息）
{
	cout<<"当前余额："<<m_Money<<endl;
	cout<<"存款日期为："<<year<<"年"<<month<<"月"<<day<<"日"<<endl;
}
/****************************成员函数定义止************************************/

void main()
{
	/*******************利率设置与获取*********************/
	CAount User;
	cout<<"设置利率为0.036："<<endl;
	CAount::SetInterestRate(0.036);
	cout<<"当前利率为："<<CAount::GetInterestRate()<<endl;
	cout<<endl;
	
	/*******************2014-1-1 存款*********************/
	cout<<"2014-1-1 存款100000"<<endl;
	User.SaveMoney(100000.0,2014,1,1);
	User.Print();
	cout<<endl;

	/*******************2014-3-10 结算利息*********************/
	cout<<"截止2014-3-10，最新一期活期利息为："<<User.CalcInterest(2014,3,10)<<endl;
	User.SaveInterest(2014,3,10);
	User.Print();
	cout<<endl;

	/*******************2014-3-30 取款200000*********************/
	cout<<"2014-3-30 取款200000"<<endl;
	if(User.LendMoney(200000.0,2014,3,30))
	{
		cout<<"取款成功！"<<endl;
	}
	else
	{
		cout<<"取款失败！"<<endl;
	}
	User.Print();
	cout<<endl;

	/*******************2014-4-4 取款50000*********************/
	cout<<"2014-4-4 取款50000"<<endl;
	if(User.LendMoney(50000.0,2014,4,4))
	{
		cout<<"取款成功！"<<endl;
		cout<<"截止2014-4-4，最新一期活期利息为："<<User.CalcInterest(50000.0,2014,4,4)<<endl;
		User.SaveInterest(50000.0,2014,4,4);
	}
	else
	{
		cout<<"取款失败！"<<endl;
	}
	User.Print();
	cout<<endl;
}