#include <stdio.h>
#include <math.h>

void main()
{
	double x1,y1,x2,y2,r,d;//���帡�����꣬�뾶���Լ��������
	printf("����������Բ������x1 y1 �뾶r ������x2 y2\n");
	scanf("%lf%lf%lf%lf%lf",&x1,&y1,&r,&x2,&y2);

	d=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));

	if(d>r)//���ǵ������������ֱ�ӱȽ���ȹ�ϵ�������������else��һ������
	{
		printf("�õ���Բ��\n");
	}
	else
	{
		printf("�õ���Բ��\n");
	}
}