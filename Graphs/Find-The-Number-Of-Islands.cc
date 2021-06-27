// https://practice.geeksforgeeks.org/problems/find-the-number-of-islands/1

#include <bits/stdc++.h>
using namespace std;


class Solution {
  private:
  int rows;
  int cols;
  vector<vector<bool>> visited;

  bool isValid(vector<vector<char>> &arr, int i, int j) {
    return i >= 0 && j >=0 &&
          i < rows && j < cols &&
          arr[i][j] == '1' && !visited[i][j];
  }

  void printVisited() {
    for (vector<bool> arr: visited) {
      for (bool x: arr) cout << x << " ";
      cout << endl;
    }
  }
  
  void markVisited(vector<vector<char>> &arr, int i, int j) {
    if (!isValid(arr, i, j)) return;

    visited[i][j] = true;

    // go top
    markVisited(arr, i-1, j);
    
    // go bottom
    markVisited(arr, i+1, j);

    // go left
    markVisited(arr, i, j-1);

    // go right
    markVisited(arr, i, j+1);

    // go top-left-diagonal
    markVisited(arr, i-1, j-1);

    // go top-right-diagonal
    markVisited(arr, i-1, j+1);

    // go bottom-left-diagonal
    markVisited(arr, i+1, j-1);

    // go bottom-right-diagonal
    markVisited(arr, i+1, j+1);
  }

  public:
  int numIslands(vector<vector<char>> &arr) {
    rows = arr.size();
    cols = arr[0].size();

    vector<bool> temp(cols, false);

    for (int i=0; i < rows; i++) {
      visited.push_back(temp);
    }
    
    int count = 0;
    for (int i=0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
        // if the element in '0' then continue
        if (arr[i][j] == '0') continue;

        // if the nodes is already visited then continue
        if (visited[i][j]) continue;

        markVisited(arr, i, j);
        count++;
        printVisited();
      }
    }

    return count;
  }
};


int main() {
  vector<vector<char>> arr = {
    {'0', '1', '1', '1', '0', '0', '0'},
    {'0', '0', '1', '1', '0', '1', '0'}
  };

  // vector<vector<char>> arr = {
  //   {'0', '1'},
  //   {'1', '0'},
  //   {'1', '1'},
  //   {'1', '0'}
  // };
  
  Solution ob;
  cout << ob.numIslands(arr);
  
  return 0;
}
