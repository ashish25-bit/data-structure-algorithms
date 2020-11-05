#include <iostream>
#include <vector>
using namespace std;
#define MAX(a, b) (a > b ? a : b)

int maximumSubarraySum(vector<int> arr) {
    int currentMaxSum = arr[0];
    int maximumSum = arr[0];
    
    for (int i=1; i<arr.size(); i++) {
        currentMaxSum = MAX(arr[i] + currentMaxSum, arr[i]);
        
        if (currentMaxSum > maximumSum)
            maximumSum = currentMaxSum;
    }
    
    return maximumSum;
}

int main() {
	
	int n, t, testCases;
	cin >> testCases;
	
	while (testCases--) {
    	cin >> n;
    	
    	vector<int> arr;
    	for (int i=0; i<n; i++) {
    	    cin >> t;
    	    arr.push_back(t);
    	}
    	
        cout << maximumSubarraySum(arr) << endl;
	}
	return 0;
}