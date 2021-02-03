int *mergeKArrays(int arr[][N], int k) {
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int *res = new int[k*k];
    int i=0;
    
    for (int i=0; i<k; i++) {
        for (int j=0; j<k; j++)
            minHeap.push(arr[i][j]);
    }
    
    while (!minHeap.empty()) {
        res[i] = minHeap.top();
        minHeap.pop();
        i++;
    }
    
    return res;
}