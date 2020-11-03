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

int main() {
    int n, k;
    cout << "Enter number for for number of elements in array: \n";
    cin >> n;

    vector<int> ar = inputArray(n);
    vector<int> res;

    cout << "Enter the value of K: \n";
    cin >> k;

    unordered_map<int, int> hashMap;

    for (int i=0; i<ar.size(); i++)
        hashMap[ar[i]]++;

    k = n/k;

    for (auto it=hashMap.begin(); it!=hashMap.end(); it++) {
        if (it->second > k)
            res.push_back(it->first);
    }

    cout << "Result: ";
    printArray(res);

    return 0;
}
