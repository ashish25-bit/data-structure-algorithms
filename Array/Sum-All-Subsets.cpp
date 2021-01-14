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

void subsetSum(vector<int> a, int l, int h, int sum, vector<int> &res) {
    if (l > h) {
        res.push_back(sum);
        return;
    }

    // include in the subarray
    subsetSum(a, l+1, h, sum + a[l], res);

    // exclude
    subsetSum(a, l+1, h, sum, res);

}

int main() {
    int n;
    cout << "Enter value for n: \t";
    cin >> n;

    vector<int> arr = inputArray(n);
    vector<int> res;

    subsetSum(arr, 0, n-1, 0, res);
    printArray(res);

    return 0;
}
