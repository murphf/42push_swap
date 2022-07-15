/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best_elements_annex.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: styes <styes@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 15:28:55 by styes             #+#    #+#             */
/*   Updated: 2022/07/15 15:44:32 by styes            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
* MOVES[0] concern moves in STACK A
* MOVES[1] concern moves in STACK B
*/

/*
* put smallest number on top of the stack (STACK A) 
*/
void	smallest_on_top(t_node	**head)
{
	int	small;
	int	pos;

	if (!*head)
		return ;
	small = smallest(head);
	pos = position(head, small);
	wich_one_ra_rra(head, pos);
}

/*
* return node if index i
*/
t_node	*node_of_index(t_node **head, int i)
{
	int		j;
	int		len;
	t_node	*first_node;

	j = 0;
	len = list_len(head);
	first_node = *head;
	while (j < len)
	{
		if (j++ == i)
			return (first_node);
		first_node = first_node->next;
	}
	return (NULL);
}

/*
* check if number @nbr is in @array of size @len
*/
bool	in_array(int	*array, int nbr, int len)
{
	len--;
	while (len)
		if (array[len--] == nbr)
			return (true);
	return (false);
}

/*
* see if a and b have the same sign 
* AND non null
*/
bool	same_sign(int a, int b)
{
	if ((a > 0 && b > 0) || (a < 0 && b < 0))
		return (true);
	return (false);
}

/*
* return absolute value of n
*/
int	abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}
