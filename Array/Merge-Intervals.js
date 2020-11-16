const readline = require('readline');

const readlineInterface = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

// input function
function input(readlineInterface, question) {
    return new Promise(resolve => {
            readlineInterface.question(question, answer => {
            resolve(answer)
        })
    })
}

// input arrauy function
async function inputArray(n, type) {
    let array = await input(readlineInterface, `Enter ${n} values for array: `);

    switch (type) {
        case 0:
            return array.split(' ').map(num => { return parseInt(num) });
    
        default:
            break;
    }
}

// main function
async function main() {
    const n = await input(readlineInterface, "Enter a value for n: ");
    let array = [];

    for (let i=0; i<n; i++) {
        const temp = await inputArray(2, 0);
        array.push(temp);
    }

    const merged = mergeIntervals(array);
    console.log(merged);

    readlineInterface.close();
}
main();

function mergeIntervals(arr) {
    // sort the array with respect to the lower value in the interval i.e. a[0] 
    arr.sort((a, b) => a[0] - b[0]);

    let stack = [arr[0]];

    for (let i = 1; i < arr.length; i++) {
        let top = stack[stack.length - 1];

        if (isOverlapping(arr[i], top)) {
            stack.pop();
            let max = top[1] >= arr[i][1] ? top[1] : arr[i][1];
            stack.push([top[0], max]);
        }
        else {
            stack.push(arr[i]);
        }
    }

    return stack;
}

function isOverlapping(a, b) {
    if (a[0] <= b[0] && a[1] >= b[0])
        return true;

    if (a[0] >= b[0] && a[1] <= b[1])
        return true;

    if (a[0] >= b[0] && a[0] <= b[1])
        return true;

    return false;
}