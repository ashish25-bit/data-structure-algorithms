// https://practice.geeksforgeeks.org/problems/maximum-of-all-subarrays-of-size-k3101/1#

#include <bits/stdc++.h>
using namespace std;

vector <int> max_of_subarrays(vector<int> arr, int n, int k) {
  deque<int> q(k);
  vector<int> res;

  for (int i=0; i < k; i++) {
    while (!q.empty() && arr[i] >= arr[q.back()])
      q.pop_back();
    q.push_back(i);
  }

  for (int i=k; i < n; i++) {
    res.push_back(arr[q.front()]);

    while (!q.empty() && q.front() <= i - k)
      q.pop_front();
    while (!q.empty() && arr[i] >= arr[q.back()])
      q.pop_back();

    q.push_back(i);
  }
  res.push_back(arr[q.front()]);

  return res;
}

int main() {
  vector<int> arr = {1, 2, 3, 1, 4, 5, 2, 3, 6};
  int k = 3;

  vector<int> res = max_of_subarrays(arr, arr.size(), k);

  for (int x: res) cout << x << " ";
  return 0;
}
