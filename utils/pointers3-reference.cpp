#include <iostream>
using namespace std;

void change(int *x) { *x = *x + 10; }

void change2(int &x) { x = x * 2; }

void swap(int &a, int &b) {
    int t = a;
    a = b;
    b = t;
}

int main() {
    int a = 10;
    cout << "Before passing to the function: " << a << endl;
    change(&a);
    cout << "After passing to the function: " << a;

    int b = 40;
    cout << "\nBefore passing to the function: " << b << endl;
    change2(b);
    cout << "After passing to the function: " << b;

    cout << endl << "a: " << a << " b: " << b << endl;
    swap(a, b);
    cout << "a: " << a << " b: " << b;

    return 0;
}