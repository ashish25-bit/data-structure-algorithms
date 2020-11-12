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

int b(vector<int> a, int start, int end, int k, int type) {
    int last = -1;

    while (start <= end) {
        int mid = start + (end - start)/2;

        if (a[mid] == k) {
            last = mid;

            if (!type)
                end = mid - 1;
            else
                start = mid + 1;
        }

        else if (a[mid] < k)
            start = mid + 1;

        else if (a[mid] > k)
            end = mid - 1;
    }

    return last;
}

int main() {
    int n, k;
    cout << "Enter value for n and k: \t";
    cin >> n >> k;

    vector<int> arr = inputArray(n);

    int low = b(arr, 0, n-1, k, 0);
    int high = b(arr, 0, n-1, k, 1);

    if (low == -1 || high == -1)
        cout << "-1";
    else
        cout << low << " " << high;

    return 0;
}

