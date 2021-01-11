#include <iostream>
using namespace std;

int smallestSubarrayWithGreaterSum(int a[], int n, int x) {
    int sum = 0;
    int i=0;
    int j=0;
    int res = -1;
    
    while (j < n) {
        sum = sum + a[j];
        
        while (j > i && sum - a[i] > x) {
            sum = sum - a[i];
            i++;
        }
        
        if (sum > x && (res == -1 || res > j - i + 1)) 
            res = j - i + 1;
            
        j++;
    }
    return res;
}

int main() {
	int t, n, x;
	cin >> t;
	
	while (t--) {
	    cin >> n >> x;
	    int a[n];
	    for (int i=0; i<n; i++)
	        cin >> a[i];
	    cout << smallestSubarrayWithGreaterSum(a, n, x) << endl;
	}
	
	return 0;
}