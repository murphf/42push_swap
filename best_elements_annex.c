/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best_elements_annex.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: styes <styes@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 15:28:55 by styes             #+#    #+#             */
/*   Updated: 2022/07/17 06:02:07 by styes            ###   ########.fr       */
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
* sort 3 numbers
* moves depending of the posisiton
* of the max, min amd medium
* medium being the number between min and max
*/
t_node	*sort3(t_node	**head)
{
	t_node	*f_node;
	int		f;
	int		s;
	int		t;

	f_node = *head;

	f = f_node->data;
	s = f_node->next->data;
	t = f_node->prev->data;
	
	if (in_range(t, f, s))
	{
		rra(head);
		sa(head);
	}
	else if (in_range(t, s, f))
		ra(head);
	else if (in_range(f, t, s))
		rra(head);
	else if (in_range(f, s, t))
		sa(head);
	else if(in_range(s, t, f))
	{
		sa(head);
		rra(head);
	}
	return (*head);
}
