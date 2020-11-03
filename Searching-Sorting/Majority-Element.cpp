/**
 THIS QUES IS SIMILAR TO THE QUESTION -> NUMBER FREQUENCY GREATER THAN N/K
 In that ques all the elements whose frequency is greater than n/k is required, so we use a hash map resulting in O(n) extra space.
 In this question we can also use hash map but there is no need to use it because there will be only one element whose frequency will be greater than n/2.
 So we don't unnecessarily need to have O(n) extra space.
 We can use an algorithm known as Voting Majarity Candidate. In this no extra space is required.
 */

#include<bits/stdc++.h>
using namespace std;

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

int findCandidate(vector<int> arr) {
    int maj_index = 0, count =1;

    for (int i=1; i<arr.size(); i++) {
        if (arr[maj_index] == arr[i])
            count++;
        else
            count--;

        if (count == 0) {
            count = 1;
            maj_index = i;
        }
    }

    return arr[maj_index];
}

int isMajority(vector<int> arr, int c) {
    int len = arr.size();
    int count = 0;

    for (int x: arr) {
        if (x == c)
            count++;
    }
    if (count > len/2)
        return 1;
    return 0;
}

int main() {

    int n;
    cout << "Enter value of n: \n";
	cin >> n;
	vector<int> arr = inputArray(n);

	int candidate = findCandidate(arr);

	if (isMajority(arr, candidate))
        cout << "Majority Element: " << candidate;
    else
        cout << "No Majority Element";

    return 0;
}
