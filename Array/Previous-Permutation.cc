#include <bits/stdc++.h>
using namespace std;

void reverse(vector<int> &arr, int start, int end) {
  while (start < end) {
    swap(arr[start], arr[end]);
    start++;
    end--;
  }
}

vector<int> prev(vector<int> arr) {
  int mark = -1;
  int n = arr.size();

  // find the largest index(mark) where arr[i-1] > arr[i]
  // or
  // find the largest index (mark) where the curr element is less than it's previous element
  for (int i = n-1; i > 0 ; i--) {
    if (arr[i-1] > arr[i]) {
      mark = i-1;
      break;
    }
  }

  if (mark == -1) {
    reverse(arr, 0, n-1);
    return arr;
  }

  // find the largest element(index) where arr[index] < arr[mark]
  // and index > mark
  int index = n-1;
  for (int i= n - 1; i > mark; i--) {
    if (arr[i] < arr[mark]) {
      index = i;
      break;
    }
  }

  swap(arr[mark], arr[index]);
  reverse(arr, mark+1, n-1);
  return arr;
}

int main() {
  vector<vector<int>> data = {
    {1, 2, 3, 4},
    {4, 3, 2, 1},
    {4, 3, 1, 2},
    {4, 2, 3, 1},
    {4, 2, 1, 3},
    {4, 1, 3, 2},
    {1, 2, 4 ,3}
  };

  for (auto arr: data) {
    for (int x: prev(arr)) {
      cout << x << ", ";
    }
    cout << endl;
  }

  return 0;
}
