// https://practice.geeksforgeeks.org/problems/pairs-with-specific-difference1533/1#

#include <bits/stdc++.h>
using namespace std;

int maxSumPairWithDifferenceLessThanK(vector<int> arr, int N, int K) {
  sort(arr.begin(), arr.end());
  int sum = 0;
  for (int i = N-1; i > 0; i--) {
    if (arr[i] - arr[i-1] < K) {
      sum = sum + arr[i] + arr[i-1];
      i--;
    }
  }
  return sum;
}

int main() {
  vector<int> arr = {3, 5, 10, 15, 17, 12, 9};
  int k = 4;
  cout << maxSumPairWithDifferenceLessThanK(arr, arr.size(), k);
  return 0;
}
