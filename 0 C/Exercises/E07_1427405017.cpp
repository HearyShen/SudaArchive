#include <stdio.h>
#include <math.h>

void main()
{
	double a,b,c,p,q,delta,x1,x2;
	printf("���������뷽�̵�ϵ��a,b,c\n");
	scanf("%lf%lf%lf",&a,&b,&c);

	delta=b*b-4.0*a*c;
	p=-b/(2.0*a);//����������׼����p,����ֱ�ӵ���

	if(delta<0)//������ʵ��������
	{
		q=sqrt(-delta)/(2.0*a);//delta<0ʱ��q��Ҫ��������
		
		printf("x1=%lf+%lfi	x2=%lf-%lfi",p,q,p,q);//��printf������������ʾ��ʽ
	}
	
	else//������ʵ��������
	{
		if(delta==0)//�������
		{
			printf("x1=x2=%lf",p);
		}
		else//��������
		{
			q=sqrt(delta)/(2.0*a);
			
			x1=p+q;
			x2=p-q;
			
			printf("x1=%lf	x2=%lf",x1,x2);
		}
	}
	printf("\n");
}