#ifndef BIGFIVE_H
#define BIGFIVE_H

#include "DArray.h"
#include "DoublyList.h"

#include <iostream>
#include <vector>
using namespace std;

class BigFive
{
	// Declaration function operator<<
	friend ostream& operator<<(ostream& out, const BigFive& bigBob);

public:
	// Default constructor
	BigFive();

	// Overloaded constructor
	BigFive(const vector<vector<int>>& v1);

	// Copy constructor
	BigFive(const BigFive& bigBob);

	// Overloaded assignment operator
	BigFive& operator=(const BigFive& bigBob);

	// Declaration function resetBigFive
	void resetBigFive() const;

	// Destructor
	~BigFive();

private:
	int *anInt;
	DArray *aDArray;
	DoublyList *aList;
	vector<int> *aVector;
};

#endif
