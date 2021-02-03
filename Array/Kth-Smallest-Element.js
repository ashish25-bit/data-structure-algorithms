function partition(arr, low, high) {
    const pivot = arr[high];
    let index = low;

    for (let j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {

            let temp = arr[index];
            arr[index] = arr[j];
            arr[j] = temp;            
            index++;
        }
    }

    let temp = arr[index];
    arr[index] = arr[high];
    arr[high] = temp; 

    return index;
}

function quickSelect(arr, low, high, k) {

    // value of k is not out of bounds.
    if (k > 0 && k <= high - low + 1) {

        // partition index
        let pi = partition(arr, low, high);
 
        if (pi - low == k - 1)
            return arr[pi];
        
        // for the left subarray
        if (pi - low > k - 1) 
            return quickSelect(arr, low, pi - 1, k);

        // for the right subarray
        return quickSelect(arr, pi + 1, high, k - pi + low - 1);
    }
    
    return Number.MAX_VALUE;
}

function main() {
    const arr = [7, 10, 4, 3, 20, 15];
    const k = 3;
    console.log(quickSelect(arr, 0, arr.length - 1, k));
}

main();