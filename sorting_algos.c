#include "push_swap.h"

/*
* range isn't a sufficant condition 
*/
t_node	*sort3(t_node	**head)
{
	t_node	*f_node;
	int		f;
	int		s;
	int		t;

	f_node = *head;
	s = f_node->next->data;
	t = f_node->prev->data;
	if (in_range(f, t, s))
	{
		rev_rotate(head);
		swap(head);
		printf("rra\nsa");
	}
	else if (in_range(t, s, f))
	{
		rev_rotate(head);
		printf("rra\n");
	}
	else if (in_range(s, f, t))
	{
		rotate(head);
		printf("ra\n");
	}
	else if (in_range(s, t, f))
	{
		swap(head);
		printf("sa\n");
	}
	else if (in_range (t, f, s))
	{
		;
	}
}

/*
* check if a is in range ]b, c[
*/
int	in_range(int a, int b, int	c)
{
	if (a > b && a < c)
		return (1);
	return (0);
}

