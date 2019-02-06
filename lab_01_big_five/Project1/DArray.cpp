#include "DArray.h"

// Definition overloaded insertion operator
ostream& operator<<(ostream& out, const DArray& outArray)
{
	for (int i = 0; i < outArray.numOfElem; ++i)
		out << outArray.a[i] << " ";

	return out;
}

// Default constructor
DArray::DArray( )
{
    capacity = CAP;
	a = new int[capacity];	
	numOfElem = 0;
}

// Overloaded constructor
DArray::DArray(int newCapacity) 
{
	capacity = newCapacity;
    a = new int[capacity];
	numOfElem = 0;	 
}

// Copy constructor
DArray::DArray(const DArray& otherArray)
{
	//set all member variables of the calling object
	capacity = otherArray.capacity;
	numOfElem = otherArray.numOfElem;

	//create a new array
	a = new int[capacity];

	//copy all elements of the array parameter
	//  onto the calling object
	for (int i = 0; i < numOfElem; ++i)
		a[i] = otherArray.a[i];
}

// Definition function addElement
void DArray::addElement(int newElement)
{
    if (numOfElem >= capacity)
    {
		cerr << "Attempt to exceed capacity in DArray.\n";
		system("Pause");
        exit(0); 
    }
	else
	{
		a[numOfElem] = newElement;
		++numOfElem;
	}
}

// Definition function populateArray
void DArray::populateDArray(int paramArray[], int paramNoOfElem)
{
	if (paramNoOfElem >= capacity)
	{
		cerr << "Attempt to exceed capacity in DArray.\n";
		system("Pause");
		exit(0);
	}
	else
	{
		for (int i = 0; i < paramNoOfElem; ++i)
		{
			a[numOfElem] = paramArray[i];
			++numOfElem;
		}
	}
}

// Definition function getNumOfElem
int DArray::getNumOfElem() const
{
	return numOfElem;
}

// Definition function getCapacity
int DArray::getCapacity() const
{
	return capacity;
}

// Definition function at
int& DArray::at(int idx) const
{
	return a[idx];
}

// Definition overloaded assignment operator
DArray& DArray::operator=(const DArray& otherArray)
{
	//to avoid self assignment, check that the 
	//   parameter passed is not the calling object
	if (&otherArray != this)
	{
		//if the array we are passing has a different
		//  capacity from the calling object,
		//  then we need to create a new array
		if (capacity != otherArray.capacity)
		{
			//deallocate the memory used by 
			//  the calling object and
			//  re-create the object so that 
			//  it has the same capacity
			delete[] a;
			a = new int[otherArray.capacity];

			//update capacity
			capacity = otherArray.capacity;
		}

		//update number of elements	
		numOfElem = otherArray.numOfElem;

		// start copying
		for (int i = 0; i < numOfElem; ++i)
			a[i] = otherArray.a[i];
	}
	else
	{
		cerr << "Attempted assignment to itself.";
	}

	return *this;
}

// Destructor
DArray::~DArray()
{
	delete[] a; //delete the array
	a = nullptr; //null the pointer 
}
