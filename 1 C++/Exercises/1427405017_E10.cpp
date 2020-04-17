/************************
	E10
	1427405017
	����S
	2015-4-19 17:40
*************************/
#include <iostream>
#include <cmath>
#include <string>

#define PI 3.1415926

using namespace std;

class Circle				//������Circle
{
private:					//˽�г�Ա
	double x,y,r;
public:						//������Ա����
	void Set(double X,double Y,double R);
	double Area()const;
	double Perimeter()const;
	double Radius()const;
	/************************��Ԫ����********************************/
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
};							//��β���з��

/***********************��Ա�������忪ʼ*******************************/
void Circle::Set(double X,double Y,double R)	//�����Ա����Set
{
	x=X;
	y=Y;
	r=R;
}

double Circle::Area()const		//�����Ա����Area
{
	return PI*r*r;
}

double Circle::Perimeter()const	//�����Ա����Perimeter
{
	return 2*PI*r;
}

double Circle::Radius()const	//�����Ա����Radius
{
	return r;
}
/***********************��Ա�����������*******************************/

/***********************��Ԫ�������忪ʼ*******************************/
Circle operator+(const Circle& A,const Circle& B)	//���ز�����+
{
	Circle Res;

	Res.x=A.x;
	Res.y=A.y;
	Res.r=A.r+B.r;

	return Res;
}
Circle operator-(const Circle& A,const Circle& B)	//���ز�����-
{
	Circle Res;

	Res.x=A.x;
	Res.y=A.y;
	Res.r=sqrt(abs(A.r*A.r - B.r*B.r));

	return Res;
}

Circle& operator++(Circle& A)						//���ز�����++��ǰ������������
{
	A.r=A.r+1.0;

	return A;
}
Circle operator++(Circle& A,int)					//���ز�����++��������
{
	Circle Res(A);
	A.r=A.r+1.0;

	return Res;
}

Circle& operator--(Circle& A)						//���ز�����--��ǰ������������
{
	if((A.r-1.0)>0)
	{
		A.r=A.r-1.0;
	}

	return A;
}
Circle operator--(Circle& A,int)					//���ز�����--�������
{
	Circle Res(A);
	if((A.r-1.0)>0)
	{
		A.r=A.r-1.0;
	}

	return Res;
}

ostream& operator<<(ostream& out,const Circle& A)	//���ز�����<<���������Ϣ
{
	out<<"���� ("<<A.x<<","<<A.y<<")";
	out<<"	�뾶 "<<A.r;
	out<<"	�ܳ� "<<A.Perimeter();
	out<<"	��� "<<A.Area()<<endl;

	return out;
}

bool operator>(const Circle& A,const Circle& B)		//���ز�����>
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
bool operator<(const Circle& A,const Circle& B)		//���ز�����<
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

bool operator==(const Circle& A,const Circle& B)	//���ز�����==
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
bool operator!=(const Circle& A,const Circle& B)	//���ز�����!=
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

bool operator&(const Circle& A,const Circle& B)		//���ز�����&���ж�ͬ��
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
string operator|(const Circle& A,const Circle& B)	//���ز�����|���ж�λ�ù�ϵ
{
	double l;
	double sumAB,minusAB;

	sumAB = A.r+B.r;
	minusAB = abs(A.r-B.r);
	l=sqrt((A.x-B.x)*(A.x-B.x)+(A.y-B.y)*(A.y-B.y));

	if(abs(l-sumAB)<1e-8 || abs(l-minusAB)<1e-8)	//�漰�߾���ʱ������������ֱ������ȱȽ�
	{
		return "��Բ����";
	}
	else if(l>sumAB)
	{
		return "��Բ����";
	}
	else if(l>minusAB && l<sumAB)
	{
		return "��Բ�ཻ";
	}
	else
	{
		return "��Բ����";
	}
}
/***********************��Ԫ�����������*******************************/

void main()
{
	/**********************�����Ա����**********************/
	Circle a;				//��������a
	a.Set(1.0,1.0,1.0);				//���ó�Ա����Ϊ����ֵ
	cout<<"aԲ ���="<<a.Area()<<endl;		//���ó�Ա���������
	cout<<"aԲ �ܳ�="<<a.Perimeter()<<endl;//���ó�Ա�������ܳ�

	Circle b;				//��������b
	b.Set(2.0,2.0,1.0);				//���ó�Ա����Ϊ����ֵ
	cout<<"bԲ ���="<<b.Area()<<endl;		//���ó�Ա���������
	cout<<"bԲ �ܳ�="<<b.Perimeter()<<endl<<endl;//���ó�Ա�������ܳ�

	/**********************������Ԫ���ز����� + **********************/
	Circle c;
	c=a+b;
	cout<<"Բ(a+b) ���="<<c.Area()<<endl;		//���ó�Ա���������
	cout<<"Բ(a+b) �ܳ�="<<c.Perimeter()<<endl<<endl;//���ó�Ա�������ܳ�

	/**********************������Ԫ���ز����� - **********************/
	c=a-b;
	cout<<"Բ(a-b) ���="<<c.Area()<<endl;		//���ó�Ա���������
	cout<<"Բ(a-b) �ܳ�="<<c.Perimeter()<<endl<<endl;//���ó�Ա�������ܳ�

	/**********************������Ԫ���ز����� ++ **********************/
	Circle d;
	cout<<"Բc �뾶"<<c.Radius()<<endl;
	d=c++;
	cout<<"Բd(d=c++) �뾶"<<d.Radius()<<endl;
	cout<<"��ʱ��Բc �뾶"<<c.Radius()<<endl;
	d=++c;
	cout<<"Բd(d=++c) �뾶"<<d.Radius()<<endl;
	cout<<"��ʱ��Բc �뾶"<<c.Radius()<<endl<<endl;

	/**********************������Ԫ���ز����� -- **********************/
	cout<<"Բc �뾶"<<c.Radius()<<endl;
	d=c--;
	cout<<"Բd(d=c--) �뾶"<<d.Radius()<<endl;
	cout<<"��ʱ��Բc �뾶"<<c.Radius()<<endl;
	d=--c;
	cout<<"Բd(d=--c) �뾶"<<d.Radius()<<endl;
	cout<<"��ʱ��Բc �뾶"<<c.Radius()<<endl<<endl;

	/**********************������Ԫ����������� << **********************/
	cout<<a<<b<<c<<endl;

	/**********************������Ԫ���ز����� > < **********************/
	cout<<"a>b?	"<<(a>b)<<endl;
	cout<<"a<b?	"<<(a<b)<<endl<<endl;

	/**********************������Ԫ���ز����� == != **********************/
	cout<<"a==b?	"<<(a==b)<<endl;
	cout<<"a!=b?	"<<(a!=b)<<endl<<endl;

	/**********************������Ԫ���ز����� & **********************/
	cout<<"a&b?	"<<(a&b)<<endl;
	cout<<"a&c?	"<<(a&c)<<endl;

	/**********************������Ԫ���ز����� | **********************/
	cout<<"a��bλ�ù�ϵ��	"<<(a|b)<<endl;
	cout<<"a��cλ�ù�ϵ��	"<<(a|c)<<endl;
}