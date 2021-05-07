#include <bits/stdc++.h>
using namespace std;

void printArr(vector<int> arr, bool nextLine = true) {
  for (int x: arr) cout << x << " ";
  if (nextLine)
    cout << endl;
}

bool inRange(int p, int p1, int p2) {
  return p >= p1 && p <= p2;
}

void minMaxInKSubarray(vector<int> arr, int k) {
  deque<int> maxQ;
  deque<int> minQ;

  vector<int> maxRes;
  vector<int> minRes;

  int p1 = 0;
  int p2 = k-1;
  int n = arr.size();

  for (int i=0; i<=p2; i++) {
    // max
    if (maxQ.empty()) maxQ.push_back(i);

    else {
      if (arr[maxQ.back()] < arr[i]) {
        while (!maxQ.empty() && arr[maxQ.back()] < arr[i]) maxQ.pop_back();
        maxQ.push_back(i);
      }
      else maxQ.push_back(i);
    }

    // min
    if (minQ.empty()) minQ.push_back(i);

    else {
      if (arr[minQ.back()] > arr[i]) {
        while (!minQ.empty() && arr[minQ.back()] > arr[i]) minQ.pop_back();
        minQ.push_back(i);
      }
      else minQ.push_back(i);
    }
  }

  while (p2 < n) {
    maxRes.push_back(arr[maxQ.front()]);
    minRes.push_back(arr[minQ.front()]);

    p1++;
    p2++;

    if (p2 < n) {
      // max
      if (!inRange(maxQ.front(), p1, p2)) {
        while (!maxQ.empty() && !inRange(maxQ.front(), p1, p2)) maxQ.pop_front();
      }

      if (maxQ.empty()) maxQ.push_back(p2);
      else {
        if (arr[maxQ.back()] < arr[p2]) {
          while (!maxQ.empty() && arr[maxQ.back()] < arr[p2]) maxQ.pop_back();
          maxQ.push_back(p2);
        }
        else maxQ.push_back(p2);
      }
      
      // min
      if (!inRange(minQ.front(), p1, p2)) {
        while (!minQ.empty() && !inRange(minQ.front(), p1, p2)) minQ.pop_front();
      }

      if (minQ.empty()) minQ.push_back(p2);

      else {
        if (arr[minQ.back()] > arr[p2]) {
          while (!minQ.empty() && arr[minQ.back()] > arr[p2]) minQ.pop_back();
          minQ.push_back(p2);
        }
        else minQ.push_back(p2);
      }
    }
  }

  printArr(maxRes);
  printArr(minRes);
}

int main() {
  // the last value in the array is the value of k
  vector<vector<int>> data = {
    {2, 7, -1, 5, -3, -1, -2,   4},
    {1, 2, 3, 1, 4, 5, 2, 3, 6,   3 },
    {12, 1, 78, 90, 57, 89, 56,   3}
  };

  for (vector<int> arr: data) {
    int k = arr[arr.size() - 1];
    arr.pop_back();
    cout << "For arr: ";
    printArr(arr, false);
    cout << " and k = " << k << endl;

    minMaxInKSubarray(arr, k);
    cout << endl;
  }
  
  return 0;
}
