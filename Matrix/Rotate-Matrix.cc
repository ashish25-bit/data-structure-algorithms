#include <bits/stdc++.h>
using namespace std;

void rotateMatrix(vector<vector<int>> &matrix) {
  int n = matrix.size();

  for (int i=0; i < n; i++) {
    for (int j=i; j < n; j++)
      swap(matrix[i][j], matrix[j][i]);
  }

  for (int i=0; i < n; i++) {
    reverse(matrix[i].begin(), matrix[i].end());
  }
}

int main() {
  vector<vector<int>> arr = {
    {5, 1, 9, 11},
    {2, 4, 8, 10},
    {13, 3, 6, 7},
    {15, 14, 12, 16}
  };

  rotateMatrix(arr);

  for (vector<int> row: arr) {
    for (int x: row) cout << x << " ";
    cout << endl;
  }
  
  return 0;
}
