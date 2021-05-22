#include <bits/stdc++.h>
using namespace std;

void printArray(vector<int> arr, int n) {
  for (int i=0; i < n; i++) {
    cout << arr[i] << " ";
  }
  cout << " (" << n << ")" << endl;
}

void streamMedian(vector<int> arr) {
  int N = arr.size();

  priority_queue<int> maxHeap;
  priority_queue<int, vector<int>, greater<int>> minHeap;

  for (int i=1; i <= N; i++) {
    int size = floor(i / 2) + 1;

    if (minHeap.empty()) {
      maxHeap.push(arr[i-1]);
    }
    else {
      if (minHeap.top() < arr[i-1]) {
        int top = minHeap.top();
        minHeap.pop();

        minHeap.push(arr[i-1]);
        maxHeap.push(top);
      }
      else 
        maxHeap.push(arr[i-1]);
    }

    if (maxHeap.size() > size) {
      int top = maxHeap.top();
      maxHeap.pop();
      minHeap.push(top);
    }

    printArray(arr, i);
    if (i % 2) cout << maxHeap.top();
    else {
      int n1 = maxHeap.top();
      maxHeap.pop();
      int n2 = maxHeap.top();
      maxHeap.push(n1);

      int med = floor((n1 + n2) / 2);
      cout << med;
    }
    
    cout << "\n\n";
  }
}

int main() {
  vector<int> arr = {5, 15, 1, 3, 2, 8, 7, 9, 10, 6, 11, 4};

  streamMedian(arr);

  return 0;
}
