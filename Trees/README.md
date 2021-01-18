* __[1-TRAVERSAL INORDER](https://github.com/ashish25-bit/data-structure-algorithms/blob/master/Trees/1-Traversal-Inorder.cpp)__

    ###### NOTE: IN THIS SOLUTION THE NODES WILL BE INSERTED IN LEVEL ORDER FASHION

    __CONTAINS BOTH ITERATIVE AND RECURSIVE SOLUTION.__

    ![Tree](https://media.geeksforgeeks.org/wp-content/uploads/BSTSearch.png)
    ```CPP
    Output: Recursive Solution: 1 3 4 6 7 8 10 13 14
            Iterative Solution: 1 3 4 6 7 8 10 13 14
    ```

<BR/>

* __[2-TRAVERSAL PREORDER](https://github.com/ashish25-bit/data-structure-algorithms/blob/master/Trees/2-Traversal-Preorder.cpp)__
 
    ###### NOTE: IN THIS SOLUTION THE NODES WILL BE INSERTED IN LEVEL ORDER FASHION
     __CONTAINS BOTH ITERATIVE AND RECURSIVE SOLUTION.__

    ![Tree](https://media.geeksforgeeks.org/wp-content/uploads/BSTSearch.png)
    ```CPP
    Output: Recursive Solution: 8 3 1 6 4 7 10 14 13
            Iterative Solution: 8 3 1 6 4 7 10 14 13
    ```

<BR/>

* __[3-TRAVERSAL POSTORDER](https://github.com/ashish25-bit/data-structure-algorithms/blob/master/Trees/3-Traversal-Postorder.cpp)__

    ###### NOTE: IN THIS SOLUTION THE NODES WILL BE INSERTED IN LEVEL ORDER FASHION
     __CONTAINS BOTH ITERATIVE AND RECURSIVE SOLUTION.__

    ![Tree](https://media.geeksforgeeks.org/wp-content/uploads/BSTSearch.png)
    ```CPP
    Output: Recursive Solution: 1 4 7 6 3 13 14 10 8
            Iterative Solution: 1 4 7 6 3 13 14 10 8
    ```

<BR/>

* __[4-TRAVERSAL LEVEL ORDER](https://github.com/ashish25-bit/data-structure-algorithms/blob/master/Trees/4-Traversal-Level-Order.cpp)__

    Given a binary tree, find its level order traversal.
    Level order traversal of a tree is breadth-first traversal for the tree.
    n:  the number of nodes to be added.
    arr: the node values  
    ###### NOTE: IN THIS SOLUTION THE NODES WILL BE INSERTED IN LEVEL ORDER FASHION

    ![Tree](https://media.geeksforgeeks.org/wp-content/uploads/BSTSearch.png)
    ```CPP
    Output: 8 3 10 1 6 14 4 7 13
    ```

<BR/>

* __[5-TRAVERSAL REVERSE LEVEL ORDER](https://github.com/ashish25-bit/data-structure-algorithms/blob/master/Trees/5-Traversal-Reverse-Level-Order.cpp)__

    Given a binary tree of size n, find its reverse level order traversal. ie- the traversal must begin from the last level.  
    ###### NOTE: IN THIS SOLUTION THE NODES WILL BE INSERTED IN LEVEL ORDER FASHION

    ![Tree](https://media.geeksforgeeks.org/wp-content/uploads/BSTSearch.png)
    ```CPP
    Output: 4 7 13 1 6 14 3 10 8
    ```

<BR/>

* __[6-TRAVERSAL DIAGONAL](https://github.com/ashish25-bit/data-structure-algorithms/blob/master/Trees/6-Traversal-Diagonal.cpp)__

    Consider lines of slope -1 passing between nodes. Given a Binary Tree, print all diagonal elements in a binary tree belonging to the same line.

    ![Tree](https://media.geeksforgeeks.org/wp-content/uploads/d1-1.png)

    ```CPP
    Output: 8 10 14 3 6 7 13 1 4
    ```

<BR/>

* __[7-TRAVERSAL ZIZ-ZAG](https://github.com/ashish25-bit/data-structure-algorithms/blob/master/Trees/7-Traversal-Zig-Zag.cpp)__

   Given a Binary Tree. Find the Zig-Zag Level Order Traversal of the Binary Tree.

    ![Tree](https://media.geeksforgeeks.org/wp-content/uploads/20200124141533/Untitled-Diagram65.jpg)

    ```CPP
    Output: 1 3 2 4 6 5 7 
    ```

<BR/>

* __[8-TRAVERSAL BOUNDARY](https://github.com/ashish25-bit/data-structure-algorithms/blob/master/Trees/8-Traversal-Boundary.cpp)__

   Given a Binary Tree, find its Boundary Traversal

    ![Tree](https://contribute.geeksforgeeks.org/wp-content/uploads/boundary.png)

    ```CPP
    Output: 20 8 4 10 14 25 22
    ```

<BR/>

* __[101-VIEW BOTTOM](https://github.com/ashish25-bit/data-structure-algorithms/blob/master/Trees/101-View-Bottom.cpp)__

    Given a binary tree, print the bottom view from left to right.
    A node is included in bottom view if it can be seen when we look at the tree from bottom.
    
    ```CPP
    Input:  10
            19 2 L 19 30 R 2 1 L 2 17 R 30 25 L 30 48 R 1 -1 N 1 -1 N 17 9
    Output: 1 9 25 30 48
    ```
               19 
             /   \
           2      30
          /  \   /  \
        1    11 25   48
               /
              9
<BR/>

* __[102-VIEW TOP](https://github.com/ashish25-bit/data-structure-algorithms/blob/master/Trees/102-View-Top.cpp)__

    Given below is a binary tree. The task is to print the top view of binary tree. Top view of a binary tree is the set of nodes visible when the tree is viewed from the top. For the given below tree

    ```CPP
    Input:  10
            19 2 L 19 30 R 2 1 L 2 17 R 30 25 L 30 48 R 1 -1 N 1 -1 N 17 9
    Output: 1 2 19 30 48
    ```
               19 
             /   \
           2      30
          /  \   /  \
        1    11 25   48
               /
              9
<BR/>

* __[103-VIEW LEFT](https://github.com/ashish25-bit/data-structure-algorithms/blob/master/Trees/103-View-Left.cpp)__

    Given a Binary Tree, print Left view of it. Left view of a Binary Tree is set of nodes visible when tree is visited from Left side. The task is to complete the function leftView(), which accepts root of the tree as argument.

    ![Tree](https://media.geeksforgeeks.org/wp-content/cdn-uploads/20190221103723/leftview.jpg)
    ```CPP
    Output: 10 20 40
    ```
<BR/>

* __[104-VIEW RIGHT](https://github.com/ashish25-bit/data-structure-algorithms/blob/master/Trees/104-View-Right.cpp)__

    Given below is a binary tree. The task is to print the top view of binary tree. Top view of a binary tree is the set of nodes visible when the tree is viewed from the top. For the given below tree

    ![Tree](https://media.geeksforgeeks.org/wp-content/cdn-uploads/20190221103723/leftview.jpg)
    ```CPP
    Output: 10 30 60
    ```
<BR/>
    
<BR/>

* __[BALANCED TREE](https://github.com/ashish25-bit/data-structure-algorithms/blob/master/Trees/Balanced-Tree.cpp)__

    Given a binary tree, find if it is height balanced or not. 
    A tree is height balanced if difference between heights of left and right subtrees is not more than one for all nodes of tree. 

    ![Tree](https://media.geeksforgeeks.org/wp-content/uploads/20200124141533/Untitled-Diagram65.jpg)

    ```CPP
    Output: 0 (meaning the tree is balanced)
    ```

<BR/>

* __[CHECK FOR SUM TREE](https://github.com/ashish25-bit/data-structure-algorithms/blob/master/Trees/Check-For-Sum-Tree.cpp)__

    Given a Binary Tree. Check whether it is a Sum Tree or not.

    A Binary Tree is a Sum Tree in which value of each node x is equal to sum of nodes present in its __left subtree__ and __right subtree__ . An empty tree is also a Sum Tree as sum of an empty tree can be considered to be 0. A leaf node is also considered as a Sum Tree.

    ```CPP
    Input: 
            3
           / \
          1   2

    Output: 1
    ```

    ```CPP
    Input:
            10
           /  \
          20   30
         /  \
        10   10

    Output: 0
    ```

<BR/>

* __[DUPLICATE SUBTREE](https://github.com/ashish25-bit/data-structure-algorithms/blob/master/Trees/Duplicate-Subtree.cpp)__

    Given a binary tree, find out whether it contains a duplicate sub-tree of size two or more, or not.

    ```CPP
    Input: 
                1
              /   \
             2     3
           /   \     \
          4     5     2
                    /   \
                   4     5

    Output: 1
    ```

    ```CPP
    Input:
            10
           /  \
          20   30
         /  \
        10   10

    Output: 0
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