// https://practice.geeksforgeeks.org/problems/lru-cache/1

#include <bits/stdc++.h>
using namespace std;

class Node {
  public:
  int key;
  int value;
  Node* next;
  Node* prev;

  Node(int k, int val) {
    key = k;
    value = val;
    next = NULL;
    prev = NULL;
  }
};

class List {
  Node* head;
  Node* tail;
  public:

  List(): head(NULL), tail(NULL) {}

  void push_front(Node* node) {
    if (!node) return;

    if (!head) {
      head = node;
      tail = head;
    }
    else {
      node->next = head;
      head->prev = node;
      head = node;
    }
  }

  void pop_back() {
    if (!tail) return;

    if (head == tail) {
      tail = NULL;
      head = NULL;
      return;
    }

    Node* temp = tail;
    tail = tail->prev;
    tail->next = NULL;
    temp->prev = NULL;
    delete temp;
  }

  int back() {
    return tail == NULL ? -1 : tail->key;
  }

  void remove(Node* node) {
    if (!node || !head) return;

    if (head == node) {
      // only head is present
      if (head->next == NULL) {
        head = NULL;
        tail = NULL;
        return;
      }

      head = head->next;
      head->prev = NULL;
      node->next = NULL;
      delete node;
      return;
    }

    if (tail == node) {
      pop_back();
      return;
    }

    node->prev->next = node->next;
    node->next->prev = node->prev;

    node->prev = NULL;
    node->next = NULL;
    delete(node);
  }
};

class LRUCache {
  int cap;
  int currCap;
  unordered_map<int, Node*> hashMap;
  List q;

  public:
  LRUCache(int c): cap(c), currCap(0) {}

  int get(int key) {
    if (hashMap.find(key) == hashMap.end())
      return -1;

    int data = hashMap[key]->value;

    q.remove(hashMap[key]);
    Node* node = new Node(key, data);

    q.push_front(node);
    hashMap[key] = node;
    return data;
  }

  void set(int key, int val) {
    if (hashMap.find(key) == hashMap.end()) {
      if (currCap == cap) {
        int back = q.back();
        hashMap.erase(back);
        q.pop_back();
        currCap--;
      }
      currCap++;
    }
    else
      q.remove(hashMap[key]);

    Node* node = new Node(key, val);
    q.push_front(node);
    hashMap[key] = node;
  }
};

int main() {
  vector<vector<int>> arr = {
    {1, 97, 30},
    {0, 43},
    {0, 13}, 
    {1, 48, 56}, 
    {0, 67}, 
    {0, 60}, 
    {1, 74, 43}, 
    {1, 72, 39}, 
    {1, 100, 59}, 
    {0, 85}, 
    {1, 91, 62}, 
    {0, 72}, 
    {1, 1, 4}, 
    {0, 1}, 
    {0, 53}, 
    {0, 5}, 
    {1, 59, 60}, 
    {1, 18, 95}, 
    {0, 37}, 
    {0, 61}, 
    {0, 15}, 
    {1, 66, 38}, 
    {0, 22}, 
    {0, 10}, 
    {1, 33, 1}, 
    {0, 5}, 
    {1, 57, 59}, 
    {1, 69, 11}, 
    {1, 29, 70}, 
    {1, 75, 47}, 
    {0, 6}, 
    {0, 2}, 
    {1, 68, 90}, 
    {0, 27}, 
    {0, 39}, 
    {1, 1, 6}, 
    {0, 58}, 
    {0, 49}, 
    {1, 8, 18}, 
    {1, 70, 98}, 
    {0, 29}, 
    {1, 71, 19}, 
    {1, 81, 93}, 
    {0, 55}, 
    {1, 44, 8}, 
    {0, 51}, 
    {1, 89, 86}, 
    {0, 91}, 
    {0, 35}, 
    {1, 84, 26}, 
    {1, 43, 95}, 
    {0, 92}, 
    {1, 21, 21}, 
    {0, 39}, 
    {0, 93}, 
    {0, 23}, 
    {0, 86}, 
    {0, 95}, 
    {0, 9}, 
    {0, 3}, 
    {1, 23, 85}, 
    {1, 58, 26}, 
    {1, 93, 3}, 
    {0, 97}, 
    {0, 31}, 
    {0, 50}, 
    {1, 57, 13}, 
    {1, 49, 55}, 
    {0, 29}, 
    {0, 58}, 
    {0, 77}, 
    {1, 21, 98}, 
    {1, 6, 95}, 
    {0, 83}, 
    {0, 24}, 
    {1, 16, 37}, 
    {1, 54, 85}, 
    {1, 55, 25}, 
    {0, 37}, 
    {0, 93}, 
    {0, 59}, 
    {0, 24},
  };

  // vector<vector<int>> arr = {
  //   {1, 1, 2},
  //   {1, 2, 3},
  //   {1, 1, 5},
  //   {1, 4, 5},
  //   {1, 6, 7},
  //   {0, 4},
  //   {1, 1, 2},
  //   {0, 3}
  // };

  int cap = 8;
  LRUCache l(cap);
  for (auto q: arr) {
    if (q[0] == 1) {
      l.set(q[1], q[2]);
    }
    else {
      cout << l.get(q[1]) << " ";
    }
  }

  return 0;
}
