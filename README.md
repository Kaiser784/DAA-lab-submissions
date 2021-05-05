# Design and Analysis of Algorithm - Lab Submission
Object Oriented Algorithm Design and Analysis Practice Lab course @IIITDM Kancheepuram, 2021.
 
 ## Team:
 ```
 Abhijeet Mahapatra   - COE19B002
 Paul Babu Kadali     - CED19I002 
 ```
 ## Lab 1
 ``` 
1.Given an integer array, present three different logic to find MAXIMUM in an array (Do NOT use SORTING in any of the logic).
` For each logic, count the number of comparisons incurred to return MAX

2.Given an integer array, present a logic to output an element which is neither maximum nor minimum. 
  Here again, avoid sorting the entire array.

3.Given a number, write an algorithm to list all its prime factors.

4.Given two integers (m,n), present three different approaches to find GCD(m,n) and LCM(m,n). 
  Can we use the Solution to Question 3 to answer this question. If so, make an attempt, let one of the logic use Q3.
 ```
---
## Lab 2
```
1. Input:   Integer Array A and an integer p
   Question: Does there exist q and r in A such that p=q+r

   Propose three different logic and implement all three. Use system time function and compare system time for each logic.
   Test drive on at least 20 different inputs and plot the graph. Is it possible to call 'excel' from C/C++ program to plot the graph.
   If yes, make an attempt. Identify which logic is efficient through system time.

2. Input: Accept a large sized integer array from the user with the following constraints
   (i) user should not enter the size of the array
   (ii) user should not enter -1 as it is used delimiter.
   User enters until some time after which the user must enter -1 only and no other integer, the user can enter -1 any number of times.

  Question:  Identify the position of the first '-1'

  Propose three different logic and implement all three.  Like the above, compare system time to pick the best.    
  As a programmer, you may declare an array of size, say, 10000. ( if the system is not accepting, then make it 5000).
  You should not run a forloop for 10000 or 5000. 
  The size is given only for modelling purposes, in theoretical sense, the size is unknown to the user.

3. Input: Accept integer n
   Question: print the following 5 types  

   1 2 3 4 5  (1....n)
   1 2 3 4
   1 2 3
   1 2
   1

   1 2 3 4 5
     2 3 4 5
       3 4 5
         4 5
           5

   1
   1 2
   1 2 3
   1 2 3 4
   1 2 3 4 5

           5
         4 5
       3 4 5
     2 3 4 5
   1 2 3 4 5


   1 2 3 4 5 6 7 8
     2 3 4 5 6 7
       3 4 5 6
         4 5
         4 5
       3 4 5 6
     2 3 4 5 6 7
   1 2 3 4 5 6 7 8
```
---
## Lab 3
```
1. Given a ternary array (filled with 0,1,2) of size 'n'.  
   Arrange them in non-decreasing order preserving stability 
   (for elements with multiplicity, their order of appearance must be preserved in the output array).

   ex: 2 0 1 1 0 0 2  --in the final array, 0 0 0 1 1 2 2 ; the first '2' of the input array must appear before the second '2'.   

   Present three diff logic.   Can this be done in theta(n) time.

2. Given an integer array, the objective is to find duplicates in the array.  Present two diff logic.

3. Subset Sum:  Input:  Integer Array A, integer k.  Question:  Does there exist a subset of A whose sum is k.
   Discover a logic and implement.

4. In the above problem, list all subsets whose sum is k.
```
---
## Lab 4

#### `Inheritance feature of OO paradigm`
#### `Divide and Conquer Paradigm`
```
1. Find MAX using 1-way, 2-way, 3-way, k-way approach

2. Count the number of negative numbers in an integer array using 2-way and 3-way approach.

3. Implement an Iterative and a Recursive algorithm for binary search, ternary search.
```
---
## Lab 5
#### `Inheritance feature of OO paradigm`
```
1. Consider a large integer array of size at least 1000. Populate the array using rand() function. 
   Use 2-way merge sort as part of divide phase and stop the recursion when the input size is less than or equal to 20. 
   For all subproblems of size at most 20, sort the subproblem using insertion sort, selection, bubble; 
   compare the system times and display which Hybrid sorting is better (Merge+insertion, Merge+selection, Merge+bubble)

2. The above problem for 3-way merge sort.

3. Implement Quicksort with 2 pivots; maintain 'small window', 'large window', middle window.
   Suppose the pivots are x and y such that x < y, then

     small window (values less than x)
     large window (values greater than y)
     middle window (between x and y)

4. Implement Insertion sort using binary search; note that at iteration i, we chk the position for A[i] in A[1...(i-1)] which is sorted.
   The classical algorithm available in texts does linear search. Perform binary search on A[1...(i-1)] to identify the right position for A[i]. 
   What is the complexity of this algorithm. Is it better than classical insertion sort.

5. Implement 3 different logic to merge two sorted arrays.

6. Given a max-heap, the objective is to find a minimum and second minimum. Implement an efficient logic.
```
---
## Midsem
#### `Coding Best Practice`
   1. Proper indentation,  name of the function must be self explanatory (ex; find_min, find_max, avoid f1, f2).   
   2. Except loop indices (i,j,k), all other variables must be self explanatory (ex: Min, SecondMin, avoid, variables, a,b,temp, m1,m2,temp2).  
   3. All functions must be public and defined in the class template.

```
1. Given an integer array A, and an integer K.  The objective is to check whether A has w,x,y,z such that K=w+x+y+z, print w,x,y,z if exists. 
   Present a logic and C++ implementation.  
   (15 marks)

    For Q1; Only 5 marks will be awarded if theta(n^4) or theta(n^3) logic is presented. Think of an efficient approach to receive full credits.

2. Given an integer array A.  The objective is to find (i) minimum (ii) maximum (iii) second minimum in A as efficiently as possible. 
   Focus on 'step count', the number of comparisons. 
   If you have, say, two logic (L1,L2) wherein L1 takes n-1 comparisons and L2 takes n-2 comparisons, then L2 is efficient. 
   Do not focus on asymptotic analysis. In asymptotic sense, both are of the same complexity.
   (25 marks)
   
   For Q2; do not perform simple linear scan, sorting - less efficient. some partial marks (5 marks) will be given if this is presented.

Extra Credit (10 marks)

   Identify a problem P and an algorithm A to solve P such that A runs in
   θ(( log n) ^2)[ the square of logn]. Write a C++ program that implements A. 
   Test drive your program with a suitable test cases. Also, show that A indeed runs in θ((log n)^2).
```
---
## Lab 6
#### `Implement Greedy Algorithm`
```
1. Coin change
2. Fractional Knapsack 
3. Scheduling
```
Look at case studies given in geeksforgeek - implement any 5 with varying complexities.

## Endsem
#### `Coding Best Practice`
   1. Proper indentation,  name of the function must be self explanatory (ex; find_min, find_max, avoid f1, f2).   
   2. Except loop indices (i,j,k), all other variables must be self explanatory (ex: Min, SecondMin, avoid, variables, a,b,temp, m1,m2,temp2).  
   3. All functions must be public and defined in the class template.

```
1. Truck Loading Problem
   
   Input: A truck with capacity C kgs, 'K' containers with weights w_i (w_1 refers to the weight of the first container).
   Objective: To load the truck with maximum number of containers, not exceeding C 
   
   Present a Greedy and DP for Q1.   (10 + 10 = 20 marks)
   Marking scheme: 3: logic 7: code for each
   
2. Truck Loading Problem - A Variant
   
   Input:  Two trucks with capacity C kgs each,  'K' containers with weights w_i (w_1 refers to the weight of the first container).
   Objective: To load the two trucks with maximum number of containers, not exceeding C for each   
   
   Present a Greedy algorithm if exists. If Greedy algorithm does not exist, then present two greedy strategies along with counter 
   examples. Implement the greedy algorithm if exists. If greedy algorithm does not exist, then NO need to implementation greedy 
   strategies discovered. It is enough to present counter examples. (5 + 5 = 10 marks)

   Present a DP solution if exists. Implement the same. (10 + 10 = 20 marks ; 10 logic, recursive solution, 10: code)
```
