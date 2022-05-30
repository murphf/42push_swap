#include "push_swap.h"

/*
* check if a is in range ]b, c[
*/
int	in_range(int a, int b, int	c)
{
	if (a > b && a < c)
		return (1);
	return (0);
}

void sort2(t_node	**head, int l)
{
	if (!is_sorted(head))
		cons_ra(head, l, 1);
}
/*
* sort 3 numbers
* moves depending of the posisiton
* of the max, min amd medium
* medium being the number between min and max
*/
t_node	*sort3(t_node	**head, int l)
{
	t_node	*f_node;
	int		f;
	int		s;
	int		t;

	f_node = *head;

	f = f_node->data;
	s = f_node->next->data;
	t = f_node->prev->data;
	
	if (in_range(t, f, s))
	{
		cons_rra(head, l, 1);
		cons_sa(head, l, 1);
	}
	else if (in_range(t, s, f))
		cons_ra(head, l, 1);
	else if (in_range(f, t, s))
		cons_rra(head, l, 1);
	else if (in_range(f, s, t))
		cons_sa(head, l, 1);
	else if(in_range(s, t, f))
	{
		cons_sa(head, l, 1);
		cons_rra(head, l, 1);
	}
	return (*head);
}

/*
* sort 5 numbers
*
*/
void	sort_small(t_node	**stack_a, t_node	**stack_b)
{
	t_node	*first_node;
	t_node	*last_node;
	int		len;
	int		pb;

	first_node = *stack_a;
	last_node = first_node->prev;
	len = last_node->index + 1;
	if (len == 2)
		sort2(stack_a, 1) ;
	else if (len == 3)
		sort3(stack_a, 1);
	else if (len == 5)
	{
		consecutive_pa(stack_a, stack_b, 2, 2);
		sort3(stack_a, 1);
		sort2(stack_b, 2);
	}
}