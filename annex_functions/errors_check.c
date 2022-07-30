/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: styes <styes@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 16:35:08 by styes             #+#    #+#             */
/*   Updated: 2022/07/30 00:49:52 by styes            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
* 2 types of error consequences
*/
void	error(int e, t_node	**stack_a)
{
	if (e)
	{
		write(2, "Error\n", 6);
		delete_list(stack_a);
	}
	exit(EXIT_FAILURE);
}

/*
* check if num is an int or not
*/
bool	is_int(long num)
{
	if (num >= INT_MIN  && num <= INT_MAX)
		return (true);
	return (false);
}

long	int_check(long num, t_node	**stack_a)
{
	if (num < INT_MIN || num > INT_MAX)
		error(1, stack_a);
	return num;
}

/*
* check if the list's data is sorted or not
*/
bool	is_sorted(t_node **head)
{
	t_node	*first_node;

	first_node = *head;
	if (!*head)
		return (false);
	while (first_node->next != *head)
	{
		if (first_node->data > first_node->next->data)
			return (false);
		first_node = first_node->next;
	}
	return (true);
}

/*
* check if the int new_data is already in the list
* start checking from the last node 
*/
bool	identical_found(t_node	**head, int new_data)
{
	t_node	*last_node;

	last_node = (*head)->prev;
	while (last_node != *head)
	{
		if (last_node->data == new_data)
			return (true);
		last_node = last_node->prev;
	}
	if (last_node->data == new_data)
		return (true);
	return (false);
}
