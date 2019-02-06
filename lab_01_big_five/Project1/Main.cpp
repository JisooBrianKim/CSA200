#include "BigFive.h"
#include "Test_DArray.h"
#include "Test_DoublyList.h"
#include "Test_BigFive.h"

#include <iostream>
using namespace std;

void test_DArray_moveFunctions();
void test_DoublyList_moveFunctions();
void test_BigFive();

int main()
{
	test_DArray_moveFunctions();
	cout << "\n%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n\n";
	test_DoublyList_moveFunctions();
	cout << "\n%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n\n";
	test_BigFive();
	cout << "\n%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n\n";

	cout << endl;
	system("Pause");
    return 0;
}

//void test_DArray_moveFunctions()
//{
//	// Test default constructor
//	cout << "TEST: DArray move constructor";
//	cout << "\nCreate a1";
//	int arr1[] = { 10, 20, 30 };
//	int numOfElem1 = 3;
//	DArray a1;
//	a1.populateDArray(arr1, numOfElem1);
//	cout << "\n\ta1: " << a1;
//
//	cout << "\nCreate a2 by using the move constructor";
//	DArray a2 = move(a1);
//	cout << "\n\ta2: " << a2;
//	cout << "\nCheck a1:";
//	cout << ((a1.checkDArray()) ? 
//		"\n\tEmpty" : "\n\tNon-empty");
//	cout << ((a1.getCapacity() == 0) ? 
//		"\n\tCap is zero" : "\n\tCap is not zero.");
//	cout << ((a1.getNumOfElem() == 0) ? 
//		"\n\tNumOfElem is zero" : "\n\tNumOfElem is not zero.");
//
//	cout << "\n----------------------------------------------------\n";
//
//	cout << "TEST: DArray move assignment operator";
//	cout << "\nCreate a3";
//	int arr3[] = { 10, 20, 30 };
//	int numOfElem3 = 3;
//	DArray a3;
//	a3.populateDArray(arr3, numOfElem3);
//	cout << "\n\ta3: " << a3;
//
//	cout << "Create a4";
//	int arr4[] = { 60, 70, 80, 90 };
//	int numOfElem4 = 4;
//	DArray a4;
//	a4.populateDArray(arr4, numOfElem4);
//	cout << "\n\ta4: " << a4;
//
//	cout << "\nUse the move assigment operator for a4 = a3";
//	a4 = move(a3);
//	cout << "\n\ta2: " << a4;
//	cout << "\nCheck a3:";
//	cout << ((a3.checkDArray()) ?
//		"\n\tEmpty" : "\n\tNon-empty");
//	cout << ((a3.getCapacity() == 0) ?
//		"\n\tCap is zero" : "\n\tCap is not zero.");
//	cout << ((a3.getNumOfElem() == 0) ?
//		"\n\tNumOfElem is zero" : "\n\tNumOfElem is not zero.");
//	cout << endl;
//}

//void test_DoublyList_moveFunctions()
//{
//	// Test default constructor
//	cout << "TEST: DLL move constructor";
//	cout << "\nCreate list1";
//	int arr1[] = { 10, 20, 30 };
//	int numOfElem1 = 3;
//	DoublyList list1;
//	list1.populateDLL(arr1, numOfElem1);
//	cout << "\n\tlist1: " << list1;
//
//	cout << "\nCreate list2 by using the move constructor";
//	DoublyList list2 = move(list1);
//	cout << "\n\tlist2: " << list2;
//	cout << "\nCheck list1:";
//	cout << ((list1.isEmpty()) ?
//		"\n\tEmpty" : "\n\tNon-empty");
//	cout << ((list1.checkFirst()) ?
//		"\n\tFirst is NULL." : "\n\tFirst is not NULL..");
//	cout << ((list1.checkLast()) ?
//		"\n\tLast is NULL." : "\n\tLast is not NULL..");
//
//	cout << "\n----------------------------------------------------\n";
//
//	cout << "TEST: DLL move assignment operator";
//	cout << "\nCreate list3";
//	int arr3[] = { 10, 20, 30 };
//	int numOfElem3 = 3;
//	DoublyList list3;
//	list3.populateDLL(arr3, numOfElem3);
//	cout << "\n\tlist3: " << list3;
//
//	cout << "Create list4";
//	int arr4[] = { 60, 70, 80, 90 };
//	int numOfElem4 = 4;
//	DoublyList list4;
//	list4.populateDLL(arr4, numOfElem4);
//	cout << "\n\ta4: " << list4;
//
//	cout << "\nUse the move assigment operator for a4 = list3";
//	list4 = move(list3);
//	cout << "\n\ta2: " << list4;
//	cout << "\nCheck list3:";
//	cout << ((list3.isEmpty()) ?
//		"\n\tEmpty" : "\n\tNon-empty");
//	cout << ((list3.checkFirst()) ?
//		"\n\tFirst is NULL." : "\n\tFirst is not NULL..");
//	cout << ((list3.checkLast()) ?
//		"\n\tLast is NULL." : "\n\tLast is not NULL..");
//	cout << endl;
//}

//void test_BigFive()
//{
//	// Test default constructor
//	cout << "TEST: Default constructor"
//		<< "\n\t(create bf_1)";
//	BigFive bf_1;
//	cout << "\nbf_1\n" << bf_1;
//	cout << "\n----------------------------------------------------\n";
//
//	// Test copy constructor
//	cout << "TEST: Copy constructor " 
//		<< "\n\t(create bf_2 by copying from bf_1)";
//	BigFive bf_2(bf_1);
//	cout << "\nbf_2\n" << bf_2;
//	cout << "\n----------------------------------------------------\n";
//
//	// Test resetBigFive
//	cout << "TEST: Function resetBigFive "
//		<< "\n\t(bf_1 and bf_2 are equal)" 
//		<< "\n\t(empty bf_1 to check no shallow copy was made)"
//		<< "\n\t(bf_1 and bf_2 should not be equal now)\n";
//	bf_1.resetBigFive();
//	cout << "\nbf_1\n" << bf_1;
//	cout << "\nbf_2\n" << bf_2;
//	cout << "\n----------------------------------------------------\n";
//
//	// Test overloaded assignment operator
//	cout << "TEST: Overloaded assignment operator "
//		<< "\n\t(create bf_3 using the default constructor)"
//		<< "\n\t(create bf_4 using the overloaded constructor)"
//		<< "\n\t(bf_3 and bf_4 should not be equal)\n";
//	int a[] = { 6, 7, 8, 9 };
//	int numOfElem = 4;
//	BigFive bf_3;
//	cout << "\nbf_3\n" << bf_3;
//	BigFive bf_4(a, numOfElem);
//	cout << "\nbf_4\n" << bf_4;
//	cout << "\n\t(call the overloaded assignment operator)"
//		<< "\n\t(bf_3 = bf_4)"
//		<< "\n\t(bf_3 and bf_4 should be equal now)\n";
//	bf_3 = bf_4;
//	cout << "bf_3\n" << bf_3 << endl;
//	cout << "\n\t(empty bf_4 to check no shallow copy was made)"
//		<< "\n\t(bf_3 and bf_4 should not be equal)\n";
//	bf_4.resetBigFive();
//	cout << "bf_4\n" << bf_4 << endl;
//	cout << "bf_3\n" << bf_3 << endl;
//}