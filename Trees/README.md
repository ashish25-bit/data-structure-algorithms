* __[FLATTEN BST](https://github.com/ashish25-bit/data-structure-algorithms/blob/master/Trees/Flatten-BST.cc)__

   Given a binary search tree, the task is to flatten it to a sorted list. Precisely, the value of each node must be lesser than the values of all the nodes at its right, and its left node must be NULL after flattening.

    ![Tree](https://media.geeksforgeeks.org/wp-content/uploads/BSTSearch.png)

    ```CPP
    Output: 1 3 4 6 7 8 10 13 14
    ```

<BR/>

* __[HEIGHT OF A TREE](https://github.com/ashish25-bit/data-structure-algorithms/blob/master/Trees/Height.cpp)__

    Given a binary tree, find its height
    n:  the number of nodes to be added.
    arr: the node values  
    ###### NOTE: IN THIS SOLUTION THE NODES WILL BE INSERTED IN LEVEL ORDER FASHION

    ![Tree](https://s3.amazonaws.com/hr-assets/0/1529959649-81b68736f7-lcaexample.png)

    ```CPP
    Output: 4
    ```

<BR/>

* __[LCA BST](https://github.com/ashish25-bit/data-structure-algorithms/blob/master/Trees/LCA-BST.cc)__

    Given a __BINARY SEARCH TREE__ find the lowest common ancestor of the given 2 number (a and b).
    ![Tree](https://media.geeksforgeeks.org/wp-content/uploads/shortestdistancebetweennodes.png)

    ```CPP
    Input: a = 2 b = 21
    Output: 5
    ```

<BR/>


* __[MIRROR](https://github.com/ashish25-bit/data-structure-algorithms/blob/master/Trees/Mirror.cpp)__

    Given a binary tree, the task is to create a new binary tree which is a mirror image of the given binary tree.
    n:  the number of nodes to be added.
    arr: the node values  
    ###### NOTE: IN THIS SOLUTION THE NODES WILL BE INSERTED IN LEVEL ORDER FASHION

    ![Tree](https://media.geeksforgeeks.org/wp-content/uploads/BSTSearch.png)
    ```CPP
    Output: Level Order Traversal Of Tree: 8 3 10 1 6 14 4 7 13
            Level Order Traversal Of Mirror Tree: 8 10 3 14 6 1 13 7 4
    ```

<BR/>

* __[POPULATE INORDER SUCCESSOR](https://github.com/ashish25-bit/data-structure-algorithms/blob/master/Trees/Populate-Inorder-Successor.cc)__

    Given a Binary Tree, write a function to populate next pointer for all nodes. The next pointer for every node should be set to point to inorder successor. 
    ###### NOTE: IN THIS SOLUTION THE NODES WILL BE INSERTED IN LEVEL ORDER FASHION

    ![Tree](https://media.geeksforgeeks.org/wp-content/uploads/BSTSearch.png)
    ```CPP
    Output: 1->3 3->4 4->6 6->7 7->8 8 10-> 10->13 14->-1
    ```

<BR/>

* __[PRINT TREE](https://github.com/ashish25-bit/data-structure-algorithms/blob/master/Trees/PrintTree.js)__

    ```CPP
    Input:

         1
        / \
       2   3
      / \   \
     4   5   6
            / \
           7   8

    Output:
        └───1
            └───2
                ├───4
                └───5
            └───3
                └───6
                    ├───7
                    └───8
    ```

<BR/>

* __[SUM OF THE LONGEST BLOODLINE](https://github.com/ashish25-bit/data-structure-algorithms/blob/master/Trees/Sum-Of-The-Longest-Bloodline.cpp)__

    Given a binary tree of size N. Your task is to complete the function sumOfLongRootToLeafPath(), that find the sum of all nodes on the longest path from root to leaf node.
    If two or more paths compete for the longest path, then the path having maximum sum of nodes is being considered.

    ![Tree](https://s3.amazonaws.com/hr-assets/0/1529959649-81b68736f7-lcaexample.png)

    ```cpp
    Output: 16
    ```
    Explanation:
    2 + 3 + 5 + 6 = 16

<BR/>

* __[SUM TREE](https://github.com/ashish25-bit/data-structure-algorithms/blob/master/Trees/Sum-Tree.cpp)__

    Given a Binary Tree of size N , where each node can have positive or negative values. Convert this to a tree where each node contains the sum of the left and right sub trees of the original tree. The values of leaf nodes are changed to 0.

    Input:

            10
           /  \
         -2    6
         / \  / \
        8  -4 7  5

    Output:

            20
           /  \
          4    12
         / \   / \
        0   0 0   0

<BR/>

* __[TREE TO DOUBLY LINKED LIST](https://github.com/ashish25-bit/data-structure-algorithms/blob/master/Trees/Tree-To-Doubly-Linked-List.cpp)__

    Given a Binary Tree (BT), convert it to a Doubly Linked List(DLL) In-Place. The left and right pointers in nodes are to be used as previous and next pointers respectively in converted DLL. The order of nodes in DLL must be same as Inorder of the given Binary Tree. The first node of Inorder traversal (leftmost node in BT) must be the head node of the DLL.

    ![Tree](http://www.geeksforgeeks.org/wp-content/uploads/TreeToList.png)

<BR/>