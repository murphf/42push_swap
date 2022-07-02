#include "push_swap.h"

int	_min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}
int	_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}
/*
* return the data of the node with the smallest data
*/
int	smallest(t_node	**stack_a)
{
	t_node	*first_node;
	t_node	*last_node;
	int		min;

	first_node = *stack_a;
	last_node = first_node->prev;
	min = _min(first_node->data, last_node->data);
	while (first_node != last_node)
	{
		if (first_node->data < min)
				min = first_node->data;
		first_node = first_node->next;
	}
	return (min);
}

// int	smallest(t_node	**stack_a, int len)
// {
// 	t_node	*first_node;
// 	t_node	*last_node;
// 	int		min;
// 	int		i;

// 	i = 0;
// 	first_node = *stack_a;
// 	min = first_node->data;
// 	while (i < len)
// 	{
// 		if (first_node->data < min)
// 				min = first_node->data;
// 		first_node = first_node->next;
// 		i++;
// 	}
// 	return (min);
// }
/*
* for the sake of optimisation we will start from the last node
*/
int	biggest(t_node	**stack_a)
{
	t_node	*first_node;
	t_node	*last_node;
	int		max;

	first_node = *stack_a;
	last_node = first_node->prev;
	max = _max(first_node->data, last_node->data);
	while (last_node != first_node)
	{
		if (last_node->data > max)
				max = last_node->data;
		last_node = last_node->prev;
	}
	return (max);
}

/*
* return index of node containing data
*/
int		position(t_node	**stack_a, int	data)
{
	int	i;

	i = 0;
	t_node	*first_node;
	t_node	*last_node;

	first_node = *stack_a;
	last_node = first_node->prev;
	while (first_node != last_node)
	{
		if (first_node->data == data)
				return (i);
		first_node = first_node->next;
		i++;
	}
	if (first_node->data == data)
		return (i);
	return (-1);
}

/*
* decide wich one is easier to use in order to get the smallest number to the top
* ra or rra?
* based on the lenght of stack A
* and position of the node	
*/
void	wich_one_ra_rra(t_node	**stack_a, int	pos)
{
	int		mid;
	int		len;
	int		i;
	int		x;

	i = 0;
	len = list_len(stack_a);
	mid = len / 2;
	if (mid > 0)
	{
		if (pos && pos <= mid)
		{
			while (i < pos)
			{
				ra(stack_a);
				i++;
			}
		}
		else if ( pos && pos > mid)
		{
			x = len - pos;
			while (i < x)
			{
				rra(stack_a);
				i++;
			}
		}
	}
}

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