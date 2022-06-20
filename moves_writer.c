#include "push_swap.h"

void	pa(t_node **head_a, t_node	**head_b)
{
	push(head_b, head_a);
	write(1, "pa\n", 4);
}

void	pb(t_node **head_a, t_node	**head_b)
{
	push(head_a, head_b);
	write(1, "pb\n", 4);
}

void	ra(t_node	**head)
{
	rotate(head);
	write(1, "ra\n", 4);
}

void	rra(t_node	**head)
{
	rev_rotate(head);
	write(1, "rra\n", 5);
}

void	rrr(t_node	**head_a, t_node	**head_b)
{
	rev_rotate(head_a);
	rev_rotate(head_b);
}

void	sa(t_node	**head)
{
	swap(head);
	write(1, "sa\n", 4);
}
