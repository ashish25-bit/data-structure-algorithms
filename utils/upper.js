let str = "Special-Stack";
let a = str.split('-');
str = a.map(s => { return s.toUpperCase() }).join(' ');
console.log(str);