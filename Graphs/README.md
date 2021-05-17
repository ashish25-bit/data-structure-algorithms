* __[CONNECTED GROUPS](https://github.com/ashish25-bit/data-structure-algorithms/blob/master/Graphs/Connected-Groups.js)__

    Given an undirected graph [as an adjacent matrix].
    1 is connected to 2(2 connected to 1 since it is an undirected graph) therefore 1-2 make a group.
    The nodes follow the property of transitivity. 
    That is if 1 is connected 2 and 2 is connected to 3 then 1 and 3 will also considered connected.
    Making 1-2-3 as a group. 
    You have to find total number of unique groups.

    ```Javascript
    Input:
    [
      [1, 0, 0, 0],
      [0, 1, 1, 0],
      [0, 1, 1, 1],
      [0, 0, 1, 1]
    ]
    Output: 2
    The unique pairs will be 1-2-3, 0
    ```
<br