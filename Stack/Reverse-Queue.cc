#include <bits/stdc++.h>
using namespace std;

// not needed for reversing queue
// just for knowledge
void insertFront(queue<int> &q, int element) {
  if (q.empty()) {
    q.push(element);
    return;
  }

  int front = q.front();
  q.pop();
  insertFront(q, element);
  q.push(front);
}

void reverseQueue(queue<int> &q) {
  if (q.size() == 1 || q.size() == 0) return;

  int front = q.front();
  q.pop();
  reverseQueue(q);
  q.push(front);
}

void printQueue(queue<int> q) {
  while (!q.empty()) {
    cout << q.front() << " ";
    q.pop();
  }

  cout << endl;
}

int main() {
  queue<int> q;
  q.push(1);
  q.push(2);
  q.push(3);
  q.push(4);

  printQueue(q);
  reverseQueue(q);
  printQueue(q);

  insertFront(q, 0);
  printQueue(q);

  return 0;
}
