#include <bits/stdc++.h>
using namespace std;

class Node {
  public:
    int data;
    Node* next;
    Node(int val) {
      this->data = val;
      this->next = NULL;
    }
};

void printLL(Node* head) {
  while (head) {
    cout << head->data << " ";
    head = head->next;
  }
  cout << endl;
}

Node* getList(vector<int> arr) {
  Node* head = NULL;
  Node* tail = NULL;

  for (int x: arr) {
    Node* newNode = new Node(x);

    if (!head) {
      head = newNode;
      tail = newNode;
    }
    else {
      tail->next = newNode;
      tail = newNode;
    }
  }
  return head;
}

struct comparator {
  bool operator() (Node* a, Node* b) {
    return a->data > b->data;
  }
};

Node * mergeKLists(Node *arr[], int K) {
  priority_queue<Node*, vector<Node*>, comparator> mh;
  
  for (int i=0; i < K; i++) 
    mh.push(arr[i]);
      
  Node* head = NULL;
  Node* prev = NULL;
  
  while (!mh.empty()) {
    Node* curr = mh.top();
    mh.pop();
    
    if (!head) 
        head = curr;
        
    if (prev)
        prev->next = curr;
        
    if (curr->next)
        mh.push(curr->next);
        
    prev = curr;
  }
  
  return head;
}

int main() {
  vector<vector<int>> data = {
    {1,2,3},
    {4,5},
    {5,6},
    {7,8}
  };

  int N = data.size();

  Node *arr[N];

  for (int i=0; i < N; i++) {
    Node* root = getList(data[i]);
    arr[i] = root;
  }

  Node* root = mergeKLists(arr, N);
  printLL(root);

  return 0;
}
