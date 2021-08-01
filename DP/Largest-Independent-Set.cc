// https://practice.geeksforgeeks.org/problems/largest-independent-set-problem/1#

/**
 * memoization not added
 * use unordered_map<Node*, int> hashMap for storing value for current node.
 */

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

int getInt(string ch) {
  int x;
  stringstream geeks(ch);
  geeks >> x;

  return x;
}

Node* buildTree(vector<string> nodes) {
  queue<Node*> q;
  int n = nodes.size();

  int pos = 1;
  Node* root = new Node(getInt(nodes[0]));

  q.push(root);

  while (!q.empty() && pos < n) {
    Node* temp = q.front();
    q.pop();

    string leftChar = nodes[pos++];
    string rightChar = "#";

    if (pos < n)
      rightChar = nodes[pos++];

    if (leftChar != "N") {
      temp->left = new Node(getInt(leftChar));
      q.push(temp->left);
    }

    if (rightChar != "N" && rightChar != "#") {
      temp->right = new Node(getInt(rightChar));
      q.push(temp->right);
    }
  }

  return root;
}

/**
 * select the current node and then explore it's grandchildren i.e. left->left, left->right, right->left, right->right
 * dont select add explore left and right child.
 */
int LIS(Node* root) {
  if (!root) return 0;

  if (!root->left && !root->right) return 1;

  // include root
  int s;
  if (root->left && root->right) {
    int l = LIS(root->left->left) + LIS(root->left->right);
    int r = LIS(root->right->left) + LIS(root->right->right);

    s = 1 + l + r;
  }
  else if (root->left) {
    s = 1 + LIS(root->left->left) + LIS(root->left->right);
  }
  else
    s = 1 + LIS(root->right->left) + LIS(root->right->right);

  int left  = LIS(root->left);
  int right = LIS(root->right);

  return max(s, left + right);
}

int main() {
  vector<string> nodes = {"10", "20", "30", "40", "50", "N", "60", "N", "N", "70", "80"};
  Node* root = buildTree(nodes);
  cout << LIS(root);

  return 0;
}
