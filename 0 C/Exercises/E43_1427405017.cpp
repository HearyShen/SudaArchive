/********************************
	1427405017
	����S
	E43
	2014-12-10 11:52
*********************************/
#include <stdio.h>
#include <string.h>

void delchar(char *p,int k,int n);			//�����ַ���ɾ������

void main()
{
	char s[1000];
	int k,n,l;

	printf("������һ���ַ�����\n");			//�����������
	gets(s);
	printf("����ȥ���ַ����ӵ�k���ַ���ʼ��n���ַ�����ֱ�������Ӧ��k��n��\n");
	printf("k=");
	scanf("%d",&k);
	printf("n=");
	scanf("%d",&n);

	l=strlen(s);
	if(k>=1 && n>=0 && (k+n-1)<=l)			//�ж���������
	{
		delchar(s,k,n);						//�����ַ���ɾ������
		printf("������ɺ���ַ���Ϊ��\n");		//��ʾ���
		puts(s);
	}
	else									//�ж�����������
	{
		printf("�������k��n������Ҫ��\n kΪ��������nΪ��������ɾ����Χ��ӦԽ�磡\n");
	}
}

void delchar(char *p,int k,int n)			//�����ַ���ɾ������
{
	int i;
	int l;

	l=strlen(p);
	for(i=k-1;i<l-n;i++)						//ɾȥ��Ӧ�ַ�����ǰ��������
	{
		p[i]=p[i+n];
	}
	p[i]='\0';									//p[l-n]��ֵ'\0'���˴�������ַ���
}