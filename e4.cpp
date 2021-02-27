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
        // if the character is an alphabet add to the expression
        if(isAlpha(exp[i])) prefix += exp[i];

        // if the character is a closing bracket push it to the stack
        else if(exp[i] == ')') prefixStack.push(exp[i]);

        // if the character is an opening bracket
        else if(exp[i] == '(') {
            // pop from stack and add to the result expression until ')' is encountered
            while(!prefixStack.empty() && prefixStack.top() != ')') {
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
            while(!prefixStack.empty() && precedence(exp[i]) < precedence(prefixStack.top())) {
                prefix += prefixStack.top();
                prefixStack.pop();
            }
            // push the current character into the stack
            prefixStack.push(exp[i]);
        }
    }   

    // popping out all the remaining characters from the stack, if any
    while(!prefixStack.empty()) {
        prefix += prefixStack.top();
        prefixStack.pop();
    }
    prefix = reverseStr(prefix);
    return prefix;
}

string postFixExpression(string exp) {
    stack<char> postfixStack;
    string postfix = "";

    for(int i = 0; i < exp.length(); i++) {

        // if the character is an alphabet add to the expression
        if(isAlpha(exp[i])) postfix += exp[i];

        // if the character is an opening bracket push it to the stack
        else if(exp[i] == '(') postfixStack.push(exp[i]);
        
        // if the character is a closing bracket
        else if(exp[i] == ')') {
            // pop from stack and add to the result expression until '(' is encountered
            while(!postfixStack.empty() && postfixStack.top() != '(') {
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
            while(!postfixStack.empty() && precedence(exp[i]) <= precedence(postfixStack.top())) {
                postfix += postfixStack.top();
                postfixStack.pop();
            }
            // push the current character into the stack
            postfixStack.push(exp[i]);
        }
    }

    // popping out all the remaining characters from the stack, if any
    while(!postfixStack.empty()) {
        postfix += postfixStack.top();
        postfixStack.pop();
    }
    return postfix;
}

int main() {
    string exp = "a*(b+c)";
    cout << "Postix Expression: " << postFixExpression(exp) << endl;
    cout << "Prefix Expression: " << preFixExpression(exp);

    return 0; 
}
