#include <stdio.h>
#define PI 3.1415926//宏定义常量PI，便于下方运算取用

void main()
{
	double r,C,s,V,S;//r不一定为整数，则其余值也不一定为整数
	
	printf("请输入一个浮点变量\n");
	scanf("%lf",&r);

	C=2*PI*r;
	s=PI*r*r;
	V=(4/3)*PI*r*r*r;
	S=4*PI*r*r;

	printf("圆的周长=%f\n圆的面积=%f\n球的体积=%f\n球的表面积=%f\n",C,s,V,S);
}