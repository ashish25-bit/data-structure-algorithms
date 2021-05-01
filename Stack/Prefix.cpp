#include<bits/stdc++.h> 
using namespace std; 
  
int precedence(char c) { 
    if(c == '^') 
        return 3; 
    else if(c == '*' || c == '/') 
        return 2; 
    else if(c == '+' || c == '-') 
        return 1;
    return -1; 
}

string reverseStr(string s) {
    int start = 0;
    int end = s.length() - 1;

    while (start < end) {
        char c = s[start];
        s[start] = s[end];
        s[end] = c;
        start++;
        end--;
    }
    return s;
}

bool isAlpha(char ch) {
    return ch >= 'a' && ch <= 'z';
}

string preFixExpression(string exp) {
    exp = reverseStr(exp);
    string prefix = "";
    stack<char> prefixStack;

    for (int i=0; i < exp.length(); i++) {
        if (exp[i] == ' ') continue;

        // if the character is an alphabet add to the expression
        if (isAlpha(exp[i])) prefix += exp[i];

        // if the character is a closing bracket push it to the stack
        else if (exp[i] == ')') prefixStack.push(exp[i]);

        // if the character is an opening bracket
        else if (exp[i] == '(') {
            // pop from stack and add to the result expression until ')' is encountered
            while (!prefixStack.empty() && prefixStack.top() != ')') {
                prefix += prefixStack.top();
                prefixStack.pop();
            }
            // pop out the closing bracket
            prefixStack.pop();
        }

        // if it's an operator
        else {
            // pop from the stack until top has greater precedence than the current character
            // OR stack is empty
            while (!prefixStack.empty() && precedence(exp[i]) < precedence(prefixStack.top())) {
                prefix += prefixStack.top();
                prefixStack.pop();
            }
            // push the current character into the stack
            prefixStack.push(exp[i]);
        }
    }   

    // popping out all the remaining characters from the stack, if any
    while (!prefixStack.empty()) {
        prefix += prefixStack.top();
        prefixStack.pop();
    }
    prefix = reverseStr(prefix);
    return prefix;
}

int main() {
    string exp = "(a+d)*(b+c)";
    cout << "Prefix Expression: " << preFixExpression(exp);

    return 0; 
}
