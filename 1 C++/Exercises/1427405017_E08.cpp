/************************
	E08
	1427405017
	����S
	2015-4-14 17:06
*************************/
#include <iostream>

#define PI 3.1415926

using namespace std;

class Circle				//������Circle
{
private:					//˽�г�Ա
	double x,y,r;
public:						//������Ա����
	void Set(double X,double Y,double R);
	double Area();
	double Perimeter();
};							//��β���з��

void Circle::Set(double X,double Y,double R)	//�����Ա����Set
{
	x=X;
	y=Y;
	r=R;
}

double Circle::Area()		//�����Ա����Area
{
	return PI*r*r;
}

double Circle::Perimeter()	//�����Ա����Perimeter
{
	return 2*PI*r;
}

void main()
{
	Circle O;				//��������O

	O.Set(1.0,2.0,3.0);				//���ó�Ա����Ϊ����ֵ
	cout<<"��Բ ���="<<O.Area()<<endl;		//���ó�Ա���������
	cout<<"��Բ �ܳ�="<<O.Perimeter()<<endl;//���ó�Ա�������ܳ�
}