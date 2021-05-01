function BS(arr, key) {
  let start = 0;
  let end = arr.length - 1;
  let ans;
  
  while (start <= end) {
    let mid = start + Math.floor((end - start) / 2);
    if (arr[mid] <= key) {
      ans = mid;
      start = mid + 1;
    }
    
    else if (arr[mid] > key) end = mid - 1;
  }

  return ans;
}

function main() {
  const arr = [5, 10, 15, 20, 25, 28, 30];
  const key = 11;

  const ans = BS(arr, key);
  console.log(ans, arr[ans]);
}

main();