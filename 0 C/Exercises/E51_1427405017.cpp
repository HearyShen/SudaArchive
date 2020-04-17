/****************************
	1427405017
	����S
	E51
	2015-1-10 10:30
*****************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Contactor			//����ṹ�����������ļ�����
{
	char name[20];			//�������������ļ��в������ظ�������
	int age;				//����
	int sex;				//�Ա�0����Ů�ԣ�1��������
	char phone[20];			//�绰����
	char postcode[10];		//��������
	char address[100];		//ͨѶ��ַ
};

struct Node					//����ṹ��������������ڵ�
{
	char name[20];			//�������������ļ��в������ظ�������
	int age;				//����
	int sex;				//�Ա�0����Ů�ԣ�1��������
	char phone[20];			//�绰����
	char postcode[10];		//��������
	char address[100];		//ͨѶ��ַ

	struct Node *next;		//ָ����
};

struct Node *Read_To_List(char *FileAddress);					//�����ļ�������������
void Display_List(struct Node *Head);							//����������ʾ����
void Initial_Add(struct Node *Head,struct Node *Add);			//�����׽ڵ���Ӻ���
void Delete_AgeReach25(Node *Head);								//����ɾ��������ﵽ25������
void Caculate_MaleAge(struct Node *Head,double *Ave,int *Max);	//������������ϵ�м��㺯��
struct Node *Search_Node(struct Node *Head);					//�����ڵ���Һ���
void Rewrite_Node(struct Node *Rewrite);						//�����ڵ��޸ĺ���
void Save_List(struct Node *Head,char *FileAddress);			//���������溯��

void main()
{
	struct Node *head,*add,*rewrite;
	double ave;
	int max;

	head = Read_To_List("D:\\contact.dat");					//(1-3).��ȡ�ļ����ݲ���ʾ
	Display_List(head);

	printf("��������Ҫ���ӵ����ݣ�����Ϊ��\n����\n����\n�Ա���1Ů0��\n�绰\n�ʱ�\n��ַ\n");
	add = (struct Node *)malloc(sizeof(struct Node));
	gets(add->name);
	scanf("%d",&add->age);
	scanf("%d",&add->sex);
	getchar();
	gets(add->phone);
	gets(add->postcode);
	gets(add->address);
	printf("\n");
	Initial_Add(head,add);									//(4).�������׽ڵ㣬����ʾ
	printf("�����ɺ󣬵�ǰ����Ϊ��\n");
	Display_List(head);

	Delete_AgeReach25(head);								//(5).ɾ������ﵽ25�Ľڵ㲢��ʾ
	printf("ɾ����ɺ󣬵�ǰ����Ϊ��\n");
	Display_List(head);

	Caculate_MaleAge(head,&ave,&max);						//(6).��������ƽ�������������䲢��ʾ
	printf("����ƽ������Ϊ��%lf\n�����������Ϊ��%d\n",ave,max);

	rewrite = Search_Node(head);							//(7).���ҽڵ㣬���޸�
	if(rewrite != NULL)
	{
		printf("��������\n");
		Rewrite_Node(rewrite);
		printf("�޸ĺ������Ϊ��\n");
		Display_List(head);
	}
	else
	{
		printf("���������ڣ�\n");
	}

	Save_List(head,"D:\\res.txt");							//(8).������������
	printf("���������ѱ�����D:\res.txt");
}

struct Node *Read_To_List(char *FileAddress)					//�����ļ�������������
{
	FILE *fp;
	struct Contactor temp;
	struct Node *Head,*p,*q;
	int flag;

	fp = fopen(FileAddress,"rb");								//�򿪶������ļ�
	if(fp == NULL)												//���
	{
		printf("���ļ�ʧ�ܣ�\n");
		exit(0);
	}

	Head = (struct Node *)malloc(sizeof(struct Node));			//��ʼ��������
	q = Head;

	while(!feof(fp))											//����������
	{
		flag = fread(&temp,sizeof(struct Contactor),1,fp);
		if(flag != 0)											//�Զ������ݽ��кϷ��ж�
		{
			p = (struct Node *)malloc(sizeof(struct Node));

			strcpy(p->name, temp.name);
			p->age = temp.age;
			p->sex = temp.sex;
			strcpy(p->phone, temp.phone);
			strcpy(p->postcode, temp.postcode);
			strcpy(p->address, temp.address);

			q->next = p;
			q = p;
		}
	}
	q->next = NULL;												//��������

	fclose(fp);													//�ر��ļ�

	return Head;
}

void Display_List(struct Node *Head)							//����������ʾ����
{
	struct Node *p;
	char sex;

	p=Head->next;
	while(p!=NULL)
	{
		if (p->sex == 1)										//�Ա���ʾΪM\F
		{
			sex='M';
		}
		else
		{
			sex='F';
		}

		printf("%-10s%-3d%-2c%-12s%8s%-20s\n", p->name, p->age, sex,p->phone,p->postcode,p->address);
		
		p=p->next;
	}
	printf("\n");
}

void Initial_Add(struct Node *Head,struct Node *Add)			//�����׽ڵ���Ӻ���
{
	struct Node *temp;											//������ʱ�ڵ�ָ�룬����ԭ�׽ڵ�Ľڵ��ַ

	temp = Head->next;
	Head->next = Add;
	Add->next = temp;
}

void Delete_AgeReach25(Node *Head)								//����ɾ��������ﵽ25������
{
	struct Node *p,*q;

	q = Head;
	p = q->next;
	while(p != NULL)
	{
		if(p->age >= 25)
		{
			q->next = p->next;
			free(p);											//�ͷ�ɾ���ڵ�Ŀռ�
			p = q->next;
		}
		else
		{
			q = p;
			p = p->next;
		}
	}
	printf("�ɹ�ɾ������������ﵽ25��ĳ�Ա��Ϣ\n");
}

void Caculate_MaleAge(struct Node *Head,double *Ave,int *Max)	//������������ϵ�м��㺯��
{
	struct Node *p,*q;
	int sum,count,max;

	q = Head;
	p = q->next;

	sum = 0;
	count = 0;
	max = 0;
	while(p != NULL)
	{
		if(p->sex == 1)
		{
			count++;
			sum = sum + p->age;									//���
			if(p->age > max)									//Ѱ�����ֵ
			{
				max = p->age;
			}
		}
		q = p;
		p = p->next;
	}

	*Ave = (double)sum/count;									//����ָ���Ӵ�����������
	*Max = max;
}

struct Node *Search_Node(struct Node *Head)						//����ڵ���Һ���
{
	char Name[20];
	struct Node *p;
	
	printf("��������Ҫ���ҵ�������\n");
	gets(Name);

	p = Head->next;
	while(1)
	{
		if(strcmp(Name,p->name) == 0)
		{
			return p;											//�ҵ������ص�ǰָ��
		}
		p = p->next;
	}
	return NULL;												//�Ҳ��������ؿ�ָ��
}

void Rewrite_Node(struct Node *Rewrite)							//����ڵ��޸ĺ���
{
	printf("��������Ҫ�޸ĵ����ݣ�����Ϊ��\n����\n����\n�Ա���1Ů0��\n�绰\n�ʱ�\n��ַ\n");

	gets(Rewrite->name);
	scanf("%d",&Rewrite->age);
	scanf("%d",&Rewrite->sex);
	getchar();													//���ջس������Ķ���Ļ��з�
	gets(Rewrite->phone);
	gets(Rewrite->postcode);
	gets(Rewrite->address);
}

void Save_List(struct Node *Head,char *FileAddress)				//���������溯��
{
	FILE *fp;
	struct Node *p;
	
	fp = fopen(FileAddress,"w");								//�򿪣��򴴽���ASCII�ļ�
	if(fp == NULL)												//���
	{
		printf("�򿪣��򴴽�������ļ�ʧ�ܣ�\n");
		exit(0);
	}

	p = Head->next;												//ָ�븳��ֵ
	while(p != NULL)											//ѭ��д��
	{
		fprintf(fp,"%-10s%-3d%-2c%-12s%8s%-20s\n", p->name, p->age,p->sex,p->phone,p->postcode,p->address);
		p = p->next;
	}

	fclose(fp);													//�ر��ļ�
}