/*****************************
	1427405017
	����S
	E38
	2014-12-4 18:36
*****************************/
#include <stdio.h>
#include <math.h>

void Binary(int x,int Arr[],int *Bit);		//����ʮ����ת�����ƺ���

void main()
{
	int input,a[100],bit,i;					//�������������������ƴ�����飬��������ռλ����ѭ������i

	printf("������һ����������\n");
	scanf("%d",&input);
	
	if(input>0)
	{
		Binary(input,a,&bit);					//����ʮ����ת�����ƺ���
	
		printf("�������Ķ�������ʽΪ��\n");
		for(i=bit;i>=0;i--)
		{
			printf("%d",a[i]);
		}
		printf("\n");
	}
	else
	{
		printf("����ֵ����������������������\n");
	}
}

void Binary(int x,int Arr[],int *Bit)		//����ʮ����ת�����ƺ���Binary
{
	int i;
	int n;
	int temp;

	for(i=0;pow(2.0,i)<=x;i++)				//���xС�����2���ݵ�ָ����pow������ʹ��(double,int)��ʽ
	{
	}
	n=i-1;
	*Bit=n;

	for(i=n;i>=0;i--)
	{
		temp=pow(2.0,i);					//pow������ʹ��(double,int)��ʽ
		if(x>=temp)							//��1�����
		{
			Arr[i]=1;
			x=x-temp;
		}
		else								//��0�����
		{
			Arr[i]=0;
		}
	}
}

