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

typedef pair<Node*, int> P;

int getInt(string ch) {
  stringstream geeks(ch);
  int x;

  geeks >> x;

  return x;
}

// level order insertion
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

class Result {
  public:
  bool status;
  int n;
  int min;
  int max;

  Result(bool b, int val, int m1, int m2) {
    status = b;
    n      = val;
    min    = m1;
    max    = m2;
  }
};

Result* largestBSTUtil(Node* root) {
  if (!root) return NULL;

  if (!root->left && !root->right)
    return new Result(true, 1, root->data, root->data);

  Result* left = largestBSTUtil(root->left);
  Result* right = largestBSTUtil(root->right);

  if (left && right) {
    if (!left->status || !right->status)
      return new Result(false, max(left->n, right->n), 0, 0);

    if (root->data > left->max && root->data < right->min)
      return new Result(true, 1 + left->n + right->n, left->max, right->min);

    return new Result(false, max(left->n, right->n), 0, 0);
  }

  else if (right) {
    if (!right->status)
      return new Result(false, right->n, 0, 0);

    if (root->data < right->min)
      return new Result(true, 1 + right->n, root->data, right->max);
    
    return new Result(false, right->n, 0, 0);
  }

  if (!left->status)
    return new Result(false, left->n, 0, 0);

  if (root->data > left->max)
    return new Result(true, 1 + left->n, left->min, root->data);
  
  return new Result(false, left->n, 0, 0);
}

int largestBST(Node* root) {
  Result* ans = largestBSTUtil(root);
  return ans->n;
}

int main() {
  vector<string> nodes = {"10", "6", "12", "3", "8", "9", "3", "2", "5", "N", "10", "8"};
  Node* root = buildTree(nodes);

  cout << largestBST(root);
  return 0;
}
