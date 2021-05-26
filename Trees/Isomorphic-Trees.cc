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

void levelOrder(Node* root) {
  queue<Node*> q;
  q.push(root);

  int currLevel = 0;

  while (!q.empty()) {
    Node* node = q.front();
    q.pop();

    if (node->left)
      q.push(node->left);

    if (node->right)
      q.push(node->right);

    cout << node->data << " ";
  }
  cout << endl;
}

bool isIsomorphic(Node *root1, Node *root2) {
  if (!root1 && !root2) return true;
  
  if (!root1 || !root2) return false;
  
  if (root1->data != root2->data) return false;
  
  bool LL = isIsomorphic(root1->left, root2->left);
  bool RR = isIsomorphic(root1->right, root2->right);
  
  bool RL = isIsomorphic(root1->right, root2->left);
  bool LR = isIsomorphic(root1->left, root2->right);
  
  return (LL && RR) || (RL && LR);
}

int main() {
  vector<char> nodes1 = {'1', '2', '3', '4'};
  Node* root1 = buildTree(nodes1);

  vector<char> nodes2 = {'1', '3', '2', '4'};
  Node* root2 = buildTree(nodes2);

  levelOrder(root1);
  levelOrder(root2);

  cout << (isIsomorphic(root1, root2) ? "Yes" : "No");

  return 0;
}
