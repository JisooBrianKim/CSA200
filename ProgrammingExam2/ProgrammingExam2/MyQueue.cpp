#include "MyQueue.h"

ostream& operator<<(ostream& out, const MyArrayQueue& newQueue)
{
	cout << "Array: ";
	for (int i = 0; i < newQueue.numOfElem; i++)
		cout << newQueue.myQueue[i] << " ";
	cout << endl;
	return out;
}

// Default Constructor
MyArrayQueue::MyArrayQueue()
{
	capacity = CAP;
	myQueue = new int[capacity];
	numOfElem = 0;
	front = back = 0;
}

// Copy Constructor
MyArrayQueue::MyArrayQueue(const MyArrayQueue& otherQueue)
{
	capacity = otherQueue.capacity;
	numOfElem = otherQueue.numOfElem;
	myQueue = new int[capacity];

	for (int i = 0; i < numOfElem; i++)
		myQueue[i] = otherQueue.myQueue[i];

	front = otherQueue.front;
	back = otherQueue.back;
}

// Move Constructor
MyArrayQueue::MyArrayQueue(MyArrayQueue&& otherQueue)
{
	myQueue = otherQueue.myQueue;
	capacity = otherQueue.capacity;
	numOfElem = otherQueue.numOfElem;
	front = otherQueue.front;
	back = otherQueue.back;

	otherQueue.front = otherQueue.back = -1;
	otherQueue.myQueue = nullptr;
	otherQueue.numOfElem = 0;
	otherQueue.capacity = 0;
}

// Assignment Operator
MyArrayQueue& MyArrayQueue::operator=(MyArrayQueue&& otherQueue)
{
	if (this != &otherQueue)
	{
		delete[] myQueue;
		myQueue = otherQueue.myQueue;
		capacity = otherQueue.capacity;
		numOfElem = otherQueue.numOfElem;
		front = otherQueue.front;
		back = otherQueue.back;

		otherQueue.myQueue = nullptr;
		otherQueue.capacity = 0;
		otherQueue.numOfElem = 0;
	}
	else
		cout << "Attempted to re-assignement to itself." << endl;
	return *this;
}

// Assignment Operator
MyArrayQueue& MyArrayQueue::operator=(const MyArrayQueue& otherQueue)
{
	numOfElem = otherQueue.numOfElem;
	capacity = otherQueue.capacity;
	myQueue = new int[capacity];

	for (int i = 0; i < numOfElem; i++)
		myQueue[i] = otherQueue.myQueue[i];
	front = otherQueue.front;
	back = otherQueue.back;

	return *this;
}

// Comparison Operator
bool MyArrayQueue::operator==(const MyArrayQueue& otherQueue)
{
	if (numOfElem == otherQueue.numOfElem && capacity == otherQueue.capacity)
	{
		int i = 0;
		while (i < numOfElem)
		{
			if (myQueue[i] != otherQueue.myQueue[i])
				return false;
			else
				i++;
		}
	}
	else
		return false;
	return true;
}

// emptyQueue
void MyArrayQueue::emptyQueue()
{
	front = back = -1;
	numOfElem = 0;
}

// push
void MyArrayQueue::push(int newItem)
{
	if (numOfElem == capacity - 1)
		cerr << "Full." << endl;
	else
	{
		myQueue[back] = newItem;
		back = (back + 1) % capacity;
		numOfElem++;
	}
}

// pop
void MyArrayQueue::pop()
{
	if (numOfElem > 0)
	{
		for (int i = 0; i < numOfElem - 1; i++)
			myQueue[i] = myQueue[i + 1];
		front = (front + 1) % capacity;
		numOfElem--;
	}
	else
		cerr << "Queue is empty.";
}

// front
int MyArrayQueue::getFront() const
{
	return front;
}

// back
int MyArrayQueue::getBack() const
{
	return back;
}

// isEmpty
bool MyArrayQueue::isEmpty() const
{
	return numOfElem == 0;
}

// swap
void MyArrayQueue::swap(MyArrayQueue& otherQueue)
{
	MyArrayQueue temp = otherQueue; // copy constructor
	otherQueue.front = front;
	otherQueue.back = back;
	otherQueue.numOfElem = numOfElem;
	otherQueue.capacity = capacity;
	for (int i = 0; i < numOfElem; i++)
		otherQueue.myQueue[i] = myQueue[i];

	*this = move(temp);
}

// resize
void MyArrayQueue::resize()
{
	capacity *= 2;
}

int MyArrayQueue::sizeQueue() const
{
	return (capacity - front + back) % capacity;
}

// Destructor Constructor
MyArrayQueue::~MyArrayQueue()
{
	myQueue = nullptr;
}

// List QUEUEEEEEEEEEEEEEEEEEEEEEEEEEEE
ostream& operator<<(ostream& out, const MyQueueList& otherList)
{
	out << "List: ";
	Node * current = otherList.front;
	for (int i = 0; i < otherList.count; i++)
	{
		out << current->getData() << " ";
		current = current->getNext();
	}
	out << endl;

	return out;
}

MyQueueList::MyQueueList()
{
	front = back = nullptr;
	count = 0;
}

// Overloaded Constructor
MyQueueList::MyQueueList(int numOfNodes, int newData)
{
	front = back = new Node(newData, nullptr);
	for (int i = 0; i < numOfNodes - 1; i++)
	{
		back->setNext(new Node(newData, nullptr));
		back = back->getNext();
	}
	count = numOfNodes;
}

// Copy Constructor
MyQueueList::MyQueueList(const MyQueueList& otherList)
{
	count = otherList.count;

	front = new Node(otherList.front->getData(), nullptr);
	
	Node * current = front;
	Node * otherCurrent = otherList.front->getNext();
	
	while (otherCurrent != nullptr)
	{
		current->setNext(new Node(otherCurrent->getData(), nullptr));
		current = current->getNext();
		otherCurrent = otherCurrent->getNext();
	}
	back = current;
}

// Move Constructor
MyQueueList::MyQueueList(MyQueueList&& otherList)
{
	count = otherList.count;
	front = otherList.front;
	back = otherList.back;

	otherList.front = otherList.back = nullptr;
	otherList.count = 0;
}

// Move Overloaded Assignment
MyQueueList& MyQueueList::operator=(MyQueueList&& otherList)
{
	if (this != &otherList)
	{
		emptyQueue();
		count = otherList.count;
		front = otherList.front;
		back = otherList.back;

		otherList.count = 0;
		delete otherList.front, otherList.back;
		otherList.front = otherList.back = nullptr;
	}
	else
	{
		cerr << "Attempted to re-assignment." << endl;
	}
	return *this;
}
// Overloaded assignment
MyQueueList& MyQueueList::operator=(const MyQueueList& otherList)
{
	emptyQueue();
	front = back = new Node(otherList.front->getData(), nullptr);
	Node * otherCurrent = otherList.front;
	
	while (otherCurrent->getNext() != nullptr)
	{
		push(otherCurrent->getData());
		otherCurrent = otherCurrent->getNext();
	}

	return *this;
}

void MyQueueList::swap(MyQueueList& otherList)
{
	MyQueueList temp = otherList;
	otherList.count = count;
	otherList.front = front;
	otherList.back = back;

	front = temp.front;
	back = temp.back;
	count = temp.count;

	temp.front = temp.back = nullptr;
}

int MyQueueList::getFront() const
{
	return front->getData();
}

int MyQueueList::getBack() const
{
	return back->getData();
}

void MyQueueList::emptyQueue()
{
	Node * temp = front;

	while (front != nullptr)
	{
		front = front->getNext();
		delete temp;
		temp = nullptr;
	}
	count = 0;
}
void MyQueueList::push(int newData)
{
	if (count == 0)
	{
		front = back = new Node(newData, nullptr);
	}
	else
	{
		back->setNext(new Node(newData, nullptr));
		back = back->getNext();
	}
	count++;
}

void MyQueueList::pop()
{
	if (count == 0)
	{
		cerr << "List is empty." << endl;
	}
	else
	{
		if (count == 1)
		{
			front = back = nullptr;
		}
		else
		{
			Node * temp = front;
			front = front->getNext();

			delete temp;
			temp = nullptr;
		}
		count--;
	}
}

MyQueueList::~MyQueueList()
{
	emptyQueue();
}