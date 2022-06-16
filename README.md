First: the parsing,
i've already made code that the number from one string , argv[1]
but I don't think they want that,
they want each argument to be a number.
I can make it work with both approaches:
> ./push_swap 9 8 7 4  && 
> ./push_swap "9 8 7 4"

--------I'll let the parsing part for last, and let's emulated with a given array----
**parsing rules:


0- sort 2
1- sort 3
2- sort 5
3- sort 100
4- sort 500
5- sort 1000+
--------
used data structure: circular doubly linked list

for the sake of simplification: I'll create a "libft_utils.c", but I'll have to call the makefile of libft in makefile of push_swap afterwards..

--------
the allowed actions:
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

sorting 5 numbers algorithm:
INPUT: -7 4 7 6 -2
EXPECTED OUTPUT: -7 -2 4 6 7
what happens:
1- pb + pb + (sort 3 numbers remaining in stack A)

---STACK A---		---STACK B---
	-2					
	6					4
	7					-7

2- see if the first number in stack B is an extreme (i.e smaller than the smallest or bigger than the biggest)
	a- if smallest: pa
	b- if biggest: pa + ra

3- if not an extreme, search its interval: we want the direct follower of the stack B number 

TESTING OF 5 NUMBERS:
1 2 5 0 8		10mv  --- could be 8mv
-1 2 5 0 8		8mv	  --- 
1 22 -5 0 8		9mv	  --- could be 7mv
1 22 -5 0 -8 	10mv

-------------
BEST ELEMENT ALGORITHM:
1- find the smallest number in STACK A and make it to the top (depending on its position, ra or rra)
2-determine the LIS (longuest increasing subsequence) starting ofc from the min of stack A 
	a- find the most optimized algorithm for that
3- remove all the numbers that doesn't belong to LIS from stack A (push them to STACK B)
	a-what 's the best element we can push from stack A to stack B (least moves)