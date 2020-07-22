// NAME: PHAM THI NGOC HA
// ID:19125089
// CLASS: 19CTT1

#include "Pointer.h"
#include <iostream>

using namespace std;

int main() {
	int a[10] = { 3, 8, 2, 7, 4, 1, 5 };
	PrintArray(a, 7);
	cout << endl;
	HeadQuickSort(a, 0, 6);
	PrintArray(a, 7);
	cout << endl;
	cout << BinarySearch(a, 7, 3) << endl;
	return 0;
}