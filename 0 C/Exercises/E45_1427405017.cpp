/****************************
	1427405017
	沈家赟
	E45
	2014-12-25 16:47
****************************/
#include <stdio.h>
#include <stdlib.h>

struct Node									//定义结构体类型Node用于构成链表节点
{
	int num;

	struct Node * next;
};

struct Node * InputList();					//声明链表输入函数InputList
void Display(struct Node *Head,int K);		//声明链表显示函数Display
void DelEven(struct Node *Head);			//声明链表偶数节点删除函数DelEven

void main()
{
	struct Node *head;						//定义链表头指针head
	int k;									//定义链表显示的换行参数k

	printf("请输入若干个节点以构成链表（输入-9999时结束输入链表）：\n");
	head = InputList();						//调用链表输入函数，显示初始链表

	k=3;
	printf("您输入的链表如下：\n");
	Display(head,k);						//调用链表显示函数

	DelEven(head);							//调用链表偶数节点删除函数

	printf("删除偶数节点的链表如下：\n");
	Display(head,k);						//调用链表输入函数，显示偶数节点删除后的链表
}

struct Node * InputList()					//定义链表输入函数InputList
{
	struct Node *Head,*p,*q;
	int Num;

	Head = (struct Node *)malloc(sizeof(struct Node));		//为链表头节点申请空间
	q = Head;												//q指针也指向头节点，为后续处理做准备

	while(1)												//无条件循环
	{
		scanf("%d",&Num);
		if(Num == -9999)									//输入值，一旦输入-9999则退出，不再申请新节点
		{
			break;
		}
		p = (struct Node *)malloc(sizeof(struct Node));		//申请下一个节点的空间，p指针指向新节点
		q->next = p;										//新节点地址赋值给前节点，保证链表连续性
		p->num = Num;										//在新节点中存放符合条件的输入值

		q=p;												//q指向当前处理的节点，为下一次循环做准备
	}
	q->next = NULL;											//循环输入结束后，最后一个节点指针为NULL
	return Head;											//返回输入链表的头指针给主函数
}

void Display(struct Node *Head,int K)						//定义链表显示函数Display
{
	struct Node *Ptr;										//定义指针Ptr
	int Count;

	Count=0;
	Ptr = Head->next;										//Ptr指向第一个有效节点
	while(Ptr != NULL)										//未到链表结束，则循环显示
	{
		printf("%5d",Ptr->num);
		Ptr = Ptr->next;									//当前项显示后，指向下一项
		Count++;
		if(Count%K == 0)									//按需换行
		{
			printf("\n");
		}
	}
	printf("\n");
}

void DelEven(struct Node *Head)						//定义链表偶数节点删除函数
{
	struct Node *q,*p;
	int Count;

	Count=0;
	p = Head->next;											//p指向第一个有效节点
	while(p != NULL)
	{
		Count++;											//循环符合一次，计数器+1
		if(Count%2 == 0)									//偶数节点情况
		{
			q->next = p->next;								//当前节点前一项连接至当前节点后一项，保证链表连续
			free(p);										//释放当前偶数节点
			p = q->next;									//p指针指向新节点，为下一次循环做准备
		}
		else
		{
			q = p;											//q前进一项
			p = p->next;									//p也前进一项
		}
	}
}