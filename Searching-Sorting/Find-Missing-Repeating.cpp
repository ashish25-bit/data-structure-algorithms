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

    vector<int> hashMap(n+1, 0);
    int f=-1, s=-1;
    
    for (int i=0; i<n; i++)
        ++hashMap[arr[i]];
        
    for (int i=1; i<=n; i++) {
        if (f==-1 && hashMap[i] == 0) 
            f = i;
            
        if (s==-1 && hashMap[i] == 2) 
            s = i;
            
        if (s != -1 && f != -1)
            break;
    }

    cout << "Repeating: " s << " Missing: " << f; 

    return 0;
}
