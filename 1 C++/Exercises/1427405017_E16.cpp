/*******************
	E16
	1427405017
	����S
	2015-5-10  11:09
*******************/
#include <iostream>
#include <cmath>

using namespace std;

class CPoint
{
private:
	int m_x; //���X����
	int m_y; //���Y����
public:
	CPoint()
	{
		m_x=0;
		m_y=0;
	}
	CPoint (int x,int y)
	{
		m_x=x;
		m_y=y;
	}
	int getx()
	{
		return m_x;
	}
	int gety()
	{
		return m_y;
	}
	void showPoint()
	{
		cout<<"("<<this->m_x<<","<<this->m_y<<")"<<endl;
	}
};

class CLine
{
private:
	CPoint m_point1;
	CPoint m_point2;
public:
	CLine();
	CLine(const int &p1_x,const int &p1_y,const int &p2_x,const int &p2_y);
	void ShowLine();
	double distance();
};

CLine::CLine()				//�ṩ�޲ι��캯��
{
}

CLine::CLine(const int &p1_x,const int &p1_y,const int &p2_x,const int &p2_y):m_point1(p1_x,p1_y),m_point2(p2_x,p2_y)	//ð���﷨��ʼ�����Ա
{
}

void CLine::ShowLine()		//��ʾ�߶����˵��Ա����
{
	cout<<"Point 1 is:";
	m_point1.showPoint();
	cout<<"Point 2 is:";
	m_point2.showPoint();
}

double CLine::distance()	//��ʾ�߶γ��ȳ�Ա����
{
	double tmp;

	tmp = pow(m_point1.getx()-m_point2.getx(),2.0) + pow(m_point1.gety()-m_point2.gety(),2.0);
	return sqrt(tmp);
}
void main()
{
	CLine line1;
	line1.ShowLine();
	cout<<"Length="<<line1.distance()<<endl;

	CLine line2(1,1,5,5);
	line2.ShowLine();
	cout<<"Length="<<line2.distance()<<endl;
}