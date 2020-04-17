#include <iostream>
#include "DoublyLinkedList.h"

using namespace std;

void main()
{
	int temp,i;

	cout<<"请输入长整数（每三位用空格隔开）"<<endl;
	cout<<"a：";
	List<int> list_a;
	i = 0;
	while(cin>>temp)
	{
		list_a.insert(i,temp);
		i++;

		char signal;
		cin.get(signal);
		if(signal == '\n')		//发现回车，则终止输入
			break;
	}

	cout<<"b：";
	List<int> list_b;
	i = 0;
	while(cin>>temp)
	{
		list_b.insert(i,temp);
		i++;

		char signal;
		cin.get(signal);
		if(signal == '\n')		//发现回车，则终止输入
			break;
	}

// a+b的测试
	List<int> result_add;
	cout<<"a+b = "<<endl;
	result_add = list_a + list_b;
	for(i=0;i < result_add.size();i++)
	{
		result_add.retrieve(i,temp);
		cout<<temp<<"'";
	}
	cout<<endl;

// a-b的测试
	List<int> result_minus;
	cout<<"a-b = "<<endl;
	result_minus = list_a - list_b;

	result_minus.retrieve(0,temp);
	cout<<temp<<"'";
	if(temp < 0)	//若a-b为负数
	{
		for(i=1;i < result_minus.size();i++)
		{
			result_minus.retrieve(i,temp);
			cout<<-temp<<"'";
		}
	}
	else			//a-b为非负数
	{
		for(i=1;i < result_minus.size();i++)
		{
			result_minus.retrieve(i,temp);
			cout<<temp<<"'";
		}
	}
	cout<<endl;
}