#include <bits/stdc++.h>
using namespace std;

// note that if the ending time is equal
// then the meeting which has the smaller index should get the smaller index
bool comparator(vector<int> i1, vector<int> i2) {
    if (i1[1] < i2[1]) return true;
    if (i1[1] > i2[1]) return false;
    if (i1[2] < i2[2]) return true;
    return false;
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

/*
47
86 32 31 98 37 65 98 71 99 58 59 32 52 69 15 75 4 86 57 36 83 18 58 50 43 29 98 53 80 5 89 73 8 97 17 100 9 21 55 55 32 74 60 32 87 72 54
126 112 134 138 89 118 107 124 126 83 133 64 124 109 108 132 111 95 82 106 86 118 82 78 92 55 128 121 118 95 94 110 111 146 124 148 95 146 109 61 93 126 74 76 110 78 91
*/