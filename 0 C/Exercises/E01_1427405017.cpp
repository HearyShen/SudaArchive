#include <stdio.h>

void main()
{
	int a,b,q,r;//����a,b��ͬʱ������q,r���ֱ���Ϊ�̺�����

	printf("����������������\n");
	scanf("%d%d",&a,&b);
	
	q=a/b;
	r=a%b;

	printf("��Ϊ%d\n����Ϊ%d\n",q,r);
}