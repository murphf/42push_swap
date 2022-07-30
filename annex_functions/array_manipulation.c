/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_manipulation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: styes <styes@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 15:24:24 by styes             #+#    #+#             */
/*   Updated: 2022/07/30 04:15:07 by styes            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
* convert circular doubly linked list to an array
*/
int	*list_to_array(t_node	**head)
{
	int		len;
	t_node	*first_node;
	int		*array;
	int		i;

	len = list_len(head);
	first_node = *head;
	array = (int *)malloc(sizeof(int) * len);
	if (!array)
		return (NULL);
	i = 0;
	while (i < len)
	{
		array[i++] = first_node->data;
		first_node = first_node->next;
	}
	return (array);
}

/*
* return array version of the list 
* with the the smallest number at the begining
*/
int	*arr_smallest_on_top(t_node	**head)
{
	int		*array;
	int		size;
	int		pos;
	int		i;
	int		k;
	t_node	*first_node;

	size = list_len(head);
	array = (int *)malloc(sizeof(int) * size);
	if (!array)
		return (NULL);
	i = 1;
	array[0] = smallest(head);
	pos = position(head, array[0]);
	first_node = node_of_index(head, pos);
	while (i < size)
	{
		first_node = first_node->next;
		array[i++] = first_node->data;
	}
	first_node = *head;
	k = 0;
	while (k++ < pos)
	{
		first_node = first_node->next;
		array[i++] = first_node->data;
	}
	return (array);
}

/*
* print content of array 
*/
void	printarray(int *array, int size)
{
	int	i;

	i = 0;
	if (!array)
		printf("NOTHING!\n");
	while (i < size)
		printf("%d ", array[i++]);
	printf("\n");
}
