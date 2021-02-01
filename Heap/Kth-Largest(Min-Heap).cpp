vector<int> kLargest(int arr[], int n, int k) {
    priority_queue<int, vector<int>, greater<int>> minHeap;
    
    for (int i=0; i < n; i++) {
        minHeap.push(arr[i]);
        
        if (minHeap.size() > k)
            minHeap.pop();
    }
    
    vector<int> res;
    
    while (!minHeap.empty()) {
        res.push_back(minHeap.top());
        minHeap.pop();
    }
    
    reverse(res.begin(), res.end());
    
    return res;
}