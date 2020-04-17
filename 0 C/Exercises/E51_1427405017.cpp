/****************************
	1427405017
	沈家赟
	E51
	2015-1-10 10:30
*****************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Contactor			//定义结构体类型用于文件数据
{
	char name[20];			//姓名，在数据文件中不存在重复的姓名
	int age;				//年龄
	int sex;				//性别，0代表女性，1代表男性
	char phone[20];			//电话号码
	char postcode[10];		//邮政编码
	char address[100];		//通讯地址
};

struct Node					//定义结构体类型用于链表节点
{
	char name[20];			//姓名，在数据文件中不存在重复的姓名
	int age;				//年龄
	int sex;				//性别，0代表女性，1代表男性
	char phone[20];			//电话号码
	char postcode[10];		//邮政编码
	char address[100];		//通讯地址

	struct Node *next;		//指针域
};

struct Node *Read_To_List(char *FileAddress);					//声明文件读出至链表函数
void Display_List(struct Node *Head);							//声明链表显示函数
void Initial_Add(struct Node *Head,struct Node *Add);			//声明首节点添加函数
void Delete_AgeReach25(Node *Head);								//声明删除（年龄达到25）函数
void Caculate_MaleAge(struct Node *Head,double *Ave,int *Max);	//声明男性年龄系列计算函数
struct Node *Search_Node(struct Node *Head);					//声明节点查找函数
void Rewrite_Node(struct Node *Rewrite);						//声明节点修改函数
void Save_List(struct Node *Head,char *FileAddress);			//声明链表保存函数

void main()
{
	struct Node *head,*add,*rewrite;
	double ave;
	int max;

	head = Read_To_List("D:\\contact.dat");					//(1-3).读取文件数据并显示
	Display_List(head);

	printf("请输入需要增加的内容，依次为：\n姓名\n年龄\n性别（男1女0）\n电话\n邮编\n地址\n");
	add = (struct Node *)malloc(sizeof(struct Node));
	gets(add->name);
	scanf("%d",&add->age);
	scanf("%d",&add->sex);
	getchar();
	gets(add->phone);
	gets(add->postcode);
	gets(add->address);
	printf("\n");
	Initial_Add(head,add);									//(4).插入至首节点，并显示
	printf("添加完成后，当前链表为：\n");
	Display_List(head);

	Delete_AgeReach25(head);								//(5).删除年龄达到25的节点并显示
	printf("删除完成后，当前链表为：\n");
	Display_List(head);

	Caculate_MaleAge(head,&ave,&max);						//(6).计算男性平均年龄和最大年龄并显示
	printf("男性平均年龄为：%lf\n男性最大年龄为：%d\n",ave,max);

	rewrite = Search_Node(head);							//(7).查找节点，并修改
	if(rewrite != NULL)
	{
		printf("姓名存在\n");
		Rewrite_Node(rewrite);
		printf("修改后的链表为：\n");
		Display_List(head);
	}
	else
	{
		printf("姓名不存在！\n");
	}

	Save_List(head,"D:\\res.txt");							//(8).保存链表数据
	printf("链表数据已保存至D:\res.txt");
}

struct Node *Read_To_List(char *FileAddress)					//定义文件读出至链表函数
{
	FILE *fp;
	struct Contactor temp;
	struct Node *Head,*p,*q;
	int flag;

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
		flag = fread(&temp,sizeof(struct Contactor),1,fp);
		if(flag != 0)											//对读出数据进行合法判断
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
	q->next = NULL;												//结束链表

	fclose(fp);													//关闭文件

	return Head;
}

void Display_List(struct Node *Head)							//定义链表显示函数
{
	struct Node *p;
	char sex;

	p=Head->next;
	while(p!=NULL)
	{
		if (p->sex == 1)										//性别显示为M\F
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

void Initial_Add(struct Node *Head,struct Node *Add)			//定义首节点添加函数
{
	struct Node *temp;											//定义临时节点指针，保存原首节点的节点地址

	temp = Head->next;
	Head->next = Add;
	Add->next = temp;
}

void Delete_AgeReach25(Node *Head)								//定义删除（年龄达到25）函数
{
	struct Node *p,*q;

	q = Head;
	p = q->next;
	while(p != NULL)
	{
		if(p->age >= 25)
		{
			q->next = p->next;
			free(p);											//释放删除节点的空间
			p = q->next;
		}
		else
		{
			q = p;
			p = p->next;
		}
	}
	printf("成功删除链表中年龄达到25岁的成员信息\n");
}

void Caculate_MaleAge(struct Node *Head,double *Ave,int *Max)	//定义男性年龄系列计算函数
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
			sum = sum + p->age;									//求和
			if(p->age > max)									//寻找最大值
			{
				max = p->age;
			}
		}
		q = p;
		p = p->next;
	}

	*Ave = (double)sum/count;									//利用指针间接传递至主函数
	*Max = max;
}

struct Node *Search_Node(struct Node *Head)						//定义节点查找函数
{
	char Name[20];
	struct Node *p;
	
	printf("请输入您要查找的姓名：\n");
	gets(Name);

	p = Head->next;
	while(1)
	{
		if(strcmp(Name,p->name) == 0)
		{
			return p;											//找到，返回当前指针
		}
		p = p->next;
	}
	return NULL;												//找不到，返回空指针
}

void Rewrite_Node(struct Node *Rewrite)							//定义节点修改函数
{
	printf("请输入需要修改的内容，依次为：\n姓名\n年龄\n性别（男1女0）\n电话\n邮编\n地址\n");

	gets(Rewrite->name);
	scanf("%d",&Rewrite->age);
	scanf("%d",&Rewrite->sex);
	getchar();													//吸收回车产生的多余的换行符
	gets(Rewrite->phone);
	gets(Rewrite->postcode);
	gets(Rewrite->address);
}

void Save_List(struct Node *Head,char *FileAddress)				//定义链表保存函数
{
	FILE *fp;
	struct Node *p;
	
	fp = fopen(FileAddress,"w");								//打开（或创建）ASCII文件
	if(fp == NULL)												//检查
	{
		printf("打开（或创建）输出文件失败！\n");
		exit(0);
	}

	p = Head->next;												//指针赋初值
	while(p != NULL)											//循环写入
	{
		fprintf(fp,"%-10s%-3d%-2c%-12s%8s%-20s\n", p->name, p->age,p->sex,p->phone,p->postcode,p->address);
		p = p->next;
	}

	fclose(fp);													//关闭文件
}