typedef double Stack_entry;
#include "stack.h"

void introduction();
void instructions();
char get_command();
bool do_command(char command, Stack &numbers);

void main()
{
	Stack stored_numbers;
	introduction();
	instructions();
	while(do_command(get_command(), stored_numbers));
}

void introduction()
{
	cout<<"Welcome to reverse Polish calculator!"<<endl<<endl;
}

void instructions()
{
	cout<<"input ? = + - * / to do calculation or q to quit"<<endl
		<<"eg. ? 1 ? 2 + =  represents  (1+2)="<<endl<<endl;
	cout<<"additional functions are also available: "<<endl
		<<"    e:  交换(exchange)栈顶的两个数值"<<endl
		<<"    s:  累加(Sum)栈中所有的数值"<<endl
		<<"    a:  对栈所有的数值求平均值(average)"<<endl<<endl;
}

char get_command()
{
	char command;
	bool waiting = true;
	cout<<"Select command and press <Enter> :";

	while(waiting)
	{
		cin>>command;
		command = tolower(command);
		if(command == '?' || command == '=' || command == '+' || command == '-' || command == '*' 
			|| command == '/' || command == 'e' || command == 's' || command == 'a' || command == 'q')
			waiting = false;
		else
		{
			cout<<"Please enter a valid command:"<<endl
				<<"[?]push to stack  [=]print top"<<endl
				<<"[+] [-] [*] [/]  are arithmetic operations"<<endl
				<<"[e] [s] [a]  are additional functions"<<endl
				<<"[Q]uit."<<endl;
		}
	}
	return command;
}

bool do_command(char command, Stack &numbers)
{
	double p,q;
	double sum;	//供选做内容
	double count;	//供选做内容

	switch(command)
	{
	case '?' :
		cout<<"Enter a real number: "<<flush;
		cin>>p;
		if(numbers.push(p) == overflow)
			cout<<"Warning : Stack full, lost number" <<endl;
		break;
	case '=':
		if(numbers.top(p) == underflow)
			cout<<"Stack empty"<<endl;
		else
			cout<<p<<endl;
		break;
	case '+':
		if(numbers.top(p) == underflow)
			cout<<"Stack empty"<<endl;
		else
		{
			numbers.pop();
			if(numbers.top(q) == underflow)
			{
				cout<<"Stack has just one entry"<<endl;
				numbers.push(p);
			}
			else
			{
				numbers.pop();
				if(numbers.push(q + p) == overflow)
					cout<<"Warning : Stack full, lost result"<<endl;
			}
		}
		break;
	case '-':
		if(numbers.top(p) == underflow)
			cout<<"Stack empty"<<endl;
		else
		{
			numbers.pop();
			if(numbers.top(q) == underflow)
			{
				cout<<"Stack has just one entry"<<endl;
				numbers.push(p);
			}
			else
			{
				numbers.pop();
				if(numbers.push(q - p) == overflow)
					cout<<"Warning : Stack full, lost result"<<endl;
			}
		}
		break;
	case '*':
		if(numbers.top(p) == underflow)
			cout<<"Stack empty"<<endl;
		else
		{
			numbers.pop();
			if(numbers.top(q) == underflow)
			{
				cout<<"Stack has just one entry"<<endl;
				numbers.push(p);
			}
			else
			{
				numbers.pop();
				if(numbers.push(q * p) == overflow)
					cout<<"Warning : Stack full, lost result"<<endl;
			}
		}
		break;
	case '/':
		if(numbers.top(p) == underflow)
			cout<<"Stack empty"<<endl;
		else
		{
			numbers.pop();
			if(numbers.top(q) == underflow)
			{
				cout<<"Stack has just one entry"<<endl;
				numbers.push(p);
			}
			else
			{
				numbers.pop();
				if(numbers.push(q / p) == overflow)
					cout<<"Warning : Stack full, lost result"<<endl;
			}
		}
		break;
//  选做内容部分
	case 'e':			//交换(exchange)栈顶的两个数值
		if(numbers.top(p) == underflow)		//p 存储栈顶首个元素
			cout<<"Stack empty"<<endl;
		else
		{
			numbers.pop();
			if(numbers.top(q) == underflow)	//q 存储栈顶第二个元素
			{
				cout<<"Stack has only one entry"<<endl;
				numbers.push(p);
			}
			else
			{
				numbers.pop();
				if( numbers.push(p) == overflow)		//先压入p（原栈首个元素）
					cout<<"Warning : Stack full, lost result"<<endl;
				if( numbers.push(q) == overflow)		//后压入q（原栈第二个元素）
					cout<<"Warning : Stack full, lost result"<<endl;
			}
		}
		cout<<"exchange success"<<endl;
		break;

	case 's':			//累加(Sum)栈中所有的数值
		sum = 0;
		while(numbers.empty() != true)	//numbers栈 -> temp栈
		{
			numbers.top(p);		//取
			numbers.pop();
			sum = sum + p;		//累加
		}
		if(numbers.push(sum) == overflow)
			cout<<"Warning : Stack full, lost result"<<endl;
		break;

	case 'a':		//对栈所有的数值求平均值(average)
		sum = 0;
		count = 0;
		while(numbers.empty() != true)	//numbers栈 -> temp栈
		{
			numbers.top(p);		//取
			numbers.pop();
			sum = sum + p;		//累加
			count++;
		}
		if(numbers.push((double)(sum/count)) == overflow)
			cout<<"Warning : Stack full, lost result"<<endl;
		break;

	case 'q':
		cout<<"Caulation finished.\n";
		return false;
	}
	return true;
}