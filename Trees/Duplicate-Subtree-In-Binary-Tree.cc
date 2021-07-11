// https://practice.geeksforgeeks.org/problems/duplicate-subtree-in-binary-tree/1

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

string dupSub(Node* root, unordered_set<string> &hashSet) {

  if (!root)
    return "-";

  string lStr = dupSub(root->left, hashSet);
  if (lStr == "") return "";
  
  string rStr = dupSub(root->right, hashSet);
  if (rStr == "") return "";

  string str = lStr + to_string(root->data) + rStr;
  
  if (str.length() > 3 && hashSet.find(str) != hashSet.end()) return "";
  
  hashSet.insert(str);
  return str;
  
}

bool dupSub(Node* root) {
  unordered_set<string> hashSet;

  string str = dupSub(root, hashSet);
  if (str == "") return true;
  return false;
}

int main() {
  vector<char> nodes = {'5', '4', '2', 'N', '4', '5', '1', 'N', '4', '1'};
  Node* root = buildTree(nodes);
  // levelOrder(root);
  // cout << endl;

  cout << dupSub(root);

  return 0;
}
