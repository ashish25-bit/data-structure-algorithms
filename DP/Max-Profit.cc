// https://practice.geeksforgeeks.org/problems/maximum-profit4657/1#

#include <bits/stdc++.h>
using namespace std;

// time: O(n*n*k)
// int maxProfit(int k, int n, vector<int> arr) {
//   vector<vector<int>> t(k+1, vector<int>(n, 0));

//   for (int i=1; i <= k; i++) {
//     for (int j=1; j < n; j++) {
//       int currMax = t[i][j-1];

//       for (int m = 0; m < j; m++)
//         currMax = max(currMax, t[i-1][m] + arr[j] - arr[m]);

//       t[i][j] = currMax;
//     }
//   }

//   return t[k][n-1];
// }

// time: O(nk)
int maxProfit(int k, int n, vector<int> arr) {
  vector<vector<int>> t(k+1, vector<int>(n, 0));

  for (int i=1; i <= k; i++) {
    int currMax = INT_MIN;
    for (int j=1; j < n; j++) {
      currMax = max(currMax, t[i-1][j-1] - arr[j-1]);

      t[i][j] = max(currMax + arr[j], t[i][j-1]);
    }
  }

  return t[k][n-1];
}

int main() {
  vector<int> arr = {10, 22, 5, 75, 65, 80};
  int k = 2;

  cout << maxProfit(k, arr.size(), arr);

  return 0;
}
