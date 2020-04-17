/*****************
	E19
	1427405017
	沈家赟
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
	CRmb(int ,int ,int );		//带参数的拷贝构造函数
	CRmb(const CRmb &);		//拷贝构造函数
	CRmb(double );			//类型转换构造函数，将一个实型数据转换为人民币对象
	~CRmb();					//析构函数
	friend ostream & operator<<(ostream& out, const CRmb &);		//在屏幕上输出Rmb的值
	friend CRmb& operator++(CRmb &A);			//前自增
	friend CRmb operator++(CRmb &A, int);		//后自增
	friend CRmb operator+(const CRmb &A, const CRmb &B);		//加号
	friend CRmb operator+(const CRmb &A, const double &B);	//加号
};

CRmb::CRmb(int Yuan, int Jiao, int Fen)		//带参数的拷贝构造函数
{
	yuan = Yuan;
	jiao = Jiao;
	fen = Fen;
}
CRmb::CRmb(const CRmb &A)				//拷贝构造函数
{
	yuan = A.yuan;
	jiao = A.jiao;
	fen = A.fen;
}
CRmb::CRmb(double A)						//类型转换构造函数，将一个实型数据转换为人民币对象
{
	yuan = (int)A;
	jiao = (int)(A-yuan)*10;
	fen = (int)(A-yuan-0.1*jiao)*100;
}
CRmb::~CRmb()								//析构函数
{
	cout<<"析构函数被调用！"<<endl;
}
ostream & operator<<(ostream& out, const CRmb &A)		//在屏幕上输出Rmb的值
{
	out<<"现在有："<<A.yuan<<"元"<<A.jiao<<"角"<<A.fen<<"分"<<endl;

	return out;
}
CRmb& operator++(CRmb &A)			//前自增
{
	A.fen++;

	if(A.fen >= 10)			//分，逢十进一
	{
		A.jiao++;
		A.fen=A.fen-10;
	}
	if(A.jiao >= 10)		//角，逢十进一
	{
		A.yuan++;
		A.jiao = A.jiao - 10;
	}

	return A;
}
CRmb operator++(CRmb &A, int)		//后自增
{
	CRmb T(A);

	++A;				//调用前自增，修改A的值

	return T;
}
CRmb operator+(const CRmb &A, const CRmb &B)			//加号
{
	CRmb T;

	T.yuan = A.yuan + B.yuan;
	T.jiao = A.jiao + B.jiao;
	T.fen = A.fen + B.fen;

	if(T.fen >= 10)				//分，逢十进一
	{
		T.jiao++;
		T.fen = T.fen - 10;
	}
	if(T.jiao >= 10)			//分，逢十进一
	{
		T.yuan++;
		T.jiao = T.jiao - 10;
	}

	return T;
}
CRmb operator+(const CRmb &A, const double &B)			//加号
{
	CRmb T;
	CRmb T_B(B);				//把double转为CRmb对象

	T = A + T_B;				//调用对象加法

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