#include "Function.h"

bool CompleteGraph(bool** a, int n)
{
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
			if (a[i][j] == false)
				return false;
	return true;
}

bool CircularGraph(bool** a, int n)
{
	bool check, * visited = new bool[n] {false};
	vector<int> load;
	double edge = 0; int cur;
	load.push_back(0);
	visited[0] = true;
	while (1) {
		check = false;
		cur = load.back();
		for (int i = 0; i < n; i++) {
			if (a[cur][i]) {
				edge++;
				if (visited[i] == false && check == false) {
					load.push_back(i);
					visited[i] = true;
					check = true;
				}
			}
		}
		if (!check)
			break;
	}
	delete[] visited;
	if ((edge / 2) != (double)n)
		return false;
	return true;
}

bool BiGraph(bool** a, int n)
{
	vector<int> order;
	int* team = new int[n];
	for (int i = 0; i < n; i++)
		team[i] = NO_COLOR;
	for (int i = 0; i < n; i++) {
		if (team[i] == NO_COLOR) {
			order.push_back(i);
			team[i] = RED;
			while (order.size()) {
				int v = order.back();
				order.pop_back();
				for (int j = 0; j < n; j++) {
					if (a[v][j])
						if (v == j || team[j] == team[v]) {
							delete[] team;
							return false;
						}
						else {
							if (team[j] == NO_COLOR)
								order.push_back(j);
							if (team[v] == RED) team[j] = GREEN;
							else team[j] = RED;
						}
				}
			}
		}
	}
	delete[] team;
	return true;
}