/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: styes <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 19:23:58 by styes             #+#    #+#             */
/*   Updated: 2021/11/23 00:31:04 by styes            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
// delete content of the linked list's nodes using the (del) function,
//and free the pointers

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tmp;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		tmp = *lst;
		(*del)((*lst)->content);
		(*lst) = (*lst)->next;
		free (tmp);
	}
}
/*
static void	ft_del(void	*content)
{
	free (content);
}
static void	printf_list(t_list *head)
{
	printf("content of the list: ");
	while (head)
	{
		printf("|%s|", head->content);
		head = head->next;
	}
	printf("\n");
}

int	main()
{
	t_list	*list;
	char	*f;
	char	*s;
	char	*t;

	list = NULL;
	f = (char *)malloc(6);
	s = (char *)malloc(7);
	t = (char *)malloc(6);
	if (!f || !s || !t)
		return (EXIT_FAILURE);
	strlcpy(f, "first", 6);
	strlcpy(s, "second", 7);
	strlcpy(t, "third", 6);

	ft_lstadd_front(&list, ft_lstnew(t));
	ft_lstadd_front(&list, ft_lstnew(s));
	ft_lstadd_front(&list, ft_lstnew(f));
	printf_list(list);
	ft_lstclear(&list, &ft_del);
	printf_list(list);
}*/
