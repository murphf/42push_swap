/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best_element_algo.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: styes <styes@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 18:15:30 by styes             #+#    #+#             */
/*   Updated: 2022/07/30 04:16:16 by styes            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
* return POSITION of the number who needs the minimum moves
*/
int	find_minimum_moves(t_node **head)
{
	t_node	*first_node;
	int		min;
	int		pos;
	int		pos_m;

	first_node = *head;
	min = first_node->nb_mv;
	pos = 0;
	pos_m = pos;
	while (first_node->next != *head)
	{	
		if (first_node->nb_mv < min)
		{
			min = first_node->nb_mv;
			pos_m = pos;
		}
		pos++;
		first_node = first_node->next;
	}
	if (first_node->nb_mv < min)
	{
		min = first_node->nb_mv;
		pos_m = pos;
	}
	return (pos_m);
}

void	best_element(t_node	**head_a, t_node	**head_b)
{
	moves_counter1(head_b);
	moves_counter0(head_a, head_b);
	all_moves_stack_b(head_b);
	push_the_elemnt_to_a(head_a, head_b);
	smallest_on_top(head_a);
}

/*
* 1- create a copy of stack A (in array) 
* where the smallest number is on top 
* 2- extract the LONGUEST INCREASING SUBSEQ from that copy
* 2- let only the LIS in stack A i.e move all the the other numbers to STACK B
* 3- iterate on stack B and store how much moves are needed for each element
* 4- push the element who needs the least amount of moves 
* to its convenable place in STACK A
* 5- once STACK B get empty, move smallest element on top of STACK A
*/
void	only_lis(t_node	**head_a, t_node	**head_b)
{
	int		*lis;
	int		lis_len;
	int		o;
	t_node	*first_node;

	lis = lis_construct(head_a, list_len(head_a));
	lis_len = lis[0] + 1;
	first_node = *head_a;
	o = 0;
	while (o < lis_len)
	{
		if (in_array(lis, first_node->data, lis_len) == false)
		{
			wich_one_ra_rra(head_a, position(head_a, first_node->data));
			pb(head_a, head_b);
			first_node = *head_a;
		}
		else
		{
			first_node = first_node->next;
			o++;
		}
	}
	free(lis);
	best_element(head_a, head_b);
}
