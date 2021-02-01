#include <bits/stdc++.h>
using namespace std;

vector<int> inputArray(int n) {
    int temp;
    vector<int> arr;
    cout << "Enter " << n << " values for array:\n";
    for (int i=0; i<n; i++) {
        cin >> temp;
        arr.push_back(temp);
    }
   return arr;
}

void heapify(vector<int> &arr, int n, int i) {
    int root = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    // FOR MIN HEAP
    // ARR[left] < ARR[ROOT]
    if (left < n && arr[left] > arr[root])
        root = left;

    // FOR MIN HEAP
    // ARR[R] < ARR[ROOT]
    if (right < n && arr[right] > arr[root])
        root = right;

    if (root != i) {
        swap(arr[i], arr[root]);
        heapify(arr, n, root);
    }
}

void buildHeap(vector<int> &arr, int n) {
    int i = (n / 2) - 1;

    for (; i >= 0; i--)
        heapify(arr, n, i);
}

int main() {
    int n;
    cout << "Enter the value of n:\t";
    cin >> n;

    vector<int> arr = inputArray(n);

    buildHeap(arr, n);

    for (int i=0; i<n; i++)
        cout << arr[i] << " ";
// 1 3 5 4 6 13 10 9 8 15 17
    return 0;
}
