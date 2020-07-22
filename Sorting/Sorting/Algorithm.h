#ifndef _ALGORITHM_H_
#define _ALGORITHM_H_

#define RANGE 255  

#include "DataGenerator.h"
#include <list>

void SelectionSort(int a[], int n);
void InsertionSort(int a[], int n);
int BinarySearch(int a[], int item, int left, int right);
void BinaryInsertionSort(int a[], int n);
void BubbleSort(int a[], int n);
void ShakerSort(int a[], int n);
int ShellSort(int arr[], int n);
void Heapify(int arr[], int n, int i);
void HeapSort(int arr[], int n);
void Merge(int a[], int l, int m, int r);
void MergeSort(int arr[], int l, int r);
void QuickSort( int a[], int l, int r);
void CountSort(int a[], int n);
void RadixSort(int* a, int n, int max);


#endif // _ALGORITHM_H_
