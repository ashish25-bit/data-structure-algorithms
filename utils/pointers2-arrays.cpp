#include <iostream>
using namespace std;

/**
 * Here in the argument, a is not an array it's a pointer to the array
 * Therefore the size of a is = size of integer (in this case)
 * A call by reference is made
 * void sum(int a[]) can be written as void sum(int *p)
 */
void sum(int* a, int n) {
    int size = sizeof(a) / sizeof(a[0]);
    cout << "Size in sum function" << size << endl;

    int i=0;
    int s = 0;
    while (i < n) {
        s = s + *a;
        a++;
        i++;
    }
    cout << s;
}

int main() {
    int a[] = {1, 2, 3, 4, 5};
    for (int i = 0; i < 3; i++) 
        cout << *(a + i) << " ";

    int *p = a;
    cout << "\npointer to array: " << *p << endl;
    p++;
    cout << "pointer to array after incrementing: " << *p << endl;

    // note a++ is invalid
    int size = sizeof(a) / sizeof(a[0]);
    cout << "Size in main function" << size << endl;
    sum(a, size);

    return 0;
}
