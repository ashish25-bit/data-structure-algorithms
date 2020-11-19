* __[BEST TIME TO SEL STOCK](https://github.com/ashish25-bit/data-structure-algorithms/blob/master/Array/Best-Time-To-Sell-Stock.cpp)__

    Say you have an array for which the ith element is the price of a given stock on day i.

    If you were only permitted to complete at most one transaction (i.e., buy one and sell one share of the stock), design an algorithm to find the maximum profit.

    Note that you cannot sell a stock before you buy one.
    n: Number of days
    arr: Price at each day

    ```CPP
    Input: n = 6
           arr = 7 6 5 4 2 1
    Output: Max Profit: 0

    Input: n = 3
           arr = 2 4 1
    Output: Max Profit: 2

    Input: n = 6
           arr = 7 1 5 3 6 4
    Output: Max Profit: 5
    ```

<BR/>

* __[CHOCOLATE DISTRIBUTION PROBLEM](https://github.com/ashish25-bit/data-structure-algorithms/blob/master/Array/Chocolate-Distribution-Problem.cpp)__

    Given an array A of positive integers of size N, where each value represents number of chocolates in a packet. Each packet can have variable number of chocolates. There are M students, the task is to distribute chocolate packets such that :
    * Each student gets one packet.
    * The difference between the number of chocolates given to the students having packet with maximum chocolates and student having packet with minimum chocolates is minimum.
    ###### NOTE: Time Complexity: m + n * log n

    ```CPP
    Input:  n = 8, m = 5
            A[] = 3 4 1 9 56 7 9 12
    Output: 6
    ```

<BR/>

* __[COMMON ELEMENTS](https://github.com/ashish25-bit/data-structure-algorithms/blob/master/Array/Common-Elements-3-Array.cpp)__

    Given three arrays sorted in increasing order. Find the elements that are common in all three arrays.

    ```CPP
    Input: n1 = 6; A = {1, 5, 10, 20, 40, 80}
           n2 = 5; B = {6, 7, 20, 80, 100}
           n3 = 8; C = {3, 4, 15, 20, 30, 70, 80, 120}
    Output: 20 80
    ```

<BR/>

* __[COUNT PAIRS WITH GIVEN SUM](https://github.com/ashish25-bit/data-structure-algorithms/blob/master/Array/Count-Pairs-With-Given-Sum.cpp)__

    Given an array of N integers, and an integer K, find the number of pairs of elements in the array whose sum is equal to K.

    ```CPP
    Input:  N = 4, K = 6
            arr[] = {1, 5, 7, 1}
    Output: 2
    ```
<BR/>

* __[FND THE DUPLICATE NUMBER](https://github.com/ashish25-bit/data-structure-algorithms/blob/master/Array/Duplicate-Element(Only-One).cpp)__

    Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.

    There is __only one duplicate__ number in nums, return this duplicate number.

    ```CPP
    Input: n = [1, 3, 4, 2, 2]
    Output: 2
    ```
<BR/>

* __[FND MEDIAN OF 2 SORTED ARRAY OF EQUAL SIZE](https://github.com/ashish25-bit/data-structure-algorithms/blob/master/Array/Find-Median-2-Sorted-Array-Equal-Size.cpp)__

    Given 2 sorted arrays of size n. Find the median.

    ```CPP
    Input:  arr1 = [1, 2, 3]
            arr2 = [4, 5, 6]
    Output: 3
    ```
<BR/>

* __[FND MEDIAN OF 2 SORTED ARRAY OF UNEQUAL SIZE](https://github.com/ashish25-bit/data-structure-algorithms/blob/master/Array/Find-Median-2-Sorted-Array-Unequal-Size.cpp)__

    Given 2 sorted arrays of size n and m. Find the median.

    ```CPP
    Input:  n = 3, m = 5
            arr1 = [1, 3, 5]
            arr2 = [2, 4, 6, 8, 9]
    Output: 3

    Input:  n = 3, m = 4
            arr1 = [1, 3, 10]
            arr2 = [2, 4, 6, 8]
    Output: 4
    ```
<BR/>

* __[FIND MEDIAN](https://github.com/ashish25-bit/data-structure-algorithms/blob/master/Array/Find-Median-Array.cpp)__

    Given an array arr[] of N integers, calculate the median

    ```CPP
    Input:  N = 5
            arr[] = 90 100 78 89 67
    Output: 89
    ```
<BR/>

* __[FIND PAIR WITH GIVEN DIFFERENCE](https://github.com/ashish25-bit/data-structure-algorithms/blob/master/Array/Find-Pair-Given-Difference.cpp)__

    Given an unsorted array arr[] and a number n. You need to write a program to find if there exists a pair of elements in the array whose difference is k.

    ```CPP
    Input:  n = 6 k = 78
            arr = 5 20 3 2 5 80
    Output: 1

    Input:  n = 5 k = 45
            arr = 90 70 20 80 50
    Output: -1
    ```
<BR/>

* __[LONGEST CONSECUTIVE SUBSEQUENCE](https://github.com/ashish25-bit/data-structure-algorithms/blob/master/Array/Longest-Consecutive-Subsequence.cpp)__

    Given an array of positive integers. Find the length of the longest sub-sequence such that elements in the subsequence are consecutive integers, __the consecutive numbers can be in any order__.

    ```CPP
    Input:  N = 7
            a[] = {2,6,1,9,4,5,3}
    Output: 6

    ```
<BR/>

* __[MAXIMUM SUBARRAY SUM](https://github.com/ashish25-bit/data-structure-algorithms/blob/master/Array/Maximum-Subarray-Sum.cpp)__

    Given an array arr of n integers. Find the contiguous sub-array with maximum sum.

    ```CPP
    Input: n = 5
           arr = { 1 2 3 -2 5 }
    Output: 9

    Input: n = 4
           arr = { -1 -2 -3 -4 }
    Output: -1
    ```
<BR/>

* __[MERGE ARRAY WITHOUT EXTRA SPACE [METHOD 1]](https://github.com/ashish25-bit/data-structure-algorithms/blob/master/Array/Merge-Array.cpp)__ 

    #### Time Complexity: O(N*M)

    Given two sorted arrays ar1[] of size N and ar2[] of size M. Each array is sorted in non-decreasing order. Merge the two arrays into one sorted array in non-decreasing order without using any extra space.

    ```CPP
    Input  : N = 4, M = 5
             ar1[] = {1, 3, 5, 7}
             ar2[] = {0, 2, 6, 8, 9}
    Output : ar1[] = {0, 1, 2, 3}
             ar2[] = {5, 6, 7, 8, 9}
    ```
<BR/>

* __[MERGE INTERVALS](https://github.com/ashish25-bit/data-structure-algorithms/blob/master/Array/Merge-Intervals.js)__

    Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.

    ```CPP
    Input:  intervals = [[1,3], [2,6], [8,10], [15,18]]
    Output: [[1,6], [8,10], [15,18]]

    Input:  intervals = [[1,4], [4,5]]
    Output: [[1,5]]
    ```
<BR/>

* __[MIN MAX ELEMENT](https://github.com/ashish25-bit/data-structure-algorithms/blob/master/Array/Min-Max-Element.cpp)__

    Maximum and minimum of an array using minimum number of comparisons

    ```CPP
    Input  : arr[] = { 1000, 11, 445, 1, 330, 3000 }
    Output : Minimum element is 1
             Maximum element is 3000
    ```
<BR/>

* __[NEGATIVE ELEMENTS ONE SIDE](https://github.com/ashish25-bit/data-structure-algorithms/blob/master/Array/Negative-One-Side.cpp)__

    Move all negative numbers to beginning and positive to end with constant extra space.
    __Note: Order of elements is not important here.__

    ```CPP
    Input  : n = 5
             arr[] = { 5 4 -1 -2 3}
    Output : -1 -2 5 4 3
    ```
<BR/>

* __[NEXT PERMUTATION](https://github.com/ashish25-bit/data-structure-algorithms/blob/master/Array/Next-Permutation.cpp)__

    Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

    If such an arrangement is not possible, it must rearrange it as the lowest possible order (i.e., sorted in ascending order).

    The replacement must be in place and use only constant extra memory.

    ```CPP
    Input  : nums = [1,2,3]
    Output : [1,3,2]
    ```
<BR/>

* __[NUMBER FREQUENCY GREATER THAN K](https://github.com/ashish25-bit/data-structure-algorithms/blob/master/Array/Number-Freqency-Greater-Than-K.cpp)__ 

    Given an array of size n and a number k, find all elements that appear more than n/k times

    ```CPP
    Input  : n = 8
             arr = 3, 1, 2, 2, 1, 2, 3, 3
             k = 4
    Output : 2 3
    ```
<BR/>

* __[ONE CYCLIC ROTATION](https://github.com/ashish25-bit/data-structure-algorithms/blob/master/Array/One-Cyclic-Rotation.cpp)__

    Given an array, cyclically rotate an array by one.

    ```CPP
    Input  : 8
             9 8 7 6 4 2 1 3
    Output : 3 9 8 7 6 4 2 1
    ```
<BR/>

* __[REVERSE AN ARRAY](https://github.com/ashish25-bit/data-structure-algorithms/blob/master/Array/Reverse.cpp)__

    Write a program to reverse an array or string

    ```CPP
    Input  : arr[] = {1, 2, 3}
    Output : arr[] = {3, 2, 1}
    ```
<BR/>

* __[SEGREGATE POSITIVE AND NEGATIVE NUMBERS](https://github.com/ashish25-bit/data-structure-algorithms/blob/master/Array/Segregate-Positive-Negative-Numbers.cpp)__

    Given an array of positive and negative numbers, arrange them in an alternate fashion such that every positive number is followed by negative and vice-versa. __Order of elements in output doesn’t matter.__

    ```CPP
    Input  : 10
             arr[] = {-5, 3, 4, 5, -6, -2, 8, 9, -1, -4}
    Output : -5 4 -2 8 -4 9 -1 5 -6 3
    ```
<BR/>

* __[SORT012](https://github.com/ashish25-bit/data-structure-algorithms/blob/master/Array/Sort012.cpp)__

    Given an array A of size N containing 0s, 1s, and 2s; you need to sort the array in ascending order without using a sorting algo.

    ```CPP
    Input  : 5
             0 2 1 2 0
    Output : 0 0 1 2 2
    ```
<BR/>

* __[SUBARRAY SUM EQUALS ZERO](https://github.com/ashish25-bit/data-structure-algorithms/blob/master/Array/Subarray-Sum-Zero.cpp)__

    Given an array arr[] of n positive and negative numbers. Find if there is a subarray (of size at-least one) with 0 sum.

    ```CPP
    Input  : n = 18
             arr = 43 6 -39 -8 -21 23 -29 -31 34 -13 48 -26 -35 20 -37 -24 41 30
    Output : Yes

    Input  : n = 7
             arr = 23 12 20 46 31 -45 -25

    Output : No
    ```
<BR/>

* __[SUBSET ARRAY](https://github.com/ashish25-bit/data-structure-algorithms/blob/master/Array/Subset-Array.cpp)__

    Given two arrays: arr1[0..n1-1] of size n1 and arr2[0..n2-1] of size n2. Task is to check whether arr2[] is a subset of arr1[] or not. Both the arrays can be both unsorted or sorted. It may be assumed that elements in both array are distinct.

    ```CPP
    Input  : n1 = 6 , n2 = 4
             arr1 = {11 1 13 21 3 7}
             arr2 = {11 3 7 1}
    Output : Yes

    Input  : n1 = 5 , n2 = 3
             arr1 = {10 5 2 23 19}
             arr2 = {19 5 3}
    Output : No
    ```
<BR/>


* __[THREE WAY PARTITIONING(1)](https://github.com/ashish25-bit/data-structure-algorithms/blob/master/Array/Three-Way-Partitioning.cpp)__

    Given an array of size N and a range [a, b]. The task is to partition the array around the range such that array is divided into three parts.
    * All elements smaller than a come first.
    * All elements in range a to b come next.
    * All elements greater than b appear in the end.
    The individual elements of three sets can appear in any order. You are required to return the modified array.
    
    ###### NOTE: Space Complexity: O(N)

    ```CPP
    Input:  N = 5
            A[] = {1, 2, 3, 3, 4}
            [a, b] = [1, 2]
    Output : {1, 2, 3, 3, 4}

    Input:  N = 3 
            A[] = {1, 2, 3}
            [a, b] = [1, 3]
    Output : {1, 2, 3}
    ```

<BR/>

* __[UNION AND INTERSECTION OF TWO  ARRAYS](https://github.com/ashish25-bit/data-structure-algorithms/blob/master/Array/Union-Intersection-Sorted-Array.cpp)__

    Given an array A of size N containing 0s, 1s, and 2s; you need to sort the array in ascending order without using a sorting algo.

    ```CPP
    Input  : arr1: 1, 2, 2, 4, 5, 6
             arr2: 2, 2, 3, 5, 7
    Output : Union Array: 1 2 2 3 4 5 6 7
             Intersection Array: 2 5
    ```

<BR/>

* __[MOVE ZEROS TO END](https://github.com/ashish25-bit/data-structure-algorithms/blob/master/Array/Zeros-To-End.cpp)__

   Given an array arr[] of n positive integers. Push all the zero’s of the given array to the right end of the array while maitaining the order of non-zero elements.

    ```CPP
    Input  : n = 5
             arr: 0 0 0 0 4
    Output : 4 0 0 0 0

    Input  : n = 7
             arr: 4 0 1 0 0 2 3
    Output : 4 1 2 3 0 0 0
    ```

<BR/>
