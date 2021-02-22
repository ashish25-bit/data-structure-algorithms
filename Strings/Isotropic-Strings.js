function status(str1, str2) {
    let charHash = new Map();
    let boolMap = new Map();

    for (let i=0; i<str1.length; i++) {
        let c1 = str1[i];
        let c2 = str2[i];

        if (charHash.has(c1)) {
            if (charHash.get(c1) != c2)
                return false;
        }

        else {
            if (boolMap.has(c2))
                return false;
            charHash.set(c1, c2);
            boolMap.set(c2, false);
        }
    }
    return true;    
}

function main() {
    
    const s1 = ["aab", "xudzhi", "pijthbsfy", "rfkqyuqf"];
    const s2 = ["xxy", "ftakcz", "fvladzpbf", "jkxyqvnr"];

    for (let i=0; i<s1.length; i++)
        console.log("For %s, %s: %s",s1[i], s2[i], status(s1[i], s2[i]))
}

main();