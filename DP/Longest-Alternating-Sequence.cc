// https://practice.geeksforgeeks.org/problems/longest-alternating-subsequence5951/1#

#include <bits/stdc++.h>
using namespace std;

int count(vector<int> arr, int n) {
  int inc = 1;
  int dec = 1;

  for (int i=1; i < n; i++) {
    if (arr[i-1] < arr[i])
      inc = dec + 1;
    else if (arr[i-1] > arr[i])
      dec = inc + 1;
  }

  return max(inc, dec);
}

int main() {
  vector<int> arr = {1, 17, 5, 10, 13, 15, 10, 5, 16, 8};
  cout << count(arr, arr.size());
  return 0;
}
