/****************************
	1427405017
	����S
	E49
	2015-1-8 16:45
*****************************/
#include <stdio.h>
#include <stdlib.h>

struct Node											//����ṹ������struct Node����������
{
	int num;

	struct Node * next;
};

struct Node * ReadToNode(FILE *Fp_In);				//�����ı����ݶ�������ReadToNode
void ArrangeNode(struct Node *Head);				//����ѡ������������ArrangeNode
void WriteToText(FILE *Fp_Out,struct Node *Head);	//�����ı�д�뺯��WriteToText

void main()
{
	FILE *fp_in,*fp_out;							//�����ļ�����ָ�룬�����������
	struct Node *head;

	fp_in = fopen("1.txt","r");						//��ԭʼ�����ı��ļ�
	if(fp_in == NULL)
	{
		printf("��ȡ�ļ�ʧ�ܣ�\n");
		exit(0);
	}

	head = ReadToNode(fp_in);						//�����ı����ݶ�������ReadToNode
	ArrangeNode(head);								//����ѡ������������ArrangeNode

	fp_out = fopen("2.txt","w");					//�򿪻򴴽���������������ı��ļ�
	if(fp_out == NULL)
	{
		printf("д���ļ��򿪣��򴴽���ʧ�ܣ�\n");
		exit(0);
	}

	WriteToText(fp_out,head);						//�����ı�д�뺯��WriteToText

	fclose(fp_in);									//�ر��ļ�
	fclose(fp_out);									//�ر��ļ�
}

struct Node * ReadToNode(FILE *Fp_In)				//�����ı����ݶ�������ReadToNode
{
	struct Node *Head,*q,*p;
	int t,t_num;

	Head = (struct Node *)malloc(sizeof(struct Node));
	q = Head;

	while(!feof(Fp_In))								//���ļ�����δ����ʱ
	{
		t = fscanf(Fp_In,"%d",&t_num);				//�����������
		if(t == 1)
		{
			p = (struct Node *)malloc(sizeof(struct Node));
			q->next = p;
			q = p;

			p->num=t_num;
		}
	}
	p->next = NULL;									//��������
	
	return Head;
}

void ArrangeNode(struct Node *Head)					//����ѡ������������ArrangeNode
{
	struct Node *pi,*qj,*p_min;
	int min,temp_min;

	pi = Head->next;

	while(pi->next != NULL)							//����ýṹ��ָ��pi����ѭ��
	{
		min = pi->num;
		qj = pi->next;
		while(qj != NULL)							//�ڲ��ýṹ��ָ��pj����ѭ��
		{
			if(qj->num < min)						//���ֽ�Сֵ
			{
				min = qj->num;
				p_min = qj;
			}
			qj = qj->next;
		}
		
		if(min != pi->num)							//��ѡ����ġ���Сֵ���Ե�
		{
			temp_min = p_min->num;
			p_min->num = pi->num;
			pi->num = temp_min;
		}
		pi = pi->next;
	}
}

void WriteToText(FILE *Fp_Out,struct Node *Head)	//�����ļ�д�뺯��WriteToText
{
	struct Node *p;

	p = Head->next;

	while(p != NULL)								//������δ����
	{
		fprintf(Fp_Out,"%d\n",p->num);				//��������ļ�д��������Ϣ
		p = p->next;
	}
}