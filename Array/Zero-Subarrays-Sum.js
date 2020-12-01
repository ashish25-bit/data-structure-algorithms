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

// input array function
async function inputArray(n, type) {
    let array = await input(readlineInterface, `Enter ${n} values for array: `);

    switch (type) {
        case 0:
            return array.split(' ').map(num => { return parseInt(num) });
    
        default:
            break;
    }
}

function zeroSubarrays(array) {
    let map = new Map();
    map.set(0, 1);
    let sum = 0;
    let count = 0;

    for (const num of array) {
        sum = sum + num;
        let temp = map.get(sum);

        if (temp != undefined) {
            count = count + temp;
            map.set(sum, temp+1);
        }
        else
            map.set(sum, 1);
    }

    return count; 
}

// main function
async function main() {
    const n = await input(readlineInterface, "Enter a value for n: ");
    let array = await inputArray(n, 0);

    console.log(zeroSubarrays(array));

    readlineInterface.close();
}
main();

// 6 -1 -3 4 -2 2 4 6 -12 -7