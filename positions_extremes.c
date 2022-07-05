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

/*
* for the sake of optimisation we will start from the last node
* return the data of the node with the biggest data
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
* return position/index of node containing data
*/
int position(t_node	**head, int data)
{
	int	pos;

	pos = 0;
	t_node	*first_node;

	first_node = *head;
	while (first_node->next != *head)
	{
		if (first_node->data == data)
			return (pos);
		pos++;
		first_node = first_node->next;
	}
	if (first_node->data == data)
			return (pos);
	return(-1);
}

/*
* decide wich one is easier to use in order to get the number in position pos to the top of the stack
* ra or rra?
* based on the lenght of stack A
* and position of the node	
*/
void	wich_one_ra_rra(t_node	**stack, int	pos)
{
	int		mid;
	int		len;
	int		i;
	int		x;

	i = 0;
	len = list_len(stack);
	mid = len / 2;
	if (mid > 0)
	{
		if (pos && pos <= mid)
		{
			while (i < pos)
			{
				ra(stack);
				i++;
			}
		}
		else if ( pos && pos > mid)
		{
			x = len - pos;
			while (i < x)
			{
				rra(stack);
				i++;
			}
		}
	}
}