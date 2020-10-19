/**
 * Input: 
 2 3 11 1 4 5
 * Output: 
 Max Element = 11
 Min Element = 1         
 */

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, temp;
    cin >> n;
    vector<int> arr;

    for (int i=0; i<n; i++) {
        cin >> temp;
        arr.push_back(temp);
    }

    int minElem = arr[0];
    int maxElem = arr[0];

    for (int num: arr) {
        minElem = num < minElem ? num : minElem;
        maxElem = num > maxElem ? num : maxElem;
    }

    cout << "Max Element = " << maxElem;
    cout << "\nMin Element = " << minElem;

    return 0;
}
