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

int findLongestConseqSubseq(vector<int> arr) {
    int N = arr.size();

    unordered_map<int, int> hashMap;
    int res = 0;

    for (int i=0; i<N; i++)
        hashMap[arr[i]]++;

    for (int i=0; i<N; i++) {

        int element = arr[i];

        if (hashMap.find(element - 1) == hashMap.end()) {
            int count = 0;
            while (hashMap.find(element) != hashMap.end() && ++count)
                element++;

            res = max(res, count);
        }
    }

    return res;
}

int main() {
    int n;
    cout << "Enter value for n: \t";
    cin >> n;
    vector<int> arr = inputArray(n);

    cout << findLongestConseqSubseq(arr);

    return 0;
}
