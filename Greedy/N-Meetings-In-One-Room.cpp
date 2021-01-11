bool comparator (vector<int> i1, vector<int> i2) {
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
        
        if (e[0] >= end_time) {
            cout << e[2] << " ";
            end_time = e[1];
        }
    }
}