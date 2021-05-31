#include <bits/stdc++.h>
using namespace std;

string getKey(int a, int b) {
  string str = to_string(a) + "-" + to_string(b);
  return str;
}

void printArr(vector<int> arr) {
  for (int x: arr) cout << x << " ";
  cout << endl;
}

int countSubets(int arr[], int sum, int n, unordered_map<string, int> &hashMap, int &count) {
  if (sum == 0) {
    count = count + 1;
    return 1;
  }

  if (n == 0 && sum != 0) return 0;

  string key = getKey(n, sum);

  if (hashMap.find(key) != hashMap.end()) {
    if (hashMap[key])count++;
    return hashMap[key];
  }

  if (arr[n-1] > sum) {
    int ans = countSubets(arr, sum, n-1, hashMap, count);
    hashMap[key] = ans;
    return ans;
  }

  // include in subset
  int include = countSubets(arr, sum - arr[n-1], n-1, hashMap, count);
  // not include

  int notInclude = countSubets(arr, sum, n-1, hashMap, count);

  hashMap[key] = include || notInclude;

  return include || notInclude;
}

int countSubets(int arr[], int sum, int n) {
  unordered_map<string, int> hashMap;

  int count = 0;
  countSubets(arr, sum, n, hashMap, count);

  return count;
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
