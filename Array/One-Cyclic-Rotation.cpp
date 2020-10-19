/**
 * Input:
 1 2 3 4 5
 * Output:
 5 1 2 3 4
 */

#include <iostream>
#include <vector>
using namespace std;

void printArray(vector<int> arr) {
    for (int n: arr)
        cout << n << " ";
    cout << endl;
}

int main() {
    int n, temp;
    cin >> n;
    vector<int> arr;

    for (int i=0; i<n; i++) {
        cin >> temp;
        arr.push_back(temp);
    }

    cout << "The Array is: " << endl;
    printArray(arr);

    int last = arr[arr.size()-1];
    auto it = arr.begin();
    arr.insert(it, last);
    arr.pop_back();
    cout << "The Array After One Rotation: " << endl;
    printArray(arr);
    return 0;
}
