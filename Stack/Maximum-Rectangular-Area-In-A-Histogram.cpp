#include <bits/stdc++.h>
using namespace std;

void printArr(vector<int> arr) {
  for (int x: arr) cout << x << " ";
  cout << endl;
}

int getMaxArea(vector<int> arr) {
  int n = arr.size();

  vector<int> leftMin(n);
  vector<int> rightMin(n);

  stack<int> s;

  rightMin[n-1] = n;
  s.push(n-1);

  for (int i=n-2; i>=0; i--) {
    if (s.empty()) {
      rightMin[i] = n;
      s.push(i);
      continue;
    }
    
    int top = s.top();

    if (arr[top] >= arr[i]) {
      while (!s.empty() && arr[s.top()] >= arr[i])
        s.pop();
      
      if (s.empty())
        rightMin[i] = n;
      else 
        rightMin[i] = s.top();
    }
    else 
      rightMin[i] = top;

    if (i > 0 && arr[i-1] >= arr[i]) s.push(i);
  }

  while (!s.empty()) s.pop();

  leftMin[0] = -1;
  s.push(0);

  for (int i=1; i<n; i++) {
    if (s.empty()) {
      leftMin[i] = -1;
      s.push(i);
      continue;
    }

    int top = s.top();

    if (arr[top] >= arr[i]) {
      while (!s.empty() && arr[s.top()] >= arr[i]) 
        s.pop();
      
      if (s.empty()) leftMin[i] = -1;
      else leftMin[i] = s.top();
    }
    else leftMin[i] = top;

    if (i < n -1 && arr[i] <= arr[i + 1]) s.push(i);
  }

  int ans = INT_MIN;

  for (int i=0; i<n; i++) {
    int curr = arr[i] * (rightMin[i] - leftMin[i] - 1);
    ans = max(ans, curr);
  }

  // printArr(rightMin);
  // printArr(leftMin);
  return ans;
}

int main() {
  vector<vector<int>> data = {
    {6, 2, 5, 4, 5, 1, 6},
    {1, 2, 3, 4, 5},
    {7, 2, 8, 9, 1, 3, 6, 5},
    {5, 4, 3, 2, 1}
  };

  for (vector<int> arr: data) {
    cout << "For arr: ";
    printArr(arr);
    cout << getMaxArea(arr) << endl << endl;
  }
  
  return 0;
}
