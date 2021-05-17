#include <bits/stdc++.h>
using namespace std;

bool isCycle(int V, vector<int>adj[]) {
	vector<bool> visited(V, false);
	queue<int> q;

	q.push(0);

	while (!q.empty()) {
		int top = q.front();

		if (visited[top]) return true;

		q.pop();
		visited[top] = true;
		vector<int> curr = adj[top];

		for (int i = 0; i < curr.size(); i++) {
			if (curr[i] == 0 || i == top) continue;
			q.push(i);
		}
	}

	return false;
}

int main() {
	// vector<int> arr [] = {
	// 	{1, 1, 0, 0, 0},
	// 	{1, 1, 1, 0, 1},
	// 	{0, 1, 1, 1, 0},
	// 	{0, 0, 1, 1, 1},
	// 	{0, 1, 0, 1, 1},
	// };

	vector<int> arr [] = {
		{0, 0, 0, 0, 1},
		{0, 0, 1, 0, 1},
		{0, 0, 0, 1, 0},
		{0, 0, 1, 0, 1},
		{1, 1, 0, 1, 0}
	};

	cout << isCycle(5, arr);
	
	return 0;
}
