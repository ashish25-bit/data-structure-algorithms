// TIme limit in gfg exceeded

#include <bits/stdc++.h>
using namespace std;

string getKey(int a, int b) {
  string str = to_string(a) + "-" + to_string(b);
  return str;
}

// int knapsack(vector<int> wt, vector<int> val, int k, int n, vector<vector<int>> &t) {
//   // Base Case
//   if (n == 0 || k == 0)
//     return 0;

//   if (t[n][k] != -1)
//     return t[n][k];

//   if (wt[n - 1] > k) {
//     int ans = knapsack(wt, val, k, n - 1, t);
//     t[n][k] = ans;
//     return ans;
//   }

//   int include = val[n - 1] + knapsack(wt, val, k - wt[n - 1], n - 1, t);
//   int notInclude = knapsack(wt, val, k, n - 1, t);

//   int ans = max(include, notInclude);
//   t[n][k] = ans;
//   return ans;
// }

int knapsack(vector<int> wt, vector<int> val, int k, int n, unordered_map<string, int> &hashMap) {
  // Base Case
  if (n == 0 || k == 0)
    return 0;

  string key = getKey(n, k);
  if (hashMap.find(key) != hashMap.end())
    return hashMap[key];

  if (wt[n - 1] > k) {
    int ans = knapsack(wt, val, k, n - 1, hashMap);
    hashMap[key] = ans;
    return ans;
  }

  int include = val[n - 1] + knapsack(wt, val, k - wt[n - 1], n - 1, hashMap);
  int notInclude = knapsack(wt, val, k, n - 1, hashMap);

  int ans = max(include, notInclude);
  hashMap[key] = ans;
  return ans;
}
 
// Driver code
int main() {
  vector<int> val = { 60, 100, 120 };
  vector<int> wt = { 10, 20, 30 };
  int k = 50;
  int n = wt.size();

  // use double pointer when the array size is defined at runtime (int **t)
  // int** t = new int*[n+1];
  // for (int i=0; i <=n; i++) {
  //   t[i] = new int[k+1];
  // }
  // for (int i=0; i <=n; i++) {
  //   for (int j=0; j <= k; j++)
  //     t[i][j] = -1;
  // }

  // vector< vector<int>> t(n + 1, vector<int> (k+1, -1));
  // cout << knapsack(wt, val, k, n, t) << endl;
  
  unordered_map<string, int> hashMap;
  cout << knapsack(wt, val, k, n, hashMap) << endl;

  return 0;
}
 