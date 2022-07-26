/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ./includes/push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: styes <styes@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 06:09:20 by styes             #+#    #+#             */
/*   Updated: 2022/07/26 03:03:22 by styes            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdbool.h>
# include <unistd.h>
# include "../libft/libft.h"

typedef struct s_node
{
	int				data;
	struct s_node	*prev;
	struct s_node	*next;
	int				moves[2];
	int				nb_mv;
}	t_node;

typedef struct s_stack
{
	t_node	**stack_a;
	t_node	**stack_b;
}	t_stack;

/* ALGEBRA */
bool	same_sign(int a, int b);
int		abs(int n);
int		_min(int a, int b);
int		_max(int a, int b);
int		in_range(int a, int b, int c);

/* ERROR CHECK */
void	error(int e, t_node	**stack_a);
bool	is_int(long num);
bool	is_sorted(t_node **head);
bool	identical_found(t_node	**head, int new_data);

/* PARSING */
int	valid_arg(char	*str, t_node	**stack_a);
t_node	**parsing(int argc, char **argv);

/* ARRAY MANIPULATION */
int		*list_to_array(t_node	**head);
int		*arr_smallest_on_top(t_node	**head);
void	printarray(int *array, int size);

/* LINKED LIST MANIPULATION */
t_node	*create_node(int data);
t_node	*add_node_end(t_node	**head, t_node	*new_node);
t_node	*add_node_beg(t_node	**head, t_node	*new_node);
void	delete_list(t_node **head);
int		list_len(t_node	**head);

/* BEST ELEMENT ALGO */
int		find_minimum_moves(t_node **head);
void	best_element(t_node	**head_a, t_node	**head_b);
void	only_lis(t_node	**head_a, t_node	**head_b);
void	smallest_on_top(t_node	**head);
t_node	*node_of_index(t_node **head, int i);
bool	in_array(int	*array, int nbr, int len);
int		to_the_top(t_node	**head, int pos);
int		to_the_other_top(t_node	**head_a, int num);
void	moves_counter1(t_node	**head);
void	moves_counter0(t_node	**head_a, t_node	**head_b);
void	all_moves_stack_b(t_node	**head);
void	pos_same_half(t_node	**head_a, t_node	**head_b, t_node	*node);
void	neg_same_half(t_node	**head_a, t_node	**head_b, t_node	*node);
void	same_half(t_node	**head_a, t_node	**head_b, t_node	*node);
void	diff_halfs(t_node	**head_a, t_node	**head_b, t_node	*node);
void	push_the_elemnt_to_a(t_node	**head_a, t_node	**head_b);
t_node	*sort3(t_node	**head);

/* LONGUEST INCREASING SUBSEQUENCE */
int		*creat_fill(int n, int size);
int		*lis_construct(t_node **head, int size);

/* MOVES */
void	swap(t_node	**head);
void	rotate(t_node	**head);
void	rev_rotate(t_node	**head);
void	push(t_node	**stack1, t_node **stack2);
void	pop(t_node	**head);
void	del_node(t_node	*node);
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

/* POSITIONS AND EXTREMES */
int		smallest(t_node	**stack_a);
int		biggest(t_node	**stack_a);
int		position(t_node	**head, int data);
void	wich_one_ra_rra(t_node **stack, int pos);

/* PRINT STACKS */
void	print_list(t_node **head);
void	print_stacks(t_node	**stack_a, t_node	**stack_b);

/* CHECKER */
void	error_check(t_node	**stack_a, t_node	**stack_b);
void	instruction_2l(char *mv, t_node **stack_a, t_node	**stack_b);
void	instruction_3l(char *mv, t_node **stack_a, t_node	**stack_b);
#endif
