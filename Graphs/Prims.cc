/**
 * Used for finding Minimum spanning tree
 * V vertexes and V - 1 edges
 * Minuimum cost on travelling
 * Greedy algorithm
 * Only the adjacent vertex of the current vertex are observed
 * For making a spanning tree the graph has to be fully connected
 * For a fully connected and undirected graph atleast one spanning tree can be made and V 
 */

/**
  * COMPLEXITY: O(V^2)
 */

#include <bits/stdc++.h>
using namespace std;

template<typename T>
void print(vector<T> arr) {
  for (T x: arr) cout << x << " ";
  cout << endl;
}

int findMinVertex(vector<int> &wt, vector<bool> &visited, int V) {
  int ans = -1;
  int currWt = INT_MAX;

  for (int i=0; i < V; i++) {
    if (visited[i]) continue;

    if (wt[i] < currWt) {
      ans = i;
      currWt = wt[i];
    }
  }

  return ans;
}

void prims(vector<vector<int>> &graph) {
  int V = graph.size();

  vector<int> wt(V, INT_MAX);
  vector<bool> visited(V, false);
  vector<int> parent(V);

  parent[0] = -1;
  wt[0] = 0;

  for (int i=0; i < V-1; i++) {
    int currVertex = findMinVertex(wt, visited, V);
    if (currVertex == -1) break;

    visited[currVertex] = true;

    for (int j = 0; j < V; j++) {
      if (graph[currVertex][j] && !visited[j] && graph[currVertex][j] < wt[j]) {
        parent[j] = currVertex;
        wt[j] = graph[currVertex][j];
      }
    }
  }

  for (int i=1; i < V; i++)
    cout << parent[i] << " " << i << ": " << graph[parent[i]][i] << endl;
}

int main() {
  vector<vector<int>> graph = {
    {0, 2, 0, 6, 0},
    {2, 0, 3, 8, 5},
    {0, 3, 0, 0, 7},
    {6, 8, 0, 0, 9},
    {0, 5, 7, 9, 0}
  };

  prims(graph);
  return 0;
}
