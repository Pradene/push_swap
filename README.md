# Push Swap
Push_Swap is a project that involves sorting a list of integers using two stacks and a limited set of operations. The goal is to arrange the numbers in ascending order with the fewest possible moves.

## Description
In this project, you are provided with two stacks, a and b. Stack a is initialized with a set of unsorted integers, while stack b starts empty. The objective is to sort the integers in stack a using a series of operations that manipulate both stacks. The challenge lies in achieving the sorted order using the minimum number of operations.

## Instructions
The following operations are available to manipulate the stacks:

- sa: Swap the first two elements of stack a.
- sb: Swap the first two elements of stack b.
- ss: Perform sa and sb simultaneously.
- pa: Push the top element of stack b onto stack a.
- pb: Push the top element of stack a onto stack b.
- ra: Rotate stack a upward (move the first element to the last position).
- rb: Rotate stack b upward.
- rr: Perform ra and rb simultaneously.
- rra: Rotate stack a downward (move the last element to the first position).
- rrb: Rotate stack b downward.
- rrr: Perform rra and rrb simultaneously.

## Installation

1. Clone the repo:
    ```bash
    git clone https://github.com/Pradene/push_swap
    ```

2. Build the project
    ```bash
    make
    ```

## Usage
After compilation, you can use the push_swap program to sort a list of integers. For example:

```bash
./push_swap 3 2 5 4 1
```
This command will output the sequence of operations needed to sort the numbers 3 2 5 4 1 in ascending order.
