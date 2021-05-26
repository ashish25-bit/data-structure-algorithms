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

int getInt(char ch) {
  return ch - '0';
}

// level order insertion
Node* buildTree(vector<char> nodes) {
  queue<Node*> q;
  int n = nodes.size();

  int pos = 1;
  Node* root = new Node(getInt(nodes[0]));

  q.push(root);

  while (!q.empty() && pos < n) {
    Node* temp = q.front();
    q.pop();

    char leftChar = nodes[pos++];
    char rightChar = '#';

    if (pos < n)
      rightChar = nodes[pos++];

    if (leftChar != 'N') {
      temp->left = new Node(getInt(leftChar));
      q.push(temp->left);
    }

    if (rightChar != 'N' && rightChar != '#') {
      temp->right = new Node(getInt(rightChar));
      q.push(temp->right);
    }
  }

  return root;
}

int getCount(Node *root, int l, int h) {
  if (!root) return 0;

  if (root->data >= l && root->data <=h) {
    int left  = getCount(root->left, l, h);
    int right = getCount(root->right, l, h);
    return 1 + left + right;
  }

  if (root->data < l)
    return getCount(root->right, l, h);
  return getCount(root->left, l, h);
}


int main() {
  vector<char> nodes = {'5', '4', '6', '3', 'N', 'N', '7', '1'};
  int l = 1, h = 5;

  Node* root = buildTree(nodes);
  cout << getCount(root, l, h);

  return 0;
}
