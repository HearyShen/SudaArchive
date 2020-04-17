#ifndef SEQUENTIAL_SEARCH_H
#define SEQUENTIAL_SEARCH_H

#include <iostream>
#include "utility.h"

using namespace std;

Error_code sequential_search(const List<Record> &the_list, const Key &target, int &position)
{
	int s = the_list.size();
	for(position=0; position<s; position++)
	{
		Record data;
		the_list.retrieve(position, data);
		if(data == target)
		{
			cout<<"关键字比较次数"<<position+1<<endl;
			return success;
		}
	}
}

#endif