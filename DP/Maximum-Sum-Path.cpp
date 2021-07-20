// https://practice.geeksforgeeks.org/problems/path-in-matrix3805/1#

#include <bits/stdc++.h>
using namespace std;

bool isValid(int i, int j, int n) {
  return i >= 0 && j >= 0 && i < n && j < n;
}
int maximum(int n, vector<vector<int>> m, int i, int j) {
  int left  = 0;
  int right = 0;
  int down  = 0;

  // left diagonal
  if (isValid(i+1, j-1, n))
      left = m[i+1][j-1];
  // right diagonal
  if (isValid(i+1, j+1, n))
      right = m[i+1][j+1];
  if (isValid(i+1, j, n))
      down = m[i+1][j];
  return max(left, max(right, down));
}

int maximumPath(int N, vector<vector<int>> M) {
  vector<vector<int>> t(N, vector<int>(N, 0));

  for (int i=0; i < N; i++)
    t[N-1][i] = M[N-1][i];

  for (int i = N-2; i >= 0; i--) {
    for (int j = N-1; j >= 0; j--) {
      t[i][j] = maximum(N, t, i, j) + M[i][j];
    }
  }

  int res = INT_MIN;
  for (int i=0; i < N; i++)
    res = max(t[0][i], res);
  return res;
}

int main() {
  vector<vector<int>> arr = {{348, 391}, {618, 193}};

  cout << maximumPath(arr.size(), arr);
  return 0;
}