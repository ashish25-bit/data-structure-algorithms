// https://practice.geeksforgeeks.org/problems/chocolate-distribution-problem3825/1

#include <bits/stdc++.h>
using namespace std;

vector<int> inputArray(int n) {
    int temp;
    vector<int> arr;
    for (int i=0; i<n; i++) {
        cin >> temp;
        arr.push_back(temp);
    }
   return arr;
}

int main() {
	int t, n, m;
	cin >> t;
	
	while (t--) {
	    cin >> n;
	    vector<int> arr = inputArray(n);
	    cin >> m;
	    
	    sort(arr.begin(), arr.end());
	    
	    int min = INT_MAX;
	    
	    for (int i=0; i+m-1<n; i++) {
	        int j = i + m -1;
	        
	        int diff = arr[j] - arr[i];
	        if (min > diff) 
	            min = diff;
	    }
        cout << min << endl;
	}
	
	return 0;
}