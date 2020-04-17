#ifndef BINARY_SEARCH_H
#define BINARY_SEARCH_H

#include <iostream>
#include "utility.h"

using namespace std;
typedef List<Record> Ordered_List;

Error_code binary_search_1(const Ordered_List &the_list, const Key &target, int &position)
{
	Record data;
	int bottom = 0, top = the_list.size()-1;
	int count=0;

	while(bottom < top)
	{
		count++;
		int mid = (bottom + top)/2;
		the_list.retrieve(mid, data);
		if(data < target)
			bottom = mid + 1;
		else
			top = mid;
	}
	if(top < bottom)
		return not_present;
	else
	{
		position = bottom;
		the_list.retrieve(bottom, data);
		if(data == target)
		{
			cout<<"关键字比较次数"<<count<<endl;
			return success;
		}
		else
			return not_present;
	}
}


Error_code binary_search_2(const Ordered_List &the_list, const Key &target, int &position)
{
	Record data;
	int bottom = 0, top = the_list.size() -1;
	int count=0;

	while(bottom <= top)
	{
		count++;
		position = (bottom + top)/2;
		the_list.retrieve(position, data);
		if(data == target)
		{
			cout<<"关键字比较次数"<<count<<endl;
			return success;
		}
		if(data < target)
			bottom = position + 1;
		else
			top = position - 1;
	}
	return not_present;
}


Error_code recursive_binary_1(const Ordered_List &the_list, const Key &target, int bottom, int top, int &position)
{
	Record data;
	if(bottom < top)
	{
		int mid = (bottom + top)/2;
		the_list.retrieve(mid,data);
		if(data<target)
			return recursive_binary_1(the_list,target,mid+1,top,position);
		else
			return recursive_binary_1(the_list,target,bottom,mid,position);
	}
	else if(top < bottom)
		return not_present;
	else
	{
		position = bottom;
		the_list.retrieve(bottom,data);
		if(data == target)
			return success;
		else
			return not_present;
	}
}

Error_code run_recursive_binary_1(const Ordered_List &the_list, const Key &target, int &position)
{
	return recursive_binary_1(the_list, target, 0, the_list.size()-1, position);
}

Error_code recursive_binary_2(const Ordered_List &the_list, const Key &target, int bottom, int top, int &position)
{
	Record data;
	if(bottom <= top)
	{
		int mid = (bottom + top)/2;
		the_list.retrieve(mid,data);
		if(data == target)
		{
			position = mid;
			return success;
		}
		else if(data < target)
			return recursive_binary_2(the_list, target, mid+1, top, position);
		else
			return recursive_binary_2(the_list, target, bottom, mid-1, position);
	}
	else
		return not_present;
}

Error_code run_recursive_binary_2(const Ordered_List &the_list, const Key &target, int &position)
{
	return recursive_binary_2(the_list, target, 0, the_list.size()-1, position);
}

#endif