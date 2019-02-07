/*
	Kim, Ji Soo

	CSA200
	February 6, 2019

	Lab 1
*/

#include "DArray.h"

// Definition function emptyArray
void DArray::emptyArray()
{
	numOfElem = 0;
}

// Definition move constructor
DArray::DArray(DArray&& otherArray)
{
	a = otherArray.a;
	capacity = otherArray.capacity;
	numOfElem = otherArray.numOfElem;

	otherArray.a = nullptr;
	otherArray.capacity = 0;
	otherArray.numOfElem = 0;
}

// Definition move assignment operator
DArray& DArray::operator=(DArray&& otherArray)
{
	if (&otherArray != this)
	{
		delete a;
		a = otherArray.a;
		capacity = otherArray.capacity;
		numOfElem = otherArray.numOfElem;

		otherArray.a = nullptr;
		otherArray.capacity = 0;
		otherArray.numOfElem = 0;
	}
	else
		cout << "Attempted assignment to itself.";

	return *this;
}

/*******************************************************************/

#include "DoublyList.h"

// Definition move constructor
DoublyList::DoublyList(DoublyList&& otherList)
{
	first = otherList.first;
	last = otherList.last;
	count = otherList.count;

	otherList.first = nullptr;
	otherList.last = nullptr;
	otherList.count = 0;
}

// Definition move assignment operator
DoublyList& DoublyList:: operator=(DoublyList&& otherList)
{
	if (&otherList != this)
	{
		destroyList();
		first = otherList.first;
		last = otherList.last;
		count = otherList.count;

		otherList.first = nullptr;
		otherList.last = nullptr;
		otherList.count = 0;
	}
	else
		cout << "Attempted assignment to itself.";

	return *this;
}

/*******************************************************************/

#include "BigFive.h"

// Definition operator<<
ostream& operator<<(ostream& out, const BigFive& bigBob)
{
	if (bigBob.anInt == nullptr && bigBob.aDArray == nullptr
		&& bigBob.aList == nullptr && bigBob.aVector == nullptr)
		out << "The BigFive object is pointing to Null";
	else
	{
		out << "Integer: " << *bigBob.anInt << endl;

		out << "Array: " << *bigBob.aDArray << endl;

		out << "List: " << *bigBob.aList << endl;

		out << "Vector: ";
		for (int i = 0; i < bigBob.aVector->size(); i++)
		{
			out << (*(bigBob.aVector))[i] << " ";
		}
		out << endl;
	}

	return out;
}

// Default constructor
BigFive::BigFive()
{
	anInt = new int;
	*anInt = 5;

	aDArray = new DArray;
	for (int i = 100; i < 103; i++)
	{
		aDArray->addElement(i);
	}

	aList = new DoublyList;
	for (int i = 200; i < 204; i++)
	{
		aList->insertBack(i);
	}

	aVector = new vector<int>;
	*aVector = { 300, 301, 302, 303, 304 };
}

// Overloaded constructor
BigFive::BigFive(const vector<vector<int>>& v)
{
	anInt = new int;
	*anInt = v[0].at(0);

	aDArray = new DArray;
	for (int i = 0; i < v[1].size(); i++)
	{
		aDArray->addElement(v[1].at(i));
	}

	aList = new DoublyList;
	for (int i = 0; i < v[2].size(); i++)
	{
		aList->insertBack(v[2].at(i));
	}

	aVector = new vector<int>;
	for (int i = 0; i < v[3].size(); i++)
	{
		aVector->push_back(v[3].at(i));
	}
}

// Copy constructor
BigFive::BigFive(const BigFive& bigBob)
{
	anInt = new int;
	*anInt = *bigBob.anInt;

	aDArray = new DArray;
	*aDArray = *bigBob.aDArray;

	aList = new DoublyList;
	*aList = *bigBob.aList;

	aVector = new vector<int>;
	*aVector = *bigBob.aVector;
}

// Overloaded assignment operator
BigFive& BigFive::operator=(const BigFive& bigBob)
{
	if (&bigBob != this)
	{
		anInt = new int;
		*anInt = *bigBob.anInt;

		aDArray = new DArray;
		*aDArray = *bigBob.aDArray;

		aList = new DoublyList;
		*aList = *bigBob.aList;

		aVector = new vector<int>;
		*aVector = *bigBob.aVector;
	}
	else
	{
		cout << "Attempted assignment to itself.";
	}
	return *this;
}

// Definition function resetBigFive
void BigFive::resetBigFive()
{
	*anInt = 0;
	aDArray->emptyArray();
	aList->destroyList();
	aVector->clear();
}

// Destructor
BigFive::~BigFive()
{
	delete anInt;
	anInt = nullptr;
	aDArray->~DArray();
	aList->~DoublyList();
	aVector->~vector();
}