/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: styes <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 19:29:29 by styes             #+#    #+#             */
/*   Updated: 2021/11/19 21:23:56 by styes            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst)
	{
		(*f)(lst -> content);
		lst = lst -> next;
	}
}
/*
static void	ft_useless(void	*s)
{
	strlcat((char *)s, " war", 12);
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
	f = (char *)malloc(11);
	s = (char *)malloc(12);
	t = (char *)malloc(11);
	if (!f || !s || !t)
		return (EXIT_FAILURE);
	strlcpy(f, "first", 6);
	strlcpy(s, "second", 7);
	strlcpy(t, "third", 6);

	ft_lstadd_front(&list, ft_lstnew(t));
	ft_lstadd_front(&list, ft_lstnew(s));
	ft_lstadd_front(&list, ft_lstnew(f));
	printf_list(list);
	ft_lstiter(list, &ft_useless);
	printf_list(list);
}*/