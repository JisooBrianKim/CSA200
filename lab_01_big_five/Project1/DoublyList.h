#ifndef DOUBLYLIST_H
#define DOUBLYLIST_H

#include <string>
#include <iostream>
using namespace std;

class Node
{
public:
	Node() : data(0), prev(nullptr), next(nullptr) {}
	Node(int theData, Node *previous, Node *next)
		: data(theData), next(next), prev(previous) {}
	Node *getNext() const { return next; }
	Node *getPrev() const { return prev; }
	int getData() const { return data; }
	void setData(int theData) { data = theData; }
	void setNext(Node *pointer) { next = pointer; }
	void setPrev(Node *pointer) { prev = pointer; }
	~Node() {}
private:
	int data;
	Node *next;
	Node *prev;
};

class DoublyList
{
	friend ostream& operator<<(ostream&, const DoublyList&);

public:
	DoublyList();
	DoublyList(const DoublyList&);

	void insertBack(int);
	void populateDLL(int[], int);
	void copyToParamList(DoublyList&);
	DoublyList& operator=(const DoublyList&);

	bool isEmpty() const;

	int getNumOfElem() const;

	void destroyList();
	~DoublyList();

	// These functions are for testing cases ONLY;
	// they check if first and last are nullptrs.
	bool checkFirst() const { return (first == nullptr); }
	bool checkLast() const { return (last == nullptr); }

	/******************************************************
	* Write your declarations below this line.
	*******************************************************/

	// Declaration move constructor
	DoublyList(DoublyList&& otherList);

	// Declaration move assignment operator
	DoublyList& operator=(DoublyList&& otherList);

private:
	Node *first;
	Node *last;
	int count;
};

#endif