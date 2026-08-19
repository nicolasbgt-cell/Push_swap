*This activity has been created as part of the 42 curriculum by nbigot.*

# 42 PUSH_SWAP

### Description

The Push swap project is a highly straightforward algorithm project that aims to sort data using a set of integer values, two stacks, and a set of operations to manipulate both stacks.
The students must write a progran in C called push_swap which calculates and displays on the stadard output the smallest program, made of push swap language operations, that sorts the integers received as arguments.

With this project, a team of two students from 42 Paris school will discover algorithm complexity in a very concrete way.

Both learners must contribute meaningfully to the project and understand all implemented algorithms. 
For this project, the structure of the program, the operations, and two of the sorting algorithms (simple and medium) were mainly developed by nbigot, while the parsing, the bench, the data initialization and the complex algorithm were mainly written by nbigot.

**Parsing**

The first function called by the program is check_args, that verify the validity of the input given by the user (eg. arguments that are not integers or outside the valid range, wrong modes or duplicate values).

**Data Initialization**

The next step is to initialize the data, that will be first put as a linked list of integer in the a stack. 
Both stacks (a and b) and a series of useful data (the optional bench, the disorder of the unsorted list, the strategy to use, the operations that will be used) are stored in a custom structure named data.

**The operations**

Here are the 11 basic operations we were allowed to use for our sorting algorithms:

|Code   | Instruction                         | Action                                                 |
| ----- | ----------------------------------- | ------------------------------------------------------ |
| `sa`  | swap a                              | swaps the 2 top elements of stack a                    |
| `sb`  | swap b                              | swaps the 2 top elements of stack b                    |
| `ss`  | swap a + swap b                     | both `sa` and `sb`                                     |
| `pa`  | push a                              | moves the top element of stack b at the top of stack a |
| `pb`  | push b                              | moves the top element of stack a at the top of stack b |
| `ra`  | rotate a                            | shifts all elements of stack a from bottom to top      |
| `rb`  | rotate b                            | shifts all elements of stack b from bottom to top      |
| `rr`  | rotate a + rotate b                 | both `ra` and `rb`                                     |
| `rra` | reverse rotate a                    | shifts all elements of stack a from top to bottom      |
| `rrb` | reverse rotate b                    | shifts all elements of stack b from top to bottom      |
| `rrr` | reverse rotate a + reverse rotate b | both `rra` and `rrb`                                   |

**The algorithms**

We selected the algorithms to use based on their time complexity, the time complexity being the number of operations needed to run an algorithm on large amount of datas. In computer science, we use the Big O notation O() to indicate the upper bound (or worst case scenario) of an algorithm, the algorithm runtime being expressed inside the parenthesis. 
 
One other thing to consider for choosing an algorithm is its space complexity, which is the total space taken by the algorithm with respect to the input size.

***Simple Algorithm***

For the simpler algorithm (that runs in O(n^2) time), we chose to use the selection sort method. We first need to find the minimal value in stack a, then, depending on its position in the stack, bring it to the top of the stack using the shortest path (ra operations, or rra). Once the minimal value is on top of stack a, it is pushed to stack b (with the pb operation).
These operations are repeated as many times as there are values in a. Once all the values are sorted and pushed to b, they are pushed back to stack as

The selection sort is a simple algorithm that happens to be very useful for small sets of data, but its run time increases really fast if the size of the list to sort increases. In the worst case scenario, if the list is sorted but in the wrong order (eg. 5 4 3 2 1), selection sort must do as many swaps as there are values in the list.
It can also be noted that the selection sort algorithm is very memory-efficient, with a space complexity of O(1), which makes it suitable for memory-limited emvironment.

***Medium algorithm***

The medium algorithm, running in O(n√n) time, uses chunk-based sorting. We first assign an index to each value in stack a (their position in the sorted list), then compute the chunk size as the integer square root of the stack size. For 100 elements, chunks are around 10; for 500, around 23.
In the first phase, we iterate through stack a and push values belonging to the current chunk to b with pb. Values from later chunks are rotated to the bottom with ra. When the current chunk is empty, we move on to the next, until a is fully empty.
In the second phase, we rebuild a sorted stack a by repeatedly extracting the maximum from b: we find its position, bring it to the top with the shortest path (rb or rrb), and push it back to a with pa. This strategy works well for medium-sized inputs (30 to 200 elements), where chunking limits rotations while keeping the algorithm simple and predictable.


***Complex algorithm***

We chose the LSD (least significant digit) radix sort method, that runs in the O(n log n) time class, for the complex algorithm. The particularity of radix sort is that it is a non-comparative sorting algorithm, that sorts numbers by processing individual digits. But instead of processing large numbers, or potential negative numbers, we will work with their indices (their position int the sorted list), that will be converted in binary.  So, like the medium algorithm, it starts by attributing an index value to each number in stack a, the index representing their relative order in the stack. We also created a function to get the maximum number of bits in the indexes of the numbers to sort. 

The algorithm works with two while loops. In the outer loop, we go throuh each bit of the numbers (index) in stack a, interating max_bits times. In the inner loop, we go through the stack a starting with the the least significant bit (rightmost) and moving towards the most significant bit (leftmost).
For each bit position :
- if the bit is 0, we move the number to stack b (using pb);
- if the bit is 1, we rotate stack a (ra), keeping the number in a.
After processing all numbers for a bit, we move all numbers from b back to a (with pa).
This process is repeated for each bit.

The radix sort algorithm has a time complexity of O(n * d), where n is the number of elements to sort, and d is the number of digits in the largest number. This is one of the reason we used the indices rather than the numbers on the list themselves. As radix sort has a linear time complexity, it is a very efficient algorithm for sorting large sets of integers. One of its disadvantage though is that it is not a efficient for small data sets. It also has a space complexity of O(n + k), that increases with the range of the input (k).


***Adaptive strategy***

The adaptive strategy is based on a preliminary step that will allow us to choose the most efficient algorithm based on the level of disorder - how already sorted is the initial list of integers. If the disorder is lesser than 0.2 (list mostly sorted already), it will chose the simple algorithm. In the case of a high disorder (more than 0.5), it will launch the complex algorithm. And if the disorder is somewhere in the middle, the medium algorithm will be chosen.


### Instructions

**Compilation**

- to compile the object files: `make`
- to remove object files: `make clean`
- to do a full rebuild: `make re`

**Input**

- to get the bench informations in the end of the program, write `--bench` as first argument
- you can then, optionally, specify the strategy by writing `--simple` for simple strategy, `--medium` for the medium one, `--complex` for the complex one, and `--adaptive` to let the program chose the best strategy based on the disorder.


### Resources

References used for this project:
- The Geeksforgeeks C language pages, especially this one <https://www.geeksforgeeks.org/dsa/sorting-algorithms/> to understand the different sorting algorithms, and this one <https://www.geeksforgeeks.org/c/bitwise-operators-in-c-cpp/> for the bitwise operators.
- The W3schools radix sort visualization : <https://www.w3schools.com/dsa/dsa_algo_radixsort.php>
- Push_Swap: The least amount of moves with two stacks <https://medium.com/@jamierobertdawson/push-swap-the-least-amount-of-moves-with-two-stacks-d1e76a71789a>
- Understanding Chunking Algorithms and Overlapping Techniques in Natural Language Processing <https://medium.com/@jagadeesan.ganesh/understanding-chunking-algorithms-and-overlapping-techniques-in-natural-language-processing-df7b2c7183b2>

### IA Resource by nicolas
I used Claude (Anthropic) to help me structure my thinking on the data structures, the operations and the sorting algorithms. The AI did not generate any code — every line was written and understood by me.
