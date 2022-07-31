## Description 
Push_Swap is a 42 projoct who's aim is to sort a stack using a specific set moves

### Alowed moves
sa 
sb 
ss 
ra 
rb 
rr 
rra 
rrb 
rrr 

## GOAL
sort the stack in the least possible number of moves 
to get the full mark, 

3 numbers should be sorted in: max 2 moves  
5 numbers should be sorted in: max 12 moves  
100 numbers should be sorted in: max 700 moves   
500 numbers should be sorted in: max 5500 moves  

## how  
this is my implementation of "the best element algorithm" (as called by the original creator, see their instruction in ressource folder)   
### 1-parsing:  
if the input is valid it gets added to a doubly circular linked list  
#### what's a valid input?
- contains only digits, but may contain ('+' or '-') once at the begining  
- an INT  
- no duplicates   
### best element algorithm 
1- copy STACK A content in array  
2- put the smallest number at the begining of the array   
3- extract the Longuest Increasing Subsequence from the array  
4- now returning to STACK A:   
5- push all numbers to STACK B except the elements of LIS   
6- loop over STACK B calculating for each element:   
	1- number of moves it'll take for the element to be on top of STACK B --> the result would be stored in moves[1]    
		-if rb is used the number is positive  
		-if rrb is used the number is negative  
		-this distinction is made to be able to use rr / rrr in case of matching sign with moves[0]  
	2- number of moves it'll take to put the element (now hypotetically on top of STACK B) in its convenable place in STACK A  --> the result would be stored in moves[0]   
		- if ra is used the number is positive   
		- if rra is used the number is negative  
		- again, this distinction is made to be able to use rr / rrr is case of matching sign with moves[1]   
	3- calculate the total number of moves:   
		there is 2 cases:   
		a- if moves[0] and moves[1] have the same sign:   
			the total numbers of moves is the *maximum* of both absolute values  
		b- if moves[0] and moves[1] have different signs:  
			the total numbers of moves is the *sum* of both absolute values  
7- chose the element with the smallest (total number of moves) and push is to its convenable place in STACK A  
8- repeat step 6 and step 7 until STACK B in empty  
9- in STACK A, put smallest number on the top  

#### how to find its convenable place in STACK A