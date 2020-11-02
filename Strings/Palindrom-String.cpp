#include <iostream>
using namespace std;

bool isPalindrome(string s) {
    int start = 0, lst = s.length()-1;
    while (start <= lst) {
        cout << s[start] << " " << s[lst] << endl;
        if (s[start] != s[lst]) {
            return false;
        }
        start++;
        lst--;
    }
    return true;
}

int main() {

    string s;
    cin >> s;
    isPalindrome(s) ? cout << s << " is palindrome" : cout << s << " is not palindrome";

    return 0;
}