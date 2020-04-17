#ifndef CONTIGUOUS_STACK_H
#define CONTIGUOUS_STACK_H

#include <iostream>
#include "utility.h"
using namespace std;

//enum Error_code{overflow, success, underflow};
const int maxstack = 10;	//small value for testing

template <class Stack_entry>
class Stack
{
public:
	Stack();
	bool empty() const;
	Error_code pop();
	Error_code top(Stack_entry &item) const;
	Error_code push(const Stack_entry &item);
	Error_code traverse(void (*visit)(Stack_entry&));
private:
	int count;
	Stack_entry entry[maxstack];
};

template <class Stack_entry>
Stack<Stack_entry>::Stack()
{
	count = 0;
}

template <class Stack_entry>
bool Stack<Stack_entry>::empty() const
{
	bool outcome = true;
	if(count > 0)
		outcome = false;
	return outcome;
}

template <class Stack_entry>
Error_code Stack<Stack_entry>::pop()
{
	Error_code outcome = success;
	if(count == 0)
		outcome = underflow;
	else
		--count;
	return outcome;
}

template <class Stack_entry>
Error_code Stack<Stack_entry>::top(Stack_entry &item) const
{
	Error_code outcome = success;
	if(count == 0)
		outcome = underflow;
	else
		item = entry[count-1];
	return outcome;
}

template <class Stack_entry>
Error_code Stack<Stack_entry>::push(const Stack_entry &item)
{
	Error_code outcome = success;
	if(count >= maxstack)
		outcome = overflow;
	else
		entry[count++] = item;
	return outcome;
}

template <class Stack_entry>
Error_code Stack<Stack_entry>::traverse(void (*visit)(Stack_entry&))
{
	for(int i=0;i<count;i++)
	{
		(*visit)(entry[i]);
	}
	return success;
}
#endif