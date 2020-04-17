#include <stdio.h>
#include <math.h>

void main()
{
	double x1,y1,x2,y2,r,d;//定义浮点坐标，半径，以及两点距离
	printf("请依次输入圆心坐标x1 y1 半径r 点坐标x2 y2\n");
	scanf("%lf%lf%lf%lf%lf",&x1,&y1,&r,&x2,&y2);

	d=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));

	if(d>r)//考虑到浮点变量不能直接比较相等关系，将这情况放入else中一并处理
	{
		printf("该点在圆外\n");
	}
	else
	{
		printf("该点在圆上\n");
	}
}