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

Node* LCA(Node* root, int n1, int n2) {
  if (!root) return NULL;

  if (n1 > n2) swap(n1, n2);

  if (root->data == n1 || root->data == n2) return root;

  if (root->data > n1 && root->data < n2) return root;

  if (root->data > n2)
    return LCA(root->left, n1, n2);

  return LCA(root->right, n1, n2);
}

int main() {
  vector<string> nodes = {"5", "4", "6", "3", "N", "N", "7", "N", "N", "N", "8"};
  Node* root = buildTree(nodes);

  int n1 = 8;
  int n2 = 7;

  Node* ans = LCA(root, n1, n2);
  if (ans) cout << ans->data;
  else cout << "Error";
  return 0;
}
