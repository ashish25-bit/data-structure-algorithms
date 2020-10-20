/**
 * Input: 
 arr1: 1, 2, 2, 4, 5, 6
 arr2: 2, 2, 3, 5, 7
 * Output:
 Union Array: 1 2 2 3 4 5 6 7
 Intersection Array: 2 5
 */

#include <iostream>
#include <vector>
using namespace std;

void printArray(vector<int> arr) {
    for (int i=0; i<arr.size(); i++)
        cout << arr[i] << " ";
    cout << endl;
}

void arrayUnion(vector<int> arr1, vector<int> arr2) {
    int n = arr1.size();
    int m = arr2.size();
    int i=0, j=0;
    vector<int> unionArray;

    while (i<n && j<m) {
        if (arr1[i] < arr2[j])
            unionArray.push_back(arr1[i++]);
        else if (arr1[i] > arr2[j])
            unionArray.push_back(arr2[j++]);
        else {
            unionArray.push_back(arr1[i++]);
            j++;
        }
    }

    // filling up remaining elements
    while (i < n)
        unionArray.push_back(arr1[i++]);
    while (j < m)
        unionArray.push_back(arr2[j++]);
    cout << "Union Array: ";
    printArray(unionArray);
}

void arrayIntersection(vector<int> arr1, vector<int> arr2) {
    int n = arr1.size();
    int m = arr2.size();
    int i=0, j=0;
    
    // consider this constraint
    // 0 <= arr1[i], arr2[i] <= 100
    vector<int> hs(100, 0);
    
    vector<int> interArray;

    while (i<n && j<m) {
        if (arr1[i] < arr2[j])
            i++;
        else if (arr1[i] > arr2[j])
            j++;
        else {
            if (!hs[arr1[i]]) {
                interArray.push_back(arr1[i]);
                hs[arr1[i]] = 1;
            }
            i++;
            j++;
        }
    }

    cout << "Intersection Array: ";
    printArray(interArray);
}

int main() {
    int n, m, temp;
    vector<int> arr1;
    vector<int> arr2;

    cout << "Enter values for m and n";
    cin >> m >> n;

    cout << "Enter " << n << " values for array 1:\n";
    for (int i=0; i<n; i++) {
        cin >> temp;
        arr1.push_back(temp);
    }

    cout << "Enter " << m << " values for array 2:\n";
    for (int i=0; i<m; i++) {
        cin >> temp;
        arr2.push_back(temp);
    }

    cout << "Array 1: ";
    printArray(arr1);
    cout << "Array 2: ";
    printArray(arr2);

    // Union of the array
    arrayUnion(arr1, arr2);

    // intersection array
    arrayIntersection(arr1, arr2);

    return 0;
}