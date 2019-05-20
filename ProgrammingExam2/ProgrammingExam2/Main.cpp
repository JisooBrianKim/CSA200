#include "MyStack.h"
#include "MyQueue.h"

int main()
{
	// DYNAMIC STACK ARRAY
	cout << "TEST STACK ARRAY" << endl;
	MyArrayStack myStack;

	cout << "-----Original Array-----" << endl;
	for (int i = 1; i < 6; i++)
		myStack.push(i);
	cout << myStack;

	cout << "----Copy----" << endl;
	MyArrayStack otherStack1 = myStack;
	cout << otherStack1;

	myStack.pop();
	cout << "----------Pop--------- " << endl;
	cout << myStack;

	myStack.push(77);
	cout << "----------Push 77---------- " << endl;
	cout << myStack;
	myStack.pop();
	myStack.push(5);

	cout << "----Other Stack-----" << endl;
	MyArrayStack otherStack;
	for (int i = 6; i < 11; i++)
		otherStack.push(i);
	cout << otherStack;

	
	cout << "--------swap--------" << endl;
	cout << "My Stack " << myStack;
	cout << "Other Stack " << otherStack;
	myStack.swap(otherStack);
	cout << "My Stack " << myStack;
	cout << "Other Stack " << otherStack;

	cout << "------move constructor------" << endl;
	MyArrayStack newStack = move(otherStack);
	cout << "New Stack " << newStack;

	otherStack = move(newStack); // move it back

	cout << "------move assignment-------" << endl;
	myStack = move(otherStack);
	cout << "My Stack " << myStack;

	// DYANMIC QUEUE ARRAY
	cout << "TEST QUEUE ARRAY" << endl;
	cout << "-----Original Array-----" << endl;
	MyArrayQueue myQueue;
	for (int i = 1; i < 6; i++)
		myQueue.push(i);
	cout << myQueue;

	cout << "-------pop--------" << endl;
	myQueue.pop();
	cout << myQueue;

	cout << "-----Copy Constructor-----" << endl;
	MyArrayQueue otherQueue = myQueue;
	cout << otherQueue;

	cout << "----Swap----" << endl;
	MyArrayQueue swapQueue;
	for (int i = 6; i < 11; i++)
		swapQueue.push(i);
	myQueue.swap(swapQueue);
	cout << myQueue;

	cout << "size: " << endl;
	cout << myQueue.sizeQueue() << endl;

	// List Stack
		cout << "TEST LIST STACK" << endl;
	MyListStack myList;

	cout << "-----Original List-----" << endl;
	for (int i = 0; i < 6; i++)
	{
		myList.push(i);
	}
	cout << myList;
	
	cout << "----Copied----" << endl;
	MyListStack otherList = myList;
	cout << otherList;

	cout << "----Overloaded----" << endl;
	MyListStack otherList1 = MyListStack(4, 100);
	cout << otherList1;

	cout << "----Move Constructor----" << endl;
	MyListStack myList1 = move(otherList1);
	cout << "myList " << myList1;
	cout << "otherList1" << otherList1;

	cout << "----swap----" << endl;
	myList.swap(myList1);
	cout << "myList " << myList;
	cout << "myList1 " << myList1;

	// QUEUE LISTTTTTTTTTTTTTTTT
	cout << "TEST QUEUE LIST" << endl;
	cout << "----Original List----" << endl;
	MyQueueList myQueueList;
	cout << myQueueList;
	for (int i = 0; i < 6; i++)
		myQueueList.push(i);

	cout << myQueueList;
	cout << "back: " << myQueueList.getBack() << endl;
	cout << "front: " << myQueueList.getFront() << endl;
	myQueueList.push(6);
	cout << "back: " << myQueueList.getBack() << endl;
	myQueueList.pop();
	cout << "front: " << myQueueList.getFront() << endl;

	cout << "----Copied----" << endl;
	MyQueueList otherQueueList = myQueueList;
	cout << otherQueueList;

	cout << "----Overloaded Constructor----" << endl;
	MyQueueList myQueueList1 = MyQueueList(4, 100);
	cout << myQueueList1;

	cout << "----Move Constructor----" << endl;
	cout << "myQueueList1 " << myQueueList1;
	MyQueueList myQueueList2 = move(myQueueList1);
	cout << "Moved from 1 to 2 " << myQueueList2;
	cout << "myQueueList1 " << myQueueList1;

	cout << "----swap----" << endl;
	for (int i = 0; i < 5; i++)
		myQueueList1.push(i);
	cout << "MyQueueList1 " << myQueueList1;
	cout << "MyQueueList2 " << myQueueList2;
	myQueueList2.swap(myQueueList1);
	cout << "MyQueueList1 " << myQueueList1;
	cout << "MyQueueList2 " << myQueueList2;
	
	
	cout << endl;
	system("Pause");
	return 0;
}