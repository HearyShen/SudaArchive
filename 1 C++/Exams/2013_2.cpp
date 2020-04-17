/***************
	1427405017
	����S
	2013_2
	2015-6-3  8:56
***************/
//=============================================
// ������Ĳ��Գ���
//=============================================
#include <iostream>
#include <string>

using namespace std;

class CSerialPort
{
private:
	string Name;
	int Speed;
	int BufferLength;
	static int ComCounts;

public:
	CSerialPort(const string &name="com1", int speed=9600,int bufferlength=500);	//����Ĭ�ϲ���ֵ�Ĺ��캯��
	CSerialPort(const CSerialPort &A);		//�������캯��
	static int GetComCounts();		//��ȡ��ǰ���ڶ�������ľ�̬���ݳ�Ա�Ľӿں���
	CSerialPort& operator++();			//ǰ������������غ�������������ʵ�ֶԴ���ͨ����������1
	CSerialPort operator++(int);		//��������������غ�������������ʵ�ֶԴ���ͨ����������1
	friend ostream& operator<<(ostream &out,const CSerialPort &A);
	~CSerialPort();			//��������
};

int CSerialPort::ComCounts = 0;

CSerialPort::CSerialPort(const string &name, int speed,int bufferlength)	//����Ĭ�ϲ���ֵ�Ĺ��캯��
{
	Name = name;
	Speed = speed;
	BufferLength = bufferlength;

	ComCounts++;
}

CSerialPort::CSerialPort(const CSerialPort &A)		//�������캯��
{
	Name = A.Name;
	Speed = A.Speed;
	BufferLength = A.BufferLength;

	ComCounts++;
}

int CSerialPort::GetComCounts()		//��ȡ��ǰ���ڶ�������ľ�̬���ݳ�Ա�Ľӿں���
{
	return ComCounts;
}

CSerialPort& CSerialPort::operator++()		//ǰ������������غ�������������ʵ�ֶԴ���ͨ����������1
{
	Speed++;

	return *this;
}

CSerialPort CSerialPort::operator++(int)		//��������������غ�������������ʵ�ֶԴ���ͨ����������1
{
	CSerialPort Temp(*this);			//������ʱ�������ڷ���

	Speed++;

	return Temp;
}

ostream& operator<<(ostream &out,const CSerialPort &A)
{
	out<<"�������ƣ�"<<A.Name<<endl;
	out<<"����ͨ�����ʣ�"<<A.Speed<<endl;

	return out;
}

CSerialPort::~CSerialPort()		//��������
{
	ComCounts--;
}

int main()
{
	CSerialPort  portA;
	cout<<"����portAΪ: \n"<<portA;
	cout<<"��ǰ�����Ĵ��ڸ���Ϊ: "<<CSerialPort::GetComCounts()<<"\n"<<endl;
	
	CSerialPort portB("com5",4800, 1024);
	cout<<"����portBΪ: \n"<<portB;
	cout<<"��ǰ�����Ĵ��ڸ���Ϊ: "<<CSerialPort::GetComCounts()<<"\n"<<endl;
	
	++(++portB);    // ����ǰ��������
	cout<<"����ǰ�����󣬴���portBΪ: \n"<<portB;
	cout<<"��ǰ�����Ĵ��ڸ���Ϊ: "<<CSerialPort::GetComCounts()<<"\n"<<endl;

	cout<<"һ�κ������󣬴���portBΪ: \n"<<portB++;
	cout<<"һ�κ������󣬴���portBΪ: \n"<<portB;
	cout<<"��ǰ�����Ĵ��ڸ���Ϊ: "<<CSerialPort::GetComCounts()<<"\n"<<endl;

	CSerialPort  *ptr_portC = new CSerialPort;
	cout<<"����portCΪ:\n"<<*ptr_portC;
	cout<<"��ǰ�����Ĵ��ڸ���Ϊ: "<<CSerialPort::GetComCounts()<<"\n"<<endl;

	delete ptr_portC;
	cout<<"ɾ������portC�󣬵�ǰ�����Ĵ��ڸ���Ϊ: "<<CSerialPort::GetComCounts()<<"\n"<<endl;

	return 0;
}