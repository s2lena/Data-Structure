#include "Function.h"

int main() {
	int n;
	cout << "N = ";
	cin >> n;
	bool** a = new bool*[n];
	for (int i = 0; i < n; i++)
		a[i] = new bool[n];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> a[i][j];
	/*if (CompleteGraph(a, n))
		cout << "It is a complete graph" << endl;
	else
		cout << "It is not a complete graph" << endl;*/
	/*if (CircularGraph(a, n))
		cout << "It is a circular graph" << endl;
	else
		cout << "It is not a circular graph" << endl;*/
	if (BiGraph(a, n))
		cout << "It is a bipartite graph" << endl;
	else
		cout << "It is not a bipartite graph" << endl;
	delete[] a;
	return 0;
}