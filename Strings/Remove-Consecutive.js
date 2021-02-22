function removeConsecutiveCharacter(S) {
    let res = "";
    let prev = "";
    
    for (let i = 0; i < S.length; i++) {
        if (prev == S[i])
            continue;
        prev = S[i];
        res = res + S[i];
    }
    return res;
}

function main() {
    const s1 = ["aab", "aabb", "aaabbb", "aaaabbcccaa"];
    s1.forEach(s => console.log(`${s} : ${removeConsecutiveCharacter(s)}`) );
}

main();