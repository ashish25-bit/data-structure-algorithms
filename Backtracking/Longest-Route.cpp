#include <bits/stdc++.h>
using namespace std;
#define MAX 5

bool isValid(vector< vector<int>> a, int i, int j, vector< vector<bool>> visited) {
    return i >= 0 && j >=0 && i < a.size() && j < a[0].size() && a[i][j] == 1 && !visited[i][j];
}

int shortestPath(vector< vector<int>> a, int i, int j, int x, int y, vector< vector<bool>> visited) {

    if (!isValid(a, i, j, visited)) return -1000000;

    if (i == x && j == y) return 0;

    visited[i][j] = true;

    int left   = shortestPath(a, i, j-1, x, y, visited) + 1;
    int right  = shortestPath(a, i, j+1, x, y, visited) + 1;
    int top    = shortestPath(a, i-1, j, x, y, visited) + 1;
    int bottom = shortestPath(a, i+1, j, x, y, visited) + 1;

    visited[i][j] = false;

    return max( max(left, right), max(top, bottom) );
}

int main() {
    
    vector< vector<int>> a = {
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 0, 1, 1, 0, 1, 1, 0, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
    };


    vector< vector<bool>> visited(a.size(), vector<bool> (a[0].size(), false));
    cout << shortestPath(a, 0, 0, 1, 7, visited);

    return 0;
}
