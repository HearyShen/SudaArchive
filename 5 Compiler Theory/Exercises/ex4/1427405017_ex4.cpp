/* ***********************************
	ex4
	递归下降的预测分析
	1427405017
	沈家赟

	input example:
	id * id + ( id + id ) $
	(split with space, end with $)
**************************************/
#include <iostream>
#include <string>

#define MAX_SIZE 50
using namespace std;

string lookahead;
string str[MAX_SIZE];
int idx = 0;
 
void expr();
void term();
void expr_1();
void term_1();
void factor();
void match(string t);
string getNext(string str, int &idx);
void error();

void main()
{
	cout<<"ex4\n\n";
	cout<<"input example:"<<endl
		<<"id * id + ( id + id ) $"<<endl
		<<"(split with space, end with $)"<<endl;
	cout<<"Please type in :"<<endl;
	string str_t;
	int count=0;
	for(count=0; count<MAX_SIZE; count++)
	{
		cin>>str_t;
		if( str_t == "$" )
		{
			break;
		}
		str[count] = str_t;
		cout<<count<<" th    "<<str[count]<<endl;
	}

	/* start with expr() */
	lookahead = str[idx++];
	expr();

	/* result summary */
	cout<<"matched count: "<<idx-1<<endl<<endl;
	if( idx-1 == count )
	{
		cout<<"Success: all matched! "<<endl;
	}
	if( idx-1 < count )
	{
		cout<<"Error: "<<idx-1<<" of "<<count<<"matched! "<<endl;
	}
}

void error()
{
	printf("ERROR ! \n");
}

void expr()
{
	if(lookahead == "(" || lookahead == "id")
	{
		term();
		expr_1();
	}
	else
	{
		error();
	}
}

void term()
{
	if(lookahead == "(" || lookahead == "id")
	{
		factor();
		term_1();
	}
	else
	{
		error();
	}
}

void factor()
{
	if(lookahead == "(")
	{
		match("(");
		expr();
		match(")");
	}
	else if( lookahead == "id")
	{
		match("id");
	}
	else
	{
		error();
	}
}

void expr_1()
{
	if(lookahead == "+")
	{
		match("+");
		term();
		expr_1();
	}
	//else if( lookahead == "e")
	//{
	//	match("e");
	//}
	//else
	//{
	//	error();
	//}
}

void term_1()
{
	if(lookahead == "*")
	{
		match("*");
		factor();
		term_1();
	}
	//else if( lookahead == "e")
	//{
	//	match("e");
	//}
	//else
	//{
	//	error();
	//}
}

void match(string t)
{
	if(lookahead == t)
	{
		cout<<"matched : "<<lookahead<<endl;
		lookahead = str[idx++];
	}
	else
	{
		cout<<"syntax error"<<endl;
	}
}