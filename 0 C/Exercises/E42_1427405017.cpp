/********************************
	1427405017
	����S
	E42
	2014-12-10 11:09
*********************************/
#include <stdio.h>
#include <string.h>

void JudgeReverse(char C[],char Judge[]);				//���������жϺ���

void main()
{
	char c[1000],judge[100];

	printf("������һ���ַ�����\n 1.���ַ�Ϊ���ģ�����ʾTRUE��������ʾFALSE\n 2.Ӣ���ַ������ִ�Сд\n");
	gets(c);

	JudgeReverse(c,judge);								//���û����жϺ���
	puts(judge);
}

void JudgeReverse(char C[],char Judge[])				//��������жϺ���
{
	int i;
	int j;
	int l;
	int mid;

	l=strlen(C);
	//printf("l=%d\n",l);
	for(i=0;i<l;i++)										//���ж�ǰ�ȴ�����ַ���
	{
		if(C[i]>='A'&&C[i]<='Z')								//��дתСд
		{
			C[i]=C[i]-('A'-'a');
		}
		else if(C[i]>='a'&&C[i]<='z')							//Сд����
		{
			continue;
		}
		else													//�����ַ�һ��ȥ��
		{
			for(j=i;j<l-1;j++)
			{
				C[j]=C[j+1];
			}
			i--;													//��ԭ��̤����
			C[l-1]='\0';											
			l--;													//ȥ�����ַ����鳤�ȼ�1
		}
	}
	//puts(C);
	
	if(l>=1)												//ʵ���ַ�������2�������ϱȽ�����
	{
		mid=(int)(l/2);
	
		for(i=0;i<mid;i++)
		{
			if(C[i] != C[l-1-i])								//һ�����ȣ���ز�Ϊ����
			{
				strcpy(Judge,"FALSE");
				return;
			}
		}
		strcpy(Judge,"TRUE");
	}
	else													//ʵ���ַ�����2���������ϻ�������
	{
		strcpy(Judge,"FALSE");
	}
}