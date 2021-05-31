#include <bits/stdc++.h>
using namespace std;

int knapsack(vector<int> wt, vector<int> val, int w, int n) {
  vector<vector<int>> t(n + 1, vector<int> (w + 1, -1));

  for (int i=0; i <= w; i++)
    t[0][i] = 0;
  
  for (int i=0; i <= n; i++)
    t[i][0] = 0;

  for (int i=1; i < n+1; i++) {
    for (int j=1; j < w+1; j++) {
      if (wt[i-1] <= j)
        t[i][j] = max(
          val[i-1] + t[i-1][j-wt[i-1]],
          t[i-1][j]
        );
      else 
        t[i][j] = t[i-1][j];
    }

  }

  for (vector<int> a: t) {
    for (int x: a) cout << x << "\t";
    cout << endl;
  }

  return t[n][w];
}

int main() {
  vector<int> wt = { 10, 20, 30 };
  vector<int> val = { 60, 100, 120 };
  int k = 50;
  int n = wt.size();

  cout << knapsack(wt, val, k, n);
  
  return 0;
}
