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

function sumTriplet(a, X) {
    let n = a.length;

    // sort the array
    a.sort((n1, n2) => { return n1 - n2 });

    // boundary variables
    let currentIndex = 0;
    let leftPointer = currentIndex + 1;
    let rightPointer = n-1;
     
    while (currentIndex < n-2) {
        if (leftPointer >= rightPointer) {
            currentIndex++;
            leftPointer = currentIndex + 1;
            rightPointer = n-1;
        }

        let currentSum = a[currentIndex] + a[leftPointer] + a[rightPointer];

        if (currentSum > X) rightPointer--;

        else if (currentSum < X) leftPointer++;

        else return true;
    }

    return false;
}

// main function
async function main() {
    const n = await input(readlineInterface, "Enter a value for n: ");
    let array = await inputArray(n, 0);
    let X = await input(readlineInterface, "Enter the value of sum needed to searched: ")
    X = parseInt(X);

    console.log(sumTriplet(array, X));
    readlineInterface.close();
}
main();