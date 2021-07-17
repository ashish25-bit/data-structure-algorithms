// https://practice.geeksforgeeks.org/problems/mobile-numeric-keypad5456/1#

#include <bits/stdc++.h>
using namespace std;

// good solution
const int R = 4;
const int C = 3;

bool isValid(int i, int j, vector<vector<long long>> &arr) {
  return i >= 0 && j >= 0 && i < R && j < C && arr[i][j] != -1;
}

long long calc(int i, int j, vector<vector<long long>> arr) {
  long long ans = arr[i][j];

  // top
  if (isValid(i-1, j, arr))
    ans = ans + arr[i-1][j];

  // down
  if (isValid(i+1, j, arr))
    ans = ans + arr[i+1][j];

  // left
  if (isValid(i, j-1, arr))
    ans = ans + arr[i][j-1];

  // right
  if (isValid(i, j+1, arr))
    ans = ans + arr[i][j+1];

  return ans;
}

long long countUtil(vector<vector<long long>> &arr) {
  vector<vector<long long>> t = arr;
  long long ans = 0;

  for (int i=0; i < R; i++) {
    for (int j=0; j < C; j++) {
      if (arr[i][j] == -1) continue;

      long long curr = calc(i, j, t);
      arr[i][j] = curr;
      ans = ans + curr;
    }
  }

  return ans;
}

long long count(int n) {
  if (n == 1) return 10;

  vector<vector<long long>> t(R, vector<long long>(C, 1));
  t[R-1][0] = -1;
  t[R-1][C-1] = -1;
  n = n -1;
  long long ans;

  while (n--) {
    ans = countUtil(t);
  }

  return ans;
}

// Recursive worst possible solution
// const char dirs[] = {'L', 'R', 'T', 'B'};
// int isValid(int num, char dir) {
//   if (dir == 'L') {
//     if (num == 1 || num == 4 || num == 7 || num == 0) return -1;
//     return num - 1;
//   }

//   if (dir == 'R') {
//     if (num == 3 || num ==  6 || num == 9 || num == 0) return -1;
//     return num + 1;
//   }

//   if (dir == 'T') {
//     if (num == 1 || num == 2 || num == 3) return -1;
//     if (num == 0) return 8;
//     return num - 3;
//   }

//   if (num == 7 || num == 9 || num == 0)
//     return -1;
//   if (num == 8) return 0;
//   return num + 3;
// }

// int countUtil(int n, int num) {
//   if (n == 1) return 1;

//   int ans = countUtil(n - 1, num);

//   for (int i=0; i < 4; i++) {
//     int next = isValid(num, dirs[i]);
//     if (next != -1)
//       ans = ans + countUtil(n-1, next);
//   }

//   return ans;
// }

// int count(int n) {
//   int ans = 0;
//   for (int i=0; i < 10; i++) {
//     int res = countUtil(n, i);
//     ans = ans + res;
//   }
//   return ans;
// }

int main() {
  int n = 25;

  cout << count(n);
  return 0;
}
