#include <iostream>
#include "ContiguousList.h"

using namespace std;

class Int
{
public:
	int num;
	void show();
};

void Int::show()
{
	cout<<num;
}

void main()
{
	List<Int> list;
	cout<<"The initial contiguous list has "<<list.size()<<" members."<<endl;


	cout<<"Now inserting 0,1,2 to the list."<<endl;
	Int i,j,k;
	i.num=0;
	list.insert(0,i);
	j.num=1;
	list.insert(1,j);
	k.num=2;
	list.insert(2,k);

	//list.traverse((show));

	//cout<<"The list is ";
	//if(list.full())
	//	cout<<"full now"<<endl;
	//else
	//	cout<<"not full now"<<endl;

	cout<<"The list is ";
	if(list.empty())
		cout<<"empty now"<<endl;
	else
		cout<<"not empty now"<<endl;


	cout<<"Now clear the list."<<endl;
	list.clear();

	cout<<"The list is ";
	if(list.empty())
		cout<<"empty now"<<endl;
	else
		cout<<"not empty now"<<endl;


}