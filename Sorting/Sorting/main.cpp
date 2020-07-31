#include "Algorithm.h"
#include <time.h>
#include <iostream>

using namespace std;

int main() {
	//	int n, range, order = 0, sort = 1;
	//	time_t start, end;
	//	int* a;
	//	n = 300000;
	//	a = new int[n] {0};
	//	cout << "The size: " << n << endl;
	//	while (1) {
	//		if (order == 0) {
	//			switch (sort)
	//			{
	//			case 1:
	//				cout << "Selection Sort:" << endl;
	//				break;
	//			case 2:
	//				cout << "Insertion Sort:" << endl;
	//				break;
	//			case 3:
	//				cout << "Binary Insertion Sort:" << endl;
	//				break;
	//			case 4:
	//				cout << "Bubble Sort:" << endl;
	//				break;
	//			case 5:
	//				cout << "Shaker Sort:" << endl;
	//				break;
	//			case 6:
	//				cout << "Shell Sort:" << endl;
	//				break;
	//			case 7:
	//				cout << "Heap Sort:" << endl;
	//				break;
	//			case 8:
	//				cout << "Merge Sort:" << endl;
	//				break;
	//			case 9:
	//				cout << "Middle Quick Sort:" << endl;
	//				break;
	//			case 10:
	//				cout << "Counting Sort:" << endl;
	//				break;
	//			case 11:
	//				cout << "Radix Sort:" << endl;
	//				break;
	//			case 12:
	//				cout << "Flash Sort:" << endl;
	//				break;
	//			default:
	//				break;
	//			}
	//		}
	//		a = new int[n] {0};
	//		GenerateData(a, n, order);
	//		order++;
	//
	//		time(&start);
	//		ios_base::sync_with_stdio(false);
	//		switch (sort)
	//		{
	//		case 1:
	//			SelectionSort(a, n);
	//			break;
	//		case 2:
	//			InsertionSort(a, n);
	//			break;
	//		case 3:
	//			BinaryInsertionSort(a, n);
	//			break;
	//		case 4:
	//			BubbleSort(a, n);
	//			break;
	//		case 5:
	//			ShakerSort(a, n);
	//			break;
	//		case 6:
	//			ShellSort(a, n);
	//			break;
	//		case 7:
	//			HeapSort(a, n);
	//			break;
	//		case 8:
	//			MergeSort(a, 0, n - 1);
	//			break;
	//		case 9:
	//			QuickSort(a, 0, n - 1);
	//			break;
	//		case 10:
	//			range = n + 2;
	//			CountingSort(a, n, range);
	//			break;
	//		case 11:
	//			Radixsort(a, n);
	//			break;
	//		case 12:
	//			FlashSort(a, n);
	//			break;
	//		default:
	//			break;
	//		}
	//		time(&end);
	//		double time_taken = double(end - start);
	//		cout << fixed
	//			<< time_taken << cout.precision(5) << endl;
	//		delete[] a;
	//
	//		if (order == 4) {
	//			sort++;
	//			order = 0;
	//		}
	//		if (sort == 13)
	//			break;
	//	}

	time_t start, end;
	int n = 300000;
	int* a = new int[n] {0};
	GenerateRandomData(a, n);
	time(&start);
	ios_base::sync_with_stdio(false);
	QuickSort(a, 0, n - 1);
	time(&end);
	double time_taken = double(end - start);
	cout << fixed << time_taken << cout.precision(5) << endl;
	delete[] a;
	return 0;
}