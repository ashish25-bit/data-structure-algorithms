// https://practice.geeksforgeeks.org/problems/coin-change2448/1#

#include <bits/stdc++.h>
using namespace std;

// bottom up approach
// string getKey(int n, int m) {
//   return to_string(n) + "-" + to_string(m);
// }

// int count(vector<int> S, int m, int n, unordered_map<string, int> &hashMap) {
//   // negative sum of coins
//   if (n < 0) return 0;
  
//   // if no sum needed then there is 1 subset present
//   if (n == 0) return 1;
  
//   // if we need sum but we have no coins
//   if (m <= 0 && n > 0) return 0;
  
//   string key = getKey(n, m);
  
//   if (hashMap.find(key) != hashMap.end())
//     return hashMap[key];
  
//   // include and stay on m
//   int include = count(S, m, n-S[m-1], hashMap);
  
//   // do not include and move to next index (m-1)
//   int _include = count(S, m-1, n, hashMap);
  
//   hashMap[key] = include + _include;
  
//   return include + _include;
// }

// int count(vector<int> S, int m, int n) {
//   unordered_map<string, int> hashMap;
//   return count(S, m, n, hashMap);
// }

// top down approach
// int count(vector<int> arr, int m, int n) {
//   vector<vector<int>> t(m+1, vector<int>(n+1, 0));

//   for (int i=0; i <= m; i++) {
//     t[i][0] = 1;
//   }

//   for (int i=1; i<=m; i++) {
//     for (int j=1; j <=n; j++) {
//       if (arr[i-1] > j) {
//         t[i][j] = t[i-1][j];
//       }
//       else {
//         t[i][j] = t[i-1][j] +  t[i][j-arr[i-1]];
//       }
//     }
//   }

//   return t[m][n];
// }

// more space optimized
// time: O(mn)
// space: O(n)
int count(vector<int> arr, int m, int n) {
  vector<int> t(n+1, 0);
  t[0] = 1;

  for(int i=0; i<m; i++) {
    for(int j = arr[i]; j<=n; j++)
      t[j] = t[j] + t[j-arr[i]];
  }

  return t[n];
}

int main() {
  vector<int> arr = {2, 5, 3, 6};
  int n = 10;

  cout << count(arr, arr.size(), n);
  
  return 0;
}
