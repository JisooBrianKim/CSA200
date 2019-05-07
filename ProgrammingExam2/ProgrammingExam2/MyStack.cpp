#include "MyStack.h"

// MYARRAYSTACKKKKKKKKKKKKKKKKkkk

// Friend Function
ostream& operator<<(ostream& out, const MyArrayStack& otherArray)
{
	cout << "Array: ";

	for (int i = 0; i < otherArray.numOfElems; i++)
	{
		cout << 
			otherArray.a[i] << " ";
	}
	cout << endl;
	cout << endl;
	return out;
}

// Default Constructor
MyArrayStack::MyArrayStack()
{
	numOfElems = 0;
	capacity = CAPACITY;
	a = new int[capacity];
}

// Copy constructor
MyArrayStack::MyArrayStack(const MyArrayStack& newStack)
{
		capacity = newStack.capacity;
		numOfElems = newStack.numOfElems;
		a = new int[capacity];

		for (int i = 0; i < numOfElems; i++)
			a[i] = newStack.a[i];
}

// Overloaded Constructor
MyArrayStack::MyArrayStack(const vector<int> vec)
{
	int size = static_cast<int>(vec.size());

	for (int i = 0; i < size; i++)
	{
		a[i] = vec[i];
	}

	numOfElems = size;
}

// Move constructor
MyArrayStack::MyArrayStack(MyArrayStack&& otherArray)
{
	a = otherArray.a;
	numOfElems = otherArray.numOfElems;
	capacity = otherArray.capacity;

	otherArray.capacity = 0;
	otherArray.a = nullptr;
	otherArray.numOfElems = 0;
}

// Move Assignment constructor
MyArrayStack& MyArrayStack::operator=(MyArrayStack&& otherArray)
{
	if (this != &otherArray)
	{
		emptyStack();
		a = otherArray.a;
		numOfElems = otherArray.numOfElems;
		capacity = otherArray.capacity;

		otherArray.a = nullptr;
		otherArray.numOfElems = 0;
		otherArray.capacity = 0;
	}
	else
		cout << "Attempted assignment to itself" << endl;

	return *this;
}

//comparison operator
bool MyArrayStack::operator==(MyArrayStack& otherArray) const
{
	int i = 0;
	while (i < numOfElems - 1)
	{
		if (otherArray.a[i] != a[i])
			return false;
		i++;
	}
	return true;
}

// emptyStack
void MyArrayStack::emptyStack()
{
	numOfElems = 0;
}

// push
void MyArrayStack::push(int newItem)
{
	if (numOfElems <= capacity)
	{
		a[numOfElems] = newItem;
		numOfElems++;
	}
	else
	{
		resize();
		push(newItem);
	}
}

// pop
void MyArrayStack::pop()
{
	numOfElems--;
}

//top
int MyArrayStack::top() const
{
	return a[0];
}

// isEmpty
bool MyArrayStack::isEmpty() const
{
	return numOfElems == 0;
}

// size
 int MyArrayStack::size() const
{
	 return numOfElems;
}

 //swap
 MyArrayStack& MyArrayStack::swap(MyArrayStack& newStack)
{
	 MyArrayStack temp = newStack;

	 newStack.a = new int[capacity];
	 newStack.capacity = capacity;
	 newStack.numOfElems = numOfElems;
	 for (int i = 0; i < numOfElems; i++)
		 newStack.a[i] = a[i];

	/* a = new int[temp.capacity];
	 capacity = temp.capacity;
	 numOfElems = temp.numOfElems;
	 for (int i = 0; i < numOfElems; i++)
		 a[i] = temp.a[i];*/
	 *this = move(temp);

	 return *this;
}

 // Resize
 void MyArrayStack::resize()
 {
	 capacity *= 2;
 }

 // Destructor
 MyArrayStack::~MyArrayStack()
 {
	 delete[] a;
	 a = nullptr;
 }

// MYLISTSTACKKKKKKKKKKKK

 ostream& operator<<(ostream& out, const MyListStack& otherList)
 {
	 cout << "List: ";
	 Node * current = otherList.top;

	 while (current != nullptr)
	 {
		 out << current->getData() << " ";
		 current = current->getNext();
	 }

	 out << endl << endl;
	 return out;
 }

 MyListStack::MyListStack()
 {
	 top = nullptr;
	 count = 0;
 }

// Copy Constructor
 MyListStack::MyListStack(const MyListStack& otherList)
 {
	
	top = new Node(otherList.top->getData(), nullptr);

	Node * current = top;
	Node * otherCurrent = otherList.top->getNext();
	while (otherCurrent != nullptr)
	{
		current->setNext(new Node(otherCurrent->getData(), nullptr));
		otherCurrent = otherCurrent->getNext();
		current = current->getNext();
	}

	count = otherList.count;
 }

 // Overloaded Constructor
 MyListStack::MyListStack(int numOfNodes, int newData)
 {
	 top = new Node(newData, nullptr);

	 Node * current = top;
	 for (int i = 0; i < numOfNodes - 1; i++)
	 {
		 current->setNext(new Node(newData, nullptr));
		 current = current->getNext();
	 }
 }


 // Move Constructor
 MyListStack::MyListStack(MyListStack&& otherList)
 {
	 emptyStack();

	 count = otherList.count;
	 top = otherList.top;

	 otherList.count = 0;
	 otherList.top = nullptr;
 }

 bool MyListStack::operator==(const MyListStack& otherList) const
 {
	 if (count == otherList.count)
	 {
		 Node * current = top;
		 Node * otherCurrent = otherList.top;
		 while (current != nullptr)
		 {
			 if (current->getData() == otherCurrent->getData())
			 {
				 current = current->getNext();
				 otherCurrent = otherCurrent->getNext();
			 }
			 else
				 return false;
		 }
	 }
	 return false;
 }

 MyListStack& MyListStack::operator=(MyListStack&& otherList)
 {
	 if (*this == otherList)
	 {
		 cerr << "Attempted re-assignment. " << endl;
	 }
	 else
	 {
		 emptyStack();

		 count = otherList.count;
		 top = otherList.top;

		 otherList.count = 0;
		 delete otherList.top;
	 }
	 return *this;
 }


 void MyListStack::emptyStack()
 {
	 while (count != 0)
	 {
		 pop();
	 }
 }

 void MyListStack::swap(MyListStack& otherList)
 {
	 if (this != &otherList)
	 {
		 Node * temp = top;
		 int tempCount = count;

		 top = otherList.top;

		 otherList.top = temp;

		 count = otherList.count;
		 otherList.count = tempCount;
	 }
	 else
	 {
		 cerr << "Attempted to reassignment. " << endl;
	 }
 }

 void MyListStack::push(int obj)
 {
	 top = new Node(obj, top);
	 count++;
 }

 void MyListStack::pop()
 {
	 if (count == 0)
	 {
		 cerr << "List is already empty." << endl;
	 }
	 else
	 {
		 if (top->getNext() != nullptr)
		 {
			 Node * current = top;
			 top = top->getNext();

			 delete current;
			 current = nullptr;
		 }
		 else
		 {
			 delete top;
			 top = nullptr;
		 }
		 count--;
	 }
 }

 int MyListStack::getTop() const
 {
	 return top->getData();
 }

 bool MyListStack::isEmpty() const
 {
	 return count == 0;
 }

 int MyListStack::size() const
 {
	 return count;
 }

 MyListStack::~MyListStack()
 {
	 emptyStack();
 }