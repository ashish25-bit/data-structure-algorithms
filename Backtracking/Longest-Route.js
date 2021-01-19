function isValid(a, visited, i, j) {
    return i >= 0 && j >= 0 && i < a.length && j < a[0].length && a[i][j] == 1 && !visited[i][j];
}

function longestPath(a, visited, i, j, x, y) {

    // if i or j is not within constraints
    if (!isValid(a, visited, i, j)) return 10000;

    if (i == x && j == y) return 0;

    visited[i][j] = true;
    let left = longestPath(a, visited, i, j-1, x, y) + 1;
    let right = longestPath(a, visited, i, j+1, x, y) + 1;
    let top = longestPath(a, visited, i-1, j, x, y) + 1;
    let bottom = longestPath(a, visited, i+1, j, x, y) + 1;
    visited[i][j] = false;
    
    return Math.min(
        Math.min(left, right),
        Math.min(top, bottom)
    );
}

function main() {

    // const a = [
    //     [1, 1, 1, 1, 1, 1, 1, 1, 1, 1], 
    //     [1, 1, 0, 1, 1, 0, 1, 1, 0, 1], 
    //     [1, 1, 1, 1, 1, 1, 1, 1, 1, 1]
    // ];

    const a = [
        [1, 1, 1, 1, 1, 0, 0, 1, 1, 1],
        [0, 1, 1, 1, 1, 1, 0, 1, 0, 1],
        [0, 0, 1, 0, 1, 1, 1, 0, 0, 1],
        [1, 0, 1, 1, 1, 0, 1, 1, 0, 1],
        [0, 0, 0, 1, 0, 0, 0, 1, 0, 1],
        [1, 0, 1, 1, 1, 0, 0, 1, 1, 0],
        [0, 0, 0, 0, 1, 0, 0, 1, 0, 1],
        [0, 1, 1, 1, 1, 1, 1, 1, 0, 0],
        [1, 1, 1, 1, 1, 0, 0, 1, 1, 1]
    ];

    let temp = new Array(a[0].length).fill(false);
    let visited = [];

    [...Array(a.length).keys()].map(() => visited.push(temp));

    console.log(longestPath(a, visited, 0, 0, 8, 0));
}

main();
