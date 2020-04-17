#include <time.h>
#include <stdio.h>
#include <stdlib.h> 
#include "utility.h"

using namespace std;

void main()
{
	List<int> list;

	Key odd = 1;
	for(int i=0;i<10000;i++)
	{
		odd = 2*i+1;
		list.insert(i,odd);
	}

	clock_t start, finish; 

	//Key key = odd;
	Key key = odd/2;
	int position = 0;

	start = clock();
	if( sequential_search(list, key, position) == success)
	{
		finish = clock();
		cout<<"˳����ҳɹ���keyֵpositionΪ"<<position<<endl
			<<"��ʱ��"<<fixed<<(double)(finish - start)/CLOCKS_PER_SEC<<"s"<<endl<<endl;
	}

	start = clock();
	if( binary_search_1(list, key, position) == success)
	{
		finish = clock();
		cout<<"�ǵݹ���ֲ���1 �ɹ���keyֵpositionΪ"<<position<<endl
			<<"��ʱ��"<<fixed<<(double)(finish - start)/CLOCKS_PER_SEC<<"s"<<endl<<endl;
	}

	start = clock();
	if( binary_search_2(list, key, position) == success)
	{
		finish = clock();
		cout<<"�ǵݹ���ֲ���2 �ɹ���keyֵpositionΪ"<<position<<endl
			<<"��ʱ��"<<fixed<<(double)(finish - start)/CLOCKS_PER_SEC<<"s"<<endl<<endl;
	}

	start = clock();
	if( run_recursive_binary_1(list, key, position) == success)
	{
		finish = clock();
		cout<<"�ݹ���ֲ���1 �ɹ���keyֵpositionΪ"<<position<<endl
			<<"��ʱ��"<<fixed<<(double)(finish - start)/CLOCKS_PER_SEC<<"s"<<endl<<endl;
	}

	start = clock();
	if( run_recursive_binary_2(list, key, position) == success)
	{
		finish = clock();
		cout<<"�ݹ���ֲ���2 �ɹ���keyֵpositionΪ"<<position<<endl
			<<"��ʱ��"<<fixed<<(double)(finish - start)/CLOCKS_PER_SEC<<"s"<<endl<<endl;
	}
}