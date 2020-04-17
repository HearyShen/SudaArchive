/*************************
	Doubly Linked List
	1427405017
	����S
	2015.10.23
**************************/
#ifndef DOUBLY_LINKED_LIST
#define DOUBLY_LINKED_LIST

#include <iostream>

using namespace std;

enum Error_code{success,fail,Range_error,underflow,overflow,fatal,not_present,
                duplicate_error,entry_inserted,entry_found,internal_error};

template <class Node_entry>
struct Node
{
//	data members
	Node_entry entry;
	Node<Node_entry> *back;
	Node<Node_entry> *next;
//	constructors
	Node()
	{
		next = NULL;
		back = NULL;
	}
	Node(Node_entry new_entry, Node<Node_entry> *link_back = NULL, Node<Node_entry> *link_next = NULL)
	{
		entry = new_entry;
		back = link_back;
		next = link_next;
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
//	the long int caculate function
	friend List<int> operator+(const List<int> &a, const List<int> &b);
	friend List<int> operator-(const List<int> &a, const List<int> &b);

protected:
//	data members for the doubly linked list implementation
	int count;
	mutable int current_position;
	mutable Node<List_entry> *current;
//	the following auxiliary function is used to locate list positions
	void set_position(int position) const;
};

template <class List_entry>
void List<List_entry>::set_position(int position) const
{
	if(current_position <= position)
		for( ; current_position != position; current_position++)
			current = current->next;
	else
		for( ; current_position != position; current_position--)
			current = current->back;
}

template<class List_entry>
List<List_entry>::List()
{
	count = 0;
	current_position = 0;
	current = NULL;
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
	Node<List_entry> *p_following, *p_current;

	set_position(0);
	if(current == NULL)	//����Ϊ�գ��������
		return;
	else
	{
		p_current = current;
		p_following = p_current->next;
		while(p_following != NULL)
		{
			p_current = p_following;
			p_following = p_following->next;

			delete p_current;
		}
		count = 0;
		current_position = 0;
		current = NULL;
	}
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

	set_position(position);
	x = current->entry;

	return success;
}

template<class List_entry>
Error_code List<List_entry>::replace(int position, const List_entry &x)
{
	if(position<0 || position>=count)
		return Range_error;

	set_position(position);
	current->entry = x;

	return success;
}

template<class List_entry>
Error_code List<List_entry>::remove(int position, List_entry &x)
{
	Node<List_entry> *preceding,*following;

	if(position<0 || position>=count)
		return Range_error;

	set_position(position);
	preceding = current->back;
	following = current->next;

	if(preceding != NULL)
		preceding->next = following;
	if(following != NULL)
		following->back = preceding;

	x = current->entry;

	delete current;
	count--;
	current = following;	//current��ָ����һ�currentһ����ʧ�ᵼ����������ʧȥ���ƣ�
	current_position = position;

	return success;
}

template <class List_entry>
Error_code List<List_entry>::insert(int position, const List_entry &x)
{
	Node<List_entry> *new_node, *following, *preceding;
	
	if(position<0 || position>count)
		return Range_error;
	if(position == 0)
	{
		if(count == 0)
		{
			following = NULL;
		}
		else
		{
			set_position(0);
			following = current;
		}
		preceding = NULL;
	}
	else
	{
		set_position(position-1);
		preceding = current;
		following = preceding->next;
	}

	new_node = new Node<List_entry>(x,preceding,following);

	if(new_node == NULL)
		return overflow;
	if(preceding != NULL)
		preceding->next = new_node;
	if(following != NULL)
		following->back = new_node;

	current = new_node;
	current_position = position;
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
	current_position = 0;
	set_position(current_position);
	for(int i=0;i<copy.size();i++)
	{
		copy.set_position(i);
		insert(i,copy.current->entry);
	}
}

template<class List_entry>
void List<List_entry>::operator=(const List<List_entry> &copy)
{
	clear();
	for(int i=0;i<copy.size();i++)
	{
		copy.set_position(i);
		insert(i,copy.current->entry);
	}
}

List<int> operator+(const List<int> &a, const List<int> &b)
{
	int flag,i,a_int,b_int;
	List<int> result;

	flag=0;
	for(i=0;i<a.size() || i<b.size();i++)		//��β��ѭ�������������������
	{
		if(i<a.size())
		{
			a.set_position(a.size()-i-1);
			a_int = a.current->entry;
		}
		else
		{
			a_int = 0;
		}

		if(i<b.size())
		{
			b.set_position(b.size()-i-1);
			b_int = b.current->entry;
		}
		else
		{
			b_int = 0;
		}

		result.insert(0,a_int + b_int);
	}

	for(i=0;i<result.size();i++)		//��β��ѭ����������ӽ�����������λ����
	{
		result.set_position(result.size()-i-1);

		if(flag == 1)	//��λ
		{
			result.replace(result.current_position, (result.current->entry + 1));
		}

		if(result.current->entry >= 1000)
		{
			result.current->entry = result.current->entry - 1000;
			flag=1;
		}
		else
		{
			flag=0;
		}
	}
	if(flag == 1)			//����������Ȼ��λ��������result��ͷ����һ��1
	{
		result.insert(0,1);
	}

	return result;
}

List<int> operator-(const List<int> &a, const List<int> &b)
{
	int flag,i,a_int,b_int,temp;
	List<int> result;

	for(i=0;i<a.size() || i<b.size();i++)		//��β��ѭ�������������������
	{
		if(i<a.size())
		{
			a.set_position(a.size()-i-1);
			a_int = a.current->entry;
		}
		else
		{
			a_int = 0;
		}

		if(i<b.size())
		{
			b.set_position(b.size()-i-1);
			b_int = b.current->entry;
		}
		else
		{
			b_int = 0;
		}

		result.insert(0,(a_int - b_int));
	}

	int zero;
	while(result.size() > 1)		//�����ͷ���ܵ�0λ
	{
		result.set_position(0);
		if(result.current->entry == 0)
		{
			result.remove(0,zero);
		}
		else
		{
			break;
		}
	}

	if(result.current->entry < 0)		//�����λΪ������������ <= -1�����
	{
		flag=0;
		for(i=0;i<result.size();i++)		//��β��ѭ�������������������������п��ܴ��ڵ��������⣨��λΪ��������ʱ��Ҫʹ��ÿλ��Ϊ������
		{
			result.set_position(result.size()-i-1);

			if(flag == 1)		//������Ϊ����������Ҫ��һλ
			{
				result.replace(result.current_position, (result.current->entry + 1));
			}

			if(result.current->entry > 0)		
			{
				result.current->entry = result.current->entry - 1000;	//��ǰ��Ϊ������һλ����ǰ���1000
				flag=1;
			}
			else
			{
				flag=0;
			}
		}
		result.set_position(0);
		if(result.current->entry == 0)			//������ԭ����-1���������λ��Ϊ0������
		{
			result.remove(0,temp);
		}

		return result;
	}
	else		//�����λΪ������������ >= 1�����
	{
		flag=0;
		for(i=0;i<result.size();i++)		//��β��ѭ�����������������������λ���⣨��λΪ��������ʱ��Ҫ��λʹ��ÿλ��Ϊ������
		{
			result.set_position(result.size()-i-1);

			if(flag == 1)
			{
				result.replace(result.current_position, (result.current->entry - 1));
			}

			if(result.current->entry < 0)
			{
				result.current->entry = result.current->entry + 1000;	//��ǰ��Ϊ�������λ����ǰ���1000��
				flag=1;
			}
			else
			{
				flag=0;
			}
		}
		result.set_position(0);
		if(result.current->entry == 0)			//������ԭ����1����������λ��Ϊ0������
		{
			result.remove(0,temp);
		}
	}

	return result;
	
}

#endif