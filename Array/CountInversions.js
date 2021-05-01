function mergeArray(arr, start, mid, end) {
  let index1 = mid - start + 1;
  let index2 = end - mid;

  let leftSubarray = [];
  let rightSubarray = [];

  for (let i=0; i<index1; i++)
    leftSubarray.push(arr[start + i]);

  for (let i=0; i<index2; i++)
    rightSubarray.push(arr[mid + 1 + i]);

  let i=0, j=0, currIndex = start;
  let inversions = 0;

  while (i < index1 && j < index2) {
    if (leftSubarray[i] > rightSubarray[j]) {
      arr[currIndex] = rightSubarray[j];
      inversions = inversions + index1 - i;
      j++;
    }
    else {
      arr[currIndex] = leftSubarray[i];
      i++;
    }
    currIndex++;
  }

  while (i < index1) arr[currIndex++] = leftSubarray[i++]
  while (j < index2) arr[currIndex++] = rightSubarray[j++]

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
