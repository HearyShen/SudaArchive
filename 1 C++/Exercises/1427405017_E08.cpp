/************************
	E08
	1427405017
	沈家赟
	2015-4-14 17:06
*************************/
#include <iostream>

#define PI 3.1415926

using namespace std;

class Circle				//定义类Circle
{
private:					//私有成员
	double x,y,r;
public:						//公开成员函数
	void Set(double X,double Y,double R);
	double Area();
	double Perimeter();
};							//结尾须有封号

void Circle::Set(double X,double Y,double R)	//定义成员函数Set
{
	x=X;
	y=Y;
	r=R;
}

double Circle::Area()		//定义成员函数Area
{
	return PI*r*r;
}

double Circle::Perimeter()	//定义成员函数Perimeter
{
	return 2*PI*r;
}

void main()
{
	Circle O;				//创建对象O

	O.Set(1.0,2.0,3.0);				//调用成员函数为对象赋值
	cout<<"该圆 面积="<<O.Area()<<endl;		//调用成员函数求面积
	cout<<"该圆 周长="<<O.Perimeter()<<endl;//调用成员函数求周长
}