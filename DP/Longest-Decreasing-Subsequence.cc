#include <bits/stdc++.h>
using namespace std;

/**
 * same as LIS
 * but the array is traversed from right to left
 */

int LDS(vector<int> arr, int n) {
  int res = 1;
  vector<int> t(n);
  t[n-1] = 1;

  for (int i=n-2; i >=0; i--) {
    int m = 1;
    for (int j=i+1; j < n; j++) {
      if (arr[i] > arr[j])
        m = max(m, t[j]+1);
    }
    t[i] = m;
    res = max(m, res);
  }
  return res;
}

int main() {
  vector<int> arr = {10, 22, 9, 33, 21, 50, 41, 60, 80, 3};
  cout << LDS(arr, arr.size());
  return 0;
}
