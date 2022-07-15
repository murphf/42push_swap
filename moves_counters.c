/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_counters.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: styes <styes@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 17:16:32 by styes             #+#    #+#             */
/*   Updated: 2022/07/15 18:28:11 by styes            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
* return how much ra/rb is needed for the node to be on top (positive number)
* or how much rra/rrb is needed.. (negative number) 
* DON'T COUNT PB
*/
int	to_the_top(t_node	**head, int pos)
{
	int		i;
	int		x;
	int		mid;	
	int		sign;

	i = 0;
	x = list_len(head) - pos;
	mid = (x + pos) / 2;
	sign = 1;
	if (mid > 0)
	{
		if (pos <= mid)
			while (i < pos)
				i++;
		else if (pos > mid)
		{
			sign = -1;
			while (i < x)
				i++;
		}
	}
	return (sign * i);
}

/*
* fill moves[1] of the STACK B numbers
* needed number of moves for each number to get on the top of STACK B
*/
void	moves_counter1(t_node	**head)
{
	t_node	*first_node;
	int		pos;

	if (!*head)
		return ;
	first_node = *head;
	while (first_node->next != *head)
	{
		pos = position(head, first_node->data);
		first_node->moves[1] = to_the_top(head, pos);
		first_node = first_node->next;
	}
	pos = position(head, first_node->data);
	first_node->moves[1] = to_the_top(head, pos);
}

/*
* calculate how many moves we meed to position number @num 
* from the top of STACK B to its fitting position in stack A 
* there's 4 cases.
*/
int	to_the_other_top(t_node	**head_a, int num)
{
	int		enter;
	int		best;
	t_node	*f_node;

	enter = 0;
	best = INT_MAX;
	f_node = *head_a;
	while (f_node->next != *head_a)
	{
		if (in_range(num, f_node->data, f_node->next->data))
		{
			enter = 1;
			if (f_node->next->data <= best)
				best = f_node->next->data;
		}
		f_node = f_node->next;
	}
	f_node = *head_a;
	if (in_range(num, f_node->prev->data, f_node->data) && f_node->data <= best)
		return (0);
	if (enter)
		return (to_the_top(head_a, position(head_a, best)));
	if (num > biggest(head_a))
		return (to_the_top(head_a, position(head_a, biggest(head_a))) + 1);
	return (-1);
}

/*
* fill moves[0] of the numbers of STACK B
* how much for it to get in the righ position in STACK A 
* (after getting in the top of STACK B)
*/
void	moves_counter0(t_node	**head_a, t_node	**head_b)
{
	t_node	*first_node_b;
	t_node	*last_node_b;

	if (!*head_b)
		return ;
	first_node_b = *head_b;
	last_node_b = first_node_b->prev;
	while (first_node_b != last_node_b)
	{
		first_node_b->moves[0] = to_the_other_top(head_a, first_node_b->data);
		first_node_b = first_node_b->next;
	}
	first_node_b->moves[0] = to_the_other_top(head_a, first_node_b->data);
}

/*
* claculate the sum of moves needed for each number in stack B
* so we can compare them and chose the one with the least number
*/
void	all_moves_stack_b(t_node	**head)
{
	t_node	*f_node;
	t_node	*l_node;

	if (!*head)
		return ;
	f_node = *head;
	l_node = f_node->prev;
	while (f_node != l_node)
	{
		if (same_sign(f_node->moves[0], f_node->moves[1]))
			f_node->nb_mv = _max(abs(f_node->moves[0]), abs(f_node->moves[1]));
		else
			f_node->nb_mv = abs(f_node->moves[0]) + abs(f_node->moves[1]);
		f_node = f_node->next;
	}
	if (same_sign(f_node->moves[0], f_node->moves[1]))
		f_node->nb_mv = _max(abs(f_node->moves[0]), abs(f_node->moves[1]));
	else
		f_node->nb_mv = abs(f_node->moves[0]) + abs(f_node->moves[1]);
}
