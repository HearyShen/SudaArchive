#include <stdio.h>

void main()
{
	int a,b,c,sum,max,min;
	double ave;//ƽ��ֵ��һ��Ϊ����
	
	printf("��������������\n");
	scanf("%d%d%d",&a,&b,&c);

	ave=(a+b+c)/3.0;//��������3.0
	sum=a+b+c;

	if(a>b)//�ȱȽ�a��b���ó����ֵ����Сֵ
	{
		max=a;
		min=b;
	}
	else 
	{
		max=b;
		min=a;
	}
	
	if(max<c)//�ٺ�c�Ƚϣ��ó����յ����ֵ����Сֵ
	{
		max=c;
	}
	if(min>c)
	{
		min=c;
	}
	
	printf("Ave=%f\nSum=%d\nMax=%d\nMin=%d\n",ave,sum,max,min);
}