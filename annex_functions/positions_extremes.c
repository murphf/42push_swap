/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   positions_extremes.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: styes <styes@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 15:07:16 by styes             #+#    #+#             */
/*   Updated: 2022/07/26 19:44:15 by styes            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
* return the data of the node with the smallest data
*/
int	smallest(t_node	**stack_a)
{
	t_node	*first_node;
	int		min;

	first_node = *stack_a;
	min = _min(first_node->data, first_node->prev->data);
	while (first_node->next != *stack_a)
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
	t_node	*last_node;
	int		max;

	last_node = (*stack_a)->prev;
	max = _max((*stack_a)->data, last_node->data);
	while (last_node->prev != *stack_a)
	{
		if (last_node->data > max)
				max = last_node->data;
		last_node = last_node->prev;
	}
	if (last_node->data > max)
				max = last_node->data;
	return (max);
}

/*
* return position/index of node containing @data
*/
int	position(t_node	**head, int data)
{
	int		pos;
	t_node	*first_node;

	pos = 0;
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
	return (-1);
}

/*
* decide wich one is better to use in order to:
* get the number in position pos to the top of the STACK A
* ra or rra?
*/
void	wich_one_ra_rra(t_node **stack, int pos)
{
	int		mid;
	int		i;
	int		x;

	i = -1;
	x = list_len(stack) - pos;
	mid = (x + pos) / 2;
	if (mid > 0)
	{
		if (pos <= mid)
			while (++i < pos)
				ra(stack);
		else
			while (++i < x)
				rra(stack);
	}
}
