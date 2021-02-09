// const exp = ["a", "ab", "a|b", "a*"];

// exp.forEach(expression => {
//     const sp = expression.split("");
    
//     // if only one operand
//     if (sp.length === 1) 
//         console.log(`For expression ${expression}: 0 ${sp[0]} 1`);
    
//     // a|b
//     else if (sp.includes('|')) {
//         let state = 1;

//         let str1 = `0 e ${state} ${sp[0]} ${state + 1}`;
//         state = state + 2;
//         let str2 = `0 e ${state} ${sp[2]} ${state + 1}`;
//         state = state + 2;

//         str1 = str1 + " e " + state;
//         str2 = str2 + " e " + state;

//         console.log(`For expression ${expression}: ${str1} ${str2}`);
//     }

//     // a*
//     else if (sp.includes('*')) {
//         let startState = 0;
//         let endState = 0;

//         let str = `${startState++} e ${startState++} ${sp[0]} ${startState++} e ${startState}`;

//         endState = startState;
//         startState = 0;

//         str = `${str} ${startState} e ${endState} ${endState - 1} e ${startState + 1}`
//         console.log(`For expression ${expression}: ${str}`);
//     }

//     // ab
//     else if (sp.length == 2) {
//         let state = 0;
//         console.log(`For expression ${expression}: ${state++} ${sp[0]} ${state++} ${sp[1]} ${state}`);
//     }

//     else 
//         console.log('invalid expression')
// })

// let nums = [];
// for (let i = 1; i<=9; i++) {
//     for (let j = 1; j<=9; j++) {
//         const num = 10 * i + j;
//         nums.push(num);
//     }
// }

// for (let num of nums) {
//     let tempNum = num;
//     let b = tempNum % 10;
//     let a = Math.floor(tempNum / 10);

//     // all the values for d
//     for (let i = 1; i <= 9; i++) {
//         let prod = num * (10 * i + b);
        
//         if (prod > 999)
//             break;
        
//         if (!(prod % 111)) {
//             let c = prod / 111;
//             console.log(`a: ${a} b : ${b} c: ${c} d: ${i}`);
//             break;
//         }
//     }

// }