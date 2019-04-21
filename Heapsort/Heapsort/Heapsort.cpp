/*
	Kim, Ji Soo

	CS A200
	April 3, 2019

	Lab 3
*/

#include "Heapsort.h"
ostream& operator<<(ostream& out, const Heapsort& myHeapsort)
{
	for (int i = 0; i < myHeapsort.numOfElem; ++i)
		out << (myHeapsort).heap[i] << " ";

	return out;
}

Heapsort::Heapsort()
{
	heap = new int[capacity];
	capacity = CAP;
	numOfElem = 0;
}

// Matt, Colin
Heapsort::Heapsort(const Heapsort& otherHeapsort)
{
	capacity = otherHeapsort.capacity;
	numOfElem = otherHeapsort.numOfElem;
	heap = new int[capacity];

	for (int i = 0; i < numOfElem; ++i)
		heap[i] = (otherHeapsort).heap[i];
}


// Winston, Cedric, Marwa, Khoi
void Heapsort::bubbleUp() const
{
	bool isLower = true;
	int i = numOfElem;
	while (i >= 0 && isLower)
	{
		if (heap[i] < heap[(i - 1) / 2])
		{
			int temp = heap[(i - 1) / 2];
			heap[(i - 1) / 2] = heap[i];
			heap[i] = temp;
		}
		else
			isLower = false;
		i /= 2;
	}
}

// Tony, Andrew, Jose, David
void Heapsort::insertNode(int node)
{

	if (numOfElem >= capacity)
		resize();

	++numOfElem;
	heap[numOfElem] = node;
	bubbleUp();
}

// Charlie, Richard, Daniel, Yitan, Hwankee, Ashkii
void Heapsort::bubbleDown() const
{
	bool isLower = true;
	int i = 0, temp = 0, 
		left = 1, right = 2, lowest = 0;

	while (isLower && right < numOfElem)
	{
		lowest = heap[right] > heap[left] ? left : right;

		if (heap[i] > heap[lowest])
		{
			temp = heap[i];
			heap[i] = heap[lowest];
			heap[lowest] = temp;

			i = lowest;
			left = 2 * i + 1;
			right = 2 * i + 2;
		}
		else
			isLower = false;
	}
}
// Paul, Phong, Hien, Duy
void Heapsort::removeRoot()
{
	if (numOfElem == 1)
		numOfElem--;
	else
	{
		heap[0] = heap[numOfElem - 1];
		numOfElem--;
	}

	bubbleDown();
}

// Logan, Junior
Heapsort& Heapsort::sort(const vector<int>& seq)
{
	for (int e : seq)
		insertNode(e);
	return *this;
}

// Colin, Brian, Logan 
Heapsort::~Heapsort()
{
	delete[] heap;
	heap = nullptr;
}

Heapsort& Heapsort::operator=(const Heapsort& otherHeapsort)
{
	if (this != &otherHeapsort)
	{
		if (capacity != otherHeapsort.capacity)
		{
			capacity = otherHeapsort.capacity;
			heap = new int[capacity];
		}

		numOfElem = otherHeapsort.numOfElem;

		for (int i = 0; i < otherHeapsort.numOfElem; ++i)
			heap[i] = otherHeapsort.heap[i];
	}

	return *this;
}


// Andrew P, Brian W, Joe N, Madusha S
void Heapsort::resize()
{
	capacity *= 2;
	int *temp = new int[capacity];
	for (int i = 0; i < numOfElem; ++i)
		temp[i] = heap[i];
	heap = temp;
	delete temp;
	temp = nullptr;
}