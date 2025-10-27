# 🧮 Algorithms Assignment 

## 📘 Overview
This repository contains implementations for **three main algorithmic tasks**
Each task explores different algorithmic paradigms — recursion, divide and conquer, dynamic programming, and data structures such as heaps and priority queues.

---

## 🧩 Task 1: Fibonacci Series

### Objective
Implement functions to compute the *n-th Fibonacci number* using three distinct methods.

### Implementations
1. **Recursive Approach**  
   - A simple recursive function following the definition:  
     `Fib(n) = Fib(n-1) + Fib(n-2)`  
   - Demonstrates the concept of overlapping subproblems.

2. **Divide and Conquer – Matrix Multiplication**  
   - Uses the mathematical matrix form of Fibonacci computation:  
     ```
     | 1 1 |^n   =  | F(n+1) F(n)   |
     | 1 0 |       | F(n)   F(n-1) |
     ```
   - Efficiently computes large Fibonacci numbers in O(log n) time.

3. **Dynamic Programming (2 marks)**  
   - Builds up the Fibonacci sequence using a bottom-up approach.  
   - Avoids redundant computations by storing intermediate results.

---

## 🔍 Task 2: Search Algorithms

### Objective
Implement and demonstrate **Sequential** and **Binary Search** algorithms using both **iterative** and **recursive** approaches.

### Implementations
1. **Sequential Search – Iterative**  
   - Takes a list and a target value as input.  
   - Scans through each element until the target is found or list ends.  

2. **Sequential Search – Recursive**  
   - Searches recursively by checking one element per call.  
   - Returns the index if found, otherwise indicates "not found".

3. **Binary Search – Iterative**  
   - Works on a **sorted list**.  
   - Repeatedly divides the search interval in half.  
   - Returns index of target or "not found" message.

4. **Binary Search – Recursive**  
   - Recursive version of binary search using `low` and `high` indices.  
   - Searches the subarray based on the comparison with the middle element.

---

## ⚙️ Task 3: Heap, Priority Queue, and Heap Sort 

### Objective
Design and implement a **Heap data structure** and use it to build a **Priority Queue** and implement **Heap Sort**.

### Implementations
1. **Heap Implementation**  
   - Define a class/structure for the heap.  
   - Support:
     - Insertion of elements.
     - Heapify operation to maintain heap property.
     - Extract maximum and minimum elements.

2. **Priority Queue using Heap**  
   - Build a priority queue using the heap structure.  
   - Allow insertion with a given priority.  
   - Extract the element with the highest priority.  
   - Maintain heap property on every insertion or extraction.

3. **Heap Sort**  
   - Use the max heap to sort an array.  
   - Repeatedly extract the maximum element and rebuild the heap until sorted.  

---

## 🧠 Concepts Covered
- Recursion  
- Divide and Conquer  
- Dynamic Programming  
- Searching Algorithms  
- Heap Data Structure  
- Priority Queue Implementation  
- Heap Sort Algorithm  

---
## Contributors
- [Rokaya Maged](https://github.com/Rokaya-Maged)
- [Rawan Ashraf](https://github.com/rawan-ashraf)
