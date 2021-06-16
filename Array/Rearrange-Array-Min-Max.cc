#include <bits/stdc++.h>
using namespace std;

vector<int> minMaxRearrange(vector<int> arr, int n) {
  int i = 1;
  int j = n-1;

  queue<long long> q;

  while (i < j) {
    q.push(arr[i]);
    
    if (i % 2 == 1) {
        arr[i] = arr[j];    
    }
    else {
        arr[i] = q.front();
        q.pop();
        j--;
    }
    i++;
  }

  j = n-1;

  while (!q.empty()) {
    arr[j] = q.front();
    j--;
    q.pop();
  }
  return arr;
}

vector<int> maxMinRearrange(vector<int> arr, int n) {
  int i = 0;
  int j = n-1;

  deque<long long> q;

  while (i <= j) {
    q.push_back(arr[i]);
    
    if (i % 2 == 0) {
        arr[i] = arr[j];
        j--;
    }
    else {
        arr[i] = q.front();
        q.pop_front();
    }
    i++;
  }


  if (n - i < q.size()) {
    while (q.size() != n - i) q.pop_back();
  }

  while (!q.empty()) {
    if (i % 2 == 0) {
        arr[i] = q.back();
        q.pop_back();
    }
    else {
        arr[i] = q.front();
        q.pop_front();
    }
    i++;
  }
  return arr;
}

void printArray(vector<int> arr) {
  for (int x: arr) cout << x << " ";
  cout << endl;
}

int main() {
  vector<int> arr = {1, 2, 3, 4, 5, 6, 7};
  int n = arr.size();

  vector<int> min_max = minMaxRearrange(arr, n);
  vector<int> max_min = maxMinRearrange(arr, n);

  cout << "Max Min: ";
  printArray(max_min);
  cout << "Min Max: ";
  printArray(min_max);
}
