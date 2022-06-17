/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: styes <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 19:19:03 by styes             #+#    #+#             */
/*   Updated: 2021/11/17 19:22:46 by styes            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

// delete the content of the node and free its pointer
void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (!lst || !del)
		return ;
	(*del)(lst -> content);
	free (lst);
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

	list = NULL;
	f = (char *)malloc(6);
	s = (char *)malloc(7);
	if (!f || !s)
		return (0);
	strlcpy(f, "first", 6);
	strlcpy(s, "second", 7);
	ft_lstadd_back(&list, ft_lstnew(f));
	ft_lstadd_back(&list, ft_lstnew(s));
	printf_list(list);	
	ft_lstdelone(ft_lstlast(list), &ft_del);
	printf_list(list);
}*/