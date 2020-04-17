/********************************
	1427405017
	����S
	E39
	2014-12-4 22:48
*********************************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void Display(int Arr[],int N);												//����������ʾ����
void Sort(int *p,int n);													//��������������

void main()
{
	int x[100],num,k;

	printf("����������������Ԫ�ظ�����\n");								//�����ʼ����
	scanf("%d",&num);
	printf("���������������Ԫ�أ�\n");
	for(k=0;k<num;k++)
	{
		scanf("%d",&x[k]);
	}
	
	Sort(x,num);															//������
	printf("����������Ϊ��\n");
	Display(x,num);
}

void Display(int Arr[],int N)												//����������ʾ����
{
	int i;

	for(i=0;i<N;i++)
	{
		printf("%8d",Arr[i]);
		if((i+1)%8==0)														//��ʱ���У���ʽ����
		{
			printf("\n");
		}
	}
	printf("\n");
}

void Sort(int *p,int n)														//��������������
{
	int i;
	int j;
	int t;

	for(i=0;i<n-1;i++)														//ð�ݷ�����
	{
		for(j=0;j<n-1-i;j++)
		{
			if(*(p+j)>*(p+j+1))												//ָ���������Ԫ��
			{
				t=*(p+j);
				*(p+j)=*(p+j+1);
				*(p+j+1)=t;
			}
		}
	}
}