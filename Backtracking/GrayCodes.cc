// https://leetcode.com/problems/gray-code/

#include <bits/stdc++.h>
using namespace std;

vector<string> grayCodeUtil(vector<string> codes) {
  vector<string> res;
  int n = codes.size();

  // from left to right
  for (int i=0; i < n; i++) {
    res.push_back("0" + codes[i]);
  }
  // from right to left
  for (int i=n-1; i >= 0; i--) {
    res.push_back("1" + codes[i]);
  }

  return res;
}

int binaryToInt(string str) {
  int base = 1;
  int n = 0;

  char *ch = &str[str.length() - 1];

  while (*ch != '\0') {
    int ld = *ch - '0';
    *ch--;

    n = n + (ld * base);
    base = base * 2;
  }

  return n;
}

vector<int> getIntegerVector(vector<string> codes) {
  vector<int> intCodes;

  for (string code: codes) {
    int x = binaryToInt(code);
    intCodes.push_back(x);
  }

  return intCodes;
}

vector<int> grayCode(int n) {
  vector<string> codes = {"0", "1"};
  if (n == 1) return {0, 1};

  n = n - 1;

  while (n--) {
    codes = grayCodeUtil(codes);
  }

  return getIntegerVector(codes);
}

int main() {
  int n = 4;
  vector<int> codes = grayCode(n);
  for (int code: codes) cout << code << " ";
  return 0;
}


/**
 * 1: [0, 1]
 * 2: [00, 01, 11, 10]
 * 3: [000, 001, 011, 010, 110, 111, 101, 100]
 */