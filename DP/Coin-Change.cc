#include <bits/stdc++.h>
using namespace std;

string getKey(int n, int m) {
  return to_string(n) + "-" + to_string(m);
}

long long int count(vector<int> S, int m, int n, unordered_map<string, int> &hashMap) {
  // negative sum of coins
  if (n < 0) return 0;
  
  // if no sum needed then there is 1 subset present
  if (n == 0) return 1;
  
  // if we need sum but we have no coins
  if (m <= 0 && n > 0) return 0;
  
  string key = getKey(n, m);
  
  if (hashMap.find(key) != hashMap.end())
    return hashMap[key];
  
  // include and stay on m
  long long int include = count(S, m, n-S[m-1], hashMap);
  
  // do not include and move to next index (m-1)
  long long int _include = count(S, m-1, n, hashMap);
  
  hashMap[key] = include + _include;
  
  return include + _include;
}

long long int count(vector<int> S, int m, int n) {
  unordered_map<string, int> hashMap;
  return count(S, m, n, hashMap);
}

int main() {
  vector<int> arr = {2, 5, 3, 6};
  int n = 10;

  cout << count(arr, arr.size(), n);
  
  return 0;
}
