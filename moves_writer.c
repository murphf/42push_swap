#include "push_swap.h"

/*
* apply push from stack a to stack b (pb) or vice versa (pa)
* depending on l value
* and write it down 
* n times
*/
int	consecutive_pa(t_node	**stack_a, t_node	**stack_b, int l, int n)
{
	int i;

	i = 0;
	while (i < n)
	{
		if (l == 1)
		{
			push(stack_b, stack_a);
			write(1, "pa\n", 4);
		}
		else
		{
			push(stack_a, stack_b);
			write(1, "pb\n", 4);
		}
		i++;
	}
	return (i);
}

int cons_ra(t_node **stack, int l, int n)
{
	int i;

	i = 0;
	while (i < n)
	{	
		rotate(stack);
		if (l == 1)
			write(1, "ra\n", 4);
		else
			write(1, "rb\n", 4);
		i++;
	}
	return (i);
}

int cons_rra(t_node **stack, int l, int n)
{
	int i;

	i = 0;
	while (i < n)
	{	
		rev_rotate(stack);
		if (l == 1)
			write(1, "rra\n", 5);
		else
			write(1, "rrb\n", 5);
		i++;
	}
	return (i);
}
int cons_sa(t_node **stack, int l, int n)
{
	int i;

	i = 0;
	while (i < n)
	{	
		swap(stack);
		if (l == 1)
			write(1, "sa\n", 4);
		else
			write(1, "sb\n", 4);
		i++;
	}
	return (i);
}