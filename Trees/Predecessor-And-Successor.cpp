#include <bits/stdc++.h>
using namespace std;

void predAndSucc(vector<int> arr, int key) {
  int n = arr.size();
  int start = 0;
  int end = n - 1;

  int pred = -1;
  int succ = -1;

  while (start <= end) {
    int mid = start + (end - start) / 2;

    int left = mid - 1;
    int right = mid + 1;

    if (arr[mid] == key) {
      if (left >= 0 && right < n) {
        pred = arr[left];
        succ = arr[right];
      }

      else if (left >= 0)
        pred = arr[left];

      else if (right < n)
        succ = arr[right];

      break;
    }

    // check left
    if (left >= 0) {
      if (arr[mid] > key && arr[left] < key) {
        pred = arr[left];
        succ = arr[mid];
        break;
      }
    }

    else {
      if (arr[mid] > key) {
        succ = arr[mid];
        break;
      }
    }

    // check right
    if (right < n) {
      if (arr[mid] < key && arr[right] > key) {
        pred = arr[mid];
        succ = arr[right];
        break;
      }
    }

    else {
      if (arr[mid] < key) {
        pred = arr[mid];
        break;
      }
    }

    if (arr[mid] > key) end = mid - 1;

    else if (arr[mid] < key) start = mid + 1;
  }

  cout << pred << " " << succ;

}

int main() {
  vector<vector<int>> data = {
    {12, 34, 45, 78, 97,  34},
    {18, 20, 40, 50, 60, 65,  17},
    {18, 20, 40, 50, 60, 65,  63},
    {18, 20, 40, 50, 60, 65,  20},
  };

  for (vector<int> arr: data) {
    int key = arr[arr.size() - 1];
    arr.pop_back();
    predAndSucc(arr, key);
    cout << endl;
  }
  
  return 0;
}
