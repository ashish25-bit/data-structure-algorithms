// Find position of set bit
function setBitPosition(num) {
    // if the number(>0) has more than one set bit num & (num - 1) will not be equal to 0.
    if (num == 0 || num & (num - 1))
        return -1;
    
    let count = 0;
    while (num) {
        num = num >> 1;
        count++;
    }

    return count;
}

function main() {
    let nums = [1, 2, 3, 4, 5];

    for (let num of nums) {
        console.log(`${num}: ${setBitPosition(num)}`);
    }
}

main();
