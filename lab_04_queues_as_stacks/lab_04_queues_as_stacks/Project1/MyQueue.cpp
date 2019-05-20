/*
	Kim, Ji Soo	

	CS A200
	April 10, 2019

	Lab 4
*/

#include "MyQueue.h"

//Definition constructor
MyQueue::MyQueue()
{
	count = 0;
	s = new stack<int>;
}

//Definition copy constructor
MyQueue::MyQueue(const MyQueue& otherQueue)
{
	count = otherQueue.count;
	s = new stack<int>;
	*s = *otherQueue.s;
}

//Definition overloaded assignment operator
MyQueue& MyQueue::operator=(const MyQueue& otherQueue)
{
	if (&otherQueue != this)
	{
		count = otherQueue.count;
		*s = *otherQueue.s;
	}
	else
		cerr << "Attempted assignment to itself.";
	return *this;
}

//Definition function back
int MyQueue::back() const
{
	if (count > 0)
		return s->top();
	else
	{
		cout << "Queue is empty. ERROR ";
		return -999;
	}
}

//Definition function front
int MyQueue::front() const
{
	if (count > 0)
	{
		stack<int> temp = *s;
		for (int i = 0; i < count - 1; i++)
			temp.pop();
		return temp.top();
	}
	else
	{
		cout << "Queue is empty. ERROR ";
		return -999;
	}
}

//Definition function dequeue
void MyQueue::dequeue()
{
	stack<int> temp;
	for (int i = 0; i < count; i++)
	{
		temp.push(s->top());
		s->pop();
	}

	temp.pop();

	for (int i = 0; i < count - 1; i++)
	{
		s->push(temp.top());
		temp.pop();
	}
	count--;
}

//Definition function enqueue
void MyQueue::enqueue(int item)
{
	s->push(item);
	count++;
}

//Definition function isEmpty
bool MyQueue::isEmpty() const
{
	return count == 0;
}

//Definition function size
int MyQueue::size() const
{
	return count;
}

//Definition function emptyQueue
void MyQueue::emptyQueue()
{
	for (int i = 0; i < count; i++)
		s->pop();
	count = 0;
}

//Definition destructor
MyQueue::~MyQueue()
{
	count = 0;
	delete s;
	s = nullptr;
}