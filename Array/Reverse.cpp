/**
 * Input: 
 1 2 3 4 5
 * Output: 
 5 4 3 2 1        
 */

#include <iostream>
#include <vector>
using namespace std;

void printArray(int arr[], int n) {
    for (int i=0; i<n; i++)
        cout << arr[i] << " ";
}

void reverseArray(int arr[], int start, int end) {
    while (start < end) {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

int main() {
    int n;
    cout << "Enter the number of elements\n";
    cin >> n;
    int arr[n];
    cout << "Enter " << n << " numbers for array elements\n";
    for (int i=0; i<n; i++)
        cin >> arr[i];
    cout << "The Array Is: ";
    printArray(arr, n);
    reverseArray(arr, 0, n-1);
    cout << "\nThe Reversed Array Is: ";
    printArray(arr, n);
    return 0;
}