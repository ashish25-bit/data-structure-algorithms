/**
 * TIME COMPLEXITY: O(N)
 * SPACE COMPLEXITY: O(1)
 */

/**
 * Two Pointer start and end
 * 0 to start -> numbers less than 'a'
 * start to end -> numbers between a and b
 * end to arr.length -> numbers greater than b
 * 
 * start is initialized to '0' and end to 'arr.length - 1'
 * if (arr[i] < a) swap(i, start) i++, start++
 * else if (arr[i] > b) swap(i, end) end--
 * else i++
 */

/**
 * 
 * @param {array} arr 
 * @param {number} lowVal 
 * @param {number} highVal 
 */
function threeWay(arr, lowVal, highVal) {
    let i = 0;
    let start = 0;
    let end = arr.length-1;

    while (i <= end) {

        if (arr[i] < lowVal) {
            let temp = arr[i];
            arr[i] = arr[start];
            arr[start] = temp;
            i++;
            start++;
        }
        
        else if (arr[i] > highVal) {
            let temp = arr[i];
            arr[i] = arr[end];
            arr[end] = temp;
            end--;
        }

        else i++;
    }
}

function main() {
    const arr = [87, 14, 15, 78, 40, 94, 16];
    const lowVal = 36;
    const highVal = 72;

    threeWay(arr, lowVal, highVal);
    console.log(arr)
}
main();