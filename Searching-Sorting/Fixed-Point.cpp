/**
 * Test Case 1:
 * Input: 
 -1 0 2 4 5 
 * Output: 
 Fixed Point is 2
 *
 * Test Case 2
 * Input: 
 -1 0 3 5 6
 * Output: 
 No Fixed Point
 */

#include <iostream>
#include <vector>
using namespace std;

void printArray(vector<int> arr) {
    for (int i=0; i<arr.size(); i++)
        cout << arr[i] << " ";
    cout << endl;
}

int fixedPoint(vector<int> arr, int low, int high) {
    if (low <= high) {
        int mid = low + (high-low)/2;
        if (mid == arr[mid])
            return mid;
        if (mid > arr[mid])
            return fixedPoint(arr, mid+1, high);
        return fixedPoint(arr, low, mid-1);
    }
    return -1;
}

int main() {
    int n, temp;
    vector<int> arr;
    cin >> n;

    cout << "Enter " << n << " values for array 1:\n";
   for (int i=0; i<n; i++) {
        cin >> temp;
        arr.push_back(temp);
   }

    cout << "Array: ";
    printArray(arr);

    int res = fixedPoint(arr, 0, arr.size()-1);
    if (res == -1)
        cout << "No Fixed Point";
    else
        cout << "Fixed Point is: " << res;

    return 0;
}
