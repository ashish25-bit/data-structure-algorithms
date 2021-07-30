#include <bits/stdc++.h>
using namespace std;

int findMin(vector<int> &distance, vector<bool> &visited, int n) {
  int minVertex = -1;

  for (int i=0; i < n; i++) {
    if (!visited[i] && (minVertex == -1 || distance[i] < distance[minVertex]))
      minVertex = i;
  }

  return minVertex;
}

void djikstra(vector<vector<int>> edges, int v) {
  vector<bool> visited(v, false);
  vector<int> distance(v, INT_MAX);

  distance[0] = 0;

  for (int i=0; i < v-1; i++) {
    int minVertex = findMin(distance, visited, v);

    for (int j=0; j < v; j++) {
      if (edges[minVertex][j] && !visited[j]) {
        int dist = distance[minVertex] + edges[minVertex][j];
        distance[j] = min(distance[j], dist);
      }
    }
    visited[i] = true;
  }

  for (int i=0; i < v; i++) {
    cout << i << ": " << distance[i] << "\n";
  }
}

int main() {
  int V = 5;
  vector<vector<int>> edges(V, vector<int>(V, 0));

  /*
  undirected edges
  edges[0][1] = 4;
  edges[0][2] = 8;

  edges[1][0] = 4;
  edges[1][2] = 2;
  edges[1][3] = 5;

  edges[2][0] = 8;
  edges[2][1] = 2;
  edges[2][3] = 5;
  edges[2][4] = 9;

  edges[3][1] = 5;
  edges[3][2] = 5;
  edges[3][4] = 4;

  edges[4][2] = 9;
  edges[4][3] = 4;
  */

  // directed edges
  edges[0][1] = 4;
  edges[0][2] = 8;

  edges[1][2] = 5;
  edges[1][3] = 1;

  edges[3][2] = 2;

  edges[4][2] = 9;
  edges[4][3] = 4;

  djikstra( edges, V);
  return 0;
}
