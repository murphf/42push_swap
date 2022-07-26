/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_writer0.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: styes <styes@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 14:29:22 by styes             #+#    #+#             */
/*   Updated: 2022/07/26 23:31:52 by styes            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	pa(t_node **head_a, t_node	**head_b)
{
	push(head_b, head_a);
	write(1, "pa\n", 3);
}

void	pb(t_node **head_a, t_node	**head_b)
{
	push(head_a, head_b);
	write(1, "pb\n", 3);
}

void	rb(t_node	**head)
{
	rotate(head);
	write(1, "rb\n", 3);
}
