#include <iostream>
using namespace std;

void change(int *x) { *x = *x + 10; }

int main() {
    int a = 10;
    cout << "Before passing to the function: " << a << endl;
    change(&a);
    cout << "After passing to the function: " << a;

    return 0;
}