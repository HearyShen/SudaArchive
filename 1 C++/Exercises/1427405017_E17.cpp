/*******************
	E17
	1427405017
	沈家赟
	2015-5-17  20:52
*******************/
#include <iostream>
#include <cmath>

using namespace std;

class CTime
{
private:
	int m_hour,m_minute,m_second;
public:
	CTime(int hour=0,int minute=0,int second=0);
	//如果时间合法，则赋值，否则赋值0 时0 分0 秒
	int SetTime(int hour=0,int minute=0,int second=0);
	//如果时间合法，则赋值并返回1，否则不赋值，并返回0
	int getHour();
	int getMinute();
	int getSecond();
	void ShowTime(bool flag);
	//flag 为True 则以24 小时制显示时间，否则以 AM PM 的方式显示
	//自己考虑是否需要添加其他成员函数
};

class CDate
{
private:
	int m_year,m_month,m_day;
public:
	CDate(int year=2000,int month=1,int day=1);
	//如果日期合法，则赋值，否则赋值2000 年1 月1 日
	int SetDate(int year=2000,int month=1,int day=1);
	//如果日期合法，则赋值并返回1，否则不赋值，并返回0
	int GetYear();
	int GetMonth();
	int GetDay();
	void ShowDate(bool flag);
	//flag 为TRUE，则以中文的方式显示日期，否则以MM/DD/YYYY 的方式显示日期
	//自己考虑是否需要添加其他成员函数
};

class CDateTime
{
private:
	CTime m_time;
	CDate m_date;
public:
	CDateTime():m_date(),m_time(){}
	CDateTime(const int &y,const int &m,const int &d,const int &hr,const int &min,const int &sec):m_date(y,m,d),m_time(hr,min,sec){}//添加必要的构造函数
	int SetDateTime(const int &y,const int &m,const int &d,const int &hr,const int &min,const int &sec);//int SetDateTime(...); 自己设计参数，考虑该函数的返回值加以表示全部正确、日期不对、时间不对等情况
	void ShowDateTime(const bool &Ch,const bool &Hr_24);//void ShowDateTime(...); 自己设计参数，考虑可以中文日期和西文日期格式，以及24 小时和AM PM 都可以控制
	int GetMonth();
	int GetMinute();//添加自己认为必要的其他成员函数
};

CTime::CTime(int hour,int minute,int second)	//定义CTime构造函数
{
	if(hour<0 || hour>24 || minute<0 || minute>60 || second<0 || second>60)		//合法性判断
	{
		m_hour=0;
		m_minute=0;
		m_second=0;
	}
	else
	{
		m_hour=hour;
		m_minute=minute;
		m_second=second;
	}
}
int CTime::SetTime(int hour,int minute,int second)	//定义CTime成员函数SetTime
{
	if(hour<0 || hour>24 || minute<0 || minute>60 || second<0 || second>60)		//合法性判断
	{
		return 0;
	}
	else
	{
		m_hour=hour;
		m_minute=minute;
		m_second=second;
		return 1;
	}
}
int CTime::getHour()		//定义CTime成员函数getHour
{
	return m_hour;
}
int CTime::getMinute()		//定义CTime成员函数getMinute
{
	return m_minute;
}
int CTime::getSecond()		//定义CTime成员函数getSecond
{
	return m_second;
}
void CTime::ShowTime(bool flag)		//定义CTime成员函数ShowTime
{
	if(flag)		//真：24小时制
	{
		cout<<m_hour<<':'<<m_minute<<':'<<m_second;
	}
	else			//假：12小时制
	{
		if(m_hour<13)
		{
			cout<<m_hour<<':'<<m_minute<<':'<<m_second<<" AM";
		}
		else
		{
			cout<<m_hour-12<<":"<<m_minute<<':'<<m_second<<" PM";
		}
	}
}

CDate::CDate(int year,int month,int day)		//定义CDate类构造函数
{
	int flag;

	flag=1;
	if(year%4==0 && year%100!=0 || year%400==0)		//闰年合法性判断
	{
		if(month<1 || month>12)
		{
			flag=0;
		}
		else if(month==1 || month==3 || month==5 || month==7 || month==8 || month==10 || month==12)
		{
			if(day<1 || day>31)
			{
				flag=0;
			}
		}
		else if(month==2)
		{
			if(day != 29)
			{
				flag=0;
			}
		}
		else
		{
			if(day<1 || day>30)
			{
				flag=0;
			}
		}
	}
	else		//平年合法性判断
	{
		if(month<1 || month>12)
		{
			flag=0;
		}
		else if(month==1 || month==3 || month==5 || month==7 || month==8 || month==10 || month==12)
		{
			if(day<1 || day>31)
			{
				flag=0;
			}
		}
		else if(month==2)
		{
			if(day != 28)
			{
				flag=0;
			}
		}
		else
		{
			if(day<1 || day>30)
			{
				flag=0;
			}
		}
	}

	if(flag == 1)
	{
		m_year=year;		//赋值
		m_month=month;
		m_day=day;
	}
	else
	{
		m_year=2000;		//赋默认值
		m_month=1;
		m_day=1;
	}

}
int CDate::SetDate(int year,int month,int day)		//定义CDate类成员函数SetDate
{
	if(year%4==0 && year%100!=0 || year%400==0)		//闰年合法性判断
	{
		if(month<1 || month>12)
		{
			return 0;
		}
		else if(month==1 || month==3 || month==5 || month==7 || month==8 || month==10 || month==12)
		{
			if(day<1 || day>31)
			{
				return 0;
			}
		}
		else if(month==2)
		{
			if(day != 29)
			{
				return 0;
			}
		}
		else
		{
			if(day<1 || day>30)
			{
				return 0;
			}
		}
	}
	else		//平年合法性判断
	{
		if(month<1 || month>12)
		{
			return 0;
		}
		else if(month==1 || month==3 || month==5 || month==7 || month==8 || month==10 || month==12)
		{
			if(day<1 || day>31)
			{
				return 0;
			}
		}
		else if(month==2)
		{
			if(day != 28)
			{
				return 0;
			}
		}
		else
		{
			if(day<1 || day>30)
			{
				return 0;
			}
		}
	}

	m_year=year;		//赋值
	m_month=month;
	m_day=day;

	return 1;
}
int CDate::GetYear()		//定义CDate类成员函数GetYear
{
	return m_year;
}
int CDate::GetMonth()		//定义CDate类成员函数GetMonth
{
	return m_month;
}
int CDate::GetDay()		//定义CDate类成员函数GetDay
{
	return m_day;
}
void CDate::ShowDate(bool flag)		//定义CDate类成员函数ShowDate
{
	if(flag)		//真：中文格式显示
	{
		cout<<m_year<<"年"<<m_month<<"月"<<m_day<<"日"<<'\t';
	}
	else			//假：英文格式显示
	{
		cout<<"month:"<<m_month<<" day:"<<m_day<<" year:"<<m_year<<'\t';
	}
}

int CDateTime::SetDateTime(const int &y,const int &m,const int &d,const int &hr,const int &min,const int &sec)	//定义CDateTime类成员函数SetDateTime
{
	if( m_date.SetDate(y,m,d) == 0)
	{
		return -1;
	}
	if( m_time.SetTime(hr,min,sec) == 0)
	{
		return -2;
	}

	return 1;
}
void CDateTime::ShowDateTime(const bool &Ch,const bool &Hr_24)		//定义CDateTime类成员函数ShowDateTime
{
	m_date.ShowDate(Ch);
	m_time.ShowTime(Hr_24);
	cout<<endl;
}
int CDateTime::GetMonth()		//定义CDateTime类成员函数GetMonth
{
	return m_date.GetMonth();
}
int CDateTime::GetMinute()		//定义CDateTime类成员函数GetMinute
{
	return m_time.getMinute();
}

void main()
{
	CDateTime d1(2014, 5, 2, 27, 12, 5);
	d1.ShowDateTime(false, true); //第1个参数表示以英文方式显示日期, 第2个参数表示以24小时制方式显示时间

	CDateTime d2;
	d2.ShowDateTime(true, false); //第1个参数表示以中文方式显示日期, 第2个参数表示以AM PM的方式显示时间
	
	int iStatus;
	iStatus=d2.SetDateTime(2014, 5, 2, 21, 55, 5);
	switch(iStatus)
	{
	case 1:
		cout<<"日期和时间数据设置正确!"<<endl;
		break;
	case -1:
		cout<<"日期数据设置不正确!"<<endl;
		break;
	case -2:
		cout<<"时间数据设置不正确!"<<endl;
		break;
	}
	d2.ShowDateTime(false, false); //第1个参数表示以英文方式显示日期, 第2个参数表示以AM PM的方式显示时间
	
	cout<<"月="<<d2.GetMonth()<<endl; //认真考虑一下如何实现此操作？
	cout<<"分钟="<<d2.GetMinute()<<endl; //认真考虑一下如何实现此操作？
}