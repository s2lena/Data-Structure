#ifndef _ALGORITHM_H_
#define _ALGORITHM_H_

#include "DataGenerator.h"
#include <list>

void SelectionSort(int* a, int n);
void InsertionSort(int* a, int n);
int BinarySearch(int* a, int item, int left, int right);
void BinaryInsertionSort(int* a, int n);
void BubbleSort(int* a, int n);
void ShakerSort(int* a, int n);
int ShellSort(int* a, int n);
void Heapify(int* a, int n, int i);
void HeapSort(int* a, int n);
void Merge(int* a, int l, int m, int r);
void MergeSort(int* a, int l, int r);
int Partition(int*& arr, int left, int right);
void QuickSort(int*& arr, int left, int right);
void CountingSort(int* a, int n, int range);
int GetMax(int* a, int n);
void countSort(int* a, int n, int exp);
void Radixsort(int* a, int n);
int* FlashSort(int* arr, int n);

#endif // _ALGORITHM_H_
