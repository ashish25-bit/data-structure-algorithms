function isPalindrome(str) {

    const len = str.length;

    if (len == 0)
        return false;
    
    if (len == 1)
        return true;

    let i = 0;
    let j = len-1;

    while (i < j) {
        if (str[i] !== str[j])
            return false;
        i++;
        j--;
    }

    return true;
}

function countCharacters(str) {
    let count = 0;
    for (let char of str) {
        if ((char >= 'a' && char <= 'z') || (char >= 'A' && char <= 'Z')) 
            count++;
    }

    return count;
}

/**
 * 
 * @param {string} str: input string
 * @param {number} position: current position in the sentence
 * @param {string} word: current word formed till position
 * @param {string} sen: sentence formed with word
 * @param {list} res: result sentences
 */
function findPalindromes(str, position, word, sen, res) {

    if (position === str.length) {
        if (sen !== "" && countCharacters(sen) === str.length)
            res.unshift(sen.trim());
        return;
    }

    // adding the current letter to the current word
    word = word + str[position];
    position++;
    
    // continue adding words
    findPalindromes(str, position, word, sen, res);
    if (isPalindrome(word)) {

        sen = sen + " " + word;
        word = "";

        findPalindromes(str, position, word, sen, res);
    }
}

function main() {
    const str = "aab";
    let res = [];

    findPalindromes(str, 0, "", "",res);
    res.forEach(ele => console.log(ele));
}

main();