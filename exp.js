const readline = require('readline');
const epsilon = '#';

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

function regexToNFA(expression) {
    const sp = expression.split("");
        
    // if only one operand
    if (sp.length === 1) 
        return `0 ${sp[0]} 1` ;
    
    // a|b
    else if (sp.includes('|')) {
        let state = 1;

        let str1 = `0 ${epsilon} ${state} ${sp[0]} ${state + 1}`;
        state = state + 2;
        let str2 = `0 ${epsilon} ${state} ${sp[2]} ${state + 1}`;
        state = state + 2;

        str1 = str1 + " " + epsilon + " " + state;
        str2 = str2 + " " + epsilon + " " + state;

        return `${str1} ${str2}`;
    }

    // a*
    else if (sp.includes('*')) {
        let startState = 0;
        let endState = 0;

        let str = `${startState++} ${epsilon} ${startState++} ${sp[0]} ${startState++} ${epsilon} ${startState}`;

        endState = startState;
        startState = 0;

        str = `${str} ${startState} ${epsilon} ${endState} ${endState - 1} ${epsilon} ${startState + 1}`
        return `${str}`;
    }

    // ab
    else if (sp.length == 2) {
        let state = 0;
        return `${state++} ${sp[0]} ${state++} ${sp[1]} ${state}`;
    }

    else 
        return 'invalid expression';
}

function isAlpha(char) {
    if (char >= 'a' && char <= 'z')
        return true;

    return false;
}

function isValidState(exp, index) {
    const left = index - 1;
    const right = index + 1;

    if (left >= 0) {
        if (isAlpha(exp[left]))
            return true;
    }
    
    if (right < exp.length) {
        if (isAlpha(exp[right]))
            return true;
    }

    return false;
}

function NFAtoDFA(exp) {
    let DFA = "";
    // splitting the expression and obtaining all the characters in an array
    exp = exp.split(' ');
    /**
     * FOR example: 
     * exp = 0 # 1 a 2 # 3 0 # 3 2 # 1
     * exp = ["0", "#", "1", "a", "2", "#", "3", "0", "#", "3", "2", "#", "1"]
     */
    
    exp.forEach((char, index) => {
        // if the character is an alphabet add to DFA
        if (isAlpha(char))
            DFA = DFA + char + " ";

        else {
            if (char !== epsilon) {
                if (isValidState(exp, index))
                    DFA = DFA + char + " ";
            }
        }
    })
    
    return DFA.trim();
}

// main function
async function main() {
    let exp = await input(readlineInterface, "Enter the expression: ");

    const NFA = regexToNFA(exp);
    console.log(`NFA: ${NFA}`);

    if (NFA !== "invalid expression")
        console.log(`DFA: ${NFAtoDFA(NFA)}`);

    readlineInterface.close();
}
main();
