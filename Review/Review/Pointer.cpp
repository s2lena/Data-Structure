#include "Pointer.h"

bool CheckPrime(int x)
{
	if (x < 2)
		return false;
	for (int i = 2; i <= sqrt(x); i++) {
		if (x % i == 0)
			return false;
	}
	return true;
}

void InputArray(int*& a, int& n)
{
	cout << "N = ";
	cin >> n;
	a = new int[n];
	cout << "Input " << n << "elements: ";
	for (int i = 0; i < n; i++)
		cin >> a[i];
}

void DeallocateArray(int*& a)
{
	delete[] a;
}

void PrintArray(int* a, int n)
{
	cout << "Array: ";
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
}

int FindMin(int* a, int n)
{
	int min = a[0];
	for (int i = 1; i < n; i++) {
		if (a[i] < min)
			min = a[i];
	}
	return min;
}

int FindMaxModulus(int* a, int n)
{
	int max = abs(a[0]);
	for (int i = 1; i < n; i++) {
		if (abs(a[i]) > max)
			max = abs(a[i]);
	}
	return max;
}

bool IsAscending(int* a, int n)
{
	int prev = a[0];
	for (int i = 1; i < n; i++) {
		if (a[i] <= prev)
			return false;
		else
			prev = a[i];
	}
	return true;
}

int SumOfArray(int* a, int n)
{
	int sum = 0;
	for (int i = 0; i < n; i++)
		sum += a[i];
	return sum;
}

int CountPrime(int* a, int n)
{
	int count = 0;
	for (int i = 0; i < n; i++) {
		if (CheckPrime(a[i]))
			count++;
	}
	return count;
}

int ReverseArray(int*& a, int* b, int n)
{
	a = new int[n];

	if (a == nullptr)
		return false;

	for (int i = 0; i < n; i++) {
		a[i] = b[n - 1 - i];
	}
	return true;
}

int LinearSearch(int* a, int n, int key)
{
	for (int i = 0; i < n; i++) {
		if (a[i] == key)
			return i;
	}
	return -1;
}

int SentineLinearSearch(int* a, int n, int key)
{
	int last = a[n - 1];
	a[n - 1] = key;
	int i = 0;
	while (a[i] != key)
		i++;
	a[n - 1] = last;
	if (i < n - 1 || a[n - 1] == key)
		return i;
	else
		return -1;
}

void Swap(int& a, int& b)
{
	int tmp = a;
	a = b;
	b = tmp;
}

void HeadQuickSort(int a[], int l, int r) {
	if (r <= l)
		return;

	int p = a[l];
	int i = l + 1;
	for (int j = l + 1; j <= r; j++) {
		if (a[j] < p) {
			Swap(a[j], a[i]);
			i++;
		}
	}
	Swap(a[i - 1], a[l]);
	if (i - 2 > 0)
		HeadQuickSort(a, l, i - 2);
	HeadQuickSort(a, i, r);
}

int BinarySearch(int* a, int n, int key)
{
	if (!IsAscending(a, n))
		HeadQuickSort(a, 0, n - 1);

	int idx = -1;
	int l = 0; int r = n - 1;
	while (1) {
		if (r >= l) {
			int mid = l + (r - l) / 2;

			if (a[mid] == key) {
				idx = mid;
				break;
			}
			else if (a[mid] > key)
				r = mid - 1;
			else
				l = mid + 1;
		}
	}
	return idx;
}

int RecursiveBinarySearch(int* a, int left, int right, int key)
{
	if (right >= left) {
		int mid = left + (right - left) / 2;

		if (a[mid] == key)
			return mid;
		if (a[mid] > key)
			return RecursiveBinarySearch(a, left, mid - 1, key);
		return RecursiveBinarySearch(a, mid + 1, right, key);
	}
	return -1;
}