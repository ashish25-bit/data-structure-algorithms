#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> PI;
//        index, value
class Solution {
    private:
    struct comparator {
        bool operator() (PI p1, PI p2) {
            return p1.second > p2.second;
        }
    };
    public:
    //Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int K) {
        priority_queue<PI, vector<PI>, comparator> minHeap;
        vector<int> index(K, 1);
        vector<int> res;
        
        for (int i=0; i < K; i++) {
            minHeap.push(make_pair(i, arr[i][0]));
        }
        
        while (!minHeap.empty()) {
            PI top = minHeap.top();
            minHeap.pop();
            
            res.push_back(top.second);
            
            if (index[top.first] >= K) continue;
            
            minHeap.push(make_pair(top.first, arr[top.first][index[top.first]]));
            index[top.first]++;
        }
        return res;
    }
};

int main() {
  vector<vector<int>> arr = {
    {1,2,3,4},
    {2,2,3,4},
    {5,5,6,6},
    {7,8,9,9}
  };

  Solution ob;

  for (int x: ob.mergeKArrays(arr, arr.size())) {
      cout << x << " ";
  }
  return 0;
}