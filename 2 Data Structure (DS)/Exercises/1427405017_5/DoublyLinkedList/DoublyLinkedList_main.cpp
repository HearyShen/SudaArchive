#include <iostream>
#include "DoublyLinkedList.h"

using namespace std;

void main()
{
	int temp,i;

	cout<<"�����볤������ÿ��λ�ÿո������"<<endl;
	cout<<"a��";
	List<int> list_a;
	i = 0;
	while(cin>>temp)
	{
		list_a.insert(i,temp);
		i++;

		char signal;
		cin.get(signal);
		if(signal == '\n')		//���ֻس�������ֹ����
			break;
	}

	cout<<"b��";
	List<int> list_b;
	i = 0;
	while(cin>>temp)
	{
		list_b.insert(i,temp);
		i++;

		char signal;
		cin.get(signal);
		if(signal == '\n')		//���ֻس�������ֹ����
			break;
	}

// a+b�Ĳ���
	List<int> result_add;
	cout<<"a+b = "<<endl;
	result_add = list_a + list_b;
	for(i=0;i < result_add.size();i++)
	{
		result_add.retrieve(i,temp);
		cout<<temp<<"'";
	}
	cout<<endl;

// a-b�Ĳ���
	List<int> result_minus;
	cout<<"a-b = "<<endl;
	result_minus = list_a - list_b;

	result_minus.retrieve(0,temp);
	cout<<temp<<"'";
	if(temp < 0)	//��a-bΪ����
	{
		for(i=1;i < result_minus.size();i++)
		{
			result_minus.retrieve(i,temp);
			cout<<-temp<<"'";
		}
	}
	else			//a-bΪ�Ǹ���
	{
		for(i=1;i < result_minus.size();i++)
		{
			result_minus.retrieve(i,temp);
			cout<<temp<<"'";
		}
	}
	cout<<endl;
}