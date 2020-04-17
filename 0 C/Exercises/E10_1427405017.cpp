#include <stdio.h>

void main()
{
	int m,d,sum,rm;//分别定义月份，日期，总天数，余数
	printf("请输入月份和日期\n");
	scanf("%d%d",&m,&d);

	switch(m)//利用月份数求总天数
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

	switch(rm)//利用余数求星期几
	{
	case 1:printf("这天是星期二\n");break;
	case 2:printf("这天是星期三\n");break;
	case 3:printf("这天是星期四\n");break;
	case 4:printf("这天是星期五\n");break;
	case 5:printf("这天是星期六\n");break;
	case 6:printf("这天是星期日\n");break;
	case 0:printf("这天是星期一\n");break;
	default:putchar('\a');
	}
}