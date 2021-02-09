function countCharacters(str) {
    let count = 0;
    for (let char of str) {
        if ((char >= 'a' && char <= 'z') || (char >= 'A' && char <= 'Z')) 
            count++;
    }

    return count;
}

/**
 * @param {string} sentence: the input sentence
 * @param {int} pos: the current position in the sentence
 * @param {string} word: the current word
 * @param {string} sen: the current sentence formed
 * @param {array} res: the result of sentences
 * @param {map} hashMap: the dict
 */
function wordBreak(sentence, pos, word, sen, res, hashMap) {

    // reached the end
    if (pos == sentence.length) {
        if (sen !== "" && countCharacters(sen) == sentence.length)
            res.push(sen.trim());
        return;
    }

    
    // adding the current letter to the current word
    word = word + sentence[pos];
    pos++;

    // continue adding to the current word
    wordBreak(sentence, pos, word, sen, res, hashMap);

    if (hashMap.has(word)) {

        // add the formed current word to the current sentence
        sen = sen + " " + word;
        word = "";
        wordBreak(sentence, pos, word, sen, res, hashMap);
    }
}

function main() {
    const sentence = "snakesandladder";
    const dict = ["snake", "snakes", "and", "sand", "ladder"];

    // const sentence = "snksnd";
    // const dict = ["snk", "snks", "snd", "nd"];

    // const sentence = "ilikeicecreamandmango";
    // const dict = ["i", "like", "sam", "sung", "samsung", "mobile", "ice", "and", "cream", "icecream", "man", "go", "mango"]

    // const sentence = "hcdarlrm";
    // const dict = ["lr", "m", "lrm", "hcdar", "wk"];

    let hashMap = new Map();

    dict.forEach(ele => hashMap.set(ele, 1));
    let res = [];

    wordBreak(sentence, 0, "", "", res, hashMap);
    console.log(res);
}

main();