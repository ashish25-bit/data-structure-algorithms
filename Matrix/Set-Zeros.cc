#include <bits/stdc++.h>
using namespace std;

void change(int index, vector<vector<int>>& matrix, int len, string type) {
  if (type == "rows") {
    for (int i=0; i<len; i++)
      matrix[index][i] = 0;
  }

  if (type == "cols") {
    for (int i=0; i<len; i++)
      matrix[i][index] = 0;
  }
}

void setZeroes(vector<vector<int>>& matrix) {
  unordered_set<int> rows;
  unordered_set<int> cols;

  int r = matrix.size();
  int c = matrix[0].size();

  for (int i=0; i < r; i++) {
    for (int j=0; j < c; j++) {
      if (matrix[i][j] == 0) {
        rows.insert(i);
        break;
      }
    }
  }
  
  for (int i=0; i < c; i++) {
    for (int j=0; j < r; j++) {
      if (matrix[j][i] == 0) {
        cols.insert(i);
        break;
      }
    }
  }

  for (int row: rows) {
    change(row, matrix, c, "rows");
  }

  for (int col: cols) {
    change(col, matrix, r, "cols");
  }
}

int main() {
  vector<vector<int>> arr = {
    {0, 1, 2, 0},
    {3, 4, 5, 2},
    {1, 3, 1, 5}
  };

  // vector<vector<int>> arr = {
  //   {1, 2, 3},
  //   {4, 5, 6},
  //   {7, 8, 9},
  //   {10, 11, 12},
  // };

  setZeroes(arr);

  for (vector<int> row: arr) {
    for (int x: row) cout << x << " ";
    cout << endl;
  }
  
  return 0;
}
