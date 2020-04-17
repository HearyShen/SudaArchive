/************************
	E12
	1427405017
	沈家赟
	2015-4-26 22:43
*************************/

/*修改：LendMoney函数：添加日期参数以及修改返回值类型为double
*		CalcInterest函数：添加金额参数以便LendMoney函数调用
*		主函数中增加取出金额输出，利息计算与结算时间修改
*/

#include<iostream>
using namespace std;

//日期
struct Date
{
	int year;	//年
	int month;	//月
	int day;	//日

	Date(){}
	Date(int y, int m, int d)
	{
		year = y;
		month = m;
		day = d;
	}
};
//账户类
class CAount
{
private:
	double m_Money;	//余额
	Date m_Date;	//存款日期
	static double m_InterestRate;	//年利率

	int NumOfDays(const Date &date) const;	//计算天数，内部计算调用

public:
	static void SetInterestRate(double interest);	//设置年利率
	static double GetInterestRate();				//获取年利率
	
	void SaveMoney(double money, const Date &date);	//存款函数
	double LendMoney(const Date &date, double money);			//取款函数
	double CalcInterest(const Date &date, double money) const;	//计算利息
	void SaveInterest(const Date &date);			//结算利息
	
	double GetBalance();	//获取余额
	Date GetDate();			//获取存款日期
};

double CAount::m_InterestRate = 0;

void CAount::SetInterestRate(double interest)	//设置年利率
{
	m_InterestRate = interest;
}
double CAount::GetInterestRate()				//获取年利率
{
	return m_InterestRate;
}

void CAount::SaveMoney(double money, const Date &date)	//存款函数
{
	if(date.month>=1 && date.month<=12 && date.day>=1 && date.day<=30)		//对存款日期进行合法性判断
	{
		m_Money =  money;

		m_Date.year = date.year;
		m_Date.month = date.month;
		m_Date.day = date.day;
	}
	else
	{
		cout<<"日期（年/月/日）有误！"<<endl;
	}
}
double CAount::LendMoney(const Date &date, double money)			//取款函数
{
	double interest;

	if((m_Money - money) >= 0)		//对取款额度进行合法性判断
	{
		m_Money = m_Money - money;
		interest = CalcInterest(date,money);	//取款成功，则同时算出所取款项应得利息

		return money + interest;
	}
	else
	{
		return -1;						//取不出来就返回负数
	}
}

double CAount::CalcInterest(const Date &date, double money)const	//计算利息
{
	int days;

	days = (date.year-m_Date.year)*360 + (date.month-m_Date.month)*30 + (date.day-m_Date.day);			//计算累计天数（间隔天数算头不算尾）

	return (money*m_InterestRate/360)*days;
}

void CAount::SaveInterest(const Date &date)			//结算利息
{
	int days;

	if(date.month>=1 && date.month<=12 && date.day>=1 && date.day<=30)		//对存款日期进行合法性判断
	{
		days = (date.year-m_Date.year)*360 + (date.month-m_Date.month)*30 + (date.day-m_Date.day);
		m_Money = m_Money + (m_Money*m_InterestRate/360)*days;

		m_Date.year = date.year;						//结算完成就刷新日期
		m_Date.month = date.month;
		m_Date.day = date.day;
	}
	else
	{
		cout<<"日期（年/月/日）错误！"<<endl;
	}
}

double CAount::GetBalance()		//获取余额
{
	return m_Money;
}

Date CAount::GetDate()			//获取存款日期
{
	return m_Date;
}

void main()
{
	double lendMoney;
	CAount account;

	CAount::SetInterestRate(0.036);//设置年利率
	account.SaveMoney(200000.0, Date(2015, 4, 22));//存款

	//输出年利率
	cout<<"设置的年利率为："<<CAount::GetInterestRate()<<endl;
	cout<<endl;
	//取款
	cout<<"取款210000元："<<endl;
	if ((lendMoney = account.LendMoney(Date(2015, 4, 22), 210000.0)) < 0)
	{
		cout<<"余额不足！"<<endl;
	}
	else
	{
		cout<<"取款成功！"<<endl;
	}
	cout<<endl;
	//利息计算与结算
	cout<<"到2016年6月1日，利息为："<<account.CalcInterest(Date(2016, 6, 1), account.GetBalance())<<"元"<<endl;
	account.SaveInterest(Date(2016, 6, 1));
	//取款
	cout<<"2016年12月1日取款100000元："<<endl;
	if ((lendMoney = account.LendMoney(Date(2016, 12, 1), 100000.0)) < 0)
	{
		cout<<"余额不足！"<<endl;
	}
	else
	{
		cout<<"取款成功！"<<endl;
		cout<<"您取出的金额为："<<lendMoney<<"元"<<endl;
		cout<<"您的余额为："<<account.GetBalance()<<"元"<<endl;
		cout<<"存款日期（或上次利息结算日期）为："<<account.GetDate().year<<"年"
			<<account.GetDate().month<<"月"<<account.GetDate().day<<"日"<<endl;
	}
}