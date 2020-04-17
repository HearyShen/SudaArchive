/*******************
	E13
	1427405017
	沈家赟
	2015-5-6  8:56
*******************/
#include <iostream>

using namespace std;

class CComplex			//定义复数类CComplex
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
	friend ostream& operator<<(ostream& out, const CComplex &C);		//重载<<
	friend CComplex operator+(const CComplex& A, const CComplex& B);	//重载+
	friend CComplex operator+(const CComplex& A, const double &B);		//重载+
	friend CComplex& operator++(CComplex& A);									//重载++A
	friend CComplex operator++(CComplex& A, int);								//重载A++
};

ostream& operator<<(ostream& out, const CComplex &C)		//重载<<
{
	out<<C.m_real<<"+"<<C.m_image<<"i";

	return out;
}

CComplex operator+(const CComplex& A, const CComplex& B)	//重载+
{
	CComplex T;

	T.m_real = A.m_real + B.m_real;
	T.m_image = A.m_image + B.m_image;

	return T;
}

CComplex operator+(const CComplex& A, const double &B)		//重载+
{
	CComplex T;

	T.m_real = A.m_real + B;
	T.m_image = A.m_image;

	return T;
}

CComplex& operator++(CComplex& A)									//重载++A
{
	A.m_real = A.m_real +1.0;
	A.m_image = A.m_image +1.0;

	return A;
}

CComplex operator++(CComplex& A, int)								//重载A++
{
	CComplex T;

	T.m_real = A.m_real;				//先准备好待返回的T
	T.m_image = A.m_image;

	A.m_real = A.m_real +1.0;		//再对A做自增
	A.m_image = A.m_image +1.0;

	return T;
}

void main()
{
	CComplex A,B;

	A.setValue(2.0,1.0);													//调用成员函数setValue
	B.setValue(3.0,2.0);
	cout<<"复数A为："<<A<<endl<<"复数B为："<<B<<endl;		//调用重载运算符<<

	cout<<"复数A+B为："<<A+B<<endl;								//调用重载运算符+
	cout<<"复数A+4.0为："<<A+4.0<<endl;

	cout<<"复数A++为："<<A++<<endl;								//调用重载运算符++
	cout<<"复数++A为："<<++A<<endl;
}