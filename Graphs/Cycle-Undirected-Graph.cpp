#include <bits/stdc++.h>
using namespace std;

bool isCycle(vector<int>adj[], int parent, int curr, vector<bool> &visited) {
	if (visited[curr]) return true;
	
	visited[curr] = true;
	
	for (int x: adj[curr]) {
		if (x != parent) {
			if (isCycle(adj, curr, x, visited))
				return true;
		}
	}
	
	return false;
}

bool isCycle(int V, vector<int>adj[]) {
	vector<bool> visited(V, false);
	int parent = -1;

	for (int i=0; i < V; i++) {
		if (!visited[i]) {
			if (isCycle(adj, parent, i, visited)) 
					return true;
		}
	}

	return false;
}

int main() {
	vector<int> arr [] = {
		/* 0 */ {1},
		/* 1 */ {0, 2, 4},
		/* 2 */ {1, 3},
		/* 3 */ {2, 4},
		/* 4 */ {1, 3},
	};

	// vector<int> arr [] = {
	// 	/* 0 */ {4},
	// 	/* 1 */ {2, 4},
	// 	/* 2 */ {1, 3},
	// 	/* 3 */ {2, 4},
	// 	/* 4 */ {0, 1, 3},
	// };

	int n = sizeof(arr) / sizeof(arr[0]);
	cout << isCycle(n, arr);
	
	return 0;
}
