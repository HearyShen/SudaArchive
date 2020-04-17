#include <iostream>

#define Pi 3.1415926

using namespace std;

class Circle
{
private:
	int ID;		//Բ�α��
	double x;	//Բ��x����
	double y;	//Բ��y����
	double r;	//�뾶
	static int max_ID;	//�Ѿ����ɵ�Բ�ζ��������ţ�ֻ���󲻼�С
	static int num;		//��ǰԲ�ζ����������������С

public:
	Circle();		//�޲ι��캯��
	Circle(const double &X,const double &Y,const double &R);	//1������3�������Ĺ��캯����3�������ֱ��ʼ��Բ�ε�Բ��x���ꡢԲ��y����Ͱ뾶�����ݳ�Ա����ʾ��Բ�ζ���ı��Ҳ��Ҫ��ʼ��
	Circle(const Circle &A);			//1���������캯������ʾ��Բ�ζ���ı�Ų��ܼ򵥸���
	~Circle();		//����������Բ�ζ�������ʱ����Ҫ����ǰԲ�ζ����������ȥ1
	static int get_num();				//1����ȡ��ǰԲ�ζ��������ĺ�������ʾ���˺�������Ϊ��̬����
	friend Circle& operator++(Circle &A);		//ǰ������������԰뾶����1
	friend Circle operator++(Circle &A,int);	//��������������԰뾶����1
	friend Circle operator+(const Circle &A, const Circle &B);	//+����������ڽ�����Բ�μ���һ�𣬵õ�һ���µ�Բ�Ρ���Բ�ε�Բ������������Բ���������ߵ��е㣬���������Բ������ĺ͡���ʾ����Ҫ�����������뾶
	friend ostream& operator<<(ostream &out,const Circle &A);	//��������㣬������ʾԲ�εı�š�Բ��x���ꡢԲ��y����Ͱ뾶��������ܳ���һ��Բ�ε���Ϣռ1��
};

int Circle::num = 0;
int Circle::max_ID = 0;

Circle::Circle()			//�޲ι��캯��
{
	ID = max_ID + 1;
	max_ID++;
	num++;

	x=0;
	y=0;
	r=0;
}

Circle::Circle(const double &X,const double &Y,const double &R)
{
	ID = max_ID + 1;
	max_ID++;
	num++;
	
	x=X;
	y=Y;
	r=R;
}

Circle::Circle(const Circle &A)
{
	ID = max_ID + 1;
	max_ID++;
	num++;
	
	x=A.x;
	y=A.y;
	r=A.r;
}

Circle::~Circle()
{
	num--;
}

int Circle::get_num()
{
	return num;
}

Circle& operator++(Circle &A)
{
	A.r++;

	return A;
}

Circle operator++(Circle &A,int)
{
	Circle T;

	T.ID = A.ID;
	T.x = A.x;
	T.y = A.y;
	T.r = A.r;

	A.r++;

	return T;
}

Circle operator+(const Circle &A, const Circle &B)
{
	Circle T;

	T.x = (A.x+B.x)/2;
	T.y = (A.y+B.y)/2;
	T.r = sqrt(A.r*A.r + B.r*B.r);

	return T;
}

ostream& operator<<(ostream &out,const Circle &A)	//���������
{
	out<<A.ID<<"\t("<<A.x<<","<<A.y<<")\t"<<A.r<<"\t"<<Pi*A.r*A.r<<"\t"<<Pi*A.r*2<<endl;

	return out;
}

int main()
{
    Circle c1( 1.12, 2.23, 3.34 ), c2( c1 );

    cout << c1 << c2;
    cout << "Number of circles = " << Circle::get_num() << endl;

    Circle c3 = c1 + c2;
    cout << c3;
    cout << "Number of circles = " << Circle::get_num() << endl;

    cout << c1++;
    cout << ++c2;
    cout << c1;

    return 0;
}