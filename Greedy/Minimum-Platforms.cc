#include <bits/stdc++.h>
using namespace std;

bool compare(vector<int> a, vector<int> b) {
  return a[0] < b[0];
}

int count(vector<int> arrival, vector<int> dept, int n) {
  vector<vector<int>> arr;
  for (int i=0; i < n; i++) {
    arr.push_back({arrival[i], dept[i]});
  }

  sort(arr.begin(), arr.end(), compare);

  vector<int> time;
  time.push_back(arr[0][1]);

  for (int i=1; i < n; i++) {
    int a_time = arr[i][0];
    int d_time = arr[i][1];
    bool added = false;

    for (int j=0; j < time.size(); j++) {
      if (time[j] < a_time) {
        time[j] = d_time;
        added = true;
        break;
      }
    }

    if (!added)
      time.push_back(d_time);
  }

  return time.size();
}

int main() {
  vector<int> arrival   = {900, 940, 950, 1100, 1500, 1800};
  vector<int> departure = {910, 1200, 1120, 1130, 1900, 2000};

  cout << count(arrival, departure, arrival.size());
  return 0;
}
