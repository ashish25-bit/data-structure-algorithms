// https://practice.geeksforgeeks.org/problems/largest-subarray-of-0s-and-1s/1

#include <bits/stdc++.h>
using namespace std;

int maxLen(vector<int> arr, int N) {
  unordered_map<int, int> hashMap;

  int sum = 0;
  int res = 0;

  hashMap[0] = -1;

  for (int i = 0; i < N; i++) {
    sum = arr[i] == 0 ? sum - 1 : sum + 1;

    if (hashMap.find(sum) == hashMap.end())
      hashMap[sum] = i;
    else {
      int temp = i - hashMap[sum];
      res = max(res, temp);
    }
  }
  return res;
}

int main() {
  vector<int> arr = {0, 1, 0, 1};
  cout << maxLen(arr, arr.size());

  return 0;
}
