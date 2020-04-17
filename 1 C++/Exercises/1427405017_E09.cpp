/****************************
	E09
	1427405017
	沈家赟
	2015-4-15 10:40
****************************/
#include <iostream>

#define PI 3.1415926

using namespace std;

class Column		//定义类Column
{
private:			//定义私有成员
	double x,y,r,h;
public:				//声明成员函数
	void Set(double X,double Y,double R,double H);
	double Buttom_Area();
	double Buttom_Perimeter();
	double Side_Area();
	double Volume();
};

void Column::Set(double X,double Y,double R,double H)	//定义成员函数Set
{
	x=X;
	y=Y;
	r=R;
	h=H;
}

double Column::Buttom_Area()		//定义成员函数Buttom_Area，求底面积
{
	return PI*r*r;
}

double Column::Buttom_Perimeter()	//定义成员函数Buttom_Perimeter，求地面周长
{
	return 2*PI*r;
}

double Column::Side_Area()			//定义成员函数Side_Area，求侧面积
{
	return 2*PI*r*h;
}

double Column::Volume()				//定义成员函数Volume，求圆柱体积
{
	return PI*r*r*h;
}

void main()
{
	Column C;		//创建Column类对象 C

	C.Set(1.0,2.0,3.0,4.0);		//设置坐标（1.0,2.0）,半径3.0，高为4.0
	cout<<"该圆柱 底面积="<<C.Buttom_Area()<<endl;;
	cout<<"该圆柱 底面周长="<<C.Buttom_Perimeter()<<endl;
	cout<<"该圆柱 侧面积="<<C.Side_Area()<<endl;
	cout<<"该圆柱 体积="<<C.Volume()<<endl;
}