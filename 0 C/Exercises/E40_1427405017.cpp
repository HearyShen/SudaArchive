/********************************
	1427405017
	����S
	E40
	2014-12-6 15:54
*********************************/
#include <stdio.h>

void Sort(int *p,int n);
void Insert(int Arr[],int N,int In);
void Display(int Arr[],int N);

void main()
{
	int x[1000],num,k,in;

	printf("�����������ĳ�ʼ���������Ԫ�ظ�����\n");						//�����ʼ����
	scanf("%d",&num);
	printf("���������������Ԫ�أ����ո����������\n");
	for(k=0;k<num;k++)
	{
		scanf("%d",&x[k]);
	}

	Sort(x,num);															//���ó�ʼ����������
	printf("����������Ϊ��\n");
	Display(x,num);

	printf("��������������ĳһ������\n");									//�����������
	scanf("%d",&in);
	num++;																	//��������ЧԪ������һ��

	Insert(x,num,in);														//���ò��뺯��
	printf("��������������Ϊ��\n");
	Display(x,num);
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

void Insert(int Arr[],int N,int In)											//������뺯��
{
	int i;
	int j;
	
	N=N-1;																	//��������Insert����ǰ���ǵ�����һ����������num++����
	for(i=0;i<N;i++)
	{
		if(Arr[i]>In)														//���������бȲ��������Ԫ��
		{
			for(j=N-1;j>=i;j--)
			{
				Arr[j+1]=Arr[j];											//�����Ԫ��������
			}
			Arr[i]=In;
			return;
		}
	}
	Arr[N]=In;																//�������и�Ԫ�ض��Ȳ���Ԫ��С
}

void Display(int Arr[],int N)												//����������ʾ����
{
	int i;

	for(i=0;i<N;i++)
	{
		printf("%6d",Arr[i]);
		if((i+1)%8==0)														//��ʱ���У���ʽ����
		{
			printf("\n");
		}
	}
	printf("\n");
}