#include <bits/stdc++.h>
using namespace std;

int main() {
    char c[] = "Hello";
    for (char *p = c; *p != '\0'; p++)
        cout << *p << " ";

    cout << endl;
    string str = "Hello";
    char *p = &str[0];
    while (*p != '\0') cout << *p++ << " ";
    return 0;
}