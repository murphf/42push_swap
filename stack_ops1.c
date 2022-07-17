/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: styes <styes@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 14:46:02 by styes             #+#    #+#             */
/*   Updated: 2022/07/16 15:04:49 by styes            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
* push first element of stack1 to the top of stack2
* works good unless we don't have a stack2
*/
void	push(t_node	**stack1, t_node **stack2)
{
	int	data_of_first;

	if (!*stack1)
		return ;
	data_of_first = (*stack1)->data;
	pop(stack1);
	if (!*stack2)
		*stack2 = create_node(data_of_first);
	else
		add_node_beg(stack2, create_node(data_of_first));
}

void	del_node(t_node	*node)
{
	free(node);
	node = NULL;
}

/*
* delete first element of list
*/
void	pop(t_node	**head)
{
	t_node	*first_node;
	t_node	*second_node;
	t_node	*last_node;

	first_node = *head;
	second_node = first_node->next;
	last_node = first_node->prev;
	if (first_node == last_node)
	{
		del_node(first_node);
		*head = NULL;
		return ;
	}
	second_node->prev = last_node;
	last_node->next = second_node;
	del_node(first_node);
	*head = second_node;
}
