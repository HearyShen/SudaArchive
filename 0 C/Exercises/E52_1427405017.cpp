/****************************
	1427405017
	����S
	E52
	2015-1-10 11:15
*****************************/
#include <stdio.h>
#include <stdlib.h>

struct Node														//����ṹ������struct Node����������
{
	int num;

	struct Node * next;
};

struct Node *Read_To_List(char *FileAddress);					//�����ļ�������������
void Arrange_Node(struct Node *Head);							//����ѡ������������ArrangeNode
void Write_To_Text(struct Node *Head);							//�����ı�д�뺯��WriteToText

void main()
{
	struct Node *head;

	head = Read_To_List("E52.dat");								//��ȡ�ļ����ݲ���ʾ
	Arrange_Node(head);											//����ѡ������������ArrangeNode
	printf("�������\n");
	Write_To_Text(head);										//�����ı�д�뺯��WriteToText
	printf("����ѱ�������Ŀ¼ E52.txt\n");
}

struct Node *Read_To_List(char *FileAddress)					//�����ļ�������������
{
	FILE *fp;
	struct Node *Head,*p,*q;
	int flag,temp;

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
		flag = fread(&temp,sizeof(int),1,fp);
		if(flag != 0)											//�Զ������ݽ��кϷ��ж�
		{
			p = (struct Node *)malloc(sizeof(struct Node));
			p->num = temp;

			q->next = p;
			q = p;
		}
	}
	q->next = NULL;												//��������

	fclose(fp);													//�ر��ļ�

	return Head;
}

void Arrange_Node(struct Node *Head)							//����ѡ������������Arrange_Node
{
	struct Node *pi,*qj,*p_min;
	int min,temp_min;

	pi = Head->next;

	while(pi->next != NULL)										//����ýṹ��ָ��pi����ѭ��
	{
		min = pi->num;
		qj = pi->next;
		while(qj != NULL)										//�ڲ��ýṹ��ָ��pj����ѭ��
		{
			if(qj->num < min)									//���ֽ�Сֵ
			{
				min = qj->num;
				p_min = qj;
			}
			qj = qj->next;
		}
		
		if(min != pi->num)										//��ѡ����ġ���Сֵ���Ե�
		{
			temp_min = p_min->num;
			p_min->num = pi->num;
			pi->num = temp_min;
		}
		pi = pi->next;
	}
}

void Write_To_Text(struct Node *Head)							//�����ļ�д�뺯��WriteToText
{
	FILE *Fp_Out;
	struct Node *p;

	Fp_Out = fopen("E52.txt","w");
	p = Head->next;

	while(p != NULL)											//������δ����
	{
		fprintf(Fp_Out,"%d\n",p->num);							//��������ļ�д��������Ϣ
		p = p->next;
	}

	fclose(Fp_Out);
}