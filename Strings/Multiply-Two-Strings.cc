// https://leetcode.com/problems/multiply-strings/

#include <bits/stdc++.h>
using namespace std;

string addNums(string s1, string s2) {
  int l1 = s1.length();
  int l2 = s2.length();

  if (l1 == 0 && l2 == 0)
    return "";

  if (l1 == 0)
    return s2;

  if (l2 == 0)
    return s1;

  int carry = 0;

  int i = 0;
  int j = 0;
  string res = "";

  while (i < l1 && j < l2) {
    int num = (s1[i] - '0') + (s2[j] - '0') + carry;
    carry = (int)num / 10;
    num = num % 10;

    res.push_back(num + '0');

    i++;
    j++;
  }

  while (i < l1) {
    int num = (s1[i] - '0') + carry;
    carry = (int)num / 10;
    num = num % 10;

    res.push_back(num + '0');
    i++;
  }

  while (j < l2) {
    int num = (s2[j] - '0') + carry;
    carry = (int)num / 10;
    num = num % 10;

    res.push_back(num + '0');
    j++;
  }

  if (carry != 0)
    res.push_back('1');

  return res;
}

string multiply(string num1, string num2) {
  int l1 = num1.length();
  int l2 = num2.length();

  if (l1 == 0 || l2 == 0)
    return "0";

  if (num1[0] == '0' || num2[0] == '0')
    return "0";

  int carry = 0;
  string result = "";
  int zeros = 0;

  for (int i = l1 - 1; i >= 0; i--) {
    string curr = "";

    for (int j = l2 - 1; j >= 0; j--) {
      int num = (num1[i] - '0') * (num2[j] - '0') + carry;
      carry = (int)num / 10;

      if (j != 0) {
        num = num % 10;
        curr.push_back((num + '0'));
      }
      else {
        string temp = to_string(num);
        reverse(temp.begin(), temp.end());
        curr.insert(curr.length(), temp);
      }
    }

    string tempZ = "";
    for (int j = 0; j < zeros; j++)
      tempZ.push_back('0');

    curr.insert(0, tempZ);
    result = addNums(result, curr);

    zeros++;
    carry = 0;
  }

  reverse(result.begin(), result.end());
  return result;
}

int main() {
  string num1 = "98";
  string num2 = "9";

  string res = multiply(num1, num2);
  cout << res;

  return 0;
}
