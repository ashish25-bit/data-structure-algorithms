#include<bits/stdc++.h>
using namespace std;

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

vector<int> sortN(vector<int> a) {
    int count = a.size();
    int i=0;

    while (count--) {
        if (a[i] == i+1) {
            i++;
            continue;
        }
        int temp = a[a[i] - 1];
        a[a[i] - 1] = a[i];
        a[i] = temp;
    }
    return a;
}

int main() {
    int n;
    cout << "Enter value for n: \t";
    cin >> n;

    vector<int> arr = inputArray(n);
    cout << "Array Before Sorting: ";
    printArray(arr);
    arr = sortN(arr);
    cout << "Array After Sorting: ";
    printArray(arr);
    return 0;
}

