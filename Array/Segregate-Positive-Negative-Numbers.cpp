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

int main() {
    int n;
    cout << "Enter value for n: \t";
    cin >> n;

    vector<int> arr = inputArray(n);

    int prevElement = 0;

    for (int i=0; i<arr.size(); i++) {
        if (arr[i] < 0) {
            if (i != prevElement) {
                int t = arr[prevElement];
                arr[prevElement] = arr[i];
                arr[i] = t;
            }
            prevElement++;
        }
    }

    cout << "After Rearranging: ";
    if (prevElement == 0 || prevElement == 1 || prevElement == n)
        printArray(arr);

    else {
        int i=1;
        while (prevElement<n && arr[i]<n) {
            swap(arr[prevElement], arr[i]);
            prevElement++;
            i=i+2;
        }
        printArray(arr);
    }
    return 0;
}
