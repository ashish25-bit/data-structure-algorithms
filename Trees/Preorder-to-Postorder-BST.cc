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

typedef unordered_map<int, int> MAP;

void postOrder(Node* root) {
  if (!root)
      return;
  postOrder(root->left);
  postOrder(root->right);
  cout << root->data << " ";
}

int head = 0;
int getIndex(MAP hashMap, int num) {
  return hashMap[num];
}

Node* constructNode(int pre[], MAP hashMap, int start, int end) {
  if (start > end) return NULL;
  
  Node* node = new Node(pre[head]);
  
  int index = getIndex(hashMap, pre[head]);
  head++;
  
  node->left  = constructNode(pre, hashMap, start, index-1);
  node->right = constructNode(pre, hashMap, index+1, end);
  
  return node;
}

Node* constructTree(int pre[], int size) {
  int head = 0;
  MAP hashMap;
  int* in = new int[size];
  
  for (int i=0; i < size; i++)
    in[i] = pre[i];
  
  sort(in, in + size);
  for (int i=0; i < size; i++) hashMap[in[i]] = i;
  
  return constructNode(pre, hashMap, 0, size - 1);
}

int main() {
  // int arr[] = {40, 30, 35, 80, 100};
  // int arr[] = {40, 30, 32, 35, 80, 90, 100, 120};

  int arr[] = {100, 10, 3, 1, 8, 7, 22, 20, 12, 18, 13, 14, 16, 21, 36, 30, 27, 26, 34, 64, 51, 48, 42, 41, 46, 44, 49, 58, 92, 67, 65, 71, 70, 83, 74, 72, 80, 77, 79, 90, 87, 93, 99, 98, 96, 1079, 695, 884, 823, 995};
  int n = sizeof(arr) / sizeof(arr[0]);

  Node* root = constructTree(arr, n);
  postOrder(root);
  
  return 0;
}
