/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: styes <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 18:55:49 by styes             #+#    #+#             */
/*   Updated: 2021/11/19 21:21:50 by styes            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	if (!*lst)
		*lst = new;
	else
		ft_lstlast(*lst)->next = new;
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
}*/