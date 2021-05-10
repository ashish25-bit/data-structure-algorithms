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

Node* insert(Node* root, int key) {
  if (!root)
    return new Node(key);
  
  if (key < root->data)
    root->left = insert(root->left, key);

  else if (key > root->data)
    root->right = insert(root->right, key);
  
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

void  preOrder(Node* root) {
  if (!root) return;

  cout << root->data << " ";
  preOrder(root->left);
  preOrder(root->right);
}

int main() {
  vector<int> arr = {1, 2, 3, 4, 5};
  Node* root = NULL;

  for (int x: arr) {
    root = insert(root, x);
    preOrder(root);
    cout << endl;
  }
  

  return 0;
}
