# push_swap
An optimized sort using only two stacks and a set of operations


## Installation
Clone repository and type `make all`

## The Game
The purpose of this program is to sort a list of non duplicate integers using two stacks and a specific set of instructions available for manipulating the stacks.
Stack A is initialized with the number set with Stack B empty, and program must output an optimized list of instructions that result in a sorted Stack A and an empty Stack B.
The goal is to sort the stacks with the fewest possible instructions.

## Instructions
The list of allowed instructions is as follows:
* sa - swap the first two elements of stack a
* sb - swap the first two elements of stack b
* ss - sa and sb at the same time
* pa - pop the top element on stack b and push it onto stack a
* pb - pop the top element on stack a and push it onto stack b
* ra - shift up all elements of stack a by 1. The first element becomes the last one
* rb - shift up all elements of stack b by 1. The first element becomes the last one
* rr - ra and rb at the same time
* rra - shift all elements of stack a down by 1. The last element becomes the first one
* rrb - shift all elements of stack b down by 1. The last element becomes the first one
* rrr - rra and rrb at the same time

## Usage
run `./push_swap	[-v] [numbers to sort...]`

Use the perl random number generator to make numbers to use as input:

`arg=$(perl randomnumber.pl 32) ; ./push_swap $arg`

The `-v` option enables the debug visualizer
