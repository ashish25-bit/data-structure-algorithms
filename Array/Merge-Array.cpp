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
    int n, m;
    cout << "Enter values for n and m: \t";
    cin >> n >> m;

    vector<int> ar1 = inputArray(n);
    vector<int> ar2 = inputArray(m);

    int i=0;
    while (i<n) {
        if (ar1[i] < ar2[0])
            i++;
        else {
            int temp = ar1[i];
            ar1[i] = ar2[0];
            ar2[0] = temp;

            int j, k = ar2[0];

            for (j=1; j<m; j++) {
                if (ar2[j] < k)
                    ar2[j-1] = ar2[j];
                else {
                    ar2[j-1] = k;
                    break;
                }
            }

            if (j == m)
                ar2[m-1] = k;
        }
    }

    cout << "Array 1: ";
    printArray(ar1);
    cout << "Array 2: ";
    printArray(ar2);

    return 0;
}
