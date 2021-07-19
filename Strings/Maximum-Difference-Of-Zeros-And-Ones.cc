// https://practice.geeksforgeeks.org/problems/maximum-difference-of-zeros-and-ones-in-binary-string4111/1

#include <bits/stdc++.h>
using namespace std;

int maxSubstring(string S) {
  int res = INT_MIN;
  int n = S.length();
  vector<int> t(n);

  for (int i=0; i < n; i++) {
    int curr = S[i] == '1' ? -1 : 1;
    int m;
    if (i == 0) {
      t[i] = curr;
      m = curr;
    }
    else {
      t[i] = max(t[i-1] + curr, curr);
      m = t[i];
    }
    res = max(m, res);
  }
  return res;
}

int main() {
  string str = "11000010001";
  cout << maxSubstring(str);
  
  return 0;
}
