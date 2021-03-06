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

    vector<int> arr = inputArray(n);
    vector<int> res;

    for (int i=0; i<n; i++) {
        if (i+1 == arr[i]) 
            res.push_back(arr[i]);
    }

    if (res.size()) 
        printArray(res);
    else 
        cout << "No Fixed Point";

    return 0;
}
