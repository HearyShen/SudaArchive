/*******************
	E17
	1427405017
	����S
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
	//���ʱ��Ϸ�����ֵ������ֵ0 ʱ0 ��0 ��
	int SetTime(int hour=0,int minute=0,int second=0);
	//���ʱ��Ϸ�����ֵ������1�����򲻸�ֵ��������0
	int getHour();
	int getMinute();
	int getSecond();
	void ShowTime(bool flag);
	//flag ΪTrue ����24 Сʱ����ʾʱ�䣬������ AM PM �ķ�ʽ��ʾ
	//�Լ������Ƿ���Ҫ���������Ա����
};

class CDate
{
private:
	int m_year,m_month,m_day;
public:
	CDate(int year=2000,int month=1,int day=1);
	//������ںϷ�����ֵ������ֵ2000 ��1 ��1 ��
	int SetDate(int year=2000,int month=1,int day=1);
	//������ںϷ�����ֵ������1�����򲻸�ֵ��������0
	int GetYear();
	int GetMonth();
	int GetDay();
	void ShowDate(bool flag);
	//flag ΪTRUE���������ĵķ�ʽ��ʾ���ڣ�������MM/DD/YYYY �ķ�ʽ��ʾ����
	//�Լ������Ƿ���Ҫ���������Ա����
};

class CDateTime
{
private:
	CTime m_time;
	CDate m_date;
public:
	CDateTime():m_date(),m_time(){}
	CDateTime(const int &y,const int &m,const int &d,const int &hr,const int &min,const int &sec):m_date(y,m,d),m_time(hr,min,sec){}//��ӱ�Ҫ�Ĺ��캯��
	int SetDateTime(const int &y,const int &m,const int &d,const int &hr,const int &min,const int &sec);//int SetDateTime(...); �Լ���Ʋ��������Ǹú����ķ���ֵ���Ա�ʾȫ����ȷ�����ڲ��ԡ�ʱ�䲻�Ե����
	void ShowDateTime(const bool &Ch,const bool &Hr_24);//void ShowDateTime(...); �Լ���Ʋ��������ǿ����������ں��������ڸ�ʽ���Լ�24 Сʱ��AM PM �����Կ���
	int GetMonth();
	int GetMinute();//����Լ���Ϊ��Ҫ��������Ա����
};

CTime::CTime(int hour,int minute,int second)	//����CTime���캯��
{
	if(hour<0 || hour>24 || minute<0 || minute>60 || second<0 || second>60)		//�Ϸ����ж�
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
int CTime::SetTime(int hour,int minute,int second)	//����CTime��Ա����SetTime
{
	if(hour<0 || hour>24 || minute<0 || minute>60 || second<0 || second>60)		//�Ϸ����ж�
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
int CTime::getHour()		//����CTime��Ա����getHour
{
	return m_hour;
}
int CTime::getMinute()		//����CTime��Ա����getMinute
{
	return m_minute;
}
int CTime::getSecond()		//����CTime��Ա����getSecond
{
	return m_second;
}
void CTime::ShowTime(bool flag)		//����CTime��Ա����ShowTime
{
	if(flag)		//�棺24Сʱ��
	{
		cout<<m_hour<<':'<<m_minute<<':'<<m_second;
	}
	else			//�٣�12Сʱ��
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

CDate::CDate(int year,int month,int day)		//����CDate�๹�캯��
{
	int flag;

	flag=1;
	if(year%4==0 && year%100!=0 || year%400==0)		//����Ϸ����ж�
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
	else		//ƽ��Ϸ����ж�
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
		m_year=year;		//��ֵ
		m_month=month;
		m_day=day;
	}
	else
	{
		m_year=2000;		//��Ĭ��ֵ
		m_month=1;
		m_day=1;
	}

}
int CDate::SetDate(int year,int month,int day)		//����CDate���Ա����SetDate
{
	if(year%4==0 && year%100!=0 || year%400==0)		//����Ϸ����ж�
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
	else		//ƽ��Ϸ����ж�
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

	m_year=year;		//��ֵ
	m_month=month;
	m_day=day;

	return 1;
}
int CDate::GetYear()		//����CDate���Ա����GetYear
{
	return m_year;
}
int CDate::GetMonth()		//����CDate���Ա����GetMonth
{
	return m_month;
}
int CDate::GetDay()		//����CDate���Ա����GetDay
{
	return m_day;
}
void CDate::ShowDate(bool flag)		//����CDate���Ա����ShowDate
{
	if(flag)		//�棺���ĸ�ʽ��ʾ
	{
		cout<<m_year<<"��"<<m_month<<"��"<<m_day<<"��"<<'\t';
	}
	else			//�٣�Ӣ�ĸ�ʽ��ʾ
	{
		cout<<"month:"<<m_month<<" day:"<<m_day<<" year:"<<m_year<<'\t';
	}
}

int CDateTime::SetDateTime(const int &y,const int &m,const int &d,const int &hr,const int &min,const int &sec)	//����CDateTime���Ա����SetDateTime
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
void CDateTime::ShowDateTime(const bool &Ch,const bool &Hr_24)		//����CDateTime���Ա����ShowDateTime
{
	m_date.ShowDate(Ch);
	m_time.ShowTime(Hr_24);
	cout<<endl;
}
int CDateTime::GetMonth()		//����CDateTime���Ա����GetMonth
{
	return m_date.GetMonth();
}
int CDateTime::GetMinute()		//����CDateTime���Ա����GetMinute
{
	return m_time.getMinute();
}

void main()
{
	CDateTime d1(2014, 5, 2, 27, 12, 5);
	d1.ShowDateTime(false, true); //��1��������ʾ��Ӣ�ķ�ʽ��ʾ����, ��2��������ʾ��24Сʱ�Ʒ�ʽ��ʾʱ��

	CDateTime d2;
	d2.ShowDateTime(true, false); //��1��������ʾ�����ķ�ʽ��ʾ����, ��2��������ʾ��AM PM�ķ�ʽ��ʾʱ��
	
	int iStatus;
	iStatus=d2.SetDateTime(2014, 5, 2, 21, 55, 5);
	switch(iStatus)
	{
	case 1:
		cout<<"���ں�ʱ������������ȷ!"<<endl;
		break;
	case -1:
		cout<<"�����������ò���ȷ!"<<endl;
		break;
	case -2:
		cout<<"ʱ���������ò���ȷ!"<<endl;
		break;
	}
	d2.ShowDateTime(false, false); //��1��������ʾ��Ӣ�ķ�ʽ��ʾ����, ��2��������ʾ��AM PM�ķ�ʽ��ʾʱ��
	
	cout<<"��="<<d2.GetMonth()<<endl; //���濼��һ�����ʵ�ִ˲�����
	cout<<"����="<<d2.GetMinute()<<endl; //���濼��һ�����ʵ�ִ˲�����
}