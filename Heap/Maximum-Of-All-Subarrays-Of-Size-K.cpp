#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> P;

struct comparator {
  bool operator() (P p1, P p2) {
    return p1.first < p2.first;
  }
};

void printArr(vector<int> arr, bool nextLine = true) {
  for (int x: arr) cout << x << " ";
  if (nextLine)
    cout << endl;
}

bool inRange(int p, int p1, int p2) {
  return p >= p1 && p <= p2;
}

vector<int> maxInKSubarray(vector<int> arr, int k) {
  int p1 = 0;
  int p2 = k-1;
  priority_queue<P, vector<P>, comparator> maxHeap;
  vector<int> res;
  int n = arr.size();

  for (int i=p1; i <= p2; i++)
    maxHeap.push(make_pair(arr[i], i));

  while (p2 < n) {
    P top = maxHeap.top();

    if (inRange(top.second, p1, p2))
      res.push_back(top.first);
    else {
      while (!inRange(maxHeap.top().second, p1, p2))
        maxHeap.pop();
      res.push_back(maxHeap.top().first);
    }

    p1++;
    p2++;

    if (p2 < n) maxHeap.push(make_pair(arr[p2], p2));
  }
  return res;
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

    vector<int> res = maxInKSubarray(arr, k);
    printArr(res);
    cout << endl;
  }

  return 0;
}
