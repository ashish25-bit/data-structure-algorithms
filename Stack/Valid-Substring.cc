// https://leetcode.com/problems/longest-valid-parentheses/

#include <bits/stdc++.h>
using namespace std;

int findMaxLen(string s) {
  int len = 0;
  stack<int> st;
  
  for (int i=0; i < s.length(); i++) {
    if (s[i] == '(')
        st.push(i);
    else {
      if (st.empty())
          st.push(i);
      else {
        if (s[st.top()] == ')') {
          st.pop();
          st.push(i);
          continue;
        }
        st.pop();
        int temp = i - (st.empty() ? -1 : st.top());
        len = max(len, temp);
      }
    }
  }
  return len;
}

int main() {
  string str = "))()(()))()";
  cout << findMaxLen(str);

  return 0;
}
