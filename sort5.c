#include "push_swap.h"
void sort2(t_node	**head)
{
	if (!is_sorted(head))
		rotate(head);
}

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
		rev_rotate(head);
		swap(head);
	}
	else if (in_range(t, s, f))
		rotate(head);
	else if (in_range(f, t, s))
		rev_rotate(head);
	else if (in_range(f, s, t))
		swap(head);
	else if(in_range(s, t, f))
	{
		swap(head);
		rev_rotate(head);
	}
	return (*head);
}
int	smallest_in3(t_node	**head)
{
	return ((*head)->data);
}

int	biggest_int_3(t_node **head)
{
	return ((*head)->prev->data);
}

t_node	*sort5(t_node	**head_a, t_node	**head_b)
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

	while (first_node_b->data > first_node_a->data)
	{
		ra_count++;
		rra_count++;
		
		if (ra_count == 3)
			{	
				ra_count = 0;
				rra_count = 1;
				break;
			}
		first_node_a = first_node_a->next;
	}

	while (i < ra_count)
		rotate(head_a);
	push(head_b, head_a);
	i = 0;
	while (i < rra_count)
		rev_rotate(head_a);
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
		sort2(&stack_a) ;
	else if (len == 3)
		sort3(&stack_a);
	else if (len == 5)
	{
		push(&stack_a, &stack_b);
		push(&stack_a, &stack_b);
		sort2(stack_b);
		sort5(stack_a, stack_b);
		sort5(stack_a, stack_b);
	}
}