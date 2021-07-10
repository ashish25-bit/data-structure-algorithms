// https://practice.geeksforgeeks.org/problems/longest-palindromic-subsequence-1612327878/1#

#include <bits/stdc++.h>
using namespace std;

// Method 1
// find all possible subsequence and amongst them find the string which is the longest palindrome
// 2.50s in GFG
bool isPalindrome(string str) {
  int start = 0;
  int end = str.length() - 1;

  while (start < end) {
    if (str[start] != str[end])
      return false;
    start++;
    end--;
  }

  return true;
}

pair<int, string> LPS1(string str, int n, string res) {
  if (n == 0) {
    if (isPalindrome(res))
      return make_pair(res.length(), res);
    return make_pair(0, "");
  }

  pair<int, string> include  = LPS1(str, n-1, str[n-1] + res);
  pair<int, string> _include = LPS1(str, n-1, res);

  // return max(include, _include);
  if (include.first >= _include.first)
    return include;
  return _include;
}

// method 2
/**
 * start and end index
 * if start == end then palindrome length is 1
 * if str[start] == str[end] LPS(str, start+1, end-1) + 2
 */
// 2.20s in GFG
int LPS2(string str, int start, int end) {
  if (start == end) return 1;

  if (str[start] == str[end] && start + 1 == end)
    return 2;

  if (str[start] == str[end])
    return LPS2(str, start + 1, end - 1) + 2;

  int include1 = LPS2(str, start, end - 1);
  int include2 = LPS2(str, start + 1, end);

  return max(include1, include2);
}

// method 3
// optimized solution
int LPS(string str) {
  int n = str.length();
  vector<vector<int>> t(n, vector<int>(n, 0));

  for (int gap = 0; gap < n; gap++) {
    for (int i=0, j = gap; j < n; i++, j++) {
      if (gap == 0) {
        t[i][j] = 1;
      }
      else if (gap == 1) {
        t[i][j] = str[i] == str[j] ? 2 : 1;
      }
      else {
        if (str[i] == str[j])
          t[i][j] = 2 + t[i+1][j-1];
        else
          t[i][j] = max(t[i+1][j], t[i][j-1]);
      }
    }
  }
  return t[0][n-1];
}

/**
 * Another solution
 * reverse the given string and find the LCS of both strings.
 */

int main() {
  // string str = "abcba";
  string str = "bbabcbcab";

  cout << LPS(str);
  return 0;
}
