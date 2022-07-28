/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_manipulation.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: styes <styes@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 06:15:47 by styes             #+#    #+#             */
/*   Updated: 2022/07/28 02:00:21 by styes            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
* create a node and assign to it: 
* data
* and index
*/
t_node	*create_node(int data)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node->data = data;
	new_node->prev = new_node;
	new_node->next = new_node;
	return (new_node);
}

/*
* add new node at the end of circular doubly linked list 
* missing: special case handling/protection
*/
t_node	*add_node_end(t_node	**head, t_node	*new_node)
{
	t_node	*first_node;
	t_node	*last_node;

	first_node = *head;
	last_node = first_node->prev;
	new_node->next = *head;
	new_node->prev = last_node;
	last_node->next = new_node;
	first_node->prev = new_node;
	return (new_node);
}

/*
* add new node at the beginning of circular doubly linked list 
* missing: special case handling/protection
*/
t_node	*add_node_beg(t_node	**head, t_node	*new_node)
{
	t_node	*first_node;
	t_node	*last_node;

	if (*head)
	{
		first_node = *head;
		last_node = first_node->prev;
		new_node->next = first_node;
		new_node->prev = last_node;
		first_node->prev = new_node;
		last_node->next = new_node;
	}
	*head = new_node;
	return (new_node);
}

/*
* delete elements of doubly circular linked list
* the linked list's elements are deleted/freed in case of found errors
*/
void	delete_list(t_node **head)
{
	t_node	*first_node;
	t_node	*last_node;
	t_node	*save;

	if (!*head)
		return ;
	first_node = *head;
	last_node = first_node->prev;
	while (first_node != last_node)
	{
		save = first_node;
		first_node = first_node->next;
		free(save);
	}
	if (last_node != *head)
		free(last_node);
}

/*
* return the lenght of circular doubly linked list
*/
int	list_len(t_node	**head)
{
	t_node	*first_node;
	int		len;

	len = 1;
	first_node = *head;
	if (!first_node)
		return (0);
	while (first_node->next != *head)
	{
		len++;
		first_node = first_node->next;
	}
	return (len);
}
