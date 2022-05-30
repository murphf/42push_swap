#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef	struct s_node
{
	int	data;
	int	index;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

/* LINKED LIST MANIP*/
t_node	*create_node(int data, int index);
t_node	*add_node_end(t_node	**head, t_node	*new_node);
t_node	*add_node_beg(t_node	**head, t_node	*new_node);
void	print_list(t_node **head);
int		delete_list(t_node **head);
/*-------------------*/
int		is_sorted(t_node **head);
int		identical_found(t_node	**head, int new_data);
void	swap(t_node	**head);
void	rotate(t_node	**head);
void	rev_rotate(t_node	**head);
t_node	*push(t_node	**stack1, t_node **stack2);
void	pop(t_node	**head);
t_node	*sort3(t_node	**head);
void sort2(t_node	**head);
void	sort_small(t_node	**stack_a, t_node	**stack_b);
static int	ft_isspace(int c);
int	ft_atoi(const char *str);

#endif