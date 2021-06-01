#include <bits/stdc++.h>
using namespace std;

/**
 * Recursive Solution in workspace ./Backtracking/Minimum-Subset-Diff
 */

int subsetSum(vector<int> arr, int n) {
  int sum = 0;
  for (int x: arr) sum += x;

  vector<vector<bool>> t(n+1, vector<bool> (sum + 1, false));

  for (int i = 0; i <= n; i++)
    t[i][0] = true;

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= sum; j++) {
      if (j < arr[i - 1])
        t[i][j] = t[i - 1][j];
      else
        t[i][j] = t[i - 1][j] || t[i - 1][j - arr[i - 1]];
    }
  }

  vector<bool> temp = t[n];
  int res = INT_MAX;
  for (int i=0; i <= (sum / 2); i++) {
    if (temp[i])
      res = min(res, sum - 2 * i);
  }

  return res;
}

int main() {

  vector<vector<int>> data = {
    {1, 6, 11, 5},
    {1, 5, 11, 5},
    {1, 2, 7}
  };

  for (vector<int> arr: data) {
    int n = arr.size();
    cout << subsetSum(arr, n) << endl;
  }

  return 0;
}
