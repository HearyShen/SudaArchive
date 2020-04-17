/****************************
	1427405017
	沈家赟
	E49
	2015-1-8 16:45
*****************************/
#include <stdio.h>
#include <stdlib.h>

struct Node											//定义结构体类型struct Node，用于链表
{
	int num;

	struct Node * next;
};

struct Node * ReadToNode(FILE *Fp_In);				//声明文本数据读出函数ReadToNode
void ArrangeNode(struct Node *Head);				//声明选择法链表排序函数ArrangeNode
void WriteToText(FILE *Fp_Out,struct Node *Head);	//声明文本写入函数WriteToText

void main()
{
	FILE *fp_in,*fp_out;							//定义文件类型指针，用于输入输出
	struct Node *head;

	fp_in = fopen("1.txt","r");						//打开原始数据文本文件
	if(fp_in == NULL)
	{
		printf("读取文件失败！\n");
		exit(0);
	}

	head = ReadToNode(fp_in);						//调用文本数据读出函数ReadToNode
	ArrangeNode(head);								//调用选择法链表排序函数ArrangeNode

	fp_out = fopen("2.txt","w");					//打开或创建排序数据输出的文本文件
	if(fp_out == NULL)
	{
		printf("写入文件打开（或创建）失败！\n");
		exit(0);
	}

	WriteToText(fp_out,head);						//调用文本写入函数WriteToText

	fclose(fp_in);									//关闭文件
	fclose(fp_out);									//关闭文件
}

struct Node * ReadToNode(FILE *Fp_In)				//定义文本数据读出函数ReadToNode
{
	struct Node *Head,*q,*p;
	int t,t_num;

	Head = (struct Node *)malloc(sizeof(struct Node));
	q = Head;

	while(!feof(Fp_In))								//当文件数据未结束时
	{
		t = fscanf(Fp_In,"%d",&t_num);				//逐个读出数据
		if(t == 1)
		{
			p = (struct Node *)malloc(sizeof(struct Node));
			q->next = p;
			q = p;

			p->num=t_num;
		}
	}
	p->next = NULL;									//结束链表
	
	return Head;
}

void ArrangeNode(struct Node *Head)					//定义选择法链表排序函数ArrangeNode
{
	struct Node *pi,*qj,*p_min;
	int min,temp_min;

	pi = Head->next;

	while(pi->next != NULL)							//外层用结构体指针pi控制循环
	{
		min = pi->num;
		qj = pi->next;
		while(qj != NULL)							//内层用结构体指针pj控制循环
		{
			if(qj->num < min)						//出现较小值
			{
				min = qj->num;
				p_min = qj;
			}
			qj = qj->next;
		}
		
		if(min != pi->num)							//与选择出的“最小值”对调
		{
			temp_min = p_min->num;
			p_min->num = pi->num;
			pi->num = temp_min;
		}
		pi = pi->next;
	}
}

void WriteToText(FILE *Fp_Out,struct Node *Head)	//定义文件写入函数WriteToText
{
	struct Node *p;

	p = Head->next;

	while(p != NULL)								//若链表未结束
	{
		fprintf(Fp_Out,"%d\n",p->num);				//则向输出文件写入链表信息
		p = p->next;
	}
}