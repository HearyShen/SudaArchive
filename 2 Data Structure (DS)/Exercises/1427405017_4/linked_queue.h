#ifndef LINKED_QUEUE_H
#define LINKED_QUEUE_H

#include <iostream>
#include "utility.h"
using namespace std;

//const int maxqueue = 10;	// small value for testing

//enum Error_code{overflow, success, underflow};

template <class Node_entry>
struct Node
{
	Node_entry entry;
	Node<Node_entry> *next;

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

template <class Queue_entry>
class Queue
{
public:
	Queue();
	bool empty() const;								//�п�
	Error_code serve();								//��ͷ������
	Error_code append(const Queue_entry &item);		//�������β
	Error_code retrieve(Queue_entry &item) const;	//��ȡ��ͷ��������
	~Queue();
protected:
	Node<Queue_entry> *front, *rear;
};

template <class Queue_entry>
Queue<Queue_entry>::Queue()
{
	rear = NULL;
	front = NULL;
}

template <class Queue_entry>
bool Queue<Queue_entry>::empty() const
{
	if(front == rear && front == NULL)
		return true;
	else
		return false;
}

template <class Queue_entry>
Error_code Queue<Queue_entry>::append(const Queue_entry &item)
{
	Node<Queue_entry> *new_rear = new Node<Queue_entry>(item);

	if(new_rear == NULL)
		return overflow;
	if(rear == NULL)		//�����޽��
	{
		rear = new_rear;
		front = rear;
	}
	else				//�����н��
	{
		rear->next = new_rear;
		rear = new_rear;
	}
	return success;
}

template <class Queue_entry>
Error_code Queue<Queue_entry>::serve()
{
	if(front == NULL)
		return underflow;
	Node<Queue_entry> *old_front = front;

	front = old_front->next;
	if(front == NULL)	//��1�����
		rear = NULL;
	delete old_front;
	return success;
}

template <class Queue_entry>
Error_code Queue<Queue_entry>::retrieve(Queue_entry &item) const
{
	if(front == NULL)
		return underflow;
	item = front->entry;
	return success;
}

template <class Queue_entry>
Queue<Queue_entry>::~Queue()
{
	Node<Queue_entry> *del,*p;

	p = front;
	while(p != NULL)
	{
		del = p;
		p = p->next;
		delete del;
	}
}
#endif