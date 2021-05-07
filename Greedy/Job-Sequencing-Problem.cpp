#include <bits/stdc++.h>
using namespace std;

struct Job {
    int job_id;
    int dead;
    int profit;
};

bool comparator(Job a, Job b) {
    return (a.profit > b.profit);
}

pair<int,int> JobScheduling(Job arr[], int n) { 
    pair<int, int> ans;
    sort(arr, arr + n, comparator);
    vector<int> res(n+1, -1);
    
    for (int i=0; i<n; i++) {
        int pos = arr[i].dead;
        int profit = arr[i].profit;
        
        for (int j = min(n, pos); j>0; j--) {
            if (res[j] == -1) {
                res[j] = profit;
                break;
            }
        }
    }
    
    int count = 0, sum = 0;
    for (int x: res) {
        if (x != -1) {
            count++;
            sum = sum + x;
        }
    }
    
    ans.first = count;
    ans.second = sum;
    
    return ans;
}

int main() {
    // int n = 4;
    // vector<int> deadline = {4, 1, 1, 1};
    // vector<int> profit =  {20, 10, 40, 30};

    int n = 5;
    vector<int> deadline = {2, 1, 2, 1, 1};
    vector<int> profit =  {100, 19, 27, 25, 15};

    Job arr[n];

    for (int i=0; i < n; i++) {
        arr[i].job_id = i+1;
        arr[i].dead = deadline[i];
        arr[i].profit = profit[i];
    }

    pair<int, int> res = JobScheduling(arr, n);
    cout << res.first << " " << res.second;
    
    return 0;
}
