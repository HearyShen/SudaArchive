/*****************
	2014_3
	1427405017
	����S
	2015-6-17  9:12
******************/
#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

class CGoods
{
private:
	int m_num;	//��Ʒ���
	string m_name;	//��Ʒ����
	float m_price;	//��Ʒ�۸�

public:
	CGoods (int, const string&, float);
	friend ostream& operator<<(ostream&, const CGoods&);
	//��Ʒ���ơ���Ʒ��ź���Ʒ�۸����ʾ��ʽ��Ҫ��Ϊռ10�С��Ҷ���
};

CGoods::CGoods(int Num, const string& Name, float Price):m_name(Name)
{
	m_num = Num;
	m_price = Price;
}
ostream& operator<<(ostream& out, const CGoods& A)
{
	cout<<setw(10)<<A.m_name<<setw(10)<<A.m_num<<setw(10)<<A.m_price;

	return out;
}

class CRouter:public CGoods
{
private:
	float frequency;	//���ڱ�ʾ·�����ź�Ƶ�ʵı�����float����
	int channels;		//���ڱ�ʾ·�����˿������ı�����int����

public:
	CRouter(int Num=1, const string& Name="M8", float Price=100.0, float Frequency=2.4, int Channels=8);	//�вι��캯��
	int GetChannels();		//��ȡ·�����˿������ĳ�Ա����GetChannels
	float GetFrequency();	//��ȡ·�����ź�Ƶ�ʵĳ�Ա����GetFrequency
	friend CRouter& operator++(CRouter& A);	//ǰ������������غ�����ʵ�ֶ˿�������1�Ĳ���
	friend CRouter operator++(CRouter& A,int);	//��������������غ�����ʵ�ֶ˿�������1�Ĳ���
	friend ostream& operator<<(ostream& out, const CRouter& A);		//���������<<�����غ���

};

CRouter::CRouter(int Num, const string& Name, float Price, float Frequency, int Channels)	:CGoods(Num,Name,Price)//�вι��캯��
{
	frequency = Frequency;
	channels = Channels;
}
int CRouter::GetChannels()		//��ȡ·�����˿������ĳ�Ա����GetChannels
{
	return channels;
}
float CRouter::GetFrequency()	//��ȡ·�����ź�Ƶ�ʵĳ�Ա����GetFrequency
{
	return frequency;
}
CRouter& operator++(CRouter& A)	//ǰ������������غ�����ʵ�ֶ˿�������1�Ĳ���
{
	A.channels++;

	return A;
}
CRouter operator++(CRouter& A,int)	//��������������غ�����ʵ�ֶ˿�������1�Ĳ���
{
	CRouter T(A);

	A.channels++;

	return T;
}
ostream& operator<<(ostream& out, const CRouter& A)	//���������<<�����غ���
{
	cout<<(CGoods)A<<setw(10)<<A.frequency<<setw(10)<<A.channels;

	return out;
}

void ReadData(vector<CRouter> &s,const string FName)		//���ı��ļ��ж�ȡ����δ֪��·������Ʒ���ݣ�����һ������
{
	ifstream fin(FName);
	try
	{
		if(fin == NULL)
		{
			throw FName;
		}
	}
	catch(string FN)
	{
		cerr<<"�ļ�"<<FN<<"��ʧ�ܣ�"<<endl;
		exit(0);
	}

	int t_num;	//��Ʒ���
	string t_name;	//��Ʒ����
	float t_price;	//��Ʒ�۸�
	float t_frequency;	//���ڱ�ʾ·�����ź�Ƶ�ʵı�����float����
	int t_channels;		//���ڱ�ʾ·�����˿������ı�����int����

	for(string t_s; getline(fin,t_s);)		//file�� --> string
	{
		istringstream t_iss(t_s);			//string -->string��

		t_iss>>t_num>>t_name>>t_price>>t_frequency>>t_channels;		//string�� -->��������
		CRouter T(t_num,t_name,t_price,t_frequency,t_channels);			//������ʱ����
		s.push_back(T);		//������������
	}
	fin.close();
}

void DisplayData(const vector<CRouter>& s)		//��ʾ����������·������Ʒ����
{
	for(int i=0;i<s.size();i++)
	{
		cout<<s[i]<<endl;
	}
}

CRouter& FindMax(vector<CRouter>& s)		//���ҵ������С��˿��������ź�Ƶ�ʵĳ˻��������Ǹ�Ԫ��
{
	int max_inx = 0;
	for(int i=1;i<s.size();i++)
	{
		if(s[i].GetChannels()*s[i].GetFrequency() > s[max_inx].GetChannels()*s[max_inx].GetFrequency())
		{
			max_inx = i;
		}
	}

	return s[max_inx];
}

void main()
{
	vector<CRouter> s;

	ReadData(s,"D:\\Data.txt");
	cout<<"��ȡ��ɺ������Ϊ"<<endl;
	DisplayData(s);

	CRouter t;
	cout<<endl<<"·��������ĳ�ʼֵΪ"<<endl<<t<<endl;

	t=FindMax(s);
	cout<<endl<<"�˻���������Ԫ��Ϊ"<<endl<<t<<endl;

	cout<<endl<<"�˻���������Ԫ�ؽ��������������ֱ�����:"<<endl;
	cout<<t++<<endl;
	cout<<t<<endl;

	cout<<++t<<endl;
	cout<<t<<endl;
}
