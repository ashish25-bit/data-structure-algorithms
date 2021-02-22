function findSentences(data, row, res, curr_sen) {

    if (row === data.length - 1) {
        for (let i=0; i < data[row].length; i++) 
            res.push(`${curr_sen} ${data[row][i]}`);
        return;
    }
    
    for (let i=0; i < data[row].length; i++) 
        findSentences(data, row + 1, res, curr_sen + " " + data[row][i]);
}

function main() {
    const data = [
        ["you", "we"],
        ["have", "are"],
        ["sleep", "eat", "drink"]
    ];

    let res = [];
    findSentences(data, 0, res, "");
    console.log(res)
}

main();