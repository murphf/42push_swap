/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_best_element.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: styes <styes@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 17:09:00 by styes             #+#    #+#             */
/*   Updated: 2022/07/16 18:36:29 by styes            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* PSEUDOCODE
* 1- find the element with the least amount of moves
* 2- CASES:
	A- moves[0] && moves[1] have the same sign
		a- strict positive
		b- strict negative
	B- moves[0] && moves[1] have different signs:
*/

/*
* moves[0] && moves[1] are both strictly positive
*/
void	pos_same_half(t_node	**head_a, t_node	**head_b, t_node	*node)
{
	int	inter;
	int	extra;
	int	big;
	int	i;

	inter = _min(abs(node->moves[0]), abs(node->moves[1]));
	big = _max(abs(node->moves[0]), abs(node->moves[1]));
	extra = big - inter;
	i = -1;
	while (++i < inter)
		rr(head_a, head_b);
	i = -1;
	if (big == abs(node->moves[0]))
		while (++i < extra)
			ra(head_a);
	else if (big == abs(node->moves[1]))
		while (++i < extra)
			rb(head_b);
	pa(head_a, head_b);
}

/*
* moves[0] && moves[1] are both strictly negative
*/
void	neg_same_half(t_node	**head_a, t_node	**head_b, t_node	*node)
{
	int	inter;
	int	extra;
	int	big;
	int	i;

	inter = _min(abs(node->moves[0]), abs(node->moves[1]));
	big = _max(abs(node->moves[0]), abs(node->moves[1]));
	extra = big - inter;
	i = -1;
	while (++i < inter)
		rrr(head_a, head_b);
	i = -1;
	if (big == abs(node->moves[0]))
		while (++i < extra)
			rra(head_a);
	else if (big == abs(node->moves[1]))
		while (++i < extra)
			rrb(head_b);
	pa(head_a, head_b);
}

/*
* moves[0] && moves[1] have the same sign;
* both strictly positive
* or both strictly negative
*/
void	same_half(t_node	**head_a, t_node	**head_b, t_node	*node)
{
	if (node->moves[0] > 0)
		pos_same_half(head_a, head_b, node);
	else
		neg_same_half(head_a, head_b, node);
}

void	diff_halfs(t_node	**head_a, t_node	**head_b, t_node	*node)
{
	int		combo;
	int		extra;
	int		i;

	combo = abs(node->moves[0]);
	extra = abs(node->moves[1]);
	i = -1;
	if (node->moves[0] >= 0)
		while (++i < combo)
			ra(head_a);
	else if (node->moves[0] < 0)
		while (++i < combo)
			rra(head_a);
	i = -1;
	if (node->moves[1] >= 0)
		while (++i < extra)
			rb(head_b);
	else if (node->moves[1] < 0)
		while (++i < extra)
			rrb(head_b);
	pa(head_a, head_b);
}

void	push_the_elemnt_to_a(t_node	**head_a, t_node	**head_b)
{
	int		best_el_pos;
	t_node	*node_b;
	int		i;

	i = 0;
	while (*head_b)
	{
		best_el_pos = find_minimum_moves(head_b);
		node_b = node_of_index(head_b, best_el_pos);
		if (same_sign(node_b->moves[0], node_b->moves[1]))
			same_half(head_a, head_b, node_b);
		else
			diff_halfs(head_a, head_b, node_b);
		if (*head_b)
		{
			moves_counter1(head_b);
			moves_counter0(head_a, head_b);
			all_moves_stack_b(head_b);
		}
	}
}
