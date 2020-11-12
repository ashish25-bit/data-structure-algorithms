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

int search(vector<int>& nums, int target) {
    int pos = 0;
    int start;
    int end;

    for (int i=0; i<nums.size()-1; i++) {
        if (nums[i] < nums[i+1])
            pos++;
        else
            break;
    }

    if (nums[pos] == target)
        return pos;

    if (target >= nums[0]) {
        start = 0;
        end = pos;
    }

    else {
        start = pos+1;
        end = nums.size()-1;
    }

    cout << "start: " << start << " end: " << end << endl;

    while (start <= end) {
        int mid = start + (end - start) / 2;

        if (nums[mid] == target)
            return mid;

        if (nums[mid] > target)
            end = mid - 1;

        else if (nums[mid] < target)
            start = mid + 1;
    }

    return -1;
}
// 4 5 6 7 0 1 2

int main() {
    int n, k;
    cout << "Enter value for n and k: \t";
    cin >> n >> k;

    vector<int> arr = inputArray(n);

    int index = search(arr, k);

    cout << index;
    return 0;
}
