/************************
	E11
	1427405017
	沈家赟
	2015-4-19 19:44
*************************/
#include <iostream>
#include <cmath>
#include <string>

#define PI 3.1415926

using namespace std;

class Circle				//定义类Circle
{
private:					//私有成员
	double x,y,r;
public:						//公开成员函数
	void Set(double X,double Y,double R);
	double Area()const;
	double Perimeter()const;
	double Radius()const;
	/************************友元函数********************************/
	friend Circle operator+(const Circle& A,const Circle& B);
	friend Circle operator-(const Circle& A,const Circle& B);
	friend Circle& operator++(Circle& A);
	friend Circle operator++(Circle& A,int);
	friend Circle& operator--(Circle& A);
	friend Circle operator--(Circle& A,int);
	friend ostream& operator<<(ostream& out,const Circle &A);
	friend bool operator>(const Circle& A,const Circle& B);
	friend bool operator<(const Circle& A,const Circle& B);
	friend bool operator==(const Circle& A,const Circle& B);
	friend bool operator!=(const Circle& A,const Circle& B);
	friend bool operator&(const Circle& A,const Circle& B);
	friend string operator|(const Circle& A,const Circle& B);
	friend bool move(Circle& A,Circle& B);
	friend double print_distance(const Circle& A,const Circle& B);
};							//结尾须有封号

/***********************成员函数定义开始*******************************/
void Circle::Set(double X,double Y,double R)	//定义成员函数Set
{
	x=X;
	y=Y;
	r=R;
}

double Circle::Area()const		//定义成员函数Area
{
	return PI*r*r;
}

double Circle::Perimeter()const	//定义成员函数Perimeter
{
	return 2*PI*r;
}

double Circle::Radius()const	//定义成员函数Radius
{
	return r;
}
/***********************成员函数定义结束*******************************/

/***********************友元函数定义开始*******************************/
Circle operator+(const Circle& A,const Circle& B)	//重载操作符+
{
	Circle Res;

	Res.x=A.x;
	Res.y=A.y;
	Res.r=A.r+B.r;

	return Res;
}
Circle operator-(const Circle& A,const Circle& B)	//重载操作符-
{
	Circle Res;

	Res.x=A.x;
	Res.y=A.y;
	Res.r=sqrt(abs(A.r*A.r - B.r*B.r));

	return Res;
}

Circle& operator++(Circle& A)						//重载操作符++（前增）返回引用
{
	A.r=A.r+1.0;

	return A;
}
Circle operator++(Circle& A,int)					//重载操作符++（后增）
{
	Circle Res(A);
	A.r=A.r+1.0;

	return Res;
}

Circle& operator--(Circle& A)						//重载操作符--（前减）返回引用
{
	if((A.r-1.0)>0)
	{
		A.r=A.r-1.0;
	}

	return A;
}
Circle operator--(Circle& A,int)					//重载操作符--（后减）
{
	Circle Res(A);
	if((A.r-1.0)>0)
	{
		A.r=A.r-1.0;
	}

	return Res;
}

ostream& operator<<(ostream& out,const Circle& A)	//重载操作符<<，输出类信息
{
	out<<"坐标 ("<<A.x<<","<<A.y<<")";
	out<<"	半径 "<<A.r;
	out<<"	周长 "<<A.Perimeter();
	out<<"	面积 "<<A.Area()<<endl;

	return out;
}

bool operator>(const Circle& A,const Circle& B)		//重载操作符>
{
	if(A.r > B.r)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool operator<(const Circle& A,const Circle& B)		//重载操作符<
{
	if(A.r < B.r)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool operator==(const Circle& A,const Circle& B)	//重载操作符==
{
	if(A.x==B.x && A.y==B.y && A.r==B.r)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool operator!=(const Circle& A,const Circle& B)	//重载操作符!=
{
	if(A.x==B.x && A.y==B.y && A.r==B.r)
	{
		return false;
	}
	else
	{
		return true;
	}
}

bool operator&(const Circle& A,const Circle& B)		//重载操作符&，判断同心
{
	if(A.x==B.x && A.y==B.y)
	{
		return true;
	}
	else
	{
		return false;
	}
}
string operator|(const Circle& A,const Circle& B)	//重载操作符|，判断位置关系
{
	double l;
	double sumAB,minusAB;

	sumAB = A.r+B.r;
	minusAB = abs(A.r-B.r);
	l=sqrt((A.x-B.x)*(A.x-B.x)+(A.y-B.y)*(A.y-B.y));

	if(abs(l-sumAB)<1e-8 || abs(l-minusAB)<1e-8)	//涉及高精度时，浮点数不可直接做相等比较
	{
		return "两圆相切";
	}
	else if(l>sumAB)
	{
		return "两圆相离";
	}
	else if(l>minusAB && l<sumAB)
	{
		return "两圆相交";
	}
	else
	{
		return "两圆包含";
	}
}

bool move(Circle& A,Circle& B)
{
	if(A.r>1.0 && B.r>1.0)
	{
		double k_x,k_y,l,dx,dy,va,vb;

		dx = (B.x-A.x);
		dy = (B.y-A.y);
		l = sqrt(dx*dx + dy*dy);
		k_x = dx/l;
		k_y = dy/l;

		if(A<B)
		{
			vb = -1.0;
			va = B.Area()/A.Area();
		}
		else
		{
			va = 1.0;
			vb = (-1.0)*A.Area()/B.Area();
		}

		A.x = A.x + va*k_x;
		A.y = A.y + va*k_y;
		B.x = B.x + vb*k_x;
		B.y = B.y + vb*k_y;
		
		A.r--;
		B.r--;

		return true;
	}
	else
	{
		return false;
	}
}

double print_distance(const Circle& A,const Circle& B)
{
	return sqrt((A.x-B.x)*(A.x-B.x)+(A.y-B.y)*(A.y-B.y));
}
/***********************友元函数定义结束*******************************/

void main()
{
	Circle a,b;

	a.Set(0,0,5);
	b.Set(10,0,4.5);
	cout<<"初始信息：\n"<<"圆a"<<a<<"圆b"<<b;
	cout<<(a|b)<<"\t圆心距离为："<<print_distance(a,b)<<endl<<endl;

	while((a|b)!="两圆相交" && (a|b)!="两圆相切")
	{
		if(move(a,b) == 1)
		{
			cout<<"圆a"<<a<<"圆b"<<b;
			cout<<(a|b)<<"\t圆心距离为："<<print_distance(a,b)<<endl<<endl;
		}
		else
		{
			cout<<"失败（圆半径≤1，无法继续）"<<endl;
			return;
		}
	}	
}