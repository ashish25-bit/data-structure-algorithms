#include <bits/stdc++.h>
using namespace std;

class Node {
  public:
  int data;
  Node* prev;
  Node* next;

  Node(int val) {
    data = val;
    prev = NULL;
    next = NULL;
  }
};

class Stack {
  private:
  int count;
  Node* top;
  Node* middleNode;

  public:
  Stack() {
    top = NULL;
    middleNode = NULL;
    count = 0;
  }

  Node* insert(int data);
  int middle();
  int deleteMiddle();
};

Node* Stack :: insert(int data) {
  Node* newNode = new Node(data);

  count = count + 1;

  if (!top)
    top = newNode;

  else {
    top->next = newNode;
    newNode->prev = top;
    top = newNode;
  }

  if (count == 1)
    middleNode = newNode;

  else if (count % 2 == 0)
    middleNode = middleNode->next;

  return top;
}

int Stack :: middle() {
  if (!middleNode) return -1;

  return middleNode->data;
}

int Stack :: deleteMiddle() {
  if (!top) return -1;

  count--;
  int data = middleNode->data;
  
  if (count == 0) {
    middleNode = NULL;
    top = NULL;
    return data;
  }

  Node* temp = middleNode;
  Node* nextNode = middleNode->next;
  Node* prevNode = middleNode->prev;

  if (count % 2)
    middleNode = middleNode->prev;
  else 
    middleNode = middleNode->next;

  prevNode->next = nextNode;
  if (nextNode)
    nextNode->prev = prevNode;
  
  temp->next = NULL;
  temp->prev = NULL;
  delete(temp);

  return data;
}

int main() {
  vector<vector<int>> queries = {
    {1, 10},
    {1, 20},
    {1, 30},
    {3},
    {2},
    {3},
    {1, 40},
    {3},
    {2},
    {3},
    {2},
    {3},
    {2},
    {3}
  };

  Stack* s = new Stack();

  for (vector<int> q: queries) {
    if (q[0] == 1) {
      Node* top = s->insert(q[1]);
      cout << "Top: " << top->data;
    }

    else if (q[0] == 2)
      cout << "Pop: " << s->deleteMiddle();

    else
      cout << "Middle: " << s->middle();
    cout << endl;
  }

  return 0;
}
