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
typedef pair<bool, int> BoolInt;

int getInt(string ch) {
  int x;
  stringstream geeks(ch);
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

void levelOrder(Node* root) {
  queue<P> q;
  q.push(make_pair(root, 0));

  int currLevel = 0;

  while (!q.empty()) {
    P p = q.front();
    q.pop();

    if (p.first->left)
      q.push(make_pair(p.first->left, p.second + 1));

    if (p.first->right)
      q.push(make_pair(p.first->right, p.second + 1));

    if (currLevel != p.second) {
      currLevel = p.second;
      cout << endl;
    }
    cout << p.first->data << "(" << p.second << ") ";
  }
}

BoolInt isHeap(Node * node, Node * parent) {
  if (parent) {
    if (parent->data < node->data) {
      return make_pair(false, -1);
    }
  }
  
  if (
    (!node->left && !node->right) // leaf node
    ||
    (node->left && !node->right) // only left child
  ) {
    return make_pair(true, 1);
  }
  
  if (!node->left && node->right) { // only right child
    return make_pair(false, -1);
  }
  
  BoolInt left  = isHeap(node->left, node);
  BoolInt right = isHeap(node->right, node);
  
  if (!left.first || !right.first || (left.second < right.second))
    return make_pair(false, -1);
      
  return make_pair(true, 1 + left.second);
  
} 
bool isHeap(Node * tree) {
  BoolInt res = isHeap(tree, NULL);
  return res.first;
}

int main() {
  vector<string> nodes = {"10", "4", "7", "3", "2", "6", "N"};
  Node* root = buildTree(nodes);
  levelOrder(root);
  cout << endl;
  isHeap(root) ? cout << "Yes" : cout << "No";
  
  return 0;
}
