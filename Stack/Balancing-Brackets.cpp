#include <bits/stdc++.h>
using namespace std;

bool isOpen(char ch) {
    return ch == '[' || ch == '(' || ch == '{';
}

bool isEqual(char top, char curr) {
    if (curr == ')') {
        if (top == '(')
            return true;
        return false;
    }

    else if (curr == ']') {
        if (top == '[')
            return true;
        return false;
    }

    else if (curr == '}') {
        if (top == '{')
            return true;
        return false;
    }

    return false;
}

bool isBalanced(string str) {
    stack<char> st;

    for (int i = 0; i < str.length(); i++) {
        if (isOpen(str[i]))
            st.push(str[i]);

        else {
            if (st.empty())
                return false;
            char top = st.top();
            st.pop();
            if (!isEqual(top, str[i])) return false;
        }
    }
    if (st.size() > 0)  return false;
    return true;
}

int main() {
    string str = ")";
    cout << isBalanced(str);

    return 0;
}