#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <stdbool.h>

typedef	struct s_node
{
	int				data;
	int				index;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

/* LINKED LIST MANIP */
t_node	*create_node(int data, int index);
t_node	*add_node_end(t_node	**head, t_node	*new_node);
t_node	*add_node_beg(t_node	**head, t_node	*new_node);
int		delete_list(t_node **head);
int		list_len(t_node	**head);
/*-------------------*/
/* PARSING */
static int	ft_isspace(int c);
long		ft_atoi(const char *str);
int			is_digit(char c);
int			valid_arg(char	*str);
bool		is_sorted(t_node **head);
bool		identical_found(t_node	**head, int new_data);
int			is_int(long a);
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
void	rra(t_node	**head);
void	sa(t_node	**head);
/*--------------*/
int	in_range(int a, int b, int	c);
t_node	*sort3(t_node	**head);
void 	sort2(t_node	**head);
void	sort5(t_node	**stack_a, t_node	**stack_b);
/* INSERT_SORT */
int		_min(int a, int b);
int		smallest(t_node	**stack_a, int len);
int		smallest0(t_node	**stack_a);
int		biggest(t_node	**stack_a);
int		position(t_node	**stack_a, int	data);
void	m_insert_sort(t_node	**stack_a, t_node	**stack_b);
void	wich_one_ra_rra(t_node	**stack_a, int	pos);
/*-------------*/
/*PRINT STACKS*/
void	print_list(t_node **head);
void	print_list_with_index(t_node **head);
void	print_stacks(t_node	**stack_a, t_node	**stack_b);
void	print_stacks_index(t_node	**stack_a, t_node	**stack_b);
/*------------*/
#endif