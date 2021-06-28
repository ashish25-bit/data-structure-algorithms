// TIME LIMIT EXCEEDED IN GFG
// https://practice.geeksforgeeks.org/problems/longest-increasing-subsequence-1587115620/1

// ACCEPTED IN LEETCODE
// https://leetcode.com/problems/longest-increasing-subsequence/

#include <bits/stdc++.h>
using namespace std;

int lengthOfLIS(int n, vector<int> arr) {
  vector<int> t(n);
  t[0] = 1;
  int res = 1;
  
  for (int i=1; i < n; i++) {
    int m = 1;

    for (int j=0; j < i; j++) {
      if (arr[i] > arr[j]) {
        m = max(m, t[j] + 1);
      }
    }

    t[i] = m;
    res = max(res, m);
  }
  return res;
}

int main() {
  vector<int> arr = {0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15};
  cout << lengthOfLIS(arr.size(),  arr);

  return 0;
}
