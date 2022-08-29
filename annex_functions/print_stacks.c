/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stacks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: styes <styes@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 02:12:46 by styes             #+#    #+#             */
/*   Updated: 2022/08/29 17:26:58 by styes            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
/* printing functions to help me debug */

/* print the data of a circular doubly linked list's nodes */
void	print_list(t_node **head)
{
	t_node	*first_node;

	if (!*head)
	{
		printf("empty list\n");
		return ;
	}
	first_node = *head;
	printf("%d\n", first_node->data);
	first_node = first_node->next;
	while (first_node != *head)
	{
		printf("%d\n", first_node->data);
		first_node = first_node->next;
	}
}

/* print what's in both stacks A && B */
void	print_stacks(t_node	**stack_a, t_node	**stack_b)
{
	printf("stack a----\n");
	print_list(stack_a);
	printf("stack b----\n");
	print_list(stack_b);
}

void print_moves(t_node **stack)
{
	t_node *node;

	node = *stack;
	while (node->next != *stack)
	{
		printf("%d moves[0]= %d moves[1]= %d nb_mv = %d\n",node->data, node->moves[0], node->moves[1], node->nb_mv);
		node = node->next;
	}
	printf("%d moves[0]= %d moves[1]= %d nb_mv = %d\n",node->data, node->moves[0], node->moves[1], node->nb_mv);
}