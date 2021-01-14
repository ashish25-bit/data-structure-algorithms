#include<bits/stdc++.h>
using namespace std;

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
    int n;
    cout << "Enter value for n: \t";
    cin >> n;

    vector<int> arr = inputArray(n);
    int sum = 0;


    for (int i=0; i<n; i++) {
        sum += arr[i] * (i+1) * (n-i);
    }
    cout << sum;
    return 0;
}
