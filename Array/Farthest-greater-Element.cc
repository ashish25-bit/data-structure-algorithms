#include <bits/stdc++.h>
using namespace std;

int BS(vector<int> arr, int low, int high, int curr) {
  int ans = -1;
  while (low <= high) {
    int mid = low + (high - low) / 2;

    if (curr <= arr[mid]) {
      ans = mid;
      low = mid + 1;
    }
    else
      high = mid - 1;
  }

  return ans;
}

vector<int> farthestGreatest(vector<int> arr, int n) {
  vector<int> rightMax(n);
  vector<int> res;

  rightMax[n-1] = arr[n-1];

  for (int i=n-2; i >= 0; i--) {
    rightMax[i] = max(rightMax[i+1], arr[i]);
  }

  for (int i=0; i < n; i++) {
    int index = BS(rightMax, i+1, n-1, arr[i]);
    if (index != -1)
      res.push_back(arr[index]);
    else
      res.push_back(-1);
  }

  return res;
}

int main() {
  vector<int> arr = {34, 8, 10, 3, 2, 80, 30, 33, 1};

  arr = farthestGreatest(arr, arr.size());

  for (int x: arr) cout << x << " ";
  return 0;
}
