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

int findMedian(vector<int> v) {
    int n = v.size();
    sort(v.begin(), v.end());

    if (n % 2)
        return v[n/2];

    return (v[n/2] + v[n/2 -1]) / 2;
}

int main() {
    int n;
    cout << "Enter value for n \t";
    cin >> n;

    vector<int> arr = inputArray(n);

    cout << findMedian(arr);
    return 0;
}

