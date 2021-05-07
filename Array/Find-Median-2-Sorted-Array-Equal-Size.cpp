#include<bits/stdc++.h>
using namespace std;

void printArray(vector<int> arr) {
    for (int x: arr)
        cout << x << " ";
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

    int e1 = arr1[i];
    int e2 = arr2[j];

    if (i == arr1.size() - 1)
        e1 = min(e1, arr2[j+1]);
    
    if (j == arr2.size() - 1)
        e2 = min(e2, arr1[i+1]);

    return (e1 + e2) / 2;
}

int main() {
    vector<int> arr2 = {1, 2, 5};
    vector<int> arr1 = {3, 4, 6};
    cout << findMedian(arr1, arr2); 
    return 0;
}

