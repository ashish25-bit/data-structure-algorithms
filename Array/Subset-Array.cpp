#include <bits/stdc++.h>
using namespace std;

int isSubset(int *a1, int n1, int *a2, int n2) {
    
    unordered_map<int, int> hashMap;
        
    for (int i=0; i<n1; i++) 
        hashMap[a1[i]]++;
        
    for (int i=0; i<n2; i++) {
        auto it = hashMap.find(a2[i]);
        if (it == hashMap.end())
            return 0;
    }
    
    return 1;
}

int main() {
	int n1, n2;
    cin >> n1 >> n2;
	    
    int a1[n1];
    int a2[n2];
    
    for (int i=0; i<n1; i++)
        cin >> a1[i];
    
    for (int i=0; i<n2; i++)
        cin >> a2[i];
        
    isSubset(a1, n1, a2, n2) ? cout << "Yes" : cout << "No";
    cout << endl;
	
	return 0;
}