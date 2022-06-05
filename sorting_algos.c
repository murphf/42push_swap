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

void sort2(t_node	**head)
{
	if (!is_sorted(head))
		ra(head);
}
/*
* sort 3 numbers
* moves depending of the posisiton
* of the max, min amd medium
* medium being the number between min and max
*/
t_node	*sort3(t_node	**head)
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
		rra(head);
		sa(head);
	}
	else if (in_range(t, s, f))
		ra(head);
	else if (in_range(f, t, s))
		rra(head);
	else if (in_range(f, s, t))
		sa(head);
	else if(in_range(s, t, f))
	{
		sa(head);
		rra(head);
	}
	return (*head);
}
t_node	*sort4(t_node	**head_a, t_node	**head_b)
{
	t_node	*first_node_a;
	t_node	*first_node_b;
	int	ra_count;
	int	rra_count;
	int	i;

	i = 0;
	ra_count = 0;
	rra_count = 0;
	first_node_a = *head_a;
	first_node_b = *head_b;

	while (first_node_b->data > first_node_a->data && i < 5)
	{
		i++;
		ra_count++;
		rra_count++;
		first_node_a = first_node_a->next;
	}

	i = 0;
	while (i < ra_count)
	{
		ra(head_a);
		i++;
	}
	//push(head_b, head_a);
	pa(head_a, head_b);
	i = 0;
	while (i < rra_count)
	{
		rra(head_a);
		i++;
	}
}
/*
* sort in a very naive manner
*/

void	sorting_unoptimized(t_node	**stack_a, t_node	**stack_b)
{
	int	len;
	int	extra;
	int	i;
	t_node	*first_node_a;
	t_node	*first_node_b;

	first_node_a = *stack_a;
	first_node_b = *stack_b;
	len = list_len(stack_a);
	extra = len - 3;
	i = 0;
	
	while (i < extra)
	{
		pb(stack_a, stack_b);
		i++;
	}
	sort3(stack_a);
	i = 0;
	while (i < extra)
	{
		sort4(stack_a, stack_b);
		i++;
	}
}
/*
* sort 5 numbers
*/
void	sort_small(t_node	**stack_a, t_node	**stack_b)
{
	t_node	*first_node;
	t_node	*last_node;
	int		len;

	first_node = *stack_a;
	last_node = first_node->prev;
	len = last_node->index + 1;
	if (len == 2)
		sort2(stack_a);
	else if (len == 3)
		sort3(stack_a);
	else if (len > 3)
	{
		sorting_unoptimized(stack_a, stack_b);
	}
}