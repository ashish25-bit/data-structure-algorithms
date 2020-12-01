const readline = require('readline');

const readLineInterface = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

// input function
function input(readLineInterface, question) {
    return new Promise(resolve => {
        readLineInterface.question(question, answer => {
            resolve(answer)
        })
    })
}

// input array function
async function inputArray(n, type) {
    let array = await input(readLineInterface, `Enter ${n} values for array: `);

    switch (type) {
        case 0:
            return array.trim().split(' ').map(num => { return parseInt(num) });
    
        default:
            break;
    }
}

function findMax(a, b, c) {
    if (a >= b && a >= c)
        return a;
    if (b >= a && b >= c)
        return b;
    return c;
}

function findMin(a, b, c) {
    if (a <= b && a <= c)
        return a;
    if (b <= a && b <= c)
        return b;
    return c;
}

function maxProduct(a) {
    let maxproduct = a[0];
    let currentMaxPositive = a[0];
    let currentMinNegative = a[0];

    for (let i=1; i<a.length; i++) {
        if (a[i] == 0) {
            currentMaxPositive = 1;
            currentMinNegative = 1;
            continue
        }

        let temp = currentMaxPositive;
        // currentMaxPositive = Math.max(a[i], currentMaxPositive * a[i], currentMinNegative * a[i]);
        // currentMinNegative = Math.min(a[i], temp * a[i], currentMinNegative * a[i]);
        currentMaxPositive = findMax(a[i], currentMaxPositive * a[i], currentMinNegative * a[i]);
        currentMinNegative = findMin(a[i], temp * a[i], currentMinNegative * a[i]);

        if (maxproduct < currentMaxPositive)
            maxproduct = currentMaxPositive;
    }

    return maxproduct;
}

async function main() {
    const n = await input(readLineInterface, "Enter a value for n: ");
    let array = await inputArray(n, 0);

    console.log(maxProduct(array))
    readLineInterface.close();
}
main();