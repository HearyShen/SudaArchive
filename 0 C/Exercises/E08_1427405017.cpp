#include <stdio.h>
#include <math.h>

void main()
{
	double x1,y1,x2,y2,x3,y3,S,l1,l2,l3,C,cos;//���ζ�������������꣬��������߳��ȣ��ܳ����Լ�����������õ�cos��
	printf("����������������������x1 y1 x2 y2 x3 y3\n");
	scanf("%lf%lf%lf%lf%lf%lf",&x1,&y1,&x2,&y2,&x3,&y3);
	
	l1=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
	l2=sqrt((x2-x3)*(x2-x3)+(y2-y3)*(y2-y3));
	l3=sqrt((x1-x3)*(x1-x3)+(y1-y3)*(y1-y3));

	if((l1+l2)<=l3||(l1+l3)<l2||(l2+l3)<=l1)//�ų�����֮�Ͳ����ڵ����ߣ��������������ε����
	{
		printf("���㲻�ܹ���������\n");
	}
	else//�ɹ��������ε����
	{
		C=l1+l2+l3;
		
		cos=(l1*l1+l2*l2-l3*l3)/(2.0*l1*l2);//��������ת�����������
		S=(1.0)*l1*l2*sqrt(1.0-cos*cos)/2.0;

		printf("�����������S=%lf	�ܳ�C=%lf\n",S,C);
	}
}