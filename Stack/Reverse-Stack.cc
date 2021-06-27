#include <bits/stdc++.h>
using namespace std;

void insertBottom(stack<int> &st, int element) {
  if (st.empty()) {
    st.push(element);
    return;
  }

  int top = st.top();
  st.pop();
  insertBottom(st, element);
  st.push(top);
}

void reverseStack(stack<int> &st) {
  if (st.size() == 1 || st.size() == 0) return;

  int top = st.top();
  st.pop();
  reverseStack(st);
  insertBottom(st, top);
}

void printStack(stack<int> st) {
  while (!st.empty()) {
    cout << st.top() << " ";
    st.pop();
  }

  cout << endl;
}

int main() {
  stack<int> st;
  st.push(1);
  st.push(2);
  st.push(3);
  st.push(4);
  st.push(5);

  printStack(st);
  reverseStack(st);
  printStack(st);
  
  return 0;
}
