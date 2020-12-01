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

function pivotElement(a) {
    let l = 0;
    let h = a.length - 1;

    while (Math.abs(h-l) != 1) {
        let mid = l + Math.floor((h-l) / 2);

        if (a[mid] >= a[l] && a[mid] >= a[h]) 
            l = mid;
        
        else if (a[mid] >= a[l] && a[mid] <= a[h])
            l = mid;

        else if (a[mid] <= a[l] && a[mid] >= a[h])
            h = mid;
        
        else if (a[mid] <= a[l] && a[mid] <= a[h])
            h = mid;
    }

    return Math.max(a[h], a[l]);
}

// main function
async function main() {
    const n = await input(readlineInterface, "Enter a value for n: ");
    let array = await inputArray(n, 0);

    console.log(pivotElement(array));

    readlineInterface.close();
}
main();
