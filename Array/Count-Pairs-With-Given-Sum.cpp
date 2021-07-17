// https://practice.geeksforgeeks.org/problems/count-pairs-with-given-sum5022/1

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

// int getPairsCount(vector<int> arr, int k) {
//     unordered_map<int, int> hashMap;
//     int n = arr.size();

//     for (int i=0; i<n; i++)
//         hashMap[arr[i]]++;

//     int count = 0;

//     for (int i=0; i<n; i++) {
//         count = count + hashMap[k - arr[i]];

//         if (k - arr[i] == arr[i])
//             count--;
//     }

//     return count/2;
// }

int getPairsCount(vector<int> arr, int k) {
    unordered_map<int, int> hashMap;
    int count = 0;

    for (int i=0; i < n; i++) {
        int diff = k - arr[i];

        if (hashMap.find(diff) != hashMap.end()) {
            count = count + hashMap[diff];
        }
        hashMap[arr[i]]++;
    }

    return count;
}

int main() {
    int n, k;
    cout << "Enter value for n and k: \t";
    cin >> n >> k;

    vector<int> arr = inputArray(n);

    cout << getPairsCount(arr,k);
    return 0;
}

