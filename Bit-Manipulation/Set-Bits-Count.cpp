#include <bits/stdc++.h>
using namespace std;

int setBits(int n) {
    int count = 0;
    while (n) {
        if (n & 1)
            count++;
        n = n >> 1;
    }
    return count;
}

int main() {
    int n;
    cout << "Enter value for n: ";
    cin >> n;

    cout << "Set bits count: " << setBits(n);

    return 0;
}