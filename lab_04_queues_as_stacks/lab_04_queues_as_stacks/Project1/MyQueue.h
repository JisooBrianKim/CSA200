#ifndef MYQUEUE_H
#define MYQUEUE_H

#include <iostream>
#include <stack>

using namespace std;

class MyQueue
{
public:
	//Constructor
	MyQueue();

	//Copy constructor
	MyQueue(const MyQueue& otherQueue);

	//Overloaded assignment operator
	MyQueue& operator=(const MyQueue& otherQueue);

	//Declaration function back
	int back() const;

	//Declaration function front
	int front() const;

	//Declaration function dequeue, delete front
	void dequeue();

	//Declaration function enqueue, delete back
	void enqueue(int item);

	//Declaration function isEmpty
	bool isEmpty() const;

	//Declaration function size
	int size() const;

	//Declaration function emptyQueue
	void emptyQueue();

	//Declaration destructor
	~MyQueue();
	
private:
	int count;
	stack<int> *s;
};

#endif