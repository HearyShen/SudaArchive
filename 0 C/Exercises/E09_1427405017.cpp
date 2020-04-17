#include <stdio.h>

void main()
{
	int m,d;//m作月份，d作天数
	printf("请输入月份数\n");
	scanf("%d",&m);

	switch(m)
	{
	case 2 : d=28;break;//特殊的小月
	case 1 :
	case 3 :
	case 5 :
	case 7 :
	case 8 :
	case 10 :
	case 12 : d=31;break;//大月
	case 4 :
	case 6 :
	case 9 :
	case 11 : d=30;break;//小月
	default: putchar('\a');
	}
	printf("该月有%d天\n",d);
}