/*
  FIND THE INORDER TRAVERSAL OF THE TREE AND FIND THE MINIMUM SWAPS TO SORT THE ARRAY.
*/

#include <bits/stdc++.h>
using namespace std;

class Node {
  public: 
  int data;
  Node* left;
  Node* right;

  Node (int val) {
      data = val;
      left = nullptr;
      right = nullptr;
  }
};

void inOrder(Node* root, vector<int> &res) {
  if (!root)
      return;
  inOrder(root->left, res);
  res.push_back(root->data);
  inOrder(root->right, res);
}

void swapNumber(vector<int> &arr, int i1, int i2) {
  int temp = arr[i1];
  arr[i1] = arr[i2];
  arr[i2] = temp;
}

int minSwaps(vector<int> nums){
  vector<int> arr = nums;
  sort(arr.begin(), arr.end());
  unordered_map<int, int> hashMap;
  int swaps = 0;
  
  for (int i=0; i<arr.size(); i++)
    hashMap[nums[i]] = i;
  
  for (int i=0; i<arr.size(); i++) {
    if (arr[i] != nums[i]) {
      swaps++;
      int index = hashMap[arr[i]];
      hashMap[arr[i]] = i;
      hashMap[nums[i]] = index;
      swapNumber(nums, i, index);
    }
  }
  return swaps;
}

int main() {
  Node*  root = new Node(5);

  root->left = new Node(6);
  root->right = new Node(7);

  root->left->left  = new Node(8);
  root->left->right = new Node(9);

  root->right->left = new Node(10);
  root->right->right = new Node(11);

  vector<int> res;
  inOrder(root, res);

  cout << minSwaps(res);

  return 0;    
}
