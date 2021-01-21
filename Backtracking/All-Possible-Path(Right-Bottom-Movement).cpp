#include <bits/stdc++.h>
using namespace std;

bool isValid(vector< vector<int>> a, int i, int j, int m, int n, vector< vector<bool>> visited) {
    return i >= 0 && j >= 0 && i < m && i < n && !visited[i][j];
}

void paths(vector< vector<int>> a, int i, int j, int m, int n, vector< vector<bool>> visited, vector< vector<int>> &res, vector<int> c_path) {

    if (!isValid(a, i, j, m, n, visited)) return;

    c_path.push_back(a[i][j]);
    if (i == m-1 && j == n-1) {
        res.push_back(c_path);
        return;
    }

    visited[i][j] = true;

    // go right
    paths(a, i+1, j, m, n, visited, res, c_path);

    // go bottom
    paths(a, i, j+1, m, n, visited, res, c_path);

    visited[i][j] = false;
    return;
}

int main() {

    vector< vector<int>> a = {
        {1, 2, 3},
        {4, 5, 6}
    };

    vector< vector<bool>> visited(a.size(), vector<bool> (a[0].size(), false));
    vector< vector<int>> res;

    paths(a, 0, 0, a.size(), a[0].size(), visited, res, {});

    for (vector<int> v: res) {
        for (int x: v)
            cout << x << " ";
        cout << endl;
    }
    return 0;
}