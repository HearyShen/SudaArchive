/****************************
	1427405017
	����S
	E45
	2014-12-25 16:47
****************************/
#include <stdio.h>
#include <stdlib.h>

struct Node									//����ṹ������Node���ڹ�������ڵ�
{
	int num;

	struct Node * next;
};

struct Node * InputList();					//�����������뺯��InputList
void Display(struct Node *Head,int K);		//����������ʾ����Display
void DelEven(struct Node *Head);			//��������ż���ڵ�ɾ������DelEven

void main()
{
	struct Node *head;						//��������ͷָ��head
	int k;									//����������ʾ�Ļ��в���k

	printf("���������ɸ��ڵ��Թ�����������-9999ʱ��������������\n");
	head = InputList();						//�����������뺯������ʾ��ʼ����

	k=3;
	printf("��������������£�\n");
	Display(head,k);						//����������ʾ����

	DelEven(head);							//��������ż���ڵ�ɾ������

	printf("ɾ��ż���ڵ���������£�\n");
	Display(head,k);						//�����������뺯������ʾż���ڵ�ɾ���������
}

struct Node * InputList()					//�����������뺯��InputList
{
	struct Node *Head,*p,*q;
	int Num;

	Head = (struct Node *)malloc(sizeof(struct Node));		//Ϊ����ͷ�ڵ�����ռ�
	q = Head;												//qָ��Ҳָ��ͷ�ڵ㣬Ϊ����������׼��

	while(1)												//������ѭ��
	{
		scanf("%d",&Num);
		if(Num == -9999)									//����ֵ��һ������-9999���˳������������½ڵ�
		{
			break;
		}
		p = (struct Node *)malloc(sizeof(struct Node));		//������һ���ڵ�Ŀռ䣬pָ��ָ���½ڵ�
		q->next = p;										//�½ڵ��ַ��ֵ��ǰ�ڵ㣬��֤����������
		p->num = Num;										//���½ڵ��д�ŷ�������������ֵ

		q=p;												//qָ��ǰ����Ľڵ㣬Ϊ��һ��ѭ����׼��
	}
	q->next = NULL;											//ѭ��������������һ���ڵ�ָ��ΪNULL
	return Head;											//�������������ͷָ���������
}

void Display(struct Node *Head,int K)						//����������ʾ����Display
{
	struct Node *Ptr;										//����ָ��Ptr
	int Count;

	Count=0;
	Ptr = Head->next;										//Ptrָ���һ����Ч�ڵ�
	while(Ptr != NULL)										//δ�������������ѭ����ʾ
	{
		printf("%5d",Ptr->num);
		Ptr = Ptr->next;									//��ǰ����ʾ��ָ����һ��
		Count++;
		if(Count%K == 0)									//���軻��
		{
			printf("\n");
		}
	}
	printf("\n");
}

void DelEven(struct Node *Head)						//��������ż���ڵ�ɾ������
{
	struct Node *q,*p;
	int Count;

	Count=0;
	p = Head->next;											//pָ���һ����Ч�ڵ�
	while(p != NULL)
	{
		Count++;											//ѭ������һ�Σ�������+1
		if(Count%2 == 0)									//ż���ڵ����
		{
			q->next = p->next;								//��ǰ�ڵ�ǰһ����������ǰ�ڵ��һ���֤��������
			free(p);										//�ͷŵ�ǰż���ڵ�
			p = q->next;									//pָ��ָ���½ڵ㣬Ϊ��һ��ѭ����׼��
		}
		else
		{
			q = p;											//qǰ��һ��
			p = p->next;									//pҲǰ��һ��
		}
	}
}