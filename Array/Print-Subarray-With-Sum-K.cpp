#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> P;

vector<P> getAllSubarrays(vector<int> arr, int k) {
  unordered_map<int, vector<int>> hashMap;
  vector<P> res;
  int curr_sum = 0;

  for (int i=0; i<arr.size(); i++) {
    curr_sum = curr_sum + arr[i];

    if (curr_sum == k) {
      P p;
      p.first = 0;
      p.second = i;
      res.push_back(p);
    }

    if (hashMap.find(curr_sum - k) != hashMap.end()) {
      for (int x: hashMap[curr_sum - k]) {
        P p;
        p.first = x+1;
        p.second = i;
        res.push_back(p);
      }
    }
    
    hashMap[curr_sum].push_back(i);
  }

  return res;
}

int main() {
  vector<int> arr = {10, 2, -2, -20, 10};
  int k = -10;

  vector<P> res = getAllSubarrays(arr, k);

  for (P p: res) cout << p.first << "..." << p.second << endl;
  
  return 0;
}
