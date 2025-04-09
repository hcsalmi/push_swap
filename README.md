# push_swap

*A Hive Helsinki school project*  
**Keywords:** `C`, `Sorting algorithms`, `Data sorting`

---

## 📌 The Gist of It

This project involves sorting data on a stack using a **limited set of instructions**, and achieving it with the **smallest number of moves** possible.

To do this, you’ll need to implement and manipulate various sorting algorithms, and choose the most efficient solution(s) for optimized data sorting.

---

## 🧠 More Specifically

- You have **two stacks**, named `A` and `B`.
- Initially, **stack A** contains a random set of **positive and/or negative integers** (no duplicates).
- **Stack B** starts empty.
- The goal is to sort **stack A in ascending order** using the allowed operations.

---

## ⚙️ Allowed Operations
&emsp;- `sa` (swap a): Swap the first 2 elements at the top of stack A.<br />

&emsp;- `sb` (swap b): Swap the first 2 elements at the top of stack B.<br />

&emsp;- `ss`: Perform `sa` and `sb` simultaneously.<br />

&emsp;- `pa` (push a): Push the top element from stack B to the top of stack A.<br />

&emsp;- `pb` (push b): Push the top element from stack A to the top of stack B.<br />

&emsp;- `ra` (rotate a): Shift up all elements of stack A by 1. The first element becomes the last one.<br />

&emsp;- `rb` (rotate b): Shift up all elements of stack B by 1. The first element becomes the last one.<br />

&emsp;- `rr`: Perform `ra` and `rb` simultaneously.<br />

&emsp;- `rra` (reverse rotate a): Shift down all elements of stack A by 1. The last element becomes the first one.<br />

&emsp;- `rrb` (reverse rotate b): Shift down all elements of stack B by 1. The last element becomes the first one.<br />

&emsp;- `rrr`: Perform `rra` and `rrb` simultaneously.<br />
