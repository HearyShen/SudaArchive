/*******************************
	1427405017
	沈家赟
	E47
	2014-12-28  11:00
*******************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Info						//定义结构体数据类型Info
{
	char name[30];
	char tel[20];
	int sex;
	int age;
	char mail[10];
	char address[50];

	struct Info * next;
};

struct Info * InputList();							//声明首次运行输入函数
void Functions(struct Info *Head);					//声明功能选择函数
void Add(struct Info *Head);						//声明录入（添加）函数
void Delete(struct Info *Head);						//声明查找删除函数
void Rewrite(struct Info *Head);					//声明查找修改函数
void Search(struct Info *Head);						//声明查询函数
int NameEqual(char NameInput[],char NameInList[]);	//声明姓名对比函数
void DisplayInfo(struct Info *Target);				//声明节点数据显示函数

void main()
{
	struct Info *head;
	int k,judge;

	printf("通讯录内还没有内容，请先输入信息。\n请依次输入需要存储的信息：\n姓名\n电话\n移动电话\n邮编\n通讯地址\n\n");
	head = InputList();								//调用首次输入函数，第一次运行时先输入数据

	Functions(head);								//调用功能选择函数
}

struct Info * InputList()							//定义首次输入函数
{
	struct Info *Head,*q,*p;
	char Name[30];

	Head = (struct Info *)malloc(sizeof(struct Info));
	q = Head;
	while(1)
	{
		printf("\n*************************************************\n");
		printf("姓名（不输入，则结束）：");
		gets(Name);
		if(Name[0] == '\0')							//一旦未输入，则结束
		{
			break;
		}
		p = (struct Info *)malloc(sizeof(struct Info));		//申请新节点
		q->next = p;

		strcpy(p->name,Name);

		printf("电话：");
		gets(p->tel);

		printf("性别（男为1,女为0）：");
		scanf("%d",&p->sex);

		printf("年龄：");
		scanf("%d",&p->age);

		printf("邮编：");
		getchar();				//吸收前一次结尾Enter产生的换行符，否则下一个gets无法正常运行
		gets(p->mail);

		printf("通讯地址：");
		gets(p->address);

		q=p;
	}
	q->next = NULL;							//循环结束后，尾节点指向NULL
	return Head;
}

void Functions(struct Info *Head)			//定义功能选择函数，提供录入，删除，修改，查询功能
{
	int judge;
	
	while(1)
	{
		printf("该通讯录管理程序目前提供一下功能：\n0)退出	1)录入(添加)	2)删除	3)修改	4)查询\n");
		printf("请输入所需功能序号，按Enter运行\n输入：");
		scanf("%d",&judge);

		getchar();			//吸收上一个scanf结尾按下的Enter，否则下一个gets无法正常运行

		switch(judge)
		{
		case 0: return;						//输入0则退出
		case 1: Add(Head);break;			//输入1则调用录入（添加）函数
		case 2: Delete(Head);break;			//输入2则调用删除函数
		case 3: Rewrite(Head);break;		//输入3则调用修改函数
		case 4: Search(Head);break;			//输入4则调用查询函数
		default: printf("您输入的序号有误！请查验后再试。\n\n");
		}
	}
}

void Add(struct Info *Head)					//定义录入（添加）函数
{
	struct Info *q,*p;
	char Name[30];

	q = Head;
	p = Head->next;

	while(p->next != NULL)					//找到链表中的尾节点
	{
		q=p;
		p=p->next;
	}
	q=p;									//q指向尾节点
	
	printf("\n*************************************************\n");
	printf("录入(添加)模块开始...\n");
	while(1)
	{
		printf("姓名（不输入，则结束）：");
		gets(Name);
		if(Name[0] == '\0')
		{
			break;
		}
		p = (struct Info *)malloc(sizeof(struct Info));		//申请新节点
		q->next = p;						//连接至新节点

		strcpy(p->name,Name);

		printf("电话：");
		gets(p->tel);

		printf("性别（男为1,女为0）：");
		scanf("%d",&p->sex);

		printf("年龄：");
		scanf("%d",&p->age);

		printf("邮编：");
		getchar();				//吸收前一次结尾Enter产生的换行符，否则下一个gets无法正常运行
		gets(p->mail);

		printf("通讯地址：");
		gets(p->address);

		q=p;
	}
	q->next = NULL;
	printf("录入(添加)模块结束.\n");
	printf("\n*************************************************\n");
}

void Delete(struct Info *Head)				//定义查找删除函数
{
	struct Info *q,*p;
	char Name[30];
	int flag;

	q = Head;
	p = Head->next;

	flag=0;
	printf("\n*************************************************\n");
	printf("删除模块开始...\n");
	printf("请输入需要删除对象的姓名：\n");
	gets(Name);
	
	while(p != NULL)
	{
		if(NameEqual(Name,p->name) == 1)	//调用姓名比对函数
		{
			flag=1;

			q->next = p->next;
			free(p);						//一旦找到，则释放该节点的内存空间
			p=q->next;

			printf("删除完毕.\n");

			break;
		}
		q=p;
		p=p->next;
	}
	if(flag==0)
	{
		printf("通讯录中没有这个对象，未执行删除操作！\n");		//利用flag，提供提示信息
	}

	printf("删除模块结束.\n");
	printf("\n*************************************************\n");
}

void Rewrite(struct Info *Head)				//定义查找修改函数
{
	struct Info *q,*p;
	char Name[30];
	int flag;

	q = Head;
	p = Head->next;
	
	flag=0;
	printf("\n*************************************************\n");
	printf("修改模块开始...\n");
	printf("请输入需要修改对象的姓名：\n");
	gets(Name);

	while(p != NULL)
	{
		if(NameEqual(Name,p->name) == 1)	//调用姓名比对函数
		{
			flag=1;

			printf("该对象原有信息为：\n");
			DisplayInfo(p);					//调用节点数据显示函数
			
			printf("请修改：\n");
			
			printf("姓名：");
			gets(p->name);

			printf("电话：");
			gets(p->tel);

			printf("性别（男为1,女为0）：");
			scanf("%d",&p->sex);

			printf("年龄：");
			scanf("%d",&p->age);

			printf("邮编：");
			getchar();				//吸收前一次结尾Enter产生的换行符
			gets(p->mail);

			printf("通讯地址：");
			getchar();				//吸收前一次结尾Enter产生的换行符
			gets(p->address);

			break;
		}
		q=p;
		p=p->next;
	}
	if(flag==0)
	{
		printf("通讯录中没有这个对象，未执行修改操作！\n");		//利用flag，提供提示信息
	}
	printf("修改模块结束.\n");
	printf("\n*************************************************\n");
}

void Search(struct Info *Head)					//定义查询函数
{
	struct Info *q,*p;
	char Name[30];
	int flag;

	q = Head;
	p = Head->next;

	flag=0;
	printf("\n*************************************************\n");
	printf("查询模块开始...\n");
	printf("请输入需要查询的对象的姓名：\n");
	gets(Name);

	while(p != NULL)
	{
		if(NameEqual(Name,p->name) == 1)		//调用姓名比对函数
		{
			flag=1;
			printf("该对象信息为：\n");
			DisplayInfo(p);						//调用节点数据显示函数

			break;
		}
		q=p;
		p=p->next;
	}
	if(flag==0)
	{
		printf("通讯录中没有这个对象，无法显示相关信息！\n");		//利用flag，提供提示信息
	}
	printf("查询模块结束.\n");
	printf("\n*************************************************\n");
}

int NameEqual(char NameInput[],char NameInList[])		//定义姓名比对函数
{
	int l_input,l_list,i;

	l_input = strlen(NameInput);
	l_list = strlen(NameInList);
	
	if(l_input == l_list)
	{
		for(i=0;i<l_input;i++)
		{
			if(NameInput[i] != NameInList[i])		//长度相等，但出现不相等元素
			{
				return 0;
			}
		}
		return 1;				//成功运行到循环结束，则必相等
	}
	else
	{
		return 0;				//长度不等，直接返回0
	}
}

void DisplayInfo(struct Info *Target)		//定义节点数据显示函数
{
	printf("------------------------------------\n");	
	printf("姓名：");
	printf("%-10s\n",Target->name);			//10列，左对齐

	printf("电话：");
	printf("%-12s\n",Target->tel);			//12列，左对齐

	printf("性别（男为M,女为F）：");
	if(Target->sex == 1)
	{
		printf(" M\n");						//2列，右对齐
	}
	else if(Target->sex == 0)
	{
		printf(" F\n");						//2列，右对齐
	}
	else
	{
		printf("存储信息有误！\n");
	}

	printf("年龄：");
	printf("%-3d\n",Target->age);			//3列，左对齐

	printf("邮编：");
	printf("%8s\n",Target->mail);			//8列，右对齐

	printf("通讯地址：");
	printf("%-20s\n",Target->address);		//20列，左对齐
	printf("------------------------------------\n");
}