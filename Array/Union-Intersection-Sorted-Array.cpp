/**
 * Input: 
 arr1: 1, 2, 2, 2, 4, 5, 6
 arr2: 2, 2, 3, 5, 7
 * Output:
 Union Array: 1 2 3 4 5 6 7
 Intersection Array: 2 5

 * ONLY APPLICABLE IF THE ARRAY IS SORTED.
 */

#include <iostream>
#include <vector>
#include<unordered_set>
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
    unordered_set<int> hs;

    while (i<n && j<m) {
        if (arr1[i] < arr2[j]) {
            if (hs.find(arr1[i]) == hs.end()) {
                unionArray.push_back(arr1[i]);
                hs.insert(arr1[i]);
            }
            i++;
        }
        else if (arr1[i] > arr2[j]) {
            if (hs.find(arr2[j]) == hs.end()) {
                unionArray.push_back(arr2[j]);
                hs.insert(arr2[j]);
            }
            j++;
        }
        else {
            if (hs.find(arr1[i]) == hs.end()) {
                unionArray.push_back(arr1[i]);
                hs.insert(arr1[i]);
            }
            i++;
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
    
    unordered_set<int> hs;    
    vector<int> interArray;

    while (i<n && j<m) {
        if (arr1[i] < arr2[j])
            i++;
        else if (arr1[i] > arr2[j])
            j++;
        else {
            if (hs.find(arr1[i]) == hs.end()) {
                interArray.push_back(arr1[i]);
                hs.insert(arr1[i]);
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