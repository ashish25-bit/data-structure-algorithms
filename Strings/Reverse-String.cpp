#include <iostream>
using namespace std;

int main() {
    string s;
    cout << "Enter string";
    cin >> s;

    int start = 0;
    int last = s.length()-1;
    
    cout << "Input String" << s << endl;

    while (start <= last) {
        // swapping
        char ch = s[start];
        s[start] = s[last];
        s[last] = ch;
    
        start++;
        last--;
    }
    
    cout << "Reversed String: " << s;
    return 0;
}