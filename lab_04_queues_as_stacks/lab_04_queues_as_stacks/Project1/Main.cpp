#include "MyQueue.h"

#include <iostream>

using namespace std;

int main()
{
	MyQueue q1;

	cout << "TEST CASE 1\n\n";
	for (int i = 1; i < 10; ++i)
		q1.enqueue(i);
	q1.dequeue();
	q1.dequeue();
	q1.enqueue(100);
	cout << "Queue is 3 4 5 6 7 8 9 100\n";
	cout << "Queue front: " << q1.front() << endl;
	cout << "Queue back: " << q1.back() << endl;
	cout << "Queue size: " << q1.size() << endl;
	cout << "Popping items from the queue: ";
	while (!q1.isEmpty())
	{
		cout << q1.front() << " ";
		q1.dequeue();
	}
	
	cout << "\n\n========================================================\n";	
	cout << "TEST CASE 2\n\n";
	cout << "Queue is now empty." << endl;
	cout << q1.front() << endl;
	cout << q1.back() << endl;
	cout << "Queue size: " << q1.size() << endl;

	cout << "\nQueue is now: 10 11 12 13 14 15" << endl;
	for (int i = 10; i < 16; ++i)
		q1.enqueue(i);
	cout << "Queue front: " << q1.front() << endl;
	cout << "Queue back: " << q1.back() << endl;
	cout << "Queue size: " << q1.size() << endl;
	
	cout << "\n========================================================\n";
	cout << "TEST CASE 3\n\n";
	cout << "Emptying queue...\n";
	q1.emptyQueue();
	cout << "Queue front: " << q1.front() << endl;
	cout << "Queue back: " << q1.back() << endl;
	cout << "Queue size: " << q1.size() << endl;

	cout << "\n========================================================\n";
	cout << "TEST CASE 4\n\n";
	for (int i = 20; i < 26; ++i)
		q1.enqueue(i);
	cout << "Queue is now: 20 21 22 23 24 25" << endl;
	cout << "Queue front: " << q1.front() << endl;
	cout << "Queue back: " << q1.back() << endl;
	cout << "Queue size: " << q1.size() << endl;

	cout << "\n========================================================\n";
	cout << "TEST CASE 5\n\n";
	cout << "Copy constructor...\n";
	MyQueue q2(q1);
	cout << "Created q2 (copy of q1)" << endl;
	cout << "Empty q1..." << endl;
	q1.emptyQueue();
	cout << "q1 front: " << q1.front() << endl;
	cout << "q1 back: " << q1.back() << endl;
	cout << "q1 size: " << q1.size() << endl;
	cout << "q2 front: " << q2.front() << endl;
	cout << "q2 back: " << q2.back() << endl;
	cout << "q2 size: " << q2.size() << endl;

	cout << "\n========================================================\n";
	cout << "TEST CASE 6\n\n";
	cout << "Overloaded assignment operator...\n";
	MyQueue q3;
	cout << "Created q3" << endl;
	for (int i = 2; i < 9; i+=2)
		q3.enqueue(i);
	cout << "q3 is 2 4 6 8\n";
	cout << "q2 = q3..." << endl;
	q2 = q3;
	cout << "Empty q3..." << endl;
	q3.emptyQueue();
	cout << "q3 front: " << q3.front() << endl;
	cout << "q3 back: " << q3.back() << endl;
	cout << "q3 size: " << q3.size() << endl;
	cout << "q2 front: " << q2.front() << endl;
	cout << "q2 back: " << q2.back() << endl;
	cout << "q2 size: " << q2.size() << endl;

	cout << endl;
	system("Pause");
	return 0;
}
