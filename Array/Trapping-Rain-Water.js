function main() {
  // const arr = [3, 0, 0, 2, 0, 4];
  const arr = [8, 2, 4, 5, 5, 1];
  // const arr = [7, 4, 0, 9];
  // const arr = [6, 9, 9];

  let leftMax = [];
  let rightMax = [];

  let currMax = arr[0];

  for (let i=0; i<arr.length; i++) {
    if (arr[i] < currMax)
      leftMax.push(currMax);
    else {
      leftMax.push(-1);
      currMax = arr[i];
    }
  }

  currMax = arr[arr.length - 1];
  for (let i=arr.length - 1; i >= 0; i--) {
    if (arr[i] < currMax)
      rightMax.push(currMax);
    else {
      rightMax.push(-1);
      currMax = arr[i];
    }
  }

  rightMax.reverse();

  console.log(leftMax);
  console.log(rightMax);

  let ans = 0;

  for (let i=0; i<arr.length; i++) {
    if (rightMax[i] !== -1 && leftMax[i] !== -1)
      ans = ans + Math.min(leftMax[i], rightMax[i]) - arr[i];
  }

  console.log(ans);
}

main();
