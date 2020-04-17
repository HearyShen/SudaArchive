#include <iostream>

#define Pi 3.1415926

using namespace std;

class Circle
{
private:
	int ID;		//圆形编号
	double x;	//圆心x坐标
	double y;	//圆心y坐标
	double r;	//半径
	static int max_ID;	//已经生成的圆形对象的最大编号，只增大不减小
	static int num;		//当前圆形对象个数，可增大或减小

public:
	Circle();		//无参构造函数
	Circle(const double &X,const double &Y,const double &R);	//1个带有3个参数的构造函数。3个参数分别初始化圆形的圆心x坐标、圆心y坐标和半径等数据成员。提示：圆形对象的编号也需要初始化
	Circle(const Circle &A);			//1个拷贝构造函数。提示：圆形对象的编号不能简单复制
	~Circle();		//析构函数。圆形对象销毁时，需要将当前圆形对象的数量减去1
	static int get_num();				//1个获取当前圆形对象数量的函数。提示：此函数建议为静态函数
	friend Circle& operator++(Circle &A);		//前自增运算符，对半径自增1
	friend Circle operator++(Circle &A,int);	//后自增运算符，对半径自增1
	friend Circle operator+(const Circle &A, const Circle &B);	//+运算符，用于将两个圆形加在一起，得到一个新的圆形。新圆形的圆心坐标是两个圆形坐标连线的中点，面积是两个圆形面积的和。提示：需要根据面积反算半径
	friend ostream& operator<<(ostream &out,const Circle &A);	//流输出运算，用于显示圆形的编号、圆心x坐标、圆心y坐标和半径、面积、周长。一个圆形的信息占1行
};

int Circle::num = 0;
int Circle::max_ID = 0;

Circle::Circle()			//无参构造函数
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

ostream& operator<<(ostream &out,const Circle &A)	//流输出运算
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