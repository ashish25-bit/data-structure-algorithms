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
    Output: 4

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

* __[FREQUENCIES OF LIMITED RANGE ARRAY ELEMENTS](https://github.com/ashish25-bit/data-structure-algorithms/blob/master/Array/Frequencies-Of-Limited-Range-Array-Elements.cpp)__

    Given an array A[] of N positive integers which can contain integers from 1 to N where elements can be repeated or can be absent from the array. Your task is to count the frequency of all elements from 1 to N.

    ###### TIME COMPLEXITY: O(N) <br/> SPACE COMPLEXITY: O(1)

    ```CPP
    Input:  N = 5
            A[] = {2, 3, 2, 3, 5}
    Output: 0 2 2 0 1

    Input:  N = 4
            A[] = {3, 3, 3, 3}
    Output: 0 0 4 0

    ```
<BR/>

* __[Kth SMALLEST ELEMENT](https://github.com/ashish25-bit/data-structure-algorithms/blob/master/Array/Kth-Smallest-Element.js)__

    __Quick Select Algorithm: O(N)__

    Find the Kth-smallest element in a array of size N.

    ```javascript
    Input:  const arr = [7, 10, 4, 3, 20, 15];
            const k = 3;
    Output: 7

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

* __[MAX VALUE ARRAY ROTATION](https://github.com/ashish25-bit/data-structure-algorithms/blob/master/Array/Max-Value-Array-Rotation.cc)__

    Given an array(0-based indexing), you have to find the max sum of i*A[i] where A[i] is the element at index i in the array. The only operation allowed is to rotate(clock-wise or counter clock-wise) the array any number of times.

    ```CPP
    Input: arr = 8 3 1 2
    Output: 29
    ```
<BR/>

* __[MAXIMUM SUBARRAY PRODUCT](https://github.com/ashish25-bit/data-structure-algorithms/blob/master/Array/Maximum-Product-Subarray.js)__

    Given an array arr that contains n integers (may be positive, negative or zero). Find the product of the maximum product subarray.

    ```CPP
    Input: n = 10
           arr = 90 91 -91 91 -91 -90 90 90 -90 -90
    Output: 404928287208900000

    Input: n = 5
           arr = 6 -3 -10 0 2
    Output: 180
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

* __[PICKING NUMBERS](https://github.com/ashish25-bit/data-structure-algorithms/blob/master/Array/Picking-Numbers.cpp)__

    Given an array of integers, find the longest subarray where the absolute difference between any two elements is less than or equal to 1.

    ```CPP
    Input  : 6
             4 6 5 3 3 1
    Output : 3
    LONGEST SUBARRAY: 4 3 3
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

* __[SMALLEST SUBARRAY WITH GREATER SUM](https://github.com/ashish25-bit/data-structure-algorithms/blob/master/Array/Smallest-Subarray-With-Greater-Sum.cpp)__

    Given an array of integers (a[])  and a number x, find the smallest subarray with sum greater than the given value.

    __Note:__ There is at least one subarray with sum greater than x

    ```CPP
    Input  : n = 7, 51
             a = {1, 4, 45, 6, 0, 19, 33}
    Output : 2
    ```
    __Subarray__ in the above test case is: __{19, 33}__
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

* __[SUM OF ALL SUBARRAYS](https://github.com/ashish25-bit/data-structure-algorithms/blob/master/Array/Sum-All-Subarray.cpp)__
    
    ```CPP
    Input:  N = 3
            arr[] = {1, 2, 3}
    Output : 20
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

* __[THREE WAY PARTITIONING(2)](https://github.com/ashish25-bit/data-structure-algorithms/blob/master/Array/Three-Way-Partitioning2.js)__

    Given an array of size N and a range [a, b]. The task is to partition the array around the range such that array is divided into three parts.
    * All elements smaller than a come first.
    * All elements in range a to b come next.
    * All elements greater than b appear in the end.
    The individual elements of three sets can appear in any order. You are required to return the modified array.
    
    ###### NOTE: Space Complexity: O(1)

    ```CPP
    Input : A[] = {87, 14, 15, 78, 40, 94, 16}
            a = 36, b = 72
    Output : {16, 14, 15, 40, 94, 78, 87}
    ```

<BR/>

* __[TRIPLE SUM IN ARRAY](https://github.com/ashish25-bit/data-structure-algorithms/blob/master/Array/Triplet-Sum-In-Array.js)__

    Given an array and an integer K. Find if there's a triplet in the array which sums up to the given integer K. 

    ```CPP
    Input  : n = 6
             K = 13
             arr[] = [1 4 45 6 10 8]
    Output : true
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

* __[ZERO SUBARRAY SUM](https://github.com/ashish25-bit/data-structure-algorithms/blob/master/Array/Zero-Subarrays-Sum.js)__

    You are given an array a[] of size N. Find the total count of sub-arrays having their sum equal to 0.

    ```CPP
    Input  : n = 10
             a[] = 6 -1 -3 4 -2 2 4 6 -12 -7
    Output : 4
    ```

<BR/>

* __[ZEROS TO END](https://github.com/ashish25-bit/data-structure-algorithms/blob/master/Array/Zeros-To-End.cpp)__

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
