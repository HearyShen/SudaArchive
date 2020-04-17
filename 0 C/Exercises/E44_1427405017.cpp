/*******************************
	1427405017
	����S
	E44
	2014-12-19 15:23
********************************/
#include <stdio.h>

struct Date																	//����ṹ������Date
{
	int y;
	int m;
	int d;
};

int LeapYear(int Y,int DayData[]);											//���������жϺ���
int Valid(int Y, int M, int D, int DayData[]);								//�������ݺϷ����жϺ���
int DateMinus(struct Date Date1, struct Date Date2, int DayData[]);			//������������

void main()
{
	struct Date date1,date2;												//����Date������ date1 date2
	int days,daydata[12]={31,28,31,30,31,30,31,31,30,31,30,31};				//���岢��ʼ��������������daydata[]�����ƽ���������
	
	printf("�������һ�����ڣ�����ʽ���� �� �գ���2014 1 1��\n");
	scanf("%d%d%d",&date1.y,&date1.m,&date1.d);

	if(Valid(date1.y,date1.m,date1.d,daydata)==1)							//�Ե�һ����������ڽ��кϷ��Լ��
	{
		printf("������ڶ������ڣ�����ʽ���� �� �գ���2014 1 1��\n");
		scanf("%d%d%d",&date2.y,&date2.m,&date2.d);
		if(Valid(date2.y,date2.m,date2.d,daydata)==1)						//�Եڶ�����������ڽ��кϷ��Լ��
		{
			days=DateMinus(date1,date2,daydata);
			printf("��������֮����� %d ��\n",days);
		}
		else
		{
			printf("������ĵڶ������ڲ��Ϸ������������ԡ�\n");
		}
	}
	else
	{
		printf("������ĵ�һ�����ڲ��Ϸ������������ԡ�\n");
	}
}

int LeapYear(int Y,int DayData[])											//���������жϺ���
{
	if((Y%4==0 && Y%100!=0) || Y%400==0)
	{
		DayData[1]=29;														//��������Ѷ���������Ϊ29
		return 1;
	}
	else
	{
		DayData[1]=28;														//����������Ѷ��������Ļ�28
		return 0;
	}
}

int Valid(int Y, int M, int D,int DayData[])								//�������ںϷ����жϺ���
{
	if(Y>=0 && M>=1 && M<=12 && D>=1 && D<=31 )								//��һ�����Ҫ���ж�
	{
		switch(M)
		{
		case 2: if(LeapYear(Y,DayData)==1)									//����·ݺ�������������н�һ����ȷ�ж�
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

int DateMinus(struct Date Date1, struct Date Date2,int DayData[])				//������������
{
	int Days,Sum,Days1,Days2,Year,i;
	struct Date T;

	if(Date1.y>Date2.y)															//ȷ��Data1�д�ŵ�������Data2֮ǰ
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
	if(LeapYear(Date1.y,DayData)==1)											//��Data1�ڵ����ǵڼ���
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
	if(LeapYear(Date2.y,DayData)==1)											//��Data2�ڵ����ǵڼ���
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
	for(Year=Date1.y;Year<Date2.y;Year++)										//�����м������������
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

	Days=Sum-Days1+Days2;														//���һǰһ������ʵ���������
	return Days;
}