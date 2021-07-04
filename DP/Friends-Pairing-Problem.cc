// https://practice.geeksforgeeks.org/problems/friends-pairing-problem5425/1#

#include <bits/stdc++.h>
using namespace std;

const unsigned long long mod = 1000000007;

// // time: 0.60s in GFG
// unordered_map<int , long long> hashMap;
// unsigned long long countRecursive(int n) {
//   if (n == 1 || n == 2) return n;
  
//   if (hashMap.find(n) != hashMap.end())
//     return hashMap[n];
  
//   unsigned long long _pair = countRecursive(n-1) % mod;
//   unsigned long long pair  = ((n-1) % mod) * (countRecursive(n-2) % mod);
  
//   hashMap[n] = (_pair + pair) % mod;
//   return hashMap[n];
// }

// time: 0.03s in GFG
int countFriendsPairings(int n) {
  if (n == 1 || n == 2) return n;

  unsigned long long t[n + 1];
  t[0] = 0; t[1] = 1; t[2] = 2;

  for (int i = 3; i <= n; i++) {
    t[i] = (
      (t[i - 1] % mod) +
      ((i - 1) * t[i - 2] % mod)
    ) % mod;
  }

  return t[n];
}

int main() {
  vector<int> arr = {3, 4, 10};

  for (auto k : arr) {
    cout << countFriendsPairings(k) << endl;
  }

  return 0;
}
