#ifndef SIMPLY_LINKED_LIST_H
#define SIMPLY_LINKED_LIST_H

#include <iostream>

using namespace std;

enum Error_code{success,fail,Range_error,underflow,overflow,fatal,not_present,
                duplicate_error,entry_inserted,entry_found,internal_error};

template <class Node_entry>
struct Node
{
//data members
	Node_entry entry;
	Node<Node_entry> *next;
//constructers
	Node()
	{
		next = NULL;
	}
	Node(Node_entry new_entry, Node<Node_entry> *link = NULL)
	{
		entry = new_entry;
		next = link;
	}
};


template <class List_entry>
class List
{
public:
//	methods of the List ADT
	List();
	int size() const;
	bool empty() const;
	void clear();
	void traverse(void (*visit)(List_entry &));
	Error_code retrieve(int position, List_entry &x) const;
	Error_code replace(int position, const List_entry &x);
	Error_code remove(int position, List_entry &x);
	Error_code insert(int position, const List_entry &x);
//	the following methods replace compiler-generated defaults
	~List();
	List(const List<List_entry> &copy);
	void operator=(const List<List_entry> &copy);

protected:
//	data members for the linked list implementation
	int count;
	Node<List_entry> *head;
//	the following auxiliary function is used to locate list positions
	Node<List_entry> *set_position(int position)const;
};

template <class List_entry>
Node<List_entry> *List<List_entry>::set_position(int position)const
{
	Node<List_entry> *q = head;
	for(int i=0;i<position;i++)
		q = q->next;

	return q;
}

template<class List_entry>
List<List_entry>::List()
{
	count = 0;
	head = NULL;
}

template<class List_entry>
int List<List_entry>::size() const
{
	return count;
}

template<class List_entry>
bool List<List_entry>::empty() const
{
	if(count == 0)
		return true;
	else
		return false;
}

template<class List_entry>
void List<List_entry>::clear()
{
	Node<List_entry> *following, *current;

	current = head;
	following = current->next;
	while(following != NULL)
	{
		current = following;
		following = following->next;

		delete current;
	}
	count = 0;
}

template<class List_entry>
void List<List_entry>::traverse(void (*visit)(List_entry &))
{
	Node<List_entry> *p = head->next;
	while(p != NULL)
	{
		(*visit)*p;

		p = p->next;
	}
}

template<class List_entry>
Error_code List<List_entry>::retrieve(int position, List_entry &x) const
{
	if(position<0 || position>=count)
		return Range_error;

	Node<List_entry> *p;

	p = set_position(position);
	x = p->entry;

	return success;
}

template<class List_entry>
Error_code List<List_entry>::replace(int position, const List_entry &x)
{
	if(position<0 || position>=count)
		return Range_error;

	Node<List_entry> *current;

	current = set_position(position);
	current->entry = x;

	return success;
}

template<class List_entry>
Error_code List<List_entry>::remove(int position, List_entry &x)
{
	if(position<0 || position>=count)
		return Range_error;

	Node<List_entry> *current, *preceding;

	current = set_position(position);

	if(position = 0)
	{
		preceding = head;
	}
	else
	{
		preceding = set_position(position-1);
	}
	preceding->next = current->next;

	x = current->entry;

	delete current;
	count--;

	return success;
}

template<class List_entry>
Error_code List<List_entry>::insert(int position, const List_entry &x)
{
	if(position<0 || position >count)
		return Range_error;

	Node<List_entry> *new_node, *previous, *following;
	if(position > 0)
	{
		previous = set_position(position-1);
		following = previous->next;
	}
	else
	{
		following = head;
	}

	new_node = new Node<List_entry>(x,following);
	if(new_node == NULL)
		return overflow;
	if(position == 0)
		head = new_node;
	else
		previous->next = new_node;

	count++;

	return success;
}

template<class List_entry>
List<List_entry>::~List()
{
	clear();
}

template<class List_entry>
List<List_entry>::List(const List<List_entry> &copy)
{
	count = 0;
	head = NULL;
	for(int i=1;i<=copy.size();i++)
	{
		insert(i,*copy.set_position(i));
	}
}

template<class List_entry>
void List<List_entry>::operator=(const List<List_entry> &copy)
{
	clear();
	for(i=1;i<=copy.size();i++)
	{
		insert(i,*copy.set_position(i));
	}
}

#endif