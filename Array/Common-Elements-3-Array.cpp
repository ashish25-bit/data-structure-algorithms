// https://practice.geeksforgeeks.org/problems/common-elements1132/1
/**
 * Input: 
 1, 5, 10, 20, 20, 40, 80
 6, 7, 20, 20, 80, 100
 3, 4, 15, 20, 20, 30, 70, 80, 120
 * Output: 
 Common Elements: 20 20 80
 */

#include <iostream>
#include <vector>
#include <unordered_set>
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

vector<int> getCommon(vector<int> a, vector<int> b, vector<int> c){
    int p = a.size(), q = b.size(), r = c.size();
    int i=0, j=0, k=0;
    vector<int> res = {};
    unordered_set<int> hashSet;

    while (i<p && j<q && k<r) {
        if (a[i] == b[j] && b[j] == c[k]) {
            if (hashSet.find(a[i]) == hashSet.end()) {
                res.push_back(a[i]);
                hashSet.insert(a[i]);
            }
            i++, j++, k++;
            continue;
        }
        
        if (a[i] < b[j])
            i++;
        else if (b[j] < c[k])
            j++;
        else
            k++;
    }
    return res;
}

int main() {
    vector<int> a = {1, 5, 10, 20, 40, 80};
    vector<int> b = {6, 7, 20, 80, 100};
    vector<int> c = {3, 4, 15, 20, 30, 70, 80, 120};

    vector<int> res = getCommon(a, b, c);

    if (!res.size())
        cout << "No Common Elements";
    else {
        cout << "Common Elements: ";
        printArray(res);
    }
    return 0;
}