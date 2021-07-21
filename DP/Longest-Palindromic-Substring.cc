// https://leetcode.com/problems/longest-palindromic-substring/

#include <bits/stdc++.h>
using namespace std;

/**
 * if the indexes are same i.e gap = 0 then t[i][j] = true and startIndex can be any index.
 * if the indexes are one index apart then there are two conditions
   * if both chars are equal then palindrome exist at that index t[i][j] = true
   * else t[i][j] = false
   * 
 * else if the indexes are far apart then again we have 2 conditions
   * if the char at both indexes are same then we have to check whether the middle part is also a palindrome or not.
   * this can be found at t[i-1][j-1]
   * else t[i][j] = false;
 */
auto LPS(string str) {
  int N = str.length();
  vector<vector<bool>> t(N, vector<bool>(N));
  int ans = 0;
  int startIndex = 0;

  for (int gap=0; gap < N; gap++) {
    for (int i=0, j=gap; j < N; i++, j++) {
      if (gap == 0) {
        t[i][j] = true;
      }
      else if (gap == 1) {
        t[i][j] = str[i] == str[j] ? true : false;
      }
      else {
        if (str[i] == str[j] && t[i+1][j-1])
          t[i][j] = true;
        else
          t[i][j] = false;
      }
      if (t[i][j]) {
        ans = gap + 1;
        startIndex = i;
      }
    }
  }
  return str.substr(startIndex, ans);
}

int main() {
  string str = "aacabdkacaa";
  cout << LPS(str);

  return 0;
}
