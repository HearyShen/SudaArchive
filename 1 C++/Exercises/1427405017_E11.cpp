/************************
	E11
	1427405017
	����S
	2015-4-19 19:44
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
	friend bool move(Circle& A,Circle& B);
	friend double print_distance(const Circle& A,const Circle& B);
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
/***********************��Ԫ�����������*******************************/

void main()
{
	Circle a,b;

	a.Set(0,0,5);
	b.Set(10,0,4.5);
	cout<<"��ʼ��Ϣ��\n"<<"Բa"<<a<<"Բb"<<b;
	cout<<(a|b)<<"\tԲ�ľ���Ϊ��"<<print_distance(a,b)<<endl<<endl;

	while((a|b)!="��Բ�ཻ" && (a|b)!="��Բ����")
	{
		if(move(a,b) == 1)
		{
			cout<<"Բa"<<a<<"Բb"<<b;
			cout<<(a|b)<<"\tԲ�ľ���Ϊ��"<<print_distance(a,b)<<endl<<endl;
		}
		else
		{
			cout<<"ʧ�ܣ�Բ�뾶��1���޷�������"<<endl;
			return;
		}
	}	
}