/**
 * Here an item can be selected any number of times.
 * 0/1 Knapsack an item can be selected atmost once.
 * 
 * So, if we select the item we stay on that item i.e. i
 * and only if not selected we move to the next item.
 */

#include <bits/stdc++.h>
using namespace std;

int unBoundedKnapsack(int W, vector<int> wt, vector<int> val) {
  int n = wt.size();
  vector<vector<int>> t(n + 1, vector<int> (W + 1, -1));

  for (int i=0; i <= W; i++)
    t[0][i] = 0;
  
  for (int i=0; i <= n; i++)
    t[i][0] = 0;

  for (int i=1; i <= n; i++) {
    for (int j=1; j <= W; j++) {
      if (wt[i-1] > j)
        t[i][j] = t[i-1][j];
      else {
        t[i][j] = max(
          val[i-1] + t[i][j - wt[i-1]],
          t[i-1][j]
        );
      }
    }
  }
  
  return t[n][W];
}

int main() {
  vector<int> val = {10, 40, 50, 70};
  vector<int> wt = {1, 3, 4, 5};
  int k = 8;

  cout << unBoundedKnapsack(k, wt, val);
  
  return 0;
}
