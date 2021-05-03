// #include <bits/stdc++.h>
// using namespace std;

#include <bits/stdc++.h>
using namespace std;

class Stack {
  public:
  stack<int> st;
  stack<int> minSt;
  void push(int x);
  void pop();
  int getMin();
  void printSt();
};

void Stack :: push(int x) {
  st.push(x);
  if (minSt.empty()) {
        minSt.push(x);
  }
  else {
    if (x <= minSt.top()) minSt.push(x);
  }
}

void Stack :: pop() {
  int top = st.top();
  if (top == minSt.top()) minSt.pop();
  st.pop();
}

int Stack :: getMin() {
  return minSt.top();
}

void Stack :: printSt() {
  stack<int> s = st;
  while (!s.empty()) {
    cout << s.top() << " ";
    s.pop();
  }
  cout << endl;
}

int main() {
  Stack* myStack = new Stack();
  // vector<vector<int>> queries = {
  //   {1, 18},
  //   {1, 19},
  //   {1, 29},
  //   {3},
  //   {2},
  //   {1, 15},
  //   {1, 16},
  //   {3},
  //   {1, 15},
  //   {3}
  // };
 
  vector<vector<int>> queries = {
    {1, 3},
    {1, 2},
    {1, 1},
    {1, 5},
    {1, 4},
    {3},
    {2},
    {3},
    {2},
    {3},
    {2},
    {3},
    {2},
    {3},
    {2}
  };

  for (vector<int> query: queries) {
    switch (query[0]) {
      case 1:
        myStack->push(query[1]);
        break;

      case 2:
        myStack->pop();
        break;

      case 3:
        cout << "Current Stack: ";
        myStack->printSt();
        cout << "Min Elem: " << myStack->getMin() << endl;
        break;

      default:
        break;
    }
  }

  return 0;
}
