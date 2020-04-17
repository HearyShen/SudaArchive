/****************************
	E09
	1427405017
	����S
	2015-4-15 10:40
****************************/
#include <iostream>

#define PI 3.1415926

using namespace std;

class Column		//������Column
{
private:			//����˽�г�Ա
	double x,y,r,h;
public:				//������Ա����
	void Set(double X,double Y,double R,double H);
	double Buttom_Area();
	double Buttom_Perimeter();
	double Side_Area();
	double Volume();
};

void Column::Set(double X,double Y,double R,double H)	//�����Ա����Set
{
	x=X;
	y=Y;
	r=R;
	h=H;
}

double Column::Buttom_Area()		//�����Ա����Buttom_Area��������
{
	return PI*r*r;
}

double Column::Buttom_Perimeter()	//�����Ա����Buttom_Perimeter��������ܳ�
{
	return 2*PI*r;
}

double Column::Side_Area()			//�����Ա����Side_Area��������
{
	return 2*PI*r*h;
}

double Column::Volume()				//�����Ա����Volume����Բ�����
{
	return PI*r*r*h;
}

void main()
{
	Column C;		//����Column����� C

	C.Set(1.0,2.0,3.0,4.0);		//�������꣨1.0,2.0��,�뾶3.0����Ϊ4.0
	cout<<"��Բ�� �����="<<C.Buttom_Area()<<endl;;
	cout<<"��Բ�� �����ܳ�="<<C.Buttom_Perimeter()<<endl;
	cout<<"��Բ�� �����="<<C.Side_Area()<<endl;
	cout<<"��Բ�� ���="<<C.Volume()<<endl;
}