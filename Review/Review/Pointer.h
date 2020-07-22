#ifndef _POINTER_H_
#define _POINTER_H_

#include <iostream>
#include <math.h>

using namespace std;

bool CheckPrime(int x);
void InputArray(int*& a, int& n);
void DeallocateArray(int*& a);
void PrintArray(int* a, int n);
int FindMin(int* a, int n);
int FindMaxModulus(int* a, int n);
bool IsAscending(int* a, int n);
int SumOfArray(int* a, int n);
int CountPrime(int* a, int n);
int ReverseArray(int*& a, int* b, int n);
int LinearSearch(int* a, int n, int key);
int SentineLinearSearch(int* a, int n, int key);
void Swap(int& a, int& b);
void HeadQuickSort(int a[], int l, int r);
int BinarySearch(int* a, int n, int key);
int RecursiveBinarySearch(int* a, int left, int right, int key);

#endif // _POINTER_H_
