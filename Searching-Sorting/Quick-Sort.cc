#include <bits/stdc++.h>
using namespace std;

int partitionEnd(vector<int> &arr, int low, int high) {
  int pivot = arr[high];
  int index = low;

  for (int j = low; j < high; j++) {
    if (arr[j] < pivot) {
      swap(arr[index], arr[j]);
      index++;
    }
  }

  swap(arr[index], arr[high]);
  return index;
}

int partitionStart(vector<int> &arr, int low, int high) {
  int pivot = arr[low];
  int index = low + 1;

  for (int j = low + 1; j <= high; j++) {
    if (arr[j] < pivot) {
      swap(arr[index], arr[j]);
      index++;
    }
  }

  arr[low] = arr[index-1];
  arr[index-1] = pivot;
  return index - 1;
}

void quickSort(vector<int> &arr, int low, int high) {
  if (low >= high) return;

  int pi = partitionEnd(arr, low, high);
  quickSort(arr, low, pi-1);
  quickSort(arr, pi+1, high);
}

int main() {
  vector<int> arr = {4, 3, 2, 1};
  quickSort(arr, 0, arr.size() - 1);

  for (auto k: arr) {
    cout << k << " ";
  }
  
  return 0;
}
