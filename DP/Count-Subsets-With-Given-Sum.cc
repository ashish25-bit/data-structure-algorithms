// https://practice.geeksforgeeks.org/problems/perfect-sum-problem5633/1

#include <bits/stdc++.h>
using namespace std;

// bottom up approch
// string getKey(int a, int b) {
//   string str = to_string(a) + "-" + to_string(b);
//   return str;
// }

// void printArr(vector<int> arr) {
//   for (int x: arr) cout << x << " ";
//   cout << endl;
// }

// int countSubets(int arr[], int sum, int n, unordered_map<string, int> &hashMap, int &count) {
//   if (sum == 0) {
//     count = count + 1;
//     return 1;
//   }

//   if (n == 0 && sum != 0) return 0;

//   string key = getKey(n, sum);

//   if (hashMap.find(key) != hashMap.end()) {
//     if (hashMap[key])count++;
//     return hashMap[key];
//   }

//   if (arr[n-1] > sum) {
//     int ans = countSubets(arr, sum, n-1, hashMap, count);
//     hashMap[key] = ans;
//     return ans;
//   }

//   // include in subset
//   int include = countSubets(arr, sum - arr[n-1], n-1, hashMap, count);
//   // not include

//   int notInclude = countSubets(arr, sum, n-1, hashMap, count);

//   hashMap[key] = include || notInclude;

//   return include || notInclude;
// }

// int countSubets(int arr[], int sum, int n) {
//   unordered_map<string, int> hashMap;

//   int count = 0;
//   countSubets(arr, sum, n, hashMap, count);

//   return count;
// }

// top down approach
int countSubets(vector<int> arr, int sum, int n) {
  vector<vector<int>> t(n+1, vector<int>(sum+1, 0));

  for (int i=0 ; i <= n; i++)
    t[i][0] = 1;
    
  for (int i=1; i <= n; i++) {
    for (int j=1; j <= sum; j++) {
        if (arr[i-1] > j)
            t[i][j] = t[i-1][j];
        else
            t[i][j] = t[i-1][j] + t[i-1][j - arr[i-1]];
    }
  }

  return t[n][sum];
}

int main() {
  int arr[] = {2, 3, 4, 5, 6, 8, 10};
  int sum = 10;

  // int arr[] = {1, 2, 3, 3};
  // int sum = 6;

  int n = sizeof(arr) / sizeof(arr[0]);

  cout << countSubets(arr, sum, n);
  return 0;
}
