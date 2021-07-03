// https://practice.geeksforgeeks.org/problems/smallest-number-on-left3403/1#

#include <bits/stdc++.h>
using namespace std;

void printArray(vector<int> arr) {
  for (int x: arr) cout << x << " ";
  cout << endl;
}

// algo same approch different
vector<int> leftSmaller(int n, vector<int> arr) {
  vector<int> res(n);
  stack<int> s;
  
  res[0] = -1;
  s.push(0);
  
  for (int i=1; i < n; i++) {
    if (s.empty()) {
      res[i] = -1;
      s.push(i);
      continue;
    }

    if (arr[s.top()] >= arr[i]) {
      while (!s.empty() && arr[s.top()] >= arr[i]) s.pop();
      
      res[i] = s.empty() ? -1 : s.top();
    }
    else
      res[i] = s.top();
      
    if (i < n-1 && arr[i] <= arr[i+1]) s.push(i);
  }
  
  for (int i=0; i < n; i++) {
      if (res[i] == -1) continue;
      res[i] = arr[res[i]];
  }
  return res;
}

int main() {
  // vector<int> arr = {4, 8, 5, 2, 25}; // 2 5 2 -1 -1
  // vector<int> arr = {6, 8, 0, 1, 3}; // 0 0 -1 -1 -1 
  vector<int> arr = {10, 3, 12, 4, 2, 9, 13, 0, 8, 11, 1, 7, 5, 6}; // 3 2 4 2 0 0 0 -1 1 1 -1 5 -1 -1 

  int n = arr.size();
  vector<int> res(n);
  stack<int> s;

  int pos = n-2;
  res[n-1] = -1;

  while (pos >= 0) {

    // if the current number is greater than the next number
    if (arr[pos] > arr[pos+1])
      s.push(arr[pos + 1]);

    if (s.empty()) {
      res[pos] = -1;
    }
    else {
      if (s.top() >= arr[pos]) {
        while (!s.empty() && s.top() >= arr[pos]) s.pop();
        if (s.empty()) res[pos] = -1;
        else res[pos] = s.top();
      }
      else 
        res[pos] = s.top();
    }

    pos--;
  }

  printArray(arr);
  printArray(res);

  return 0;
}
