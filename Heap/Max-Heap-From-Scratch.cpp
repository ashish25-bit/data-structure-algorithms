#include <bits/stdc++.h>
using namespace std;

class max_heap {
  private:
  vector<int> arr;
  void heapify(int childIndex) {

    if (empty()) return;

    if (childIndex <= 0) return;

    int parent;
    if (childIndex % 2 == 0)
      parent = (childIndex / 2) - 1;
    else 
      parent = floor(childIndex / 2);

    if (arr[childIndex] > arr[parent]) {
      swap(arr[childIndex], arr[parent]);
      heapify(parent);
    }
  }

  void heapifyUtil(int parent) {
    if (empty()) return;

    int left = 2 * parent + 1;
    int right = 2 * parent + 2;

    if (left >= size() && right >= size()) return;

    if (right >= size()) {
      if (arr[left] > arr[parent]) {
        swap(arr[left], arr[parent]);
        heapifyUtil(left);
      }
      return;
    }

    int swapIndex = -1;

    if (arr[left] >= arr[right])
      swapIndex = left;
    else 
      swapIndex = right;

    if (arr[parent]  < arr[swapIndex]) {
      swap(arr[parent], arr[swapIndex]);
      heapifyUtil(swapIndex);
    }
  }

  public:
  max_heap() {
    arr = {};
  }

  max_heap(vector<int> array) {
    for (int x: array) push(x);
  }
  
  int size() {
    return arr.size();
  }

  bool empty() {
    return size() == 0;
  }

  void push(int x) {
    arr.push_back(x);
    if (size() == 1) {
      return;
    }

    heapify(size() - 1);
  }

  void pop() {
    if (empty()) return;
      
    arr[0] = arr[size() - 1];
    arr.pop_back();
    if (empty()) return;

    heapifyUtil(0);
  }

  int top() {
    if (empty()) return -1;

    return arr[0];
  }

  void print() {
    for (auto x: arr) cout << x << " ";
    cout << endl;
  }

};

int main() {
  vector<int> arr = {12, 20, 2, 13, 32, 50, 88, 21, 18, 91};
  
  max_heap *mh = new max_heap(arr);
  mh->print();
  
  while (!mh->empty()) {
    cout << mh->top() << endl;
    mh->pop();
  }

  return 0;
}
