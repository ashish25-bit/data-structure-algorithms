#include<bits/stdc++.h>
using namespace std;

void frequencycount(vector<int>& arr, int n) {
    // code here
    for (int i=0; i<n; i++)
        arr[i] = arr[i] * (n+1);
    
    for (int i=0; i<n; i++) {
        int d = arr[i]/(n+1);
        arr[d-1] = arr[d-1] + 1;
    }
    
    for (int i=0; i<n; i++) 
        arr[i] = arr[i] % (n+1);
}

int main() {
    int n;
    cin >> n; 
	    
	vector<int> arr(n,0);
	    
    for(int i=0; i<n; i++)
        cin >> arr[i]; 

    frequencycount(arr,n); 
		
    for (int i =0; i<n; i++) 
        cout << arr[i] << " ";

	return 0; 
}