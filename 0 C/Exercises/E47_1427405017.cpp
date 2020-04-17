/*******************************
	1427405017
	����S
	E47
	2014-12-28  11:00
*******************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Info						//����ṹ����������Info
{
	char name[30];
	char tel[20];
	int sex;
	int age;
	char mail[10];
	char address[50];

	struct Info * next;
};

struct Info * InputList();							//�����״��������뺯��
void Functions(struct Info *Head);					//��������ѡ����
void Add(struct Info *Head);						//����¼�루��ӣ�����
void Delete(struct Info *Head);						//��������ɾ������
void Rewrite(struct Info *Head);					//���������޸ĺ���
void Search(struct Info *Head);						//������ѯ����
int NameEqual(char NameInput[],char NameInList[]);	//���������ԱȺ���
void DisplayInfo(struct Info *Target);				//�����ڵ�������ʾ����

void main()
{
	struct Info *head;
	int k,judge;

	printf("ͨѶ¼�ڻ�û�����ݣ�����������Ϣ��\n������������Ҫ�洢����Ϣ��\n����\n�绰\n�ƶ��绰\n�ʱ�\nͨѶ��ַ\n\n");
	head = InputList();								//�����״����뺯������һ������ʱ����������

	Functions(head);								//���ù���ѡ����
}

struct Info * InputList()							//�����״����뺯��
{
	struct Info *Head,*q,*p;
	char Name[30];

	Head = (struct Info *)malloc(sizeof(struct Info));
	q = Head;
	while(1)
	{
		printf("\n*************************************************\n");
		printf("�����������룬���������");
		gets(Name);
		if(Name[0] == '\0')							//һ��δ���룬�����
		{
			break;
		}
		p = (struct Info *)malloc(sizeof(struct Info));		//�����½ڵ�
		q->next = p;

		strcpy(p->name,Name);

		printf("�绰��");
		gets(p->tel);

		printf("�Ա���Ϊ1,ŮΪ0����");
		scanf("%d",&p->sex);

		printf("���䣺");
		scanf("%d",&p->age);

		printf("�ʱࣺ");
		getchar();				//����ǰһ�ν�βEnter�����Ļ��з���������һ��gets�޷���������
		gets(p->mail);

		printf("ͨѶ��ַ��");
		gets(p->address);

		q=p;
	}
	q->next = NULL;							//ѭ��������β�ڵ�ָ��NULL
	return Head;
}

void Functions(struct Info *Head)			//���幦��ѡ�������ṩ¼�룬ɾ�����޸ģ���ѯ����
{
	int judge;
	
	while(1)
	{
		printf("��ͨѶ¼�������Ŀǰ�ṩһ�¹��ܣ�\n0)�˳�	1)¼��(���)	2)ɾ��	3)�޸�	4)��ѯ\n");
		printf("���������蹦����ţ���Enter����\n���룺");
		scanf("%d",&judge);

		getchar();			//������һ��scanf��β���µ�Enter��������һ��gets�޷���������

		switch(judge)
		{
		case 0: return;						//����0���˳�
		case 1: Add(Head);break;			//����1�����¼�루��ӣ�����
		case 2: Delete(Head);break;			//����2�����ɾ������
		case 3: Rewrite(Head);break;		//����3������޸ĺ���
		case 4: Search(Head);break;			//����4����ò�ѯ����
		default: printf("�����������������������ԡ�\n\n");
		}
	}
}

void Add(struct Info *Head)					//����¼�루��ӣ�����
{
	struct Info *q,*p;
	char Name[30];

	q = Head;
	p = Head->next;

	while(p->next != NULL)					//�ҵ������е�β�ڵ�
	{
		q=p;
		p=p->next;
	}
	q=p;									//qָ��β�ڵ�
	
	printf("\n*************************************************\n");
	printf("¼��(���)ģ�鿪ʼ...\n");
	while(1)
	{
		printf("�����������룬���������");
		gets(Name);
		if(Name[0] == '\0')
		{
			break;
		}
		p = (struct Info *)malloc(sizeof(struct Info));		//�����½ڵ�
		q->next = p;						//�������½ڵ�

		strcpy(p->name,Name);

		printf("�绰��");
		gets(p->tel);

		printf("�Ա���Ϊ1,ŮΪ0����");
		scanf("%d",&p->sex);

		printf("���䣺");
		scanf("%d",&p->age);

		printf("�ʱࣺ");
		getchar();				//����ǰһ�ν�βEnter�����Ļ��з���������һ��gets�޷���������
		gets(p->mail);

		printf("ͨѶ��ַ��");
		gets(p->address);

		q=p;
	}
	q->next = NULL;
	printf("¼��(���)ģ�����.\n");
	printf("\n*************************************************\n");
}

void Delete(struct Info *Head)				//�������ɾ������
{
	struct Info *q,*p;
	char Name[30];
	int flag;

	q = Head;
	p = Head->next;

	flag=0;
	printf("\n*************************************************\n");
	printf("ɾ��ģ�鿪ʼ...\n");
	printf("��������Ҫɾ�������������\n");
	gets(Name);
	
	while(p != NULL)
	{
		if(NameEqual(Name,p->name) == 1)	//���������ȶԺ���
		{
			flag=1;

			q->next = p->next;
			free(p);						//һ���ҵ������ͷŸýڵ���ڴ�ռ�
			p=q->next;

			printf("ɾ�����.\n");

			break;
		}
		q=p;
		p=p->next;
	}
	if(flag==0)
	{
		printf("ͨѶ¼��û���������δִ��ɾ��������\n");		//����flag���ṩ��ʾ��Ϣ
	}

	printf("ɾ��ģ�����.\n");
	printf("\n*************************************************\n");
}

void Rewrite(struct Info *Head)				//��������޸ĺ���
{
	struct Info *q,*p;
	char Name[30];
	int flag;

	q = Head;
	p = Head->next;
	
	flag=0;
	printf("\n*************************************************\n");
	printf("�޸�ģ�鿪ʼ...\n");
	printf("��������Ҫ�޸Ķ����������\n");
	gets(Name);

	while(p != NULL)
	{
		if(NameEqual(Name,p->name) == 1)	//���������ȶԺ���
		{
			flag=1;

			printf("�ö���ԭ����ϢΪ��\n");
			DisplayInfo(p);					//���ýڵ�������ʾ����
			
			printf("���޸ģ�\n");
			
			printf("������");
			gets(p->name);

			printf("�绰��");
			gets(p->tel);

			printf("�Ա���Ϊ1,ŮΪ0����");
			scanf("%d",&p->sex);

			printf("���䣺");
			scanf("%d",&p->age);

			printf("�ʱࣺ");
			getchar();				//����ǰһ�ν�βEnter�����Ļ��з�
			gets(p->mail);

			printf("ͨѶ��ַ��");
			getchar();				//����ǰһ�ν�βEnter�����Ļ��з�
			gets(p->address);

			break;
		}
		q=p;
		p=p->next;
	}
	if(flag==0)
	{
		printf("ͨѶ¼��û���������δִ���޸Ĳ�����\n");		//����flag���ṩ��ʾ��Ϣ
	}
	printf("�޸�ģ�����.\n");
	printf("\n*************************************************\n");
}

void Search(struct Info *Head)					//�����ѯ����
{
	struct Info *q,*p;
	char Name[30];
	int flag;

	q = Head;
	p = Head->next;

	flag=0;
	printf("\n*************************************************\n");
	printf("��ѯģ�鿪ʼ...\n");
	printf("��������Ҫ��ѯ�Ķ����������\n");
	gets(Name);

	while(p != NULL)
	{
		if(NameEqual(Name,p->name) == 1)		//���������ȶԺ���
		{
			flag=1;
			printf("�ö�����ϢΪ��\n");
			DisplayInfo(p);						//���ýڵ�������ʾ����

			break;
		}
		q=p;
		p=p->next;
	}
	if(flag==0)
	{
		printf("ͨѶ¼��û����������޷���ʾ�����Ϣ��\n");		//����flag���ṩ��ʾ��Ϣ
	}
	printf("��ѯģ�����.\n");
	printf("\n*************************************************\n");
}

int NameEqual(char NameInput[],char NameInList[])		//���������ȶԺ���
{
	int l_input,l_list,i;

	l_input = strlen(NameInput);
	l_list = strlen(NameInList);
	
	if(l_input == l_list)
	{
		for(i=0;i<l_input;i++)
		{
			if(NameInput[i] != NameInList[i])		//������ȣ������ֲ����Ԫ��
			{
				return 0;
			}
		}
		return 1;				//�ɹ����е�ѭ��������������
	}
	else
	{
		return 0;				//���Ȳ��ȣ�ֱ�ӷ���0
	}
}

void DisplayInfo(struct Info *Target)		//����ڵ�������ʾ����
{
	printf("------------------------------------\n");	
	printf("������");
	printf("%-10s\n",Target->name);			//10�У������

	printf("�绰��");
	printf("%-12s\n",Target->tel);			//12�У������

	printf("�Ա���ΪM,ŮΪF����");
	if(Target->sex == 1)
	{
		printf(" M\n");						//2�У��Ҷ���
	}
	else if(Target->sex == 0)
	{
		printf(" F\n");						//2�У��Ҷ���
	}
	else
	{
		printf("�洢��Ϣ����\n");
	}

	printf("���䣺");
	printf("%-3d\n",Target->age);			//3�У������

	printf("�ʱࣺ");
	printf("%8s\n",Target->mail);			//8�У��Ҷ���

	printf("ͨѶ��ַ��");
	printf("%-20s\n",Target->address);		//20�У������
	printf("------------------------------------\n");
}