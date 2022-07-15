#include "push_swap.h"

void	pa(t_node **head_a, t_node	**head_b)
{
	push(head_b, head_a);
	write(1, "pa\n", 3);
}

void	pb(t_node **head_a, t_node	**head_b)
{
	push(head_a, head_b);
	write(1, "pb\n", 3);
}

void	rb(t_node	**head)
{
	rotate(head);
	write(1, "rb\n", 3);
}

void	ra(t_node	**head)
{
	rotate(head);
	write(1, "ra\n", 3);
}
void	rra(t_node	**head)
{
	rev_rotate(head);
	write(1, "rra\n", 4);
}

void	rrb(t_node	**head)
{
	rev_rotate(head);
	write(1, "rrb\n", 4);
}

void	rrr(t_node	**head_a, t_node	**head_b)
{
	rev_rotate(head_a);
	rev_rotate(head_b);
	write(1, "rrr\n", 4);
}
void	sa(t_node	**head)
{
	swap(head);
	write(1, "sa\n", 3);
}

void	sb(t_node	**head)
{
	swap(head);
	write(1, "sb\n", 3);
}

void	ss(t_node	**head_a, t_node	**head_b)
{
	swap(head_a);
	swap(head_b);
	write(1, "ss\n", 3);
}

void	rr(t_node	**head_a, t_node	**head_b)
{
	rotate(head_a);
	rotate(head_b);
	write(1, "rr\n", 3);
}
