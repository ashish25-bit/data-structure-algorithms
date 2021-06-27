* __[ADD TWO NUMBERS](https://github.com/ashish25-bit/data-structure-algorithms/blob/master/LinkedList/Add-Two-Numbers.cpp)__
    
    Given two numbers represented by two linked lists(THE NUMBERS IN THE LIST ARE IN REVERSE ORDER).
    The task is to return a sum list. The sum list is a linked list representation of the addition of two input numbers.

    ```CPP
    Input: l1 = {2-> 4-> 3} { 342 }
           l1 = {5-> 6-> 4} {465}
    Output: 7-> 0-> 8 {807}
    
    Input: l1 = {9-> 9} {99}
           l1 = {0-> 1} {10}
    Output: 9-> 0-> 1 {109}
    ```
<BR/>

* __[CLONE LINKED LIST](https://github.com/ashish25-bit/data-structure-algorithms/blob/master/LinkedList/Clone-LL.cpp)__
    
    Clone a linked list which have a __next pointer__ which points to the next node and an __arbitrary pointer__ which may or may not points to any node.

    ![](https://contribute.geeksforgeeks.org/wp-content/uploads/clone.jpg)

<BR/>


* __[CYCLE DECTECTION](https://github.com/ashish25-bit/data-structure-algorithms/blob/master/LinkedList/Cycle-Detection.cpp)__
    
    ![Cycle Detection Image](https://www.geeksforgeeks.org/wp-content/uploads/2009/04/Linked-List-Loop.gif)
    ```CPP
    Output: LOOP FOUND 
    ```

    ![Linked List](https://media.geeksforgeeks.org/wp-content/cdn-uploads/gq/2013/03/Linkedlist.png)
    ```CPP
    Output: LOOP NOT FOUND 
    ```

<BR/>

* __[FIND MEDIAN ELEMENT](https://github.com/ashish25-bit/data-structure-algorithms/blob/master/LinkedList/Find-Median-Element.cpp)__

    Given a non-empty, singly linked list with head node head, return a middle node of linked list.

    If there are two middle nodes, return the second middle node.

    ```CPP
    Input:  [1,2,3,4,5]
    Output: Node 3 from this list (Serialization: [3,4,5])
            The returned node has value 3.  (The judge's serialization of this node is [3,4,5]).
    ```

<BR/>

* __[FIRST NON REPEATING CHARACTER IN A STREAM](https://github.com/ashish25-bit/data-structure-algorithms/blob/master/LinkedList/First-Non-Repeating-Character-In-A-Stream.cpp)__

    Given an input stream of A of n characters consisting only of lower case alphabets. The task is to find the first non repeating character, each time a character is inserted to the stream. If there is no such character then append '#' to the answer.

    ```CPP
    Input:  abab
    Output: aab#
    
    Input:  aabbbcdeef
    Output: a#b##ccccc
    ```

<BR/>

* __[INTERSECTING NODES OF 2 SORTED LINKED LIST](https://github.com/ashish25-bit/data-structure-algorithms/blob/master/LinkedList/Intersection-Nodes-Of-Sorted-LL.cpp)__

    Given two lists sorted in increasing order, create a new list representing the intersection of the two lists. The new list should be made with its own memory — the original lists should not be changed.

    ```CPP
    Input:  L1 = 1->2->3->4->6->NULL
            L2 = 2->4->6->8->NULL
    Output: 2->4->6->NULL
    ```

<BR/>

* __[INTERSECTION POINT OF Y SHAPED LINKED LIST](https://github.com/ashish25-bit/data-structure-algorithms/blob/master/LinkedList/Intersection-Point-Y-Shapped-LL.cpp)__

    Given two singly linked lists of size N and M, write a program to get the point where two linked lists intersect each other.
    If linked list do not merge at any point, then it should return -1.

    ![Tree](https://contribute.geeksforgeeks.org/wp-content/uploads/linked.jpg)


    ```CPP
    Input:  LinkList1 = 3->6->9->common
            LinkList2 = 10->common
            common = 15->30->NULL
    Output: 15
    ```

<BR/>

* __[LOOP DETECTION AND DELETION](https://github.com/ashish25-bit/data-structure-algorithms/blob/master/LinkedList/Loop-Detection-Deletion.cpp)__
    
    ![Cycle Detection Image](https://www.geeksforgeeks.org/wp-content/uploads/2009/04/Linked-List-Loop.gif)
    ```CPP
    Output: LOOP FOUND
            Linked List: 1->2->3->4->5->NULL
    ```

    ![Linked List](https://media.geeksforgeeks.org/wp-content/cdn-uploads/gq/2013/03/Linkedlist.png)
    ```CPP
    Output: LOOP NOT FOUND
    ```

<BR/>

* __[MOVE TO FRONT](https://github.com/ashish25-bit/data-structure-algorithms/blob/master/LinkedList/Move-To-Front.cpp)__
    
    Write a function that moves the last element to the front in a given Singly Linked List.

    ```CPP
    Input: 1->1->2->2->3->NULL 
    Output: 1->2->3
    ```
<BR/>

* __[NTH NODE FROM END](https://github.com/ashish25-bit/data-structure-algorithms/blob/master/LinkedList/Nth-Node-From-End.cpp)__
    
    ```CPP
    Input:  N = 2
            LinkedList: 1->2->3->4->5->6->7->8->9
    Output: 8

    Input:  N = 5
            LinkedList: 10->5->100->5
    Output: -1
    ```
<BR/>


* __[REARRANGE NODES](https://github.com/ashish25-bit/data-structure-algorithms/blob/master/LinkedList/Rearrange-Nodes.cc)__
    Given a singly linked list, the task is to rearrange it in a way that all odd position nodes are together and all even positions node are together.

    Expected Time Complexity: O(N).
    Expected Auxiliary Space: O(1).


    ```CPP
    Input:  1->2->3->4->5->NULL
    Output: 1->3->5->2->4->NULL
    ```
<BR/>

* __[REMOVE DUPLICATES FROM A SORTED LIST](https://github.com/ashish25-bit/data-structure-algorithms/blob/master/LinkedList/Remove-Duplicates-Sorted-Linked-List.cpp)__
    
    ```CPP
    Input:  1->2->3->4->5->NULL 
    Output: 5->1->2->3->4->NULL 
    ```
<BR/>

* __[REMOVE DUPLICATES FROM AN UNSORTED LIST](https://github.com/ashish25-bit/data-structure-algorithms/blob/master/LinkedList/Remove-Duplicates-Unsorted-Linked-List.cpp)__
    
    ```CPP
    Input:  5->1->2->1->3->NULL
    Output: 5->1->2->3->NULL
    ```
<BR/>

* __[REVERSE K NODES](https://github.com/ashish25-bit/data-structure-algorithms/blob/master/LinkedList/Reverse-K-Nodes.cpp)__

    Given a linked list of size n. The task is to reverse every k nodes (where k is an input to the function) in the linked list.
    
    ```CPP
    Input:  n = 5, k = 2
            1->2->3->4->5->NULL 
    Output: 2->1->4->3->5->NULL
    ```
<BR/>

* __[REVERSE A LINKED LIST (ITERATIVE)](https://github.com/ashish25-bit/data-structure-algorithms/blob/master/LinkedList/Reverse-SLL-Iterative.cpp)__
    
    ```CPP
    Input:  1->2->3->4->NULL 
    Output: 4->3->2->1->NULL
    ```
<BR/>

* __[REVERSE A LINKED LIST (RECURSIVE)](https://github.com/ashish25-bit/data-structure-algorithms/blob/master/LinkedList/Reverse-SLL-Recursive.cpp)__
    
    ```CPP
    Input:  1->2->3->4->NULL 
    Output: 4->3->2->1->NULL
    ```
<BR/>

* __[SEGREGATE EVEN AND ODD NODES](https://github.com/ashish25-bit/data-structure-algorithms/blob/master/LinkedList/Segreagate-Even-Odd-Nodes.cpp)__
    
    Given a link list of size N, modify the list such that all the even numbers appear before all the odd numbers in the modified list. The order of appearance of numbers within each segregation should be __same as that in the original list__.

    ```CPP
    Input:  17->15->8->9->2->4->6->NULL
    Output: 8->2->4->6->17->15->9->NULL
    ```
<BR/>

* __[GIVEN A LINKED LIST OF 0s, 1s AND 2s SORT IT.](https://github.com/ashish25-bit/data-structure-algorithms/blob/master/LinkedList/Sort012.cpp)__
    
    ```CPP
    Input:  {1,2,2,1,2,0,2,2}
    Output: 0 1 1 2 2 2 2 2
    ```

<BR/>

* __[STARTING POINT OF THE LOOP](https://github.com/ashish25-bit/data-structure-algorithms/blob/master/LinkedList/Starting-Point-Loop.cpp)__
    
    ![Cycle Detection Image](https://www.geeksforgeeks.org/wp-content/uploads/2009/04/Linked-List-Loop.gif)
    ```CPP
    Output: LOOP FOUND
            Starting Point: 2
    ```

<BR/>
