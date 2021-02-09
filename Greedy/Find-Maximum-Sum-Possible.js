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

function maxSum(stack1, stack2, stack3) {
    let sum1 = stack1.reduce((a, b) => a + b, 0);
    let sum2 = stack2.reduce((a, b) => a + b, 0);
    let sum3 = stack3.reduce((a, b) => a + b, 0);
    
    let top1 = 0;
    let top2 = 0;
    let top3 = 0;

    while (top1 < stack1.length && top2 < stack2.length && top3 < stack3.length) {

        if (sum1 === sum2 && sum2 === sum3)
            return sum1;

        if (sum1 > sum2 && sum1 > sum3) {
            sum1 = sum1 - stack1[top1];
            top1++;
        }

        else if (sum2 > sum1 && sum2 > sum3) {
            sum2 = sum2 - stack2[top2];
            top2++;
        }

        else {
            sum3 = sum3 - stack3[top3];
            top3++;
        }

    }
    
    return 0;
}

async function main() {
    // // stack 1
    const s1 = await input(readlineInterface, "Enter size of stack 1: ");
    const stack1 = await inputArray(s1, 0);

    // stack 2
    const s2 = await input(readlineInterface, "Enter size of stack 2: ");
    const stack2 = await inputArray(s2, 0);

    // stack 3
    const s3 = await input(readlineInterface, "Enter size of stack 3: ");
    const stack3 = await inputArray(s3, 0);

    console.log(maxSum(stack1, stack2, stack3));
    readlineInterface.close();
}
main();