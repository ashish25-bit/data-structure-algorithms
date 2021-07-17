/**
 * It is basically a n-ary tree
 class TrieNode {
   char ch; // for storing the current character
   TrieNode *child[26]; // for next letter/alphabet
   int wordend; // keep count of the words which end here, intialize to zero
 };
 */

#include <bits/stdc++.h>
using namespace std;

class TrieNode {
  public:
  char ch;
  TrieNode *child[26] = {NULL};
  bool wordEnd;

  TrieNode(char c): ch (c), wordEnd(0) {}
};

// Time: O(N * max(Word-length))
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
      else
        prev = prev->child[index];

      *ch++;
    }
    if (prev != root)
      prev->wordEnd = true;
  }

  return root;
}

bool search(TrieNode* root, char *ch) {
  if (!root) return false;

  if (*ch == '\0' && root->wordEnd) return true;

  if (*ch == '\0' && !root->wordEnd) return false;

  int index = *ch - 'a';
  if (root->child[index] == NULL) return false;

  *ch++;
  return search(root->child[index], ch);
}

void deleteWord(TrieNode* root, char *ch) {
  if (!root) return;

  if (*ch == '\0' && !root->wordEnd) return;

  if (*ch == '\0' && root->wordEnd) {
    cout << "Word deleted\n";
    root->wordEnd = false;
    return;
  }

  int index = *ch - 'a';
  deleteWord(root->child[index], ch + 1);
}

int main() {
  vector<string> data = {"aba", "abc", "ab", "bab"};
  TrieNode* root = insert(data);

  for (string str: {"bab", "bac", "baba", "ba", "ab"}) {
    if (search(root, &str[0]))
      cout << str << ": Found\n";
    else
      cout << str << ": Not Found\n";
  }

  string str = "ab";
  deleteWord(root, &str[0]);
  if (search(root, &str[0]))
    cout << str << ": Found\n";
  else
    cout << str << ": Not Found\n";

  return 0;
}
