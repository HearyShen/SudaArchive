/*******************
	E13
	1427405017
	����S
	2015-5-6  8:56
*******************/
#include <iostream>

using namespace std;

class CComplex			//���帴����CComplex
{
private:
	double m_real;
	double m_image;
public:
	void setValue(double real,double image)
	{
		m_real = real;
		m_image = image;
	}
	friend ostream& operator<<(ostream& out, const CComplex &C);		//����<<
	friend CComplex operator+(const CComplex& A, const CComplex& B);	//����+
	friend CComplex operator+(const CComplex& A, const double &B);		//����+
	friend CComplex& operator++(CComplex& A);									//����++A
	friend CComplex operator++(CComplex& A, int);								//����A++
};

ostream& operator<<(ostream& out, const CComplex &C)		//����<<
{
	out<<C.m_real<<"+"<<C.m_image<<"i";

	return out;
}

CComplex operator+(const CComplex& A, const CComplex& B)	//����+
{
	CComplex T;

	T.m_real = A.m_real + B.m_real;
	T.m_image = A.m_image + B.m_image;

	return T;
}

CComplex operator+(const CComplex& A, const double &B)		//����+
{
	CComplex T;

	T.m_real = A.m_real + B;
	T.m_image = A.m_image;

	return T;
}

CComplex& operator++(CComplex& A)									//����++A
{
	A.m_real = A.m_real +1.0;
	A.m_image = A.m_image +1.0;

	return A;
}

CComplex operator++(CComplex& A, int)								//����A++
{
	CComplex T;

	T.m_real = A.m_real;				//��׼���ô����ص�T
	T.m_image = A.m_image;

	A.m_real = A.m_real +1.0;		//�ٶ�A������
	A.m_image = A.m_image +1.0;

	return T;
}

void main()
{
	CComplex A,B;

	A.setValue(2.0,1.0);													//���ó�Ա����setValue
	B.setValue(3.0,2.0);
	cout<<"����AΪ��"<<A<<endl<<"����BΪ��"<<B<<endl;		//�������������<<

	cout<<"����A+BΪ��"<<A+B<<endl;								//�������������+
	cout<<"����A+4.0Ϊ��"<<A+4.0<<endl;

	cout<<"����A++Ϊ��"<<A++<<endl;								//�������������++
	cout<<"����++AΪ��"<<++A<<endl;
}