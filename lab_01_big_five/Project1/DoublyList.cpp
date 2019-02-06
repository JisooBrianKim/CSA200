#include "DoublyList.h"

// Definition overloaded insertion operator
ostream& operator<<(ostream& out, const DoublyList& list)
{
	Node *temp = list.first;
	while (temp != nullptr)
	{
		cout << temp->getData() << " ";
		temp = temp->getNext();
	}
	return out;
}

// Default constructor
DoublyList::DoublyList()
{
	first = nullptr;
	last = nullptr;
	count = 0;
}

// Definition copy constructor
DoublyList::DoublyList(const DoublyList& otherList)
{
	if (otherList.count == 0)
	{
		first = nullptr;
		last = nullptr;
		count = 0;
	}
	else
	{
		Node *temp = otherList.first;
		while (temp != nullptr)
		{
			insertBack(temp->getData());
			temp = temp->getNext();
		}
	}
}

// Definition function insertBack
void DoublyList::insertBack(int newData)
{
	Node *newNode = new Node(newData, last, nullptr);

	if (first == nullptr)
		first = newNode;
	else
		last->setNext(newNode);

	last = newNode;
	++count;
}

// Definition populateDLL
void DoublyList::populateDLL(int a[], int numOfElem)
{
	for (int i = 0; i < numOfElem; ++i)
		insertBack(a[i]);
}

// Definition function copyToParamList
void DoublyList::copyToParamList(DoublyList& otherList)
{
	Node *current = first;
	while (current != nullptr)
	{
		otherList.insertBack(current->getData());
		current = current->getNext();
	}
}

// Declaration overloaded assignment operator
DoublyList& DoublyList::operator=(const DoublyList& otherList)
{
	// simple version 

	if (&otherList != this)
	{
		destroyList();

		if (otherList.first != nullptr)
		{
			Node *temp = otherList.first;
			while (temp != nullptr)
			{
				insertBack(temp->getData());
				temp = temp->getNext();
			}
		}
	}
	else
	{
		cerr << "Attempted assignment to itself." << endl;
	}

	return *this;
}

// Definition function isEmpty
bool DoublyList::isEmpty() const
{
	return (first == nullptr);
}

// Definition function getNumOfElem
int DoublyList::getNumOfElem() const
{
	return count;
}

// Definition function destroyList
void DoublyList::destroyList()
{
	Node *temp = first;
	while (first != nullptr)
	{
		first = first->getNext();
		delete temp;
		temp = first;
	}
	last = nullptr;
	count = 0;
}

DoublyList::~DoublyList()
{
	destroyList();
}








