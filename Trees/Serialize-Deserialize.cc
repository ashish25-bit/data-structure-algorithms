// https://practice.geeksforgeeks.org/problems/serialize-and-deserialize-a-binary-tree/1#

#include <bits/stdc++.h>
using namespace std;

class Node {
  public:
  int data;
  Node* left;
  Node* right;

  Node(int val) {
    data = val;
    left = NULL;
    right = NULL;
  }
};

void serializeUtil(Node* root, vector<int> &res) {
  if(!root) {
    res.push_back(-1);
    return;
  }

  res.push_back(root->data);
  serializeUtil(root->left, res);
  serializeUtil(root->right, res);
}

vector<int> serialize(Node* root) {
  vector<int> res;
  serializeUtil(root, res);
  return res;
}

Node* deSerialize(vector<int> arr) {
  static int INDEX = 0;
  if (INDEX >= arr.size()) return NULL;

  if (arr[INDEX] == -1) {
    INDEX++;
    return NULL;
  }

  Node* root = new Node(arr[INDEX]);
  INDEX++;

  root->left  = deSerialize(arr);
  root->right = deSerialize(arr);

  return root;
}

void preorder(Node* root) {
  if (!root) return;

  cout << root->data << " ";
  preorder(root->left);
  preorder(root->right);
}

int main() {
  Node* root = new Node(20);
  root->left = new Node(8);
  root->left->left = new Node(4);
  root->left->right = new Node(12);
  root->left->right->left = new Node(10);
  root->left->right->right = new Node(14);

  vector<int> res = serialize(root);

  for (int x: res) cout << x << " ";
  cout << endl;
  root = deSerialize(res);
  preorder(root);
  
  return 0;
}

