/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops0.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: styes <styes@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 14:45:47 by styes             #+#    #+#             */
/*   Updated: 2022/07/29 23:40:47 by styes            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
* swap first two elements of the list
*/
void	swap(t_node	**head)
{
	t_node	*first_node;
	t_node	*second_node;
	t_node	*third_node;
	t_node	*last_node;

	if (!*head)
		return ;
	if (list_len(head) == 2)
	{
		rotate(head);
		return ;
	}
	first_node = *head;
	second_node = first_node->next;
	third_node = second_node->next;
	last_node = first_node->prev;
	first_node->next = third_node;
	first_node->prev = second_node;
	second_node->next = first_node;
	second_node->prev = last_node;
	third_node->prev = first_node;
	last_node->next = second_node;
	*head = second_node;
}

/*
 * first element becomes last 
 */
void	rotate(t_node	**head)
{
	t_node	*second_node;

	if (!*head)
		return ;
	second_node = (*head)->next;
	*head = second_node;
}

/*
* last element becomes first
*/
void	rev_rotate(t_node	**head)
{
	t_node	*last_node;

	if (!*head)
		return ;
	last_node = (*head)->prev;
	*head = last_node;
}
