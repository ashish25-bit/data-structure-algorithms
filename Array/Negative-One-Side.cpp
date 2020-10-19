/**
 * Input
 12 -11 -21 2 -2
 -11 -21 - 2 2 12
 */

#include <iostream>
#include <vector>
using namespace std;

/**
 * IN THIS QUESTION ORDER IS NOT MANDATORY  
 */

void printArray(vector<int> arr) {
    for (int i=0; i<arr.size(); i++)
        cout << arr[i] << " ";
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

    int prevElement = 0;

    for (int i=0; i<arr.size(); i++) {
        if (arr[i] < 0) {
            if (i != prevElement) {
                int t = arr[prevElement];
                arr[prevElement] = arr[i];
                arr[i] = t;
            }
            prevElement++;
        }
    }

    printArray(arr);
    return 0;
}
