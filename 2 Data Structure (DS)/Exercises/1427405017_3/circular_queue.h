#ifndef CIRCULAR_QUEUE
#define CIRCULAR_QUEUE

#include <iostream>
using namespace std;

const int maxqueue = 10;	// small value for testing

enum Error_code{overflow, success, underflow};

typedef char Queue_entry;

class Queue
{
public:
	Queue();
	bool empty() const;								//判空
	Error_code serve();								//队头出队列
	Error_code append(const Queue_entry &item);		//数据入队尾
	Error_code retrieve(Queue_entry &item) const;	//读取队头，不出队
protected:
	int count;
	int front,rear;
	Queue_entry entry[maxqueue];
};

Queue::Queue()
{
	count = 0;
	rear = maxqueue - 1;
	front = 0;
}

bool Queue::empty() const
{
	return count == 0;
}

Error_code Queue::append(const Queue_entry &item)
{
	if(count >= maxqueue)
		return overflow;
	count++;
	rear = ((rear + 1)==maxqueue) ? 0:(rear+1);
	entry[rear] = item;
	return success;
}

Error_code Queue::serve()
{
	if(count <= 0)
		return underflow;
	count--;
	front = ((front + 1) == maxqueue) ? 0:(front + 1);
	return success;
}

Error_code Queue::retrieve(Queue_entry &item) const
{
	if(count <= 0)
		return underflow;
	item = entry[front];
	return success;
}
#endif