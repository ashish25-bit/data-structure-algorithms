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

int findDiff(vector<int> arr, int k) {
    unordered_map<int, int> hashMap;

    for (int x: arr)
        hashMap[x]++;

    for (int x: arr) {
        int num = x >= k ? x - k : k + x;

        if (hashMap.find(num) != hashMap.end())
            return 1;
    }

    return -1;
}

int main() {
    int n, k;
    cout << "Enter value for n and k: \t";
    cin >> n >> k;

    vector<int> arr = inputArray(n);

    cout << findDiff(arr, k);
    return 0;
}
