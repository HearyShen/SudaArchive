#ifndef LINKED_QUEUE
#define LINKED_QUEUE

#include <iostream>
using namespace std;

//const int maxqueue = 10;	// small value for testing

enum Error_code{overflow, success, underflow};

typedef char Queue_entry;

struct Node
{
	Queue_entry entry;
	Node *next;

	Node()
	{
		next = NULL;
	}
	Node(Queue_entry new_entry, Node *link = NULL)
	{
		entry = new_entry;
		next = link;
	}
};

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
	Node *front, *rear;
};

Queue::Queue()
{
	rear = NULL;
	front = NULL;
}

bool Queue::empty() const
{
	if(front == rear && front == NULL)
		return true;
	else
		return false;
}

Error_code Queue::append(const Queue_entry &item)
{
	Node *new_rear = new Node(item);

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

Error_code Queue::serve()
{
	if(front == NULL)
		return underflow;
	Node *old_front = front;

	front = old_front->next;
	if(front == NULL)	//��1�����
		rear = NULL;
	delete old_front;
	return success;
}

Error_code Queue::retrieve(Queue_entry &item) const
{
	if(front == NULL)
		return underflow;
	item = front->entry;
	return success;
}

Queue::~Queue()
{
	Node *del,*p;

	p = front;
	while(p != NULL)
	{
		del = p;
		p = p->next;
		delete del;
	}
}
#endif