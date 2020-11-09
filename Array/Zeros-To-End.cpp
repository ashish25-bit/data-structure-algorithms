#include<bits/stdc++.h>
using namespace std;
#define MAX(a, b) (a > b ? a : b)

void printArray(vector<int> arr) {
    for (int x: arr)
        cout << x << " ";
    cout << endl;
}

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

int main() {
    int n;
    cout << "Enter value for n: \t";
    cin >> n;

    vector<int> arr = inputArray(n);

    int i=0, j=0;

    while (i < n && j < n) {
        if (arr[i] != 0 && arr[j] != 0) {
            i++;
            j++;
            continue;
        }

        if (arr[i] == 0 && arr[j] == 0)
            j++;
        else if (arr[i] == 0 && arr[j] != 0) {
            arr[j] = arr[j] + arr[i];
            arr[i] = arr[j] - arr[i];
            arr[j] = arr[j] - arr[i];
            i++;
            j++;
        }
    }

    cout << "Array After Moving Zeros To End: ";
    printArray(arr);
    return 0;
}