First: the parsing,
i've already made code that the number from one string , argv[1]
but I don't think they want that,
they want each argument to be a number.
I can make it work with both approaches:
> ./push_swap 9 8 7 4  && 
> ./push_swap "9 8 7 4"

--------I'll let the parsing part for last, and let's emulated with a given array
1- sort 3
2- sort 5
3- sort 100
4- sort 500

--------
used data structure: circular doubly linked list

for the sake of simplification: I'll create a "libft_utils.c", but I'll have to call the makefile of libft in makefile of push_swap afterwards..

--------
the given actions:
let's say we have list [9, 4, 8, 7] in stack A and [1, 2] in stack B:
NOTE: initially stack b is empty

sa *Swap the first 2 elements at the top of stack*
sa: A = [4, 9, 8, 7] 	sb: B = [2, 1]
ss = sa + sb

pa * Take the first element at the top of b and put it at the top of a*
pa: [1, 9, 4, 8, 7]	B = [2]
pb: A = [4, 8, 7] 	B = [9, 2, 1]

ra *first element becomes last one*
ra: A = [4, 8, 7, 9]   rb: B = [1, 2]
rr = ra + rb

rra *The last element becomes the first one*
rra: A = [7, 9, 4, 8]	rrb: B = [2, 1]
rrr = rra + rrb
-------
I can store the minimum number while creating the list