function partition(arr, low, high) {
    const pivot = arr[high];
    let index = low - 1;

    for (let j = low; j <= high; j++) {
        if (arr[j] < pivot) {
            index++;
            // swapping elements
            let temp = arr[index];
            arr[index] = arr[j];
            arr[j] = temp;
        }
    }

    let temp = arr[index + 1];
    arr[index + 1] = arr[high];
    arr[high] = temp;

    return index + 1;
}

function quickSelect(arr, low, high, k) {

    if (low < high) {
        let pi = partition(arr, low, high);
    
        console.log(arr);
        console.log(`partition: ${pi}`)
        console.log(`k: ${k}`)
    
        // if (pi === k-1) 
        //     return arr[pi];
            
        quickSelect(arr, low, pi-1, k)
    }
}

function main() {
    const arr = [7, 10, 4, 3, 20, 15];
    const k = 3;
    quickSelect(arr, 0, arr.length - 1, k);
    // console.log(quickSelect(arr, 0, arr.length - 1, k));
    // console.log(arr);
}

main();