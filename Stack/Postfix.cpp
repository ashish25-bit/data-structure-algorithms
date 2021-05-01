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

bool isAlpha(char ch) {
    return ch >= 'a' && ch <= 'z';
}

string postFixExpression(string exp) {
    stack<char> postfixStack;
    string postfix = "";

    for (int i = 0; i < exp.length(); i++) {
        if (exp[i] == ' ') continue;

        // if the character is an alphabet add to the expression
        if (isAlpha(exp[i])) postfix += exp[i];

        // if the character is an opening bracket push it to the stack
        else if (exp[i] == '(') postfixStack.push(exp[i]);
        
        // if the character is a closing bracket
        else if (exp[i] == ')') {
            // pop from stack and add to the result expression until '(' is encountered
            while (!postfixStack.empty() && postfixStack.top() != '(') {
                postfix += postfixStack.top();
                postfixStack.pop();
            }
            // pop the opening bracket
            postfixStack.pop();
        }

        // if it's an operator
        else {
            // pop from the stack until top has greater or equal precedence than the current character
            // OR stack is empty
            while (!postfixStack.empty() && precedence(exp[i]) <= precedence(postfixStack.top())) {
                postfix += postfixStack.top();
                postfixStack.pop();
            }
            // push the current character into the stack
            postfixStack.push(exp[i]);
        }
    }

    // popping out all the remaining characters from the stack, if any
    while (!postfixStack.empty()) {
        postfix += postfixStack.top();
        postfixStack.pop();
    }
    return postfix;
}

int main() {
    // string exp = "(a+b) *c-d";
    string exp = "a*b/c";
    // string exp = "(a+d)*(b+c)";
    cout << "Postix Expression: " << postFixExpression(exp);

    return 0; 
}
