#include "push_swap.h"
/*LONGUEST INCREASING SUBSEQUENCE*/



/*
* put smallest number on top of the stack (STACK A) 
*/
void	smallest_on_top(t_node	**head)
{
	int	small;
	int	pos;

	if (*head == NULL)
		return ;
	small = smallest(head);
	pos = position(head, small);
	wich_one_ra_rra(head, pos);
}

bool	in_lis(int	*array, int nbr, int len)
{
	int i;

	i = 0;
	while (i < len)
	{
		if (array[i] == nbr)
			return (true);
		i++;
	}
	return (false);
}

/*
* 1- let the smallest be on top
* 2- let only the longuest increasing subsq in stack A
*/
void	best_element(t_node	**head_a, t_node	**head_b)
{
	int		*lis;
	int		lis_len;
	int		pos;
	t_node	*first_node;
	t_node	*last_node;

	smallest_on_top(head_a);
	first_node = *head_a;
	last_node = first_node->prev;
	lis = lis_constructor(head_a);
	lis_len = 6; //lenght of LIS
	while (first_node != last_node)
	{
		if (in_lis(lis, first_node->data, lis_len) == false)
		{
			pos = position(head_a, first_node->data);
			wich_one_ra_rra(head_a, pos);
			pb(head_a, head_b);
			first_node = *head_a;
			last_node = first_node->prev;
		}
		first_node = first_node->next;
	}
	if (in_lis(lis, first_node->data, lis_len) == false)
	{
		pos = position(head_a, first_node->data);
		wich_one_ra_rra(head_a, pos);
		pb(head_a, head_b);
	}
}
