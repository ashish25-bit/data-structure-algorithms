// https://practice.geeksforgeeks.org/problems/topological-sort/1

#include <bits/stdc++.h>
using namespace std;

// TIME LIMIT EXCEEDED
// int findMin(vector<int> &arr) {
//   int x = INT_MAX;
//   int res = 0;

//   for (int i=0; i < arr.size(); i++) {
//     if (arr[i] == -1) continue;
//     if (x > arr[i]) {
//       x = arr[i];
//       res = i;
//     }
//   }

//   return res;
// }

// void printMap(vector<int> &arr) {
//   for (int i=0; i < arr.size(); i++) {
//     cout << i << ": " << arr[i] << endl;
//   }
// }

// void deleteNode(vector<int> &arr, vector<int> &hashMap) {
//   for (int x: arr) {
//     hashMap[x]--;
//   }
// }

// vector<int> topoSort(int V, vector<vector<int>> adj) {
//   vector<int> hashMap(V, 0);
//   vector<int> res;

//   for (int i=0; i < V; i++) {
//     for (int x: adj[i])
//       hashMap[x]++;
//   }

//   printMap(hashMap);
//   int node = findMin(hashMap);
  
//   while (hashMap[node] == 0) {
//     res.push_back(node);
//     hashMap[node] = -1;

//     deleteNode(adj[node], hashMap);
//     node = findMin(hashMap);
//   }

//   return res;
// }

void topoSortUtil(vector<vector<int>> &adj, int curr, vector<bool> &visited, vector<int> &res) {
  visited[curr] = true;

  for (int x: adj[curr]) {
    if (visited[x]) continue;

    topoSortUtil(adj, x, visited, res);
  }

  res.push_back(curr);
}

vector<int> topoSort(int V, vector<vector<int>> &adj) {
  vector<bool> visited(V, false);
  vector<int> res;

  for (int i=0; i < V; i++) {
    if (visited[i]) continue;

    topoSortUtil(adj, i, visited, res);
  }

  reverse(res.begin(), res.end());
  return res;
}

int main() {
  // vector<vector<int>> adj = {
  //   {}, {}, {3}, {1},
  //   {0, 1}, {2, 0}
  // };
  
  vector<vector<int>> adj = {
    {}, {0}, {0}, {0},
  };

  vector<int> arr = topoSort(adj.size(), adj);
  for (int x: arr) cout << x << " ";
  
  return 0;
}
