// https://leetcode.com/problems/maximal-rectangle/

#include <bits/stdc++.h>
using namespace std;

void printArray(vector<int> &arr) {
  for (auto &k: arr) {
    cout << k << " ";
  }
  cout << endl;
}

int getMaxArea(vector<int> arr) {
  int n = arr.size();

  vector<int> leftMin(n);
  vector<int> rightMin(n);

  stack<int> s;

  s.push(n-1);
  rightMin[n-1] = n;

  for (int i = n-2; i >= 0; i--) {
    if (s.empty()) {
      rightMin[i] = n;
      s.push(i);
      continue;
    }

    if (arr[i] <= arr[s.top()]) {
      while (!s.empty() && arr[i] <= arr[s.top()]) s.pop();

      rightMin[i] = s.empty() ? n : s.top();
    }
    else
      rightMin[i] = s.top();

    if (i > 0 && arr[i] <= arr[i-1])
      s.push(i);
  }

  while (!s.empty()) s.pop();

  leftMin[0] = -1;
  s.push(0);

  for (int i=1; i < n; i++) {
    if (s.empty()) {
      leftMin[i] = -1;
      s.push(i);
      continue;
    }

    if (arr[i] <= arr[s.top()]) {
      while (!s.empty() && arr[i] <= arr[s.top()]) s.pop();

      leftMin[i] = s.empty() ? -1 : s.top();
    }
    else
      leftMin[i] = s.top();

    if (i < n-1 && arr[i] <= arr[i+1])
      s.push(i);
  }

  int ans = INT_MIN;

  for (int i=0; i < n; i++) {
    int curr = arr[i] * (rightMin[i] - leftMin[i] - 1);
    ans = max(ans, curr);
  }

  return ans;
}

int maxRectangle(vector<vector<int>> M) {
  int cols = M[0].size();

  int res = INT_MIN;
  vector<int> arr(cols, 0);

  for (int i=0; i < M.size(); i++) {
    for (int j=0; j < cols; j++) {
      if (M[i][j] == 0)
        arr[j] = 0;
      else
        arr[j] = arr[j] + 1;
    }
    int maxArea = getMaxArea(arr);
    res = max(res, maxArea);
  }

  return res;
}

int main() {
  // vector<vector<int>> mat = {
  //   {0, 1, 1, 0},
  //   {1, 1, 1, 1},
  //   {1, 1, 1, 1},
  //   {1, 1, 0, 0}
  // };
  
  // vector<vector<int>> mat = {
  //   {1, 0, 1, 0, 0},
  //   {1, 0, 1, 1, 1},
  //   {1, 1, 1, 1, 1},
  //   {1, 0, 0, 1, 0}
  // };

  vector<vector<int>> mat = {{1, 0}};

  cout << maxRectangle(mat);
  
  return 0;
}
