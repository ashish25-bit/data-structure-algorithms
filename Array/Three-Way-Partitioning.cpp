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

vector<int> threeWayPartition(vector<int> A, int a, int b) {
    vector<int> part1;
    vector<int> part2;
    vector<int> part3;

    for (int x: A) {

        if (x < a)
            part1.push_back(x);

        else if (x >= a && x <= b)
            part2.push_back(x);

        else if (x > b)
            part3.push_back(x);
    }

    int pos = 0, i = 0;
    while (i < part1.size()) {
        A[pos] = part1[i];
        pos++;
        i++;
    }

    i=0;
    while (i < part2.size()) {
        A[pos] = part2[i];
        pos++;
        i++;
    }

    i=0;
    while (i < part3.size()) {
        A[pos] = part3[i];
        pos++;
        i++;
    }

    return A;
}


int main() {
    int n, a, b;
    cout << "Enter value for n: \t";
    cin >> n;
    vector<int> arr = inputArray(n);

    cout << "Enter the value for a and b:\t";
    cin >> a >> b;

    cout << "Array Before Modification: ";
    printArray(arr);
    arr = threeWayPartition(arr, a, b);
    cout << "Array After Modification: ";
    printArray(arr);

    return 0;
}
