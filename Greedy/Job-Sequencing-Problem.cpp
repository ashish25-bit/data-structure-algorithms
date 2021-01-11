// STRUCTURE DEFINITION
// struct Job {
//     int dead;
//     int profit;
// };

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