#ifndef TEST_BIGFIVE_H
#define TEST_BIGFIVE_H

#include "BigFive.h"

#include <iostream>
#include <vector>
using namespace std;

void test_BigFive()
{
	// Test default constructor
	cout << "TEST: Default constructor"
		<< "\n\t(create bf_1)";
	BigFive bf_1;
	cout << "\nbf_1\n" << bf_1;
	cout << "\n----------------------------------------------------\n";

	// Test copy constructor
	cout << "TEST: Copy constructor "
		<< "\n\t(create bf_2 by copying from bf_1)";
	BigFive bf_2(bf_1);
	cout << "\nbf_2\n" << bf_2;
	cout << "\n----------------------------------------------------\n";

	// Test resetBigFive
	cout << "TEST: Function resetBigFive "
		<< "\n\t(bf_1 and bf_2 are equal)"
		<< "\n\t(empty bf_1 to check no shallow copy was made)"
		<< "\n\t(bf_1 and bf_2 should not be equal now)\n";
	bf_1.resetBigFive();
	cout << "\nbf_1\n" << bf_1;
	cout << "\nbf_2\n" << bf_2;
	cout << "\n----------------------------------------------------\n";

	// Test overloaded assignment operator
	cout << "TEST: Overloaded assignment operator "
		<< "\n\t(create bf_3 using the default constructor)"
		<< "\n\t(create bf_4 using the overloaded constructor)"
		<< "\n\t(bf_3 and bf_4 should not be equal)\n";
	vector<vector<int>> v = {
		{6},
		{700, 701, 702, 703},
		{800, 810, 820, 830, 840},
		{990, 991, 992, 993},
	};
	BigFive bf_3;
	cout << "\nbf_3\n" << bf_3;
	BigFive bf_4(v);
	cout << "\nbf_4\n" << bf_4;
	cout << "\n\t(call the overloaded assignment operator)"
		<< "\n\t(bf_3 = bf_4)"
		<< "\n\t(bf_3 and bf_4 should be equal now)\n";
	bf_3 = bf_4;
	cout << "bf_3\n" << bf_3 << endl;
	cout << "\n\t(empty bf_4 to check no shallow copy was made)"
		<< "\n\t(bf_3 and bf_4 should not be equal)\n";
	bf_4.resetBigFive();
	cout << "bf_4\n" << bf_4 << endl;
	cout << "bf_3\n" << bf_3 << endl;
}

#endif
