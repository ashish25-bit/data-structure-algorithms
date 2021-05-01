#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> maximumSize(vector<int> arr, int target) {
  unordered_map<int, vector<int>> hashMap;
  int curr_sum = 0;
  vector<vector<int>> res;

  for (int i=0; i < arr.size(); i++) {
    curr_sum += arr[i];

    if (curr_sum == target)
      res.push_back({ 0, i });

    if (hashMap.find(curr_sum - target) != hashMap.end()) {
      for (int index: hashMap[curr_sum - target])
        res.push_back({ index + 1, i });
    }

    hashMap[curr_sum].push_back(i);
  }

  return res;
} 

int main() {
  // vector<int> arr = {6, 3, -1, -3, 4, -2, 2, 4, 6, -12, -7};
  // int target = 0;

  // vector<int> arr = {15, 2, 4, 8, 9, 5, 10, 23};
  // int target = 23;

  // vector<int> arr = {10, 2, -2, -20, 10};
  // int target = -10;

  vector<int> arr = {10, 2, -2, -20, 10};
  int target = 20;

  vector<vector<int>> ans = maximumSize(arr, target);

  if (ans.size())
    for (vector<int> x: ans) cout << x[0] << " " << x[1] << endl;

  else cout << "No Subarray";

  return 0;
}
