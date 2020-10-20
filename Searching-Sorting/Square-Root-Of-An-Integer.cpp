/**
 * Input: 
 101
 * Output: 
 10
 */

#include<bits/stdc++.h>
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

// this method has complexity of O(log N)
int logN_Answer(int n) {
    return int(sqrt(n));
}

// this has the complexity of O(_/n)
int rootN_Answer(int n) {
    if (n == 0 || n == 1)
        return n;
    int count = 1;
    int start = 1;
    while (start <= n) {
        count++;
        start = count*count;
    }
    return count-1;
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    cout << "O(log n) Complexity: " << logN_Answer(n) << endl;
    cout << "O(_/n) Complexity: " << rootN_Answer(n);
    return 0;
}