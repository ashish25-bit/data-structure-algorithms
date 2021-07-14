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

Node* LCA(Node* root, int n1, int n2) {
  if (!root) return NULL;

  if (root->data == n1 || root->data == n2) return root;

  Node* left  = LCA(root->left, n1, n2);
  Node* right = LCA(root->right, n1, n2);

  if (left != NULL && right != NULL) return root;
  if (left) return left;
  return right;
}

int main() {
  vector<string> nodes = {"1", "2", "3", "4", "5", "6", "7"};
  Node* root = buildTree(nodes);

  int n1 = 4;
  int n2 = 1;

  Node* node = LCA(root, n1, n2);
  if (node)
    cout << node->data;

  return 0;
}
