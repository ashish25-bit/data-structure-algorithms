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

int findMedian(vector<int> arr1, vector<int> arr2) {
    int i=0;
    int j=0;
    int count = arr1.size()-1;

    while (count--) {
        if (arr1[i] < arr2[j])
            i++;
        else if (arr1[i] > arr2[j])
            j++;
        else if (arr1[i] == arr2[j]) {
            i++;
            j++;
        }
    }

    return (arr1[i] + arr2[j]) / 2;
}

int main() {
    int n;
    cout << "Enter value for n \t";
    cin >> n;

    vector<int> arr1 = inputArray(n);
    vector<int> arr2 = inputArray(n);

    cout << findMedian(arr1, arr2);
    return 0;
}

