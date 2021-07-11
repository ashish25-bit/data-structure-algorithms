// https://practice.geeksforgeeks.org/problems/largest-square-formed-in-a-matrix0806/1

#include <bits/stdc++.h>
using namespace std;

int maxSquare(vector<vector<int>> mat) {
  int n = mat.size();
  int m = mat[0].size();

  vector<vector<int>> t(n, vector<int>(m, 0));
  int res = 0;

  for (int i=n-1; i >= 0; i--) {
    for (int j=m-1; j >= 0; j--) {

      if (i == n-1)
        t[i][j] = mat[i][j];
      else if (j == m-1)
        t[i][j] = mat[i][j];
      else if (mat[i][j] == 0)
        t[i][j] = 0;
      else {
        t[i][j] = 1 + min(t[i+1][j+1], min(t[i+1][j], t[i][j+1]) );
      }
      res = max(res, t[i][j]);
    }
  }

  return res;
}

int main() {
  vector<vector<int>> mat = {
    {0, 0, 1, 1},
    {0, 1, 1, 0},
    {1, 1, 1, 0},
    {1, 0, 0, 1}
  };

  cout << maxSquare(mat);

  return 0;
}
