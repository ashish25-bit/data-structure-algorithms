// https://practice.geeksforgeeks.org/problems/next-larger-element-1587115620/1#

#include <bits/stdc++.h>
using namespace std;

void printArray(vector<int> arr) {
  for (int x: arr) cout << x << " ";
  cout << endl;
}

// algo same approach different
vector<int> nextLargerElement(vector<int> arr, int n) {
  vector<int> res(n);
  stack<int> s;
  
  res[n-1] = -1;
  s.push(n-1);
  
  for (int i=n-2; i >= 0; i--) {
    if (s.empty()) {
      res[i] = -1;
      s.push(i);
      continue;
    }

    if (arr[s.top()] <= arr[i]) {
      while (!s.empty() && arr[s.top()] <= arr[i]) s.pop();

      res[i] = s.empty() ? -1 : s.top();
    }
    else
      res[i] = s.top();

    if (i > 0 && arr[i] >= arr[i-1]) s.push(i);
  }

  for (int i=0; i < n; i++) {
      if (res[i] == -1) continue;
      res[i] = arr[res[i]];
  }
  return res;
}

int main() {
  // vector<int> arr = {4, 25, 2, 25}; // 5 25 25 -1
  // vector<int> arr = {4, 35, 2, 25}; // 35 -1 25 -1
  // vector<int> arr = {6, 8, 0, 1, 3}; // 8 -1 1 3 -1
  vector<int> arr = {10, 3, 12, 4, 2, 9, 13, 0, 8, 11, 1, 7, 5, 6}; // 12 12 13 9 9 13 -1 8 11 -1 7 -1 6 -1

  int n = arr.size();
  vector<int> res(n);
  stack<int> s;

  int pos = n-2;
  res[n-1] = -1;

  while (pos >= 0) {

    // if the current number is less than the next number
    if (arr[pos] < arr[pos+1])
      s.push(arr[pos+1]);

    if (s.empty()) {
      res[pos] = -1;
    }
    else {
      if (s.top() <= arr[pos]) {
        while (!s.empty() && s.top() <= arr[pos]) s.pop();
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
