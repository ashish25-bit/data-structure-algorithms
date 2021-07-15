// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/

#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int>& prices) {
  int n = prices.size();
  vector<int> profit(n, 0);

  int currMax = prices[n-1];
  for (int i = n-2; i >= 0; i--) {
      currMax = max(currMax, prices[i]);
      profit[i] = max(profit[i+1], currMax - prices[i]);
  }

  int currMin = prices[0];
  for (int i=1; i < n; i++) {
      currMin = min(currMin, prices[i]);
      profit[i] = max(profit[i-1], profit[i] + prices[i] - currMin);
  }
  return profit[n-1];
}

int main() {
  vector<int> arr = {3, 3, 5, 0, 0, 3, 1, 4};
  cout << maxProfit(arr);

  return 0;
}
