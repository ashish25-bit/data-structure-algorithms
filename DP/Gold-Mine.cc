// https://practice.geeksforgeeks.org/problems/gold-mine-problem2608/1#

#include <bits/stdc++.h>
using namespace std;

int maxGold(int n, int m, vector<vector<int>> M) {
  int t[n][m];
  int res = INT_MIN;

  for (int col = m - 1; col >= 0; col--) {
    for (int row = 0; row < n; row++) {
      int curr = M[row][col];

      if (col == m - 1)
        t[row][col] = curr;
      else {
        int val = 0;

        if (row - 1 >= 0)
          val = max(val, t[row - 1][col + 1]);
        val = max(val, t[row][col + 1]);
        if (row + 1 < n)
          val = max(val, t[row + 1][col + 1]);

        t[row][col] = curr + val;
      }

      if (col == 0)
        res = max(res, t[row][col]);
    }
  }

  return res;
}

int main() {
  vector<vector<int>> arr = {
    {1, 3, 3},
    {2, 1, 4},
    {0, 6, 4}
  };

  cout << maxGold(arr.size(), arr[0].size(), arr);

  return 0;
}
