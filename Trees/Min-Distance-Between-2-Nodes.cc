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

// void findDist(Node* root, int a, int b) {
//   int count = 0;
//   unordered_map<int, unordered_set<int>> hashMap;
//   queue<Node*> q;

//   q.push(root);

//   while (!q.empty() && count != 2) {
//     Node* temp = q.front();
//     Node* left = temp->left;
//     Node* right = temp->right;
//     q.pop();

//     if (temp->data == a || temp->data == b) count++;

//     if (left) {
//       hashMap[temp->data].insert(left->data);
//       hashMap[left->data].insert(temp->data);
//       q.push(temp->left);
//     }
//     if (right) {
//       hashMap[temp->data].insert(right->data);
//       hashMap[right->data].insert(temp->data);
//       q.push(temp->right);
//     }
//   }

//   for (auto it: hashMap) {
//     cout << it.first << ": ";
//     for (auto x: it.second) cout << x << " ";
//     cout << endl;
//   }

//   unordered_set<int> visited;
//   queue<int> q2;
//   int ans = 0;
//   vector<int> chain;

//   q2.push(a);

//   while (!q2.empty()) {
//     int curr = q2.front();
//     q2.pop();
//     chain.push_back(curr);
//     ans++;
    
//     if (hashMap[curr].find(b) != hashMap[curr].end()) break;

//     visited.insert(curr);

//     for (int x: hashMap[curr]) {
//       if (visited.find(x) == visited.end()) 
//         q2.push(x);
//     }
//   }

//   cout << endl << "Min distance: " << ans << endl;
//   for (int x: chain) cout << x << "->";
//   cout << b;
// }

int main() {
  vector<char> nodes = {'1', '2', '3', 'N', 'N', '4', '6', 'N', '5', 'N', 'N', '7', 'N'};
  Node* root = buildTree(nodes);
  levelOrder(root);
  return 0;
}
