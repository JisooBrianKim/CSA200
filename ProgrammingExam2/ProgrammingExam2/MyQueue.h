#ifndef MYQUEUE_H
#define MYQUEUE_H

#include <iostream>
#include "Node.h"

using namespace std;

const int CAP = 20;

// ARRAY QUEUEEEEEEEEEE
class MyArrayQueue
{
	friend ostream& operator<<(ostream& out, const MyArrayQueue& newQueue);
public:
	// Default Constructor
	MyArrayQueue();

	// Overloaded Constructor
	MyArrayQueue(int);

	// Copy Constructor
	MyArrayQueue(const MyArrayQueue& otherQueue);

	// Move Constructor
	MyArrayQueue(MyArrayQueue&& otherQueue);

	// Move Assignment
	MyArrayQueue& operator=(MyArrayQueue&& otherQueue);

	// Assignment Operator
	MyArrayQueue& operator=(const MyArrayQueue&);

	// Comparison Operator
	bool operator==(const MyArrayQueue&);

	// emptyQueue
	void emptyQueue();

	// push
	void push(int newItem);

	// pop
	void pop();

	// front
	int getFront() const;

	// back 
	int getBack() const;

	// isEmpty?
	bool isEmpty() const;

	// size
	int sizeQueue() const;

	// swap
	void swap(MyArrayQueue&);

	//resize
	void resize();

	// Destructor
	~MyArrayQueue();
private:
	int * myQueue;
	int capacity;
	int front;
	int back;
	int numOfElem;
};


class MyQueueList
{
	friend ostream& operator<<(ostream& out, const MyQueueList&);
public:
	MyQueueList();
	MyQueueList(int, int);
	MyQueueList(const MyQueueList&);
	MyQueueList(MyQueueList&&);


	MyQueueList& operator=(const MyQueueList&);
	MyQueueList& operator=(MyQueueList&&);
	bool operator==(const MyQueueList&) const;

	~MyQueueList();

	void emptyQueue();
	void push(int);
	void pop();
	int getFront() const;
	int getBack() const;

	bool isEmpty() const;
	int size() const;
	void swap(MyQueueList&);

private:
	Node * front;
	Node * back;
	int data;
	int count;
};

#endif