/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_writer1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: styes <styes@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 14:29:34 by styes             #+#    #+#             */
/*   Updated: 2022/07/26 23:31:57 by styes            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ra(t_node	**head)
{
	rotate(head);
	write(1, "ra\n", 3);
}

void	rra(t_node	**head)
{
	rev_rotate(head);
	write(1, "rra\n", 4);
}

void	rrb(t_node	**head)
{
	rev_rotate(head);
	write(1, "rrb\n", 4);
}
