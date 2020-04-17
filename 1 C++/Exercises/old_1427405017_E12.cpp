/*********************
	E12
	1427405017
	����S
	2015-4-22 10:32
*********************/
#include <iostream>

using namespace std;

class CAount			//����CAount��
{
private:
	double m_Money;
	int year,month,day;
	static double m_InterestRate;
public:
	static void SetInterestRate(const double Interest);		//������̬��Ա�������������ʣ�
	static double GetInterestRate();						//������̬��Ա��������ȡ���ʣ�
	bool SaveMoney(const double &Money,const int &Year,const int &Month,const int &Day);		//������Ա��������
	bool LendMoney(const double &Money,const int &Year,const int &Month,const int &Day);		//������Ա������ȡ�
	double CalcInterest(const int &Year,const int &Month,const int &Day);						//������Ա������������Ϣ��
	double CalcInterest(const double &Money,const int &Year,const int &Month,const int &Day);	//�������س�Ա���������㶨����Ϣ��
	bool SaveInterest(const int &Year,const int &Month,const int &Day);							//������Ա������������Ϣ��
	bool SaveInterest(const double &Money,const int &Year,const int &Month,const int &Day);		//������Ա���������㶨����Ϣ��
	void Print()const;																			//��������Ա��������ʾ�˻���Ϣ��
};

double CAount::m_InterestRate = 0;		//��̬��Աm_InterestRate����ֵ

/****************************��Ա����������************************************/
void CAount::SetInterestRate(const double Interest)		//���徲̬��Ա�������������ʣ�
{
	m_InterestRate = Interest;
}
double CAount::GetInterestRate()						//���徲̬��Ա��������ȡ���ʣ�
{
	return m_InterestRate;
}

bool CAount::SaveMoney(const double &Money,const int &Year,const int &Month,const int &Day)		//�����Ա��������
{
	if(Month>=1 && Month<=12 && Day>=1 && Day<=30)		//�Դ�����ڽ��кϷ����ж�
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
bool CAount::LendMoney(const double &Money,const int &Year,const int &Month,const int &Day)		//�����Ա������ȡ�
{
	if((m_Money - Money) >= 0)		//��ȡ���Ƚ��кϷ����ж�
	{
		m_Money = m_Money - Money;
		return true;
	}
	else
	{
		return false;
	}
}

double CAount::CalcInterest(const int &Year,const int &Month,const int &Day)		//�����Ա������������Ϣ��
{
	int days;

	days = (Year-year)*360 + (Month-month)*30 + (Day-day+1);			//�����ۼ�����������Ҳ�����ڣ�

	return (m_Money*m_InterestRate/360)*days;
}
double CAount::CalcInterest(const double &Money,const int &Year,const int &Month,const int &Day)	//�������س�Ա���������㶨����Ϣ��
{
	int days;

	days = (Year-year)*360 + (Month-month)*30 + (Day-day+1);			//�����ۼ�����������Ҳ�����ڣ�

	return (Money*m_InterestRate/360)*days;
}

bool CAount::SaveInterest(const int &Year,const int &Month,const int &Day)		//�����Ա������������Ϣ��
{
	int days;

	if(Month>=1 && Month<=12 && Day>=1 && Day<=30)						//�Դ�����ڽ��кϷ����ж�
	{
		days = (Year-year)*360 + (Month-month)*30 + (Day-day+1);
		m_Money = m_Money + (m_Money*m_InterestRate/360)*days;

		year = Year;							//����������Ϣ���������ô������
		month = Month;
		day = Day;

		return true;
	}
	else
	{
		return false;
	}
}
bool CAount::SaveInterest(const double &Money,const int &Year,const int &Month,const int &Day)		//�����Ա���������㶨����Ϣ��
{
	int days;

	if(Month>=1 && Month<=12 && Day>=1 && Day<=30)		//�Դ�����ڽ��кϷ����ж�
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

void CAount::Print()const							//���峣��Ա��������ʾ�˻���Ϣ��
{
	cout<<"��ǰ��"<<m_Money<<endl;
	cout<<"�������Ϊ��"<<year<<"��"<<month<<"��"<<day<<"��"<<endl;
}
/****************************��Ա��������ֹ************************************/

void main()
{
	/*******************�����������ȡ*********************/
	CAount User;
	cout<<"��������Ϊ0.036��"<<endl;
	CAount::SetInterestRate(0.036);
	cout<<"��ǰ����Ϊ��"<<CAount::GetInterestRate()<<endl;
	cout<<endl;
	
	/*******************2014-1-1 ���*********************/
	cout<<"2014-1-1 ���100000"<<endl;
	User.SaveMoney(100000.0,2014,1,1);
	User.Print();
	cout<<endl;

	/*******************2014-3-10 ������Ϣ*********************/
	cout<<"��ֹ2014-3-10������һ�ڻ�����ϢΪ��"<<User.CalcInterest(2014,3,10)<<endl;
	User.SaveInterest(2014,3,10);
	User.Print();
	cout<<endl;

	/*******************2014-3-30 ȡ��200000*********************/
	cout<<"2014-3-30 ȡ��200000"<<endl;
	if(User.LendMoney(200000.0,2014,3,30))
	{
		cout<<"ȡ��ɹ���"<<endl;
	}
	else
	{
		cout<<"ȡ��ʧ�ܣ�"<<endl;
	}
	User.Print();
	cout<<endl;

	/*******************2014-4-4 ȡ��50000*********************/
	cout<<"2014-4-4 ȡ��50000"<<endl;
	if(User.LendMoney(50000.0,2014,4,4))
	{
		cout<<"ȡ��ɹ���"<<endl;
		cout<<"��ֹ2014-4-4������һ�ڻ�����ϢΪ��"<<User.CalcInterest(50000.0,2014,4,4)<<endl;
		User.SaveInterest(50000.0,2014,4,4);
	}
	else
	{
		cout<<"ȡ��ʧ�ܣ�"<<endl;
	}
	User.Print();
	cout<<endl;
}