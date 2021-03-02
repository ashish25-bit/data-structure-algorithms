function countEqualSubstrings(str) {
    let count = 0;
    let count_0 = 0;
    let count_1 = 0;
    let curr = "";

    for (let c of str.split('')) {
        if (c == '1') count_1++;
        else count_0++;

        curr = curr + c;
        
        if (count_0 == count_1) {
            console.log(curr);
            count_0 = 0;
            count_1 = 0;
            curr = ""
            count++;
        }
    }
    return count;
}

function main() {
    const str = ["0100110101", "0111100010"];
    str.forEach(s => console.log(countEqualSubstrings(s)));
}
main();