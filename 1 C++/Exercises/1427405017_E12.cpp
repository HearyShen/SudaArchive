/************************
	E12
	1427405017
	����S
	2015-4-26 22:43
*************************/

/*�޸ģ�LendMoney������������ڲ����Լ��޸ķ���ֵ����Ϊdouble
*		CalcInterest��������ӽ������Ա�LendMoney��������
*		������������ȡ������������Ϣ���������ʱ���޸�
*/

#include<iostream>
using namespace std;

//����
struct Date
{
	int year;	//��
	int month;	//��
	int day;	//��

	Date(){}
	Date(int y, int m, int d)
	{
		year = y;
		month = m;
		day = d;
	}
};
//�˻���
class CAount
{
private:
	double m_Money;	//���
	Date m_Date;	//�������
	static double m_InterestRate;	//������

	int NumOfDays(const Date &date) const;	//�����������ڲ��������

public:
	static void SetInterestRate(double interest);	//����������
	static double GetInterestRate();				//��ȡ������
	
	void SaveMoney(double money, const Date &date);	//����
	double LendMoney(const Date &date, double money);			//ȡ���
	double CalcInterest(const Date &date, double money) const;	//������Ϣ
	void SaveInterest(const Date &date);			//������Ϣ
	
	double GetBalance();	//��ȡ���
	Date GetDate();			//��ȡ�������
};

double CAount::m_InterestRate = 0;

void CAount::SetInterestRate(double interest)	//����������
{
	m_InterestRate = interest;
}
double CAount::GetInterestRate()				//��ȡ������
{
	return m_InterestRate;
}

void CAount::SaveMoney(double money, const Date &date)	//����
{
	if(date.month>=1 && date.month<=12 && date.day>=1 && date.day<=30)		//�Դ�����ڽ��кϷ����ж�
	{
		m_Money =  money;

		m_Date.year = date.year;
		m_Date.month = date.month;
		m_Date.day = date.day;
	}
	else
	{
		cout<<"���ڣ���/��/�գ�����"<<endl;
	}
}
double CAount::LendMoney(const Date &date, double money)			//ȡ���
{
	double interest;

	if((m_Money - money) >= 0)		//��ȡ���Ƚ��кϷ����ж�
	{
		m_Money = m_Money - money;
		interest = CalcInterest(date,money);	//ȡ��ɹ�����ͬʱ�����ȡ����Ӧ����Ϣ

		return money + interest;
	}
	else
	{
		return -1;						//ȡ�������ͷ��ظ���
	}
}

double CAount::CalcInterest(const Date &date, double money)const	//������Ϣ
{
	int days;

	days = (date.year-m_Date.year)*360 + (date.month-m_Date.month)*30 + (date.day-m_Date.day);			//�����ۼ����������������ͷ����β��

	return (money*m_InterestRate/360)*days;
}

void CAount::SaveInterest(const Date &date)			//������Ϣ
{
	int days;

	if(date.month>=1 && date.month<=12 && date.day>=1 && date.day<=30)		//�Դ�����ڽ��кϷ����ж�
	{
		days = (date.year-m_Date.year)*360 + (date.month-m_Date.month)*30 + (date.day-m_Date.day);
		m_Money = m_Money + (m_Money*m_InterestRate/360)*days;

		m_Date.year = date.year;						//������ɾ�ˢ������
		m_Date.month = date.month;
		m_Date.day = date.day;
	}
	else
	{
		cout<<"���ڣ���/��/�գ�����"<<endl;
	}
}

double CAount::GetBalance()		//��ȡ���
{
	return m_Money;
}

Date CAount::GetDate()			//��ȡ�������
{
	return m_Date;
}

void main()
{
	double lendMoney;
	CAount account;

	CAount::SetInterestRate(0.036);//����������
	account.SaveMoney(200000.0, Date(2015, 4, 22));//���

	//���������
	cout<<"���õ�������Ϊ��"<<CAount::GetInterestRate()<<endl;
	cout<<endl;
	//ȡ��
	cout<<"ȡ��210000Ԫ��"<<endl;
	if ((lendMoney = account.LendMoney(Date(2015, 4, 22), 210000.0)) < 0)
	{
		cout<<"���㣡"<<endl;
	}
	else
	{
		cout<<"ȡ��ɹ���"<<endl;
	}
	cout<<endl;
	//��Ϣ���������
	cout<<"��2016��6��1�գ���ϢΪ��"<<account.CalcInterest(Date(2016, 6, 1), account.GetBalance())<<"Ԫ"<<endl;
	account.SaveInterest(Date(2016, 6, 1));
	//ȡ��
	cout<<"2016��12��1��ȡ��100000Ԫ��"<<endl;
	if ((lendMoney = account.LendMoney(Date(2016, 12, 1), 100000.0)) < 0)
	{
		cout<<"���㣡"<<endl;
	}
	else
	{
		cout<<"ȡ��ɹ���"<<endl;
		cout<<"��ȡ���Ľ��Ϊ��"<<lendMoney<<"Ԫ"<<endl;
		cout<<"�������Ϊ��"<<account.GetBalance()<<"Ԫ"<<endl;
		cout<<"������ڣ����ϴ���Ϣ�������ڣ�Ϊ��"<<account.GetDate().year<<"��"
			<<account.GetDate().month<<"��"<<account.GetDate().day<<"��"<<endl;
	}
}