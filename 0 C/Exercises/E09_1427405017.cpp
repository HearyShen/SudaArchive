#include <stdio.h>

void main()
{
	int m,d;//m���·ݣ�d������
	printf("�������·���\n");
	scanf("%d",&m);

	switch(m)
	{
	case 2 : d=28;break;//�����С��
	case 1 :
	case 3 :
	case 5 :
	case 7 :
	case 8 :
	case 10 :
	case 12 : d=31;break;//����
	case 4 :
	case 6 :
	case 9 :
	case 11 : d=30;break;//С��
	default: putchar('\a');
	}
	printf("������%d��\n",d);
}