// https://practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1

#include <bits/stdc++.h>
using namespace std;

bool isCycleUtil(vector<vector<int>> &adj, vector<bool> &visited, vector<int> &stack, int curr) {
  stack[curr] = 1;

  if (!visited[curr]) {
    visited[curr] = true;

    for (int x: adj[curr]) {
      if (!visited[x] && isCycleUtil(adj, visited, stack, x)) return true;
      if (stack[x]) return true;
    }
  }

  stack[curr] = 0;
  return false;
}

bool isCycle(int V, vector<vector<int>> adj) {
  vector<int> stack(V, 0);
  vector<bool> visited(V, false);

  for (int i=0; i < V; i++) {
    if (!visited[i]) {
      if (isCycleUtil(adj, visited, stack, i)) return true;
    }
  }
  
  return false;
}

int main() {
  vector<vector<int>> adj = {
    {0, 1},
    {1, 2},
    {2, 3},
    {3, 3}
  };

  int V = 4;

  cout << isCycle(V, adj);
  
  return 0;
}
