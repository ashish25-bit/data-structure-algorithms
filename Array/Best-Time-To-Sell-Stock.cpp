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

int maxProfit(vector<int> prices) {
    int n = prices.size();
    if (n == 1 || n == 0)
        return 0;

    int minPosition = 0;
    int profit = 0;

    for (int i=1; i<n; i++) {
        int potentialMaxProfit = prices[i] - prices[minPosition];
        if (potentialMaxProfit > profit)
            profit = potentialMaxProfit;
        else if (potentialMaxProfit < 0)
            minPosition = i;
    }

    return profit;
}

int main() {
    int n;
    cout << "Enter value for n: \t";
    cin >> n;

    vector<int> arr = inputArray(n);

    cout << "Max Profit: " << maxProfit(arr);
    return 0;
}

