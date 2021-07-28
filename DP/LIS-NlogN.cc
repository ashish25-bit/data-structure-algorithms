#include <bits/stdc++.h>
using namespace std;

int BS(vector<int> arr, int low, int high, int key) {
  int ans = 0;

  while (low <= high) {
    int mid = low + (high - low) / 2;

    if (arr[mid] >= key) {
      ans = mid;
      high = mid - 1;
    }
    else
      low = mid + 1;
  }

  return ans;
}

int longestSubsequence(int n, vector<int> a) {
  vector<int> sub;
  sub.push_back(a[0]);

  for (int i = 1; i < n; i++) {
    int size = sub.size() - 1;
    if (sub[0] > a[i])
      sub[0] = a[i];
    else if (sub[size] < a[i])
      sub.push_back(a[i]);
    else {
      int index = BS(sub, 0, size, a[i]);
      sub[index] = a[i];
    }
  }
  return sub.size();
}

int main() {
  vector<int> arr = {0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15};
  cout << longestSubsequence(arr.size(), arr);
  return 0;
}
