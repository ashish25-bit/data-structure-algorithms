// https://practice.geeksforgeeks.org/problems/maximum-index-1587115620/1#

#include <bits/stdc++.h>
using namespace std;

int maxIndexDiff(vector<int> arr, int n) {
  vector<int> leftMin(n);
  vector<int> rightMax(n);

  leftMin[0] = arr[0];
  for (int i=1; i < n; i++)
    leftMin[i] = min(leftMin[i-1], arr[i]);

  rightMax[n-1] = arr[n-1];
  for (int i=n-2; i >= 0; i--)
    rightMax[i] = max(rightMax[i+1], arr[i]);

  int p1 = 0;
  int p2 = 0;
  int res = -1;

  while (p1 < n && p2 < n) {
    if (leftMin[p1] <= rightMax[p2]) {
      res = max(res, p2-p1);
      p2++;
    }
    else p1++;
  }

  return res;
}

int main() {
  vector<int> arr = {34, 8, 10, 3, 2, 80, 30, 33, 1};

  cout << maxIndexDiff(arr, arr.size());
  return 0;
}
