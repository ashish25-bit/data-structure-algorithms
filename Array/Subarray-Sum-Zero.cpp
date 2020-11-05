#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

string sum0(vector<int> a) {
    int sum = 0;
    unordered_map<int, int> hashMap;

    for (int i=0; i<a.size(); i++) {
        sum += a[i];

        if (sum == 0 || hashMap.find(sum) != hashMap.end())
            return "Yes";
        hashMap[sum]++;
    }
    return "No";
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
	int n, testCases;
	cout << "Enter the value of n:\t";
    cin >> n;

    vector<int> arr = inputArray(n);

    cout << sum0(arr) << endl;

	return 0;
}
