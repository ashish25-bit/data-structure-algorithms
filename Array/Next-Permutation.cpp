/**
 * The idea here is: 
 * find the largest index(mark) where arr[i-1] < arr[i].
 * if mark = -1 that means array was sorted in descending order. sort the array in ascending and return.
 * swap tbe elements at mark and idx.
 * reverse the array from index mark + 1 to end and return.
 */ 

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

vector<int> reverseNums(vector<int> a, int i, int j) {
    while (i < j) {
        int temp = a[i];
        a[i] = a[j];
        a[j] = temp;
        i++;
        j--;
    }
    return a;
}

vector<int> nextPermutation(vector<int> nums) {

    // find the largest index(mark) where arr[i-1] < arr[i]
    int mark = -1;
    for (int i = nums.size() - 1; i > 0; i--) {
        if (nums[i] > nums[i - 1]) {
            mark = i - 1;
            break;
        }
    }

    // if mark = -1 that means array was sorted in descending order
    // sort the array in ascending and return
    if (mark == -1) {
        nums = reverseNums(nums, 0, nums.size() - 1);
        return nums;
    }

    // find a largest index(idx) where arr[idx] > arr[mark]
    // the condition is the index(idx) should be greater than mark
    int idx = nums.size()-1;
    for (int i = nums.size()-1; i >= mark+1; i--) {
        if (nums[i] > nums[mark]) {
            idx = i;
            break;
        }
    }

    // swap tbe elements at mark and idx
    int temp = nums[mark];
    nums[mark] = nums[idx];
    nums[idx] = temp;

    // reverse the array from index mark + 1 to end and return.
    return reverseNums(nums, mark + 1, nums.size() - 1);
}

int main() {
    int n;
    cout << "Enter value for n: \t";
    cin >> n;
    vector<int> arr = inputArray(n);

    arr = nextPermutation(arr);
    printArray(arr);

    return 0;
}