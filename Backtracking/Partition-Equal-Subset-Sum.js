function equalPartition(N, arr) {

    let sum = arr.reduce((sum , n) => sum + n);
    return sum % 2 == 0 && partition(N, arr, sum/2, 0);
}

function partition(N, arr, sum, i) {
    if (i >= N || sum < 0) return 0;
    
    if (sum == 0) return 1;
    
    let include = partition(N, arr, sum - arr[i], i+1);
    if (include) return 1;
    
    return partition(N, arr, sum, i+1);
}

function main() {
    const arr = [1, 5, 11, 5];
    const N = arr.length;

    console.log(equalPartition(N, arr) ? "YES" : "NO");
}

main();