/*****************
	E19
	1427405017
	����S
	2015-5-20 9:20
******************/
#include <iostream>

using namespace std;

class CRmb
{
private:
	int yuan;
	int jiao;
	int fen;
public:
	CRmb(){yuan=0; jiao=0; fen=0;}
	CRmb(int ,int ,int );		//�������Ŀ������캯��
	CRmb(const CRmb &);		//�������캯��
	CRmb(double );			//����ת�����캯������һ��ʵ������ת��Ϊ����Ҷ���
	~CRmb();					//��������
	friend ostream & operator<<(ostream& out, const CRmb &);		//����Ļ�����Rmb��ֵ
	friend CRmb& operator++(CRmb &A);			//ǰ����
	friend CRmb operator++(CRmb &A, int);		//������
	friend CRmb operator+(const CRmb &A, const CRmb &B);		//�Ӻ�
	friend CRmb operator+(const CRmb &A, const double &B);	//�Ӻ�
};

CRmb::CRmb(int Yuan, int Jiao, int Fen)		//�������Ŀ������캯��
{
	yuan = Yuan;
	jiao = Jiao;
	fen = Fen;
}
CRmb::CRmb(const CRmb &A)				//�������캯��
{
	yuan = A.yuan;
	jiao = A.jiao;
	fen = A.fen;
}
CRmb::CRmb(double A)						//����ת�����캯������һ��ʵ������ת��Ϊ����Ҷ���
{
	yuan = (int)A;
	jiao = (int)(A-yuan)*10;
	fen = (int)(A-yuan-0.1*jiao)*100;
}
CRmb::~CRmb()								//��������
{
	cout<<"�������������ã�"<<endl;
}
ostream & operator<<(ostream& out, const CRmb &A)		//����Ļ�����Rmb��ֵ
{
	out<<"�����У�"<<A.yuan<<"Ԫ"<<A.jiao<<"��"<<A.fen<<"��"<<endl;

	return out;
}
CRmb& operator++(CRmb &A)			//ǰ����
{
	A.fen++;

	if(A.fen >= 10)			//�֣���ʮ��һ
	{
		A.jiao++;
		A.fen=A.fen-10;
	}
	if(A.jiao >= 10)		//�ǣ���ʮ��һ
	{
		A.yuan++;
		A.jiao = A.jiao - 10;
	}

	return A;
}
CRmb operator++(CRmb &A, int)		//������
{
	CRmb T(A);

	++A;				//����ǰ�������޸�A��ֵ

	return T;
}
CRmb operator+(const CRmb &A, const CRmb &B)			//�Ӻ�
{
	CRmb T;

	T.yuan = A.yuan + B.yuan;
	T.jiao = A.jiao + B.jiao;
	T.fen = A.fen + B.fen;

	if(T.fen >= 10)				//�֣���ʮ��һ
	{
		T.jiao++;
		T.fen = T.fen - 10;
	}
	if(T.jiao >= 10)			//�֣���ʮ��һ
	{
		T.yuan++;
		T.jiao = T.jiao - 10;
	}

	return T;
}
CRmb operator+(const CRmb &A, const double &B)			//�Ӻ�
{
	CRmb T;
	CRmb T_B(B);				//��doubleתΪCRmb����

	T = A + T_B;				//���ö���ӷ�

	return T;
}

void fn(const CRmb& x)
{
	cout<<"ln fn: "<<x<<endl;
}

void main()
{
	CRmb m1;
	cout<<m1<<endl<<endl<<endl;

	CRmb m2(1001,9,9);
	m2++;
	cout<<m2<<endl;
	++m2;
	cout<<m2<<endl<<endl<<endl;

	CRmb m3(m2);
	cout<<m3<<endl<<endl<<endl;

	CRmb m4=m1+m2;
	cout<<m4<<endl;
	m4=m1+50.0;
	cout<<m4<<endl<<endl<<endl;

	fn(50.13);
}