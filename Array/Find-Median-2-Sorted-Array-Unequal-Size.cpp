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

int findMedian(vector<int> arr1, vector<int> arr2) {
    int n = arr1.size();
    int m = arr2.size();
    int i = 0;
    int j = 0;
    int prev = 0;
    int count = (m + n) / 2;

    // if the total number is odd.
    if ((m+n) % 2) {
        while (count--) {
            if (i != n and j != m) {
                if (arr1[i] < arr2[j])
                    i++;
                else if (arr1[i] > arr2[j])
                    j++;
                else {
                    i++;
                    j++;
                }
            }

            else if (i < n)
                i++;
            else if (j < m)
                j++;
        }
        if (i != n && j != m)
            return min(arr1[i], arr2[j]);

        if (i < n)
            return arr1[i];

        return arr2[j];
    }

    int m2 = -1;
    int m1 = -1;
    count += 1;
    while (count--) {
        m2 = m1;

        if (i != n && j != m)
            m1 = arr1[i] > arr2[j] ? arr2[j++] : arr1[i++];

        else if (i < n)
            m1 = arr1[i++];

        else if (j < m)
            m1 = arr2[j++];
    }

    return (m1+m2)/2;
}

int main() {
    int n, m;
    cout << "Enter value for n and m:\t";
    cin >> n >> m;

    vector<int> arr1 = inputArray(n);
    vector<int> arr2 = inputArray(m);

    cout << findMedian(arr1, arr2);
    return 0;
}

