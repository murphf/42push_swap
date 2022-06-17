/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: styes <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 17:32:48 by styes             #+#    #+#             */
/*   Updated: 2021/11/19 21:24:44 by styes            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst -> next)
		lst = lst -> next;
	return (lst);
}
/*
static void	print_list_num(t_list *head)
{
	printf("the content of the list: ");
	while(head)
	{
		printf("|%d| ", *(int *)head->content);
		head = head->next;
	}
	printf("\n");
}

int	main()
{
	t_list	*list;
	list = NULL;
	int	i;

	i = 0;
	int	array[] ={1, 2, 3, 4, 5};
	while (i < 5)
	{
		ft_lstadd_back(&list, ft_lstnew(&array[i]));
		i++;
	}
	print_list_num(list);
	printf("the last node's content: |%d|\n", *(int *)ft_lstlast(list)->content);
}
*/