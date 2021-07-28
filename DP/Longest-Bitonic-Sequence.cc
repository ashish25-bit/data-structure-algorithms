// https://practice.geeksforgeeks.org/problems/longest-bitonic-subsequence0824/1

#include <bits/stdc++.h>
using namespace std;

int LIS(vector<int> arr, int n) {
  vector<int> inc(n);
  inc[0] = 1;
  for (int i=1; i < n; i++) {
    int m = 1;
    for (int j=0;  j < i; j++) {
      if (arr[i] > arr[j])
        m = max(m, 1 + inc[j]);
    }
    inc[i] = m;
  }

  vector<int> dec(n);
  dec[n-1] = 1;
  for (int i=n-2; i >= 0; i--) {
    int m = 1;
    for (int j=n-1;  j > i; j--) {
      if (arr[i] > arr[j])
        m = max(m, 1 + dec[j]);
    }
    dec[i] = m;
  }

  int res = 1;
  for (int i=0; i < n; i++)
    res = max(res, inc[i] + dec[i] - 1);

  return res;
}

int main() {
  vector<int> arr = {1, 2, 5, 3, 2};
  cout << LIS(arr, arr.size());
  return 0;
}
