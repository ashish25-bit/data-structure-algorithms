#include <bits/stdc++.h>
using namespace std;

class TrieNode {
  public:
  char ch;
  TrieNode *child[26] = {NULL};
  int prefix;

  TrieNode(char c): ch (c), prefix(1) {}
};

TrieNode* insert(vector<string> data) {
  TrieNode* root = new TrieNode(' ');

  for (string str: data) {
    char *ch = &str[0];
    TrieNode* prev = root;

    while (*ch != '\0') {
      int index = *ch - 'a';

      if (prev->child[index] == NULL) {
        TrieNode* node = new TrieNode(*ch);
        prev->child[index] = node;
        prev = node;
      }
      else {
        prev->child[index]->prefix++;
        prev = prev->child[index];
      }
      *ch++;
    }
  }

  return root;
}

void findPrefix(TrieNode* root, string str, vector<string> &res) {
  if (root->prefix == 1) {
    str = str + root->ch;
    res.push_back(str);
    return;
  }

  for (int i=0; i < 26; i++) {
    if (root->child[i] != NULL)
      findPrefix(root->child[i], str + root->ch, res);
  }
}

vector<string> findPrefix(vector<string> data) {
  TrieNode* root = insert(data);

  vector<string> res;
  for (int i=0; i < 26; i++) {
    if (root->child[i] != NULL)
      findPrefix(root->child[i], "", res);
  }

  return res;
}

int main() {
  vector<string> data = {"zebra", "dog", "duck", "dove"};
  vector<string> prefix = findPrefix(data);

  for (auto str: prefix) cout << str << " ";
  return 0;
}
