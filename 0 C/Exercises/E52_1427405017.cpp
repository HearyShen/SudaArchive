/****************************
	1427405017
	沈家赟
	E52
	2015-1-10 11:15
*****************************/
#include <stdio.h>
#include <stdlib.h>

struct Node														//定义结构体类型struct Node，用于链表
{
	int num;

	struct Node * next;
};

struct Node *Read_To_List(char *FileAddress);					//声明文件读出至链表函数
void Arrange_Node(struct Node *Head);							//声明选择法链表排序函数ArrangeNode
void Write_To_Text(struct Node *Head);							//声明文本写入函数WriteToText

void main()
{
	struct Node *head;

	head = Read_To_List("E52.dat");								//读取文件数据并显示
	Arrange_Node(head);											//调用选择法链表排序函数ArrangeNode
	printf("排序完成\n");
	Write_To_Text(head);										//调用文本写入函数WriteToText
	printf("结果已保存至根目录 E52.txt\n");
}

struct Node *Read_To_List(char *FileAddress)					//定义文件读出至链表函数
{
	FILE *fp;
	struct Node *Head,*p,*q;
	int flag,temp;

	fp = fopen(FileAddress,"rb");								//打开二进制文件
	if(fp == NULL)												//检查
	{
		printf("打开文件失败！\n");
		exit(0);
	}

	Head = (struct Node *)malloc(sizeof(struct Node));			//开始创建链表
	q = Head;

	while(!feof(fp))											//读出至链表
	{
		flag = fread(&temp,sizeof(int),1,fp);
		if(flag != 0)											//对读出数据进行合法判断
		{
			p = (struct Node *)malloc(sizeof(struct Node));
			p->num = temp;

			q->next = p;
			q = p;
		}
	}
	q->next = NULL;												//结束链表

	fclose(fp);													//关闭文件

	return Head;
}

void Arrange_Node(struct Node *Head)							//定义选择法链表排序函数Arrange_Node
{
	struct Node *pi,*qj,*p_min;
	int min,temp_min;

	pi = Head->next;

	while(pi->next != NULL)										//外层用结构体指针pi控制循环
	{
		min = pi->num;
		qj = pi->next;
		while(qj != NULL)										//内层用结构体指针pj控制循环
		{
			if(qj->num < min)									//出现较小值
			{
				min = qj->num;
				p_min = qj;
			}
			qj = qj->next;
		}
		
		if(min != pi->num)										//与选择出的“最小值”对调
		{
			temp_min = p_min->num;
			p_min->num = pi->num;
			pi->num = temp_min;
		}
		pi = pi->next;
	}
}

void Write_To_Text(struct Node *Head)							//定义文件写入函数WriteToText
{
	FILE *Fp_Out;
	struct Node *p;

	Fp_Out = fopen("E52.txt","w");
	p = Head->next;

	while(p != NULL)											//若链表未结束
	{
		fprintf(Fp_Out,"%d\n",p->num);							//则向输出文件写入链表信息
		p = p->next;
	}

	fclose(Fp_Out);
}