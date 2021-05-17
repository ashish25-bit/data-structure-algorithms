function getConnectedNodes(arr, current, visited) {
  if (visited[current]) return "";

  visited[current] = true;
  let str = current;

  for (let i=0; i < arr[current].length; i++) {
    if (arr[current][i] != 0 && i != current) {
      let temp = getConnectedNodes(arr, i, visited);
      
      if (temp != "") str = str + "-" + temp;
    }
  }

  return str; 
}

function countGroups(arr) {
  let current = 0;
  let count = 0;
  let N = arr.length;
  
  let visited = new Array(N).fill(false);

  while (current < N) {
    if (visited[current]) {
      current++;
      continue;
    }

    console.log(getConnectedNodes(arr, current, visited));
    count++;
    current++;
  }

  return count;
}

function main() {
  const arr = [
    [1, 1, 0, 0],
    [1, 1, 1, 0],
    [0, 1, 1, 0],
    [0, 0, 0, 1]
  ];

  // const arr = [
  //   [1, 0, 0, 0],
  //   [0, 1, 1, 0],
  //   [0, 1, 1, 1],
  //   [0, 0, 1, 1]
  // ];
  
  // const arr = [
  //   [1, 1, 0],
  //   [0, 1, 1],
  //   [0, 1, 1],
  // ];

  console.log(countGroups(arr));
}
main();