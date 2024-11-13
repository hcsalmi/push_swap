# push_swap
A Hive Helsinki school project. Keywords: C, Sorting algorithms, Data sorting

The gist of it:
This project involves sorting data on a stack, with a limited set of instructions, and the smallest number of moves. To make this happen, you will have to manipulate various sorting algorithms and choose the most appropriate solution(s) for optimized data sorting.

More specifically:<br />
• You have 2 stacks named A and B.<br />
• At the beginning stack A contains a random amount of negative and/or positive numbers(no duplicates). Stack B is empty.<br />
• The goal is to sort in ascending order numbers into stack A. Following operations are allowed:<br />
&emsp;sa (swap a): Swap the first 2 elements at the top of stack A.<br />
&emsp;sb (swap b): Swap the first 2 elements at the top of stack B.<br />
&emsp;ss : sa and sb at the same time.<br />
&emsp;pa (push a): Take the first element at the top of B and put it at the top of A.<br />
&emsp;pb (push b): Take the first element at the top of A and put it at the top of B.<br />
&emsp;ra (rotate a): Shift up all elements of stack a by 1. The first element becomes the last one.<br />
&emsp;rb (rotate b): Shift up all elements of stack b by 1. The first element becomes the last one.<br />
&emsp;rr : ra and rb at the same time.<br />
&emsp;rra (reverse rotate a): Shift down all elements of stack a by 1. The last element becomes the first one.<br />
&emsp;rrb (reverse rotate b): Shift down all elements of stack b by 1. The last element becomes the first one.<br />
&emsp;rrr : rra and rrb at the same time.<br />
