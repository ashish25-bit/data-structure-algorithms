function isPalindrome(str) {

    const len = str.length;

    if (len == 0)
        return false;
    
    if (len == 1)
        return true;

    let i = 0;
    let j = len-1;

    while (i <= j) {
        if (str[i] !== str[j])
            return false;
        i++;
        j--;
    }

    return true;
}

function findPalindromes(str, position, word, sen, res) {

    if (position === str.length) {
        if (sen !== "")
            res.unshift(sen);
        return;
    }

    word = word + str[position];
    position++;

    if (isPalindrome(word)) {
        findPalindromes(str, position, word, sen, res);

        sen = sen + " " + word;
        word = "";

        findPalindromes(str, position, word, sen, res);
    }

    else findPalindromes(str, position, word, sen, res);
}

function main() {
    const str = "nitin";
    let res = [];

    findPalindromes(str, 0, "", "",res);
    res.forEach(ele => console.log(ele));
}

main();