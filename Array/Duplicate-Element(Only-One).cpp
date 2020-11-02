/**
 * Test Case 1:
 * Input: 
 1 2 2 5 3 3
 * Output: 
 Duplicate Element: 2
 * 
 * Test Case 2:
 * Input: 
 1 2 4 3 5
 * Output: 
 No Duplicate element   
 */

#include <iostream>
#include <vector>
using namespace std;

void printArray(vector<int> arr) {
    for (int i=0; i<arr.size(); i++)
        cout << arr[i] << " ";
    cout << endl;
}

int getDuplicate(vector<int> arr) {
    // creating hash table
    vector<int> hs(arr.size(), 0);

    for (int x: arr) {
        if (hs[x])
            return x;
        else
            hs[x] = 1;
    }
    return 0;
}

int main() {
    int n, key, temp;
    vector<int> arr;
    cin >> n;

    cout << "Enter " << n << " values for array 1:\n";
   for (int i=0; i<n; i++) {
        cin >> temp;
        arr.push_back(temp);
   }


    cout << "Array: ";
    printArray(arr);
    int res = getDuplicate(arr);
    res ? cout << "Duplicate Element: " << res : cout << "No Duplicate Element";

    return 0;
}
