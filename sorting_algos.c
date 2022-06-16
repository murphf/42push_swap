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

/*
* return position of the number who's just AFTER n
*/
int	in_between(t_node	**stack_a, int n)
{
	t_node	*first_node;
	t_node	*last_node;
	int		i;

	i = 0;
	first_node = *stack_a;
	last_node = first_node->prev;
	while (first_node != last_node)
	{
		if (in_range(n, first_node->data, first_node->next->data))
			return (first_node->next->data);
		first_node = first_node->next;
		i++;
	}
	if (in_range(n, last_node->data, last_node->next->data))
		return (last_node->next->data);
	return (-1);
}

/*
* insert sort implemented using only one list
* THIS DON'T WORK: insert sort implementation in one linked list
*/
void	one_stack_insert_sort(t_node	**stack_a)
{
	int	small;
	int	pos;

	small = smallest(stack_a);
	pos = position(stack_a, small);
	wich_one_ra_rra(stack_a, pos);
}

/* SORT 5 NUMBERS: MAX: 12 MOVES*/

/*
* this sequence doesn't pass -7 4 7 6 -2
*/
void	sort5(t_node	**stack_a, t_node	**stack_b)
{
	int		pos;
	t_node	*last_node_a;
	t_node	*first_node_a;
	int		after;

	last_node_a = (*stack_a)->prev;
	pb(stack_a, stack_b);
	pb(stack_a, stack_b);
	sort3(stack_a);
	while (*stack_b)
	{
		if ((*stack_b)->data > biggest(stack_a))
		{
			pa(stack_a, stack_b);
			ra(stack_a);
		}
		else if ((*stack_b)->data < smallest(stack_a))
			pa(stack_a, stack_b);
		else
		{
			after = in_between(stack_a, (*stack_b)->data);
			pos = position(stack_a, after);
			wich_one_ra_rra(stack_a, pos);
			pa(stack_a, stack_b);
		}
		one_stack_insert_sort(stack_a);
	}
}