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

function countBitsFlip(a, b) {
    let count = 0;
    let XOR = a ^ b;

    while (XOR) {
        if (XOR & 1)
            count++;
        XOR = XOR >> 1; 
    }

    return count;
}

// main function
async function main() {
    const a = parseInt(await input(readlineInterface, "Enter a value for a: "));
    const b = parseInt(await input(readlineInterface, "Enter a value for b: "));

    console.log(countBitsFlip(a, b));

    readlineInterface.close();
}
main();