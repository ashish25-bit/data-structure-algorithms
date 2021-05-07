function mergeArray(arr, start, mid, end) {
  let length1 = mid - start + 1;
  let length2 = end - mid;

  let leftSubarray = [];
  let rightSubarray = [];

  for (let i=0; i<length1; i++)
    leftSubarray.push(arr[start + i]);

  for (let i=0; i<length2; i++)
    rightSubarray.push(arr[mid + 1 + i]);

  let i=0, j=0, currIndex = start;
  let inversions = 0;

  while (i < length1 && j < length2) {
    if (leftSubarray[i] > rightSubarray[j]) {
      arr[currIndex] = rightSubarray[j];
      inversions = inversions + length1 - i;
      j++;
    }
    else {
      arr[currIndex] = leftSubarray[i];
      i++;
    }
    currIndex++;
  }

  while (i < length1) arr[currIndex++] = leftSubarray[i++]
  while (j < length2) arr[currIndex++] = rightSubarray[j++]

  return inversions;
}

function mergeSort(arr, start, end) {
  if (start >= end) return 0;

  let mid = start + Math.floor((end - start)/2);
  let leftInversion = mergeSort(arr, start, mid);
  let rightInversion = mergeSort(arr, mid+1, end);
  let inversion = mergeArray(arr, start, mid, end);

  return leftInversion + rightInversion + inversion;
}

function countInversions(arr) {
  return mergeSort(arr, 0, arr.length - 1);
}

function main() {
  let arr = [5, 4, 3, 2, 1];
  console.log(countInversions(arr));
  console.log(arr)
}

main();
