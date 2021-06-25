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

Node* lca(Node* root ,int n1 ,int n2 ) {
  if (!root) return NULL;
  
  if (root->data == n1 || root->data == n2) return root;
  
  Node* leftSub = lca(root->left, n1, n2);
  Node* rightSub = lca(root->right, n1, n2);
  
  if (leftSub && rightSub) return root;
  
  if (leftSub) return leftSub;
  return rightSub;
}

int getDist(Node* root, int n) {
  if (!root) return 100000;
  
  if (root->data == n) return 0;
  
  int left  = getDist(root->left, n);
  int right = getDist(root->right, n);
  
  return 1 + min(left, right);
}

int findDist(Node* root, int a, int b) {
  Node* common = lca(root, a, b);
  return getDist(common, a) + getDist(common, b);
}

int main() {
  vector<string> arr = {"1", "2", "3", "N", "N", "4", "6", "N", "5", "N", "N", "7", "N"};
  Node* root = buildTree(arr);

  int a = 7;
  int b = 2;

  cout << findDist(root, a, b);
  
  return 0;
}
