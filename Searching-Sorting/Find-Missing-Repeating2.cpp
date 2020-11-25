#include <iostream>
#include <vector>
using namespace std;

void printArray(vector<int> arr) {
    for (int i=0; i<arr.size(); i++)
        cout << arr[i] << " ";
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
    cout << "Enter values for n \t";
    cin >> n;

    vector<int> a = inputArray(n);

    int duplicate;
    int missing;

    for (int i=0; i<n; i++) {
        int numP = abs(a[i]);
        if (a[numP - 1] < 0)
            duplicate = abs(a[i]);
        else 
            a[numP-1] = -a[numP-1];
    }
    
    for (int  i=0; i<n ;i++) {
        if (a[i] > 0) {
            missing = i + 1;
            break;
        }
    }

    cout << "Repeating: " << duplicate << " Missing: " << missing;

    return 0;
}
