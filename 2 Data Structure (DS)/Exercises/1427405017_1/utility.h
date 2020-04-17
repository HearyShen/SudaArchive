# include<iostream>
using namespace std;

enum Error_code{success,fail,range_error,underflow,overflow,fatal,not_present,
                duplicate_error,entry_inserted,entry_found,internal_error};

bool user_says_yes()
{
	int c;
	bool initial_response=true;
	do
	{
		if(initial_response)
			cout<<"(y,n)?"<<flush;
		else
			cout<<"Respond with either y or n:"<<flush;
		do
		{
			c=cin.get();
		}while(c=='\n'||c==' '||c=='\t');					//ignore space and tab
		initial_response=false;
	}while(c!='y' && c!='Y' && c!='n' && c!='N');	//ignore useless characters

	return (c=='y'||c=='Y');		// when y or Y, then return true
}