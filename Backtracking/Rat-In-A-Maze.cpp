/**
 * TIME LIMIT EXCEEDED IN GEEKS FOR GEEKS 
*/

bool isValid(int m[MAX][MAX], int n, int i, int j, vector< vector<bool>> visited) {
    return i >= 0 && j >=0 && i < n && j < n && m[i][j] == 1 && !visited[i][j];
}

// m -> matrix
// n -> number of rows and columns
// i -> current row
// j -> current column
// x -> destination row
// y -> destination column
// visited -> visited nodes status
// res -> contains the result
// str -> current path string
void findPath(int m[MAX][MAX], int n, int i, int j, int x, int y, 
vector< vector<bool>> visited, vector<string> &res, string str) {
    
    if (!isValid(m, n, i, j, visited)) return;

    if (i == x && j == y) {
        res.push_back(str);
        return;
    }
    
    visited[i][j] = true;
    
    // go bottom
    findPath(m, n, i+1, j, x, y, visited, res, str + "D");
    
    // go left
    findPath(m, n, i, j-1, x, y, visited, res, str + "L");
    
    // go right
    findPath(m, n, i, j+1, x, y, visited, res, str + "R");
    
    // go top
    findPath(m, n, i-1, j, x, y, visited, res, str + "T");
    
    visited[i][j] = false;
}

vector<string> findPath(int m[MAX][MAX], int n) {
    vector<string> res;
    
    vector< vector<bool>> visited(n, vector<bool> (n, false));
    
    findPath(m, n, 0, 0, n-1, n-1, visited, res, "");
    
    return res;
}