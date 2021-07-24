// https://practice.geeksforgeeks.org/problems/first-negative-integer-in-every-window-of-size-k3345/1

#include <bits/stdc++.h>
using namespace std;

vector<int>printFirstNegativeInteger(vector<int> A, int K) {
  vector<int> res;
  queue<int> q;

  int N = A.size();
  
  for (int i=0; i<K; i++)
    if (A[i] < 0) q.push(i);
  
  int p1 = 0;
  int p2 = K-1;
  
  while (p2 < N) {
    if (q.empty())
      res.push_back(0);
    else 
      res.push_back(A[q.front()]);
    
    p2++;
    if (p2 < N && A[p2] < 0)
        q.push(p2);
    if (A[p1] < 0)
        q.pop();
    p1++;
  }
  
  return res;
}

int main() {
  vector<int> arr = {12, -1, -7, 8, -15, 30, 16, 28};
  int k = 3;

  vector<int> res = printFirstNegativeInteger(arr, k);

  for (int x: res) cout << x << " ";
  
  return 0;
}
