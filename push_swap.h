#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <stdbool.h>
#include "libft/libft.h"
#define N 42
typedef	struct s_node
{
	int				data;
	struct s_node	*prev;
	struct s_node	*next;
	int			moves[2];
	int			nb_moves;
}	t_node;

typedef struct s_stack
{
	t_node	**stack_a;
	t_node	**stack_b;
} t_stack;

/* LINKED LIST MANIP */
t_node	*create_node(int data);
t_node	*add_node_end(t_node	**head, t_node	*new_node);
t_node	*add_node_beg(t_node	**head, t_node	*new_node);
int		delete_list(t_node **head);
int		list_len(t_node	**head);
/*-------------------*/
/* PARSING */
int			valid_arg(char	*str);
t_node		**parsing(int argc, char **argv);
/*---------*/
/*ERRORS_CHECK*/
void		error(int e, t_node	**stack_a);
bool		is_int(long num);
bool		is_sorted(t_node **head);
bool		identical_found(t_node	**head, int new_data);

/*---------*/
/* MOVES */
void	swap(t_node	**head);
void	rotate(t_node	**head);
void	rev_rotate(t_node	**head);
t_node	*push(t_node	**stack1, t_node **stack2);
void	pop(t_node	**head);
/*--------*/
/* MOVES WRITERS */
void	pa(t_node **head_a, t_node	**head_b);
void	pb(t_node **head_a, t_node	**head_b);
void	ra(t_node	**head);
void	rb(t_node	**head);
void	rr(t_node	**head_a, t_node	**head_b);
void	rra(t_node	**head);
void	rrb(t_node	**head);
void	rrr(t_node	**head_a, t_node	**head_b);
void	sa(t_node	**head);
void	sb(t_node	**head);
void	ss(t_node	**head_a, t_node	**head_b);
/*--------------*/
int	in_range(int a, int b, int	c);
t_node	*sort3(t_node	**head);
void 	sort2(t_node	**head);
void	sort5(t_node	**stack_a, t_node	**stack_b);
/* INSERT_SORT */
int		_min(int a, int b);
int		_max(int a, int b);
int		smallest(t_node	**stack_a);
int		biggest(t_node	**stack_a);
int		position(t_node	**head, int	data);
void	m_insert_sort(t_node	**stack_a, t_node	**stack_b);
void	wich_one_ra_rra(t_node	**stack_a, int	pos);
/*-------------*/
/*PRINT STACKS*/
void	print_list(t_node **head);
void	print_stacks(t_node	**stack_a, t_node	**stack_b);
void	print_stacks_index(t_node	**stack_a, t_node	**stack_b);
/*------------*/
/*LONGUEST INCREASING SUBSEQUENCE*/
void	smallest_on_top(t_node	**head);
void	biggest_on_top(t_node	**head);
void	best_element(t_node	**head_a, t_node	**head_b);
t_node  *node_of_index(t_node   **head, int i);
int		*LIS_constructor(t_node	**stack_a);
int		abs(int	n);
int		find_minimum_moves(t_node	**head);
void	push_the_elemnt_to_a(t_node	**head_a, t_node	**head_b);
bool	same_sign(int	a, int	b);
bool	in_array(int	*array, int nbr, int len);
/*MOVES COUNTER*/
void	moves_counter0(t_node	**head_a, t_node	**head_b);
void	moves_counter1(t_node	**head);
int		how_much_to_the_other_top(t_node	**head_a, int num);
int		how_much_to_the_top(t_node	**head, int pos);
void	print_nb_of_moves(t_node	**head);
void	all_moves_stack_b(t_node	**head);
/*-------------*/
/*ARRAYS*/
int		*list_to_array(t_node	**head);
void 	printarray(int *array, int size);
/*QUICKSORT*/
void 	swap2(int *a, int *b);
int		partition(int	*arr, int low, int high);
void	quicksort(int	*arr, int	low, int	high);
int		*quicksort__stack(t_node    **stack_a, int size);
void    subseq(t_node   **stack_a, t_node   **stack_b, int  *sorted_arr);
/*-----*/
/*C LIS_CONSTRUCTOR*/
int	*creat_fill(int n, int size);
int	*lis_construct0(t_node	**head, int	size);
int	*lis_construct(int *arr, int	size);

int	*arr_smallest_on_top(t_node	**head);
#endif