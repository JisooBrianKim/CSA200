#ifndef DARRAY_H
#define DARRAY_H

#include <iostream>
using namespace std;

const int CAP = 50;

class DArray
{
	friend ostream& operator<<(ostream&, const DArray&);
	// Overloaded insertion operator to print array

public:
    DArray( );
	DArray(int);
	DArray(const DArray&);    

    void addElement(int);
	void populateDArray(int[], int);

	int getNumOfElem() const;
	int getCapacity() const;
	int& at(int) const;

	DArray& operator=(const DArray&);
	
	~DArray();

	// This function is for testing cases ONLY;
	// it checks if a is pointing to an array.
	bool checkDArray() const { return (a == nullptr); }

	/******************************************************
	* Write your declarations below this line.
	*******************************************************/

	// Declaration emptyArray


	// Declaration move constructor


	// Declaration move assignment operator


private:
    int *a;	//will point to an array of integers
    int capacity;			
    int numOfElem;		

};

#endif