#include <bits/stdc++.h>
using namespace std;

void swapNumber(vector<int> &arr, int i1, int i2) {
  int temp = arr[i1];
  arr[i1] = arr[i2];
  arr[i2] = temp;
}

int minSwaps(vector<int>&nums){
  vector<int> arr = nums;
  sort(arr.begin(), arr.end());
  unordered_map<int, int> hashMap;
  int swaps = 0;

  for (int i=0; i<arr.size(); i++)
    hashMap[nums[i]] = i;

  for (int i=0; i<arr.size(); i++) {
    if (arr[i] != nums[i]) {
      swaps++;
      int index = hashMap[arr[i]];
      hashMap[arr[i]] = i;
      hashMap[nums[i]] = index;
      swapNumber(nums, i, index);
    }
  }
  return swaps;
}

int main() {
  vector<int> arr = {10, 19, 6, 3, 5};
  cout << minSwaps(arr);
  
  return 0;
}
