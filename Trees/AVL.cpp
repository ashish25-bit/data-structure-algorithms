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

  root->height = 1 + max(height(root->left), height(root->right));

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

void  preOrder(Node* root, int &n, string str = "root") {
  if (!root) return;

  n++;
  cout << str << ": " << root->data << "\n";
  preOrder(root->left, n, str + " left");
  preOrder(root->right, n, str + " right");
}

Node* deleteNode(Node* root, int key) {
  if (!root) return root;

  if (root->data > key) {
    root->left = deleteNode(root->left, key);
    return root;
  }
  else if (root->data < key) {
    root->right = deleteNode(root->right, key);
    return root;
  }

  // leaf node
  if (!root->left && !root->right) {
    delete(root);
    return NULL;
  }

  // only left child
  if (root->left && !root->right) {
    Node* left = root->left;
    delete(root);
    return left;
  }

  // only right child
  if (root->right && !root->left) {
    Node* right = root->right;
    delete(root);
    return right;
  }


  // both left and right children are present
  Node* minValue = root->right;

  while (minValue->left)
    minValue = minValue->left;

  root->data = minValue->data;
  root->right = deleteNode(root->right, minValue->data);

  // balancing the tree
  if (!root) return root;

  root->height = 1 + max(height(root->left), height(root->right));

  int diff = getdiff(root);

  // left left
  if (diff > 1 && getdiff(root->left) >= 0)
    return rightRotate(root);

  // right right
  if (diff < -1 && getdiff(root->right) <= 0)
    return leftRotate(root);

  // left right
  if (diff > 1 && getdiff(root->left) < 0) {
    root->left = leftRotate(root->left);
    return rightRotate(root);
  }

  // right left
  if (diff < -1 && getdiff(root->right) > 0) {
    root->right = rightRotate(root->right);
    return leftRotate(root);
  }

  return root;
}

int main() {
  vector<int> arr = {14, 11, 19, 7, 12, 17, 53, 4, 8, 13, 16, 20, 60};
  Node* root = NULL;

  for (int x: arr)
    root = insert(root, x);
  
  int n = 0;
  preOrder(root, n);
  cout << "Total Node: " << n << "\n\n";

  // delete data from avl tree
  vector<int> dn = {8, 7, 11, 14, 17};

  for (int key: dn) {
    root = deleteNode(root, key);
    cout << "DELETED NODE " << key << "\n";
    int n = 0;
    preOrder(root, n);
    cout << "Total Node: " << n << "\n\n";
  }

  return 0;
}
