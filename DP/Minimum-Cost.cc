// https://practice.geeksforgeeks.org/problems/minimum-cost-to-fill-given-weight-in-a-bag1956/1

#include <bits/stdc++.h>
using namespace std;

// int minimumCostUtil(vector<int> cost, int n, int w) {
//   if (w == 0 || n == 0 && w == 0) return 0;
//   if (n == 0) return 1e5;

//   if (n > w || cost[n-1] == -1)
//     return minimumCostUtil(cost, n - 1, w);

//   int include  = cost[n-1] + minimumCostUtil(cost, n, w - n);
//   int _include = minimumCostUtil(cost, n-1, w);

//   return min(_include, include);
// }

// int minimumCost(vector<int> cost, int n, int w) {
//   int ans = minimumCostUtil(cost, n, w);
//   return ans >= 1e5 ? -1 : ans;
// }

int minimumCost(vector<int> cost, int n, int w) {
  vector<vector<int>> t(n+1, vector<int>(w+1, 0));

  for (int i=0; i <= w; i++) {
    t[0][i] = 1e7;
  }

  for (int i=1; i <= n; i++) {
    for (int j=1; j <= w; j++) {
      if (i > j || cost[i-1] == -1)
        t[i][j] = t[i-1][j];
      else
        t[i][j] = min(t[i-1][j], t[i][j - i] + cost[i-1]);
    }
  }

  return t[n][w] >= 1e7 ? -1 : t[n][w];
}

int main() {
  // vector<int> arr = {20, 10, 4, 50, 100};
  // int w = 5;

  vector<int> arr = {16, 19, 6, 3, 12, 10};
  int w = 15;

  cout << minimumCost(arr, arr.size(), w);

  return 0;
}
