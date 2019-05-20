#ifndef MYSTACK_H
#define MYSTACK_H

#include <iostream>
#include <vector>
#include "Node.h"

using namespace std;

const int CAPACITY = 20;

// A class MyStack using the DArray class
class MyArrayStack
{
	friend ostream& operator<<(ostream& out, const MyArrayStack& otherArray);
public:

	// Default constructor
	MyArrayStack();

	// Copy constructor
	MyArrayStack(const MyArrayStack& newStack);

	// Overloaded constructor
	MyArrayStack(const vector<int> vec);

	// Move constructor
	MyArrayStack(MyArrayStack&& otherArray);

	// Move Assignment constructor
	MyArrayStack& operator=(MyArrayStack&& otherArray);

	//comparison operator
	bool operator==(MyArrayStack& otherArray) const;

	// emptyStack
	void emptyStack();

	// push
	void push(int newItem);
	
	// pop
	void pop();

	// top
	int top() const;

	// isEmpty?
	bool isEmpty() const;

	//size
	int size() const;

	//swap
	MyArrayStack& swap(MyArrayStack& newStack);

	// resize
	void resize();

	// Destructor
	~MyArrayStack();
private:
	int numOfElems;
	int * a;
	int capacity;
};



class MyListStack
{
	friend ostream& operator<<(ostream& out, const MyListStack&);
public:
	// Default Constructor
	MyListStack();

	// Copy Constructor
	MyListStack(const MyListStack&);

	// Overloaded Constructor
	MyListStack(int, int);

	// Move Constructor
	MyListStack(MyListStack&&);

	// Overloaded move Assignment
	MyListStack& operator=(MyListStack&&);

	// Comparison
	bool operator==(const MyListStack&) const;

	void emptyStack();

	void push(int obj);

	void pop();

	int getTop() const;

	bool isEmpty() const;

	int size() const;

	void swap(MyListStack&);

	// Destructor
	~MyListStack();

private:
	Node * top;
	int data;
	int count;
};

#endif