#include <stdio.h>
#define PI 3.1415926//�궨�峣��PI�������·�����ȡ��

void main()
{
	double r,C,s,V,S;//r��һ��Ϊ������������ֵҲ��һ��Ϊ����
	
	printf("������һ���������\n");
	scanf("%lf",&r);

	C=2*PI*r;
	s=PI*r*r;
	V=(4/3)*PI*r*r*r;
	S=4*PI*r*r;

	printf("Բ���ܳ�=%f\nԲ�����=%f\n������=%f\n��ı����=%f\n",C,s,V,S);
}