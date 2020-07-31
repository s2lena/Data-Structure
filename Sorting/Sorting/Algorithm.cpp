#include "Algorithm.h"

void SelectionSort(int* a, int n)
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

void InsertionSort(int* a, int n)
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

int BinarySearch(int* a, int item, int left, int right)
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

void BinaryInsertionSort(int* a, int n)
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

void BubbleSort(int* a, int n)
{
	int i, j;
	for (i = 0; i < n - 1; i++)

		for (j = 0; j < n - i - 1; j++)
			if (a[j] > a[j + 1])
				Swap(a[j], a[j + 1]);
}

void ShakerSort(int* a, int n)
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

int ShellSort(int* a, int n)
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

void Heapify(int* a, int n, int i)
{
	int largest = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;

	if (l < n && a[l] > a[largest])
		largest = l;

	if (r < n && a[r] > a[largest])
		largest = r;

	if (largest != i) {
		Swap(a[i], a[largest]);
		Heapify(a, n, largest);
	}
}

void HeapSort(int* a, int n)
{
	for (int i = n / 2 - 1; i >= 0; i--)
		Heapify(a, n, i);

	for (int i = n - 1; i > 0; i--) {
		Swap(a[0], a[i]);
		Heapify(a, i, 0);
	}
}

void Merge(int* a, int l, int m, int r)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;

	int* L = new int[n1];
	int* R = new int[n2];

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

void MergeSort(int* a, int l, int r)
{
	if (l < r) {
		int m = l + (r - l) / 2;

		MergeSort(a, l, m);
		MergeSort(a, m + 1, r);

		Merge(a, l, m, r);
	}
}

int Partition(int*& a, int left, int right)
{
	int k = rand() % (right - left) + left;
	int pivot = a[k];
	Swap(a[k], a[left]);
	
	int i = left;

	for (int j = left + 1; j <= right; j++)
	{

		if (a[j] < pivot)
		{
			i++;
			Swap(a[i], a[j]);
		}
	}
	Swap(a[i], a[left]);
	return i;
}

void QuickSort(int*& a, int left, int right) {
	int s;
	if (left < right) {
		s = Partition(a, left, right);
		QuickSort(a, left, s - 1);
		QuickSort(a, s + 1, right);
	}
}

void CountingSort(int* a, int n, int range) {
	int* count = new int[range] { 0 };
	int i;
	int* out = new int[n] {0};

	for (i = 0; i < n; i++)
		++count[a[i]];

	for (i = 1; i < range; i++)
		count[i] += count[i - 1];

	for (i = n - 1; i >= 0; i--) {
		out[count[a[i]] - 1] = a[i];
		--count[a[i]];
	}

	for (i = 0; i < n; i++)
		a[i] = out[i];

	delete[] count;
	delete[] out;
}

int GetMax(int* a, int n)
{
	int mx = a[0];
	for (int i = 1; i < n; i++)
		if (a[i] > mx)
			mx = a[i];
	return mx;
}

void countSort(int* a, int n, int exp)
{
	int* output = new int[n] {0};
	int i, count[10] = { 0 };

	for (i = 0; i < n; i++)
		count[(a[i] / exp) % 10]++;
	
	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	for (i = n - 1; i >= 0; i--)
	{
		output[count[(a[i] / exp) % 10] - 1] = a[i];
		count[(a[i] / exp) % 10]--;
	}

	for (i = 0; i < n; i++)
		a[i] = output[i];
	delete[] output;
}

void Radixsort(int* a, int n)
{
	int m = GetMax(a, n);
	for (int exp = 1; m / exp > 0; exp *= 10)
		countSort(a, n, exp);
}

int* FlashSort(int* arr, int n) {
	int max = 0, min = arr[0];

	int m = (0.45 * n);
	int* l = new int[m] {0};
	int i;
	for (i = 1; i < n; ++i) {
		if (arr[i] < min) {
			min = arr[i];
		}
		if (arr[i] > arr[max]) {
			max = i;
		}
	}

	if (min == arr[max]) {
		return arr;
	}

	int c1 = (m - 1) / (arr[max] - min);

	int k;
	for (k = 0; k < m; k++) {
		l[k] = 0;
	}
	int j;
	for (j = 0; j < n; ++j) {
		k = (c1 * (arr[j] - min));
		++l[k];
	}

	for (int p = 1; p < m; ++p) {
		l[p] = l[p] + l[p - 1];
	}

	int hold = arr[max];
	arr[max] = arr[0];
	arr[0] = hold;

	int move = 0, t, flash;
	j = 0;
	k = m - 1;

	while (move < (n - 1)) {
		while (j > (l[k] - 1)) {
			++j;
			k = (c1 * (arr[j] - min));
		}
		if (k < 0) break;
		flash = arr[j];
		while (j != l[k]) {
			k = (c1 * (flash - min));
			hold = arr[t = --l[k]];
			arr[t] = flash;
			flash = hold;
			++move;
		}
	}
	for (j = 1; j < n; j++) {
		hold = arr[j];
		i = j - 1;
		while (i >= 0 && arr[i] > hold) {
			arr[i + 1] = arr[i--];
		}
		arr[i + 1] = hold;
	}
	return arr;
}
