#include "push_swap.h"
void	m_insert_sort(t_node	**stack_a, t_node	**stack_b)
{
	int		small;
	int		pos;
	int 	i = 0;

	while (*stack_a)
	{
		small = smallest(stack_a);
		pos = position(stack_a, small);
		wich_one_ra_rra(stack_a, pos);
		pb(stack_a, stack_b);
		i++;
	}
	while (*stack_b)
		pa(stack_a, stack_b);	
}