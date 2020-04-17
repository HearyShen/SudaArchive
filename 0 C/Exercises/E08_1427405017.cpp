#include <stdio.h>
#include <math.h>

void main()
{
	double x1,y1,x2,y2,x3,y3,S,l1,l2,l3,C,cos;//依次定义三点横纵坐标，面积，三边长度，周长，以及计算面积所用的cos角
	printf("请依次输入三个顶点坐标x1 y1 x2 y2 x3 y3\n");
	scanf("%lf%lf%lf%lf%lf%lf",&x1,&y1,&x2,&y2,&x3,&y3);
	
	l1=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
	l2=sqrt((x2-x3)*(x2-x3)+(y2-y3)*(y2-y3));
	l3=sqrt((x1-x3)*(x1-x3)+(y1-y3)*(y1-y3));

	if((l1+l2)<=l3||(l1+l3)<l2||(l2+l3)<=l1)//排除两边之和不大于第三边，即不存在三角形的情况
	{
		printf("三点不能构成三角形\n");
	}
	else//可构成三角形的情况
	{
		C=l1+l2+l3;
		
		cos=(l1*l1+l2*l2-l3*l3)/(2.0*l1*l2);//利用余弦转化正弦求面积
		S=(1.0)*l1*l2*sqrt(1.0-cos*cos)/2.0;

		printf("该三角形面积S=%lf	周长C=%lf\n",S,C);
	}
}