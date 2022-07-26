/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_writer2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: styes <styes@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 14:32:13 by styes             #+#    #+#             */
/*   Updated: 2022/07/26 23:32:02 by styes            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rrr(t_node	**head_a, t_node	**head_b)
{
	rev_rotate(head_a);
	rev_rotate(head_b);
	write(1, "rrr\n", 4);
}

void	sa(t_node	**head)
{
	swap(head);
	write(1, "sa\n", 3);
}

void	sb(t_node	**head)
{
	swap(head);
	write(1, "sb\n", 3);
}

void	ss(t_node	**head_a, t_node	**head_b)
{
	swap(head_a);
	swap(head_b);
	write(1, "ss\n", 3);
}

void	rr(t_node	**head_a, t_node	**head_b)
{
	rotate(head_a);
	rotate(head_b);
	write(1, "rr\n", 3);
}
