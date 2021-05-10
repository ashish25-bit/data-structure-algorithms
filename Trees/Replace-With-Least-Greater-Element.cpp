#include <bits/stdc++.h>
using namespace std;

class Node {
  public:
  int data;
  Node* left;
  Node* right;
  int height;

  Node(int key) {
    data = key;
    left = NULL;
    right = NULL;
    height = 1;
  }
};

int height(Node *node) {
  if (!node) return 0;
  return node->height;
}

// difference between left subtree and right subtree
int getdiff(Node* root) {
  if (!root) return 0;

  return height(root->left) - height(root->right);
}

Node* leftRotate(Node* node) {
  Node *temp1 = node->right;
  Node *temp2 = temp1->left;

  temp1->left = node;
  node->right = temp2;

  node->height = max(height(node->left), height(node->right)) + 1;
  temp1->height = max(height(temp1->left), height(temp1->right)) + 1;

  return temp1;
}

Node* rightRotate(Node *node) {
  Node *temp1 = node->left;
  Node *temp2 = temp1->right;

  temp1->right = node;
  node->left = temp2;

  node->height = max(height(node->left), height(node->right)) + 1;
  temp1->height = max(height(temp1->left), height(temp1->right)) + 1;

  return temp1;
}

Node* insert(Node* root, int key, int &ans) {
  if (!root)
    return new Node(key);
  
  if (key < root->data) {
    ans = root->data;
    root->left = insert(root->left, key, ans);
  }

  else if (key > root->data)
    root->right = insert(root->right, key, ans);
  
  else return root;

  root->height = root->height + 1;

  int diff = getdiff(root);

  // left left
  if (diff > 1 && key < root->left->data)
    return rightRotate(root);

  // right right
  if (diff < -1 && key > root->right->data)
    return leftRotate(root);

  // left right
  if (diff > 1 && key > root->left->data) {
    root->left = leftRotate(root->left);
    return rightRotate(root);
  }

  // right left
  if (diff < -1 && key < root->right->data) {
    root->right = rightRotate(root->right);
    return leftRotate(root);
  }

  return root;
}

int main() {
  vector<int> arr = {8, 58, 71, 18, 31, 32, 63, 92, 43, 3, 91, 93, 25, 80, 28};
  Node* root = NULL;

  list<int> res;

  for (int i = arr.size() - 1; i >= 0; i--) {
    int ans = -1;
    root = insert(root, arr[i], ans);
    res.push_front(ans);
  }

  for (auto x: res) cout << x << " ";

  return 0;
}
