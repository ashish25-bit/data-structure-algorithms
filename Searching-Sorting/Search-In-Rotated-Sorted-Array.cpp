/**
 * Input: 
 5 4 3 2 1
 4
 * Output: 
 Element 4 found at position 2
 */

#include <iostream>
#include <vector>
using namespace std;

void printArray(vector<int> arr) {
    for (int i=0; i<arr.size(); i++)
        cout << arr[i] << " ";
    cout << endl;
}

int bs(vector<int> arr, int low, int high, int key) {
    if (low <= high) {
        int mid = low + (high-low)/2;
        if (arr[mid] == key)
            return mid;
        if (arr[mid] < key)
            return bs(arr, low, mid-1, key);
        return bs(arr, mid+1, high, key);
    }
    return -1;
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

   cout << "Enter the element you want to search\n";
   cin >> key;
    int res = bs(arr, 0, arr.size()-1, key);
    if (res == -1)
        cout << "Element " << key << " is not present";
    else
        cout << "Element " << key << " is found at position " << res+1;

    return 0;
}