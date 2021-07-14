// https://practice.geeksforgeeks.org/problems/minimum-sum-partition3317/1

#include <bits/stdc++.h>
using namespace std;

void minDiff(vector<int> arr, int s1, int s2, int index, int &ans) {
  if (index < 0 || index >= arr.size()) return;

  ans = min(ans, abs(s1 - s2));

  // include arr[index]
  minDiff(arr, s1 - arr[index], s2 + arr[index], index + 1,ans);
  // don't include
  minDiff(arr, s1, s2, index + 1, ans);
}

int main() {
  vector<vector<int>> data = {
    {1, 5, 11, 5},
    {1, 6, 11, 5},
    {1, 2, 7},
  };

  for (vector<int> arr: data) {
    int sum = 0;
    int ans = INT_MAX;

    for (int x: arr) sum += x;

    minDiff(arr, sum, 0, 0, ans);
    cout << ans << endl;
  }


  return 0;
}
