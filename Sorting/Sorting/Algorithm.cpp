#include "Algorithm.h"

void SelectionSort(int a[], int n)
{
	int i, j, minIdx;

	for (i = 0; i < n - 1; i++)
	{
		minIdx = i;
		for (j = i + 1; j < n; j++)
			if (a[j] < a[minIdx])
				minIdx = j;

		Swap(a[minIdx], a[i]);
	}
}

void InsertionSort(int a[], int n)
{
	int i, key, j;
	for (i = 1; i < n; i++)
	{
		key = a[i];
		j = i - 1;

		while (j >= 0 && a[j] > key)
		{
			a[j + 1] = a[j];
			j = j - 1;
		}
		a[j + 1] = key;
	}
}

int BinarySearch(int a[], int item, int left, int right)
{
	if (right <= left)
		return (item > a[left]) ? (left + 1) : left;

	int mid = (left + right) / 2;

	if (item == a[mid])
		return mid + 1;

	if (item > a[mid])
		return BinarySearch(a, item, mid + 1, right);
	return BinarySearch(a, item, left, mid - 1);
}

void BinaryInsertionSort(int a[], int n)
{
	int i, loc, j, k, selected;

	for (i = 1; i < n; ++i)
	{
		j = i - 1;
		selected = a[i];

		loc = BinarySearch(a, selected, 0, j);

		while (j >= loc)
		{
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = selected;
	}
}

void BubbleSort(int a[], int n)
{
	int i, j;
	for (i = 2; i <= n; i++)
		for (j = n; j >= i; j--)
			if (a[j] < a[j - 1])
				swap(a[j], a[j - 1]);
}

void ShakerSort(int a[], int n) 
{
	int i, j, k;
	for (i = 0; i < n;) {
		for (j = i + 1; j < n; j++) {
			if (a[j] < a[j - 1])
				Swap(a[j], a[j - 1]);
		}
		n--;
		for (k = n - 1; k > i; k--) {
			if (a[k] < a[k - 1])
				Swap(a[k], a[k - 1]);
		}
		i++;
	}
}

int ShellSort(int a[], int n)
{
	for (int gap = n / 2; gap > 0; gap /= 2) {
		for (int i = gap; i < n; i += 1) {
			int temp = a[i];
			int j;
			for (j = i; j >= gap && a[j - gap] > temp; j -= gap)
				a[j] = a[j - gap];
			a[j] = temp;
		}
	}
	return 0;
}

void Heapify(int arr[], int n, int i)
{
	int largest = i; 
	int l = 2 * i + 1; 
	int r = 2 * i + 2; 

	if (l < n && arr[l] > arr[largest])
		largest = l;

	if (r < n && arr[r] > arr[largest])
		largest = r;
	
	if (largest != i) {
		Swap(arr[i], arr[largest]);
		Heapify(arr, n, largest);
	}
}

void HeapSort(int arr[], int n)
{
	for (int i = n / 2 - 1; i >= 0; i--)
		Heapify(arr, n, i);
	
	for (int i = n - 1; i > 0; i--) {
		Swap(arr[0], arr[i]);
		Heapify(arr, i, 0);
	}
}

void Merge(int a[], int l, int m, int r)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;

	int *L = new int[n1];
	int *R = new int[n2];

	for (i = 0; i < n1; i++)
		L[i] = a[l + i];
	for (j = 0; j < n2; j++)
		R[j] = a[m + 1 + j];

	i = 0; 
	j = 0; 
	k = l; 
	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			a[k] = L[i];
			i++;
		}
		else {
			a[k] = R[j];
			j++;
		}
		k++;
	}

	while (i < n1) {
		a[k] = L[i];
		i++;
		k++;
	}

	while (j < n2) {
		a[k] = R[j];
		j++;
		k++;
	}

	delete L;
	delete R;
}

void MergeSort(int arr[], int l, int r)
{
	if (l < r) {
		int m = l + (r - l) / 2;

		MergeSort(arr, l, m);
		MergeSort(arr, m + 1, r);

		Merge(arr, l, m, r);
	}
}

void QuickSort(int a[], int l, int r) 
{
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
		QuickSort(a, l, i - 2);
	QuickSort(a, i, r);
}

void CountSort(int a[], int n)
{
	int* output = new int[n];

	int count[RANGE + 1], i;
	memset(count, 0, sizeof(count));

	for (i = 0; a[i]; ++i)
		++count[a[i]];

	for (i = 1; i <= RANGE; ++i)
		count[i] += count[i - 1];

	for (i = 0; a[i]; ++i)
	{
		output[count[a[i]] - 1] = a[i];
		--count[a[i]];
	}
	
	for (i = 0; a[i]; ++i)
		a[i] = output[i];
	
	delete output;
}

void RadixSort(int* a, int n, int max) 
{
	int i, j, m, p = 1, index, temp, count = 0;
	list<int> pocket[10];      
	for (i = 0; i < max; i++) {
		m = pow(10, i + 1);
		p = pow(10, i);
		for (j = 0; j < n; j++) {
			temp = a[j] % m;
			index = temp / p;      
			pocket[index].push_back(a[j]);
		}
		count = 0;
		for (j = 0; j < 10; j++) {
			while (!pocket[j].empty()) {
				a[count] = *(pocket[j].begin());
				pocket[j].erase(pocket[j].begin());
				count++;
			}
		}
	}
}