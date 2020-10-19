/**
 * Input: 
 0 1 0 0 1 2 0 1
 * Output: 
 0 0 0 0 1 1 1 2        
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

    int count0 = 0,
        count1 = 0,
        count2 = 0;

    for (int val: arr) {
        if (val == 0)
            count0++;
        else if (val == 1)
            count1++;
        else if (val == 2)
            count2++;
    }

    int pointer = 0;
    while (count0--)
        arr[pointer++] = 0;
    while (count1--)
        arr[pointer++] = 1;
    while (count2--)
        arr[pointer++] = 2;

    cout << "The Sorted Array is: " << endl;
    printArray(arr);

    return 0;
}
