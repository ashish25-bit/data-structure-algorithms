#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> IP;

string getKey(int row, int col) {
  return to_string(row) + "-" + to_string(col);
}

bool isValid(int rows, int cols, vector<vector<int>> image, int rootColor, unordered_set<string> visited, int x, int y) {
  string key = getKey(x, y);
  return x >= 0 && y >= 0 && 
        x < rows && y < cols &&
        visited.find(key) == visited.end() &&
        image[x][y] == rootColor;
} 

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
  int rows = image.size();
  int cols = image[0].size();

  queue<IP> q;
  q.push(make_pair(sr, sc));

  unordered_set<string> visited;
  string key = getKey(sr, sc);
  visited.insert(key);

  vector<vector<int>> arr = image;
  int rootColor = image[sr][sc];

  while (!q.empty()) {
    IP curr = q.front();
    q.pop();
    
    int x = curr.first;
    int y = curr.second;
    
    arr[x][y] = newColor;
    
    // top
    if (isValid(rows, cols, image, rootColor, visited, x-1, y)) {
      q.push(make_pair(x - 1, y));
      string key = getKey(x-1, y);
      visited.insert(key);
    }
    
    // bottom
    if (isValid(rows, cols, image, rootColor, visited, x+1, y)) {
      q.push(make_pair(x+1, y));
      string key = getKey(x+1, y);
      visited.insert(key);
    }
    
    // right
    if (isValid(rows, cols, image, rootColor, visited, x, y+1)) {
      q.push(make_pair(x, y+1));
      string key = getKey(x, y+1);
      visited.insert(key);
    }
    
    // left
    if (isValid(rows, cols, image, rootColor, visited, x, y-1)) {
      q.push(make_pair(x, y-1));
      string key = getKey(x, y-1);
      visited.insert(key);
    }
  }
    
  return arr;
}

int main() {
  vector<vector<int>> arr = {
    {1,1,1},
    {1,1,0},
    {1,0,1}
  };

  int sr = 1, sc = 1, newColor = 2;
  
  vector<vector<int>> res = floodFill(arr, sr, sc, newColor);

  for (vector<int> t: res) {
    for (int x: t) cout << x << " ";
    cout << endl;
  }
  
  return 0;
}
