#ifndef HEAPSORT_H
#define HEAPSORT_H
#include <iostream>
#include <vector>

using namespace std;
const int CAP = 15;

class Heapsort
{
	friend ostream& operator<<(ostream& out, const Heapsort& myHeapsort);
public:
	Heapsort();
	Heapsort(const Heapsort& otherHeapsort);

	void removeRoot();

	Heapsort& sort(const vector<int>& seq);
	
	Heapsort& operator=(const Heapsort& otherHeapsort);

	~Heapsort();
private:

	void insertNode(int node);
	int * heap;
	int capacity;
	int numOfElem;

	void bubbleUp() const;
	void bubbleDown() const;

	void resize();
};
#endif