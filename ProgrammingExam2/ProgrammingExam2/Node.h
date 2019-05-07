#ifndef NODE_H
#define NODE_H

class Node
{
public:
	Node() : data(0), next(nullptr) {}
	Node(int theData, Node *newNext) : data(theData), next(newNext) {}
	Node* getNext() const { return next; }
	int getData() const { return data; }
	void setData(int theData) { data = theData; }
	void setNext(Node *newNext) { next = newNext; }
	~Node() {}
private:
	int data;
	Node *next;	//pointer that points to next node
};

#endif