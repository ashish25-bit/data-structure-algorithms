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

function kthElement(a, b, k) {
    let j = 0, i = 0;
    let element = Math.min(a[i], b[j]);
    
    while (--k) {

        if (i < a.length && j < b.length) {
            if (a[i] >= b[j])
                j++;
            else
                i++;
            
            if (i < a.length && j < b.length)
                element = Math.min(a[i], b[j]);
            else {
                element = -1;
                if (i < a.length)
                    element = a[i];
                else if (j < b.length)
                    element = b[j];
            }
        }

        else {
            if (i < a.length) {
                i++;
                element = a[i];
            }
            
            else if (j < b.length) {
                j++;
                element = b[j];
            }
        }
    }
    return element
}

// main function
async function main() {
    const n = await input(readlineInterface, "Enter a value for n: ");
    const m = await input(readlineInterface, "Enter a value for m: ");
    const k = await input(readlineInterface, "Enter a value for k: ");
    let a = await inputArray(n, 0);
    let b = await inputArray(m, 0);

    console.log(kthElement(a, b, k));

    readlineInterface.close();
}
main();