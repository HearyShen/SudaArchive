#include <stdio.h>

void main()
{
	int m,d,sum,rm;//�ֱ����·ݣ����ڣ�������������
	printf("�������·ݺ�����\n");
	scanf("%d%d",&m,&d);

	switch(m)//�����·�����������
	{
	case 1:sum=d;break;
	case 2:sum=d+31;break;
	case 3:sum=d+31+28;break;
	case 4:sum=d+31*2+28;break;
	case 5:sum=d+31*2+28+30;break;
	case 6:sum=d+31*3+28+30;break;
	case 7:sum=d+31*3+28+30*2;break;
	case 8:sum=d+31*4+28+30*2;break;
	case 9:sum=d+31*5+28+30*2;break;
	case 10:sum=d+31*5+28+30*3;break;
	case 11:sum=d+31*6+28+30*3;break;
	case 12:sum=d+31*6+28+30*4;break;
	default:putchar('\a');
	}

	rm=sum%7;

	switch(rm)//�������������ڼ�
	{
	case 1:printf("���������ڶ�\n");break;
	case 2:printf("������������\n");break;
	case 3:printf("������������\n");break;
	case 4:printf("������������\n");break;
	case 5:printf("������������\n");break;
	case 6:printf("������������\n");break;
	case 0:printf("����������һ\n");break;
	default:putchar('\a');
	}
}