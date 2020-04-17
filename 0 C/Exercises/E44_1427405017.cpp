/*******************************
	1427405017
	沈家赟
	E44
	2014-12-19 15:23
********************************/
#include <stdio.h>

struct Date																	//定义结构体类型Date
{
	int y;
	int m;
	int d;
};

int LeapYear(int Y,int DayData[]);											//声明闰年判断函数
int Valid(int Y, int M, int D, int DayData[]);								//声明数据合法性判断函数
int DateMinus(struct Date Date1, struct Date Date2, int DayData[]);			//声明日期求差函数

void main()
{
	struct Date date1,date2;												//定义Date型数据 date1 date2
	int days,daydata[12]={31,28,31,30,31,30,31,31,30,31,30,31};				//定义并初始化天数数据数组daydata[]，存放平年各月天数
	
	printf("请输入第一个日期：（格式：年 月 日，如2014 1 1）\n");
	scanf("%d%d%d",&date1.y,&date1.m,&date1.d);

	if(Valid(date1.y,date1.m,date1.d,daydata)==1)							//对第一个输入的日期进行合法性检查
	{
		printf("请输入第二个日期：（格式：年 月 日，如2014 1 1）\n");
		scanf("%d%d%d",&date2.y,&date2.m,&date2.d);
		if(Valid(date2.y,date2.m,date2.d,daydata)==1)						//对第二个输入的日期进行合法性检查
		{
			days=DateMinus(date1,date2,daydata);
			printf("两个日期之间相差 %d 天\n",days);
		}
		else
		{
			printf("您输入的第二个日期不合法！请查验后重试。\n");
		}
	}
	else
	{
		printf("您输入的第一个日期不合法！请查验后重试。\n");
	}
}

int LeapYear(int Y,int DayData[])											//定义闰年判断函数
{
	if((Y%4==0 && Y%100!=0) || Y%400==0)
	{
		DayData[1]=29;														//是闰年则把二月天数改为29
		return 1;
	}
	else
	{
		DayData[1]=28;														//不是闰年则把二月天数改回28
		return 0;
	}
}

int Valid(int Y, int M, int D,int DayData[])								//定义日期合法性判断函数
{
	if(Y>=0 && M>=1 && M<=12 && D>=1 && D<=31 )								//第一遍基本要求判断
	{
		switch(M)
		{
		case 2: if(LeapYear(Y,DayData)==1)									//针对月份和闰年情况，进行进一步精确判断
				{
					if(D > 29)
					{
						return 0;
					}
				}
				else
				{
					if(D > 28)
					{
						return 0;
					}
				}
				break;
		case 4:
		case 6:
		case 9:
		case 11: if(D > 30)
				 {
					 return 0;
				 }
				 break;
		}
		return 1;
	}
	else
	{
		return 0;
	}
}

int DateMinus(struct Date Date1, struct Date Date2,int DayData[])				//定义日期求差函数
{
	int Days,Sum,Days1,Days2,Year,i;
	struct Date T;

	if(Date1.y>Date2.y)															//确保Data1中存放的日期在Data2之前
	{
		T=Date1;
		Date1=Date2;
		Date2=T;
	}
	if(Date1.y==Date2.y)
	{
		if(Date1.m>Date2.m)
		{
			T=Date1;
			Date1=Date2;
			Date2=T;
		}
		if(Date1.m==Date2.m)
		{
			if(Date1.d>Date2.d)
			{
				T=Date1;
				Date1=Date2;
				Date2=T;
			}
		}
	}

	Days1=0;
	if(LeapYear(Date1.y,DayData)==1)											//求Data1在当年是第几天
	{
		for(i=0;i<Date1.m;i++)
		{
			Days1=Days1+DayData[i];
		}
		Days1=Days1+Date1.d;
	}
	else
	{
		for(i=0;i<Date1.m;i++)
		{
			Days1=Days1+DayData[i];
		}
		Days1=Days1+Date1.d;
	}
	
	Days2=0;
	if(LeapYear(Date2.y,DayData)==1)											//求Data2在当年是第几天
	{
		for(i=0;i<Date2.m;i++)
		{
			Days2=Days2+DayData[i];
		}
		Days2=Days2+Date2.d;
	}
	else
	{
		for(i=0;i<Date2.m;i++)
		{
			Days2=Days2+DayData[i];
		}
		Days2=Days2+Date2.d;
	}

	Sum=0;
	for(Year=Date1.y;Year<Date2.y;Year++)										//补足中间间隔的年份天数
	{
		if(LeapYear(Year,DayData)==1)
		{
			Sum=Sum+366;
		}
		else
		{
			Sum=Sum+365;
		}
	}

	Days=Sum-Days1+Days2;														//求出一前一后两年实际相差天数
	return Days;
}