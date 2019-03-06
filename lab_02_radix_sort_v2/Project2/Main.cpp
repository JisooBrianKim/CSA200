/********************************************

Radix Sort
Running time: O(n * k)

********************************************/

#include <iostream>
#include <string>
#include <string>

using namespace std;

void print(const int *a, int numOfElements);

int main()
{
	int *a1 = new int[15]{ 789, 456, 123, 741, 852, 963, 321, 654, 987, 147, 258, 369, 159, 753, 111 };
	int digits = 3;
	int numOfElements = 15;
	cout << "Start:  ";
	print(a1, numOfElements);
	cout << endl;

	//int *a1 = new int[9] {3789, 4156, 1213, 4741, 5852, 1963, 8321, 6454, 9857};
	//int digits = 4;
	//int numOfElements = 9;
	//cout << "Start:  ";
	//print(a1, numOfElements);
	//cout << endl;

	int *a2 = new int[numOfElements];

	/***********************************************************************************************************/
	// Your code ONLY in this section...

	// PRINT FROM HERE....
	/*
		Kim, Ji Soo

		CS A200
		February 27, 2019

		Lab 2
	*/

	int mod = 10;
	int l = 1;

	for (int i = digits; i > 0; i--) // O(k) k is number of digits,
	{								 // so the loop depends on the number of unique digits
		int pos = 0;
		for (int j = 0; j < 10; j++) // O(1), we know it goes from 0 to 9
		{
			int k = 0;
			while (k <numOfElements && pos < numOfElements) // O(n), n is the number of elements in the array
			{
				if (((a1[k] % mod) / (mod / 10)) == j)
				{
					a2[pos] = a1[k];
					pos++;
				}
				k++;
			}
		}
		mod *= 10;

		int* temp = a1;
		a1 = a2;
		a2 = temp;
		temp = nullptr;
	}
	delete[] a2;
	a2 = nullptr;
}
	// END PRINTING HERE... 
	/***********************************************************************************************************/

	cout << "\n\nFinal result should be in a1:\n";
	print(a1, numOfElements);

	delete[] a1;
	a1 = nullptr;

	cout << endl << endl;
	system("Pause");
	return 0;
}

void print(const int *a, int numOfElements)
{
	for (int i = 0; i < numOfElements; ++i)
		cout << a[i] << " ";
}