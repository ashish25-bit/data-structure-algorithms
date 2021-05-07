#include <bits/stdc++.h>
using namespace std;

bool comparator(vector<int> i1, vector<int> i2) {
    return (i1[1] < i2[1]);
}

void maxMeetings(int start[], int end[], int n) {
    vector<vector<int>> timings;

    for (int i=0; i<n; i++) {
        timings.push_back({ start[i], end[i], i+1 });
    }

    sort(timings.begin(), timings.end(), comparator);
    cout << timings[0][2] << " ";
    int end_time = timings[0][1];
    
    for (int i=1; i<n; i++) {
        vector<int> e = timings[i];
        
        if (e[0] > end_time) {
            cout << e[2] << " ";
            end_time = e[1];
        }
    }
}

int main() {
    int start[] = {1, 3, 0, 5, 8, 5};
    int end[]   = {2, 4, 6, 7, 9, 9};
    int n = sizeof(start) / sizeof(start[0]);

    maxMeetings(start, end, n);
    
    return 0;
}
