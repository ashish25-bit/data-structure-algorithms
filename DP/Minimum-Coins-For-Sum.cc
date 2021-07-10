// https://practice.geeksforgeeks.org/problems/number-of-coins1824/1

#include <bits/stdc++.h>
using namespace std;

/*
  Recursive solution
  Time limit exceeded in GFG
*/

// class Solution{
//   private:
//   string getKey(int n, int m) {
//     return to_string(n) + "-" + to_string(m);
//   }
//   int minCoins(int coins[], int m, int n, unordered_map<string, int> &hashMap) {
//     if (n < 0) return INT_MAX - 1; if (n == 0) return 0; if (m <= 0 && n > 0) return INT_MAX - 1;
//     string key = getKey(n, m);
//     if (hashMap.find(key) != hashMap.end()) return hashMap[key];
//     int include = 1 + minCoins(coins, m, n-coins[m-1], hashMap);
//     int _include = minCoins(coins, m-1, n, hashMap);
//     return min(include, _include);
//   }
// 	public:
// 	int minCoins(int coins[], int m, int n) {
//     unordered_map<string, int> hashMap;
//     int ans = minCoins(coins, m, n, hashMap);
//     if (ans == INT_MAX || ans == INT_MAX - 1) return -1;
//       return ans;
// 	} 
// };

int minCoins(vector<int> coins, int n, int amount) {
  int t[n+1][amount+1];
  
  for (int i=0; i <= n; i++) {
    for (int j=0; j <= amount; j++) {
      if (j == 0)
          t[i][j] = 0;
      else if (i == 0)
          t[i][j] = 1e5;
          
      else if (coins[i-1] > j)
          t[i][j] = t[i-1][j];
      else {
                  // min(1 + include, exclude)
          t[i][j] = min(1 + t[i][j-coins[i-1]], t[i-1][j]);
      }
    }
  }
  
  return t[n][amount] > 1e4 - 1 ? -1 : t[n][amount];
}

int main() {
  vector<int> arr = {9, 6, 5, 1};
  int n = 11;

  cout << minCoins(arr, arr.size(), n);
  
  return 0;
}
