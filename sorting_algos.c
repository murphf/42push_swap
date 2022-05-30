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
	rotate(head);
	printf("ra\n");
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
		rev_rotate(head);
		swap(head);
		printf("rra\nsa\n");
	}
	else if (in_range(t, s, f))
	{
		rotate(head);
		printf("ra\n");
	}
	else if (in_range(f, t, s))
	{
		rev_rotate(head);
		printf("rra\n");
	}
	else if (in_range(f, s, t))
	{
		swap(head);
		printf("sa\n");
	}
	else if(in_range(s, t, f))
	{
		swap(head);
		rev_rotate(head);
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

	first_node = *stack_a;
	last_node = first_node->prev;
	if (last_node->index == 1)
		sort2(stack_a);
	else if (last_node->index == 2)
		sort3(stack_a);

}