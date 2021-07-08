// https://www.geeksforgeeks.org/minimum-removals-array-make-max-min-k/

#include <bits/stdc++.h>
using namespace std;

// recursive approach
// int minEliminationUtil(vector<int> arr, int start, int end, int k) {
//   if (start >= end) return 0;

//   if (arr[end] - arr[start] <= k) return 0;

//   return 1 + min(
//     minEliminationUtil(arr, start + 1, end, k),
//     minEliminationUtil(arr, start, end - 1, k)
//   );
// }

// int minElimination(vector<int> arr, int k) {
//   sort(arr.begin(), arr.end());

//   return minEliminationUtil(arr, 0, arr.size() - 1, k);
// }

int BS(vector<int> arr, int start, int end, int key) {
  int ans = INT_MAX;

  while (start <= end) {
    int mid = start + (end - start) / 2;
    if (arr[mid] <= key) {
      ans = mid;
      start = mid + 1;
    }
    else
      end = mid - 1;
  }

  return ans;
}

int minElimination(vector<int> arr, int k) {
  sort(arr.begin(), arr.end());

  int n = arr.size();
  int res = n - 1;

  for (int i=0; i < n; i++) {
    int element = arr[i] + k;
    int index = BS(arr, i, n-1, element);
    res = min(res, n - (index - i + 1));
  }

  return res;
}

int main() {
  vector<int> arr = {1, 3, 4, 9, 10, 11, 12, 17, 20};
  int k = 4;

  cout << minElimination(arr, k);
  
  return 0;
}
