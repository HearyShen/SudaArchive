/* 
ex1_2
��׺���ʽת��׺���ʽ
	2���﷨�Ƶ��ķ���
1427405017
����S

input example: 
9+5-2
*/

#include <stdio.h>

char lookahead;
char str[100];
int idx = 0;

void expr();
void term();
void match(char t);

void main()
{
	printf("ex1_2 postfix\n��׺���ʽת��׺���ʽ - �﷨�Ƶ��ķ��루��λ���Ӽ�����\n");

	puts("Please type in (end with Enter):");
	gets(str);

	puts("postfix format:");
	lookahead = str[idx];
	expr();
	printf("\n\n");
}

void expr()
{
	term();
	while(true)
	{
		if( lookahead == '+')
		{
			match('+');
			term();
			printf("+");
		}
		else if( lookahead == '-')
		{
			match('-');
			term();
			printf("-");
		}
		else 
			return;
	}
}

void term()
{
	if(lookahead >= '0' && lookahead <= '9')
	{
		printf("%c", lookahead);
		match(lookahead);
	}
	else
	{
		printf("syntax error\n");
	}
}

void match(char t)
{
	if(lookahead == t)
		lookahead = str[++idx];
	else
		printf("syntax error");
}