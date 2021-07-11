// https://practice.geeksforgeeks.org/problems/check-mirror-in-n-ary-tree1528/1

#include <bits/stdc++.h>
using namespace std;

int checkMirrorTree(int n, int e, int A[], int B[]) {
  unordered_map<int, vector<int>> mat1;
  unordered_map<int, vector<int>> mat2;
  
  int parent1;
  int parent2;
  for (int i=0; i < 2*e; i++) {
    if (i % 2 == 0) {
      parent1 = A[i];
      parent2 = B[i];
      continue;
    }
    mat1[parent1].push_back(A[i]);
    mat2[parent2].push_back(B[i]);
  }

  cout << "Matrix1:\n";
  for (auto it: mat1) {
    cout << it.first << ": ";
    for (int x: it.second) cout << x << " ";
    cout << endl;
  }
  
  cout << "\nMatrix2:\n";
  for (auto it: mat2) {
    cout << it.first << ": ";
    for (int x: it.second) cout << x << " ";
    cout << endl;
  }
  cout << endl;

  for (auto it: mat1) {
    vector<int> arr1 = it.second;
    vector<int> arr2 = mat2[it.first];

    int pos = arr2.size() - 1;

    for (int i=0; i < arr1.size(); i++, pos--) {
      if (arr1[i] != arr2[pos]) return 0;
    }
  }
  
  return 1;
}

int main() {
  int a[] = {1, 2, 1, 3, 2, 4, 2, 5};
  int b[] = {1, 3, 1, 2, 2, 5, 2, 4};

  int e = (sizeof(a) / sizeof(a[0])) / 2;
  
  unordered_set<int> s;
  for (int i=0; i < 2*e; i++) s.insert(a[i]);

  int n = s.size();

  cout << checkMirrorTree(n, e, a, b);
  
  return 0;
}
