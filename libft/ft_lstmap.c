/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: styes <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 13:28:25 by styes             #+#    #+#             */
/*   Updated: 2021/11/23 00:31:45 by styes            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
/*
 * create a new list composed of elements from (lst) with (f)
 * applied to their content
 * used functions: 
 * ft_lstnew: to create a new node
 * ft_clear: to delete the list if the allocation fails (uses (del) onction)
 * ft_lstadd_back: to add each new node to our new list
 */
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*first;
	t_list	*node;

	if (!lst || !f)
		return (NULL);
	first = NULL;
	while (lst)
	{
		node = ft_lstnew((*f)(lst -> content));
		if (!node)
		{
			ft_lstclear(&first, del);
			return (NULL);
		}
		ft_lstadd_back(&first, node);
		lst = lst -> next;
	}
	return (first);
}
/*
static void	*ft_useless(void	*s)
{
	char	*sub;
	sub = ft_substr(s, 3, 2);
	return ((void *)sub);
}
static static void	ft_del(void	*content)
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
	t_list	*f_list;
	t_list	*s_list;
	char	*f;
	char	*s;
	char	*t;

	f_list = NULL;
	f = (char *)malloc(6);
	s = (char *)malloc(7);
	t = (char *)malloc(6);
	if (!f || !s || !t)
		return (EXIT_FAILURE);
	strlcpy(f, "first", 11);
	strlcpy(s, "second", 12);
	strlcpy(t, "third", 11);

	ft_lstadd_front(&f_list, ft_lstnew(t));
	ft_lstadd_front(&f_list, ft_lstnew(s));
	ft_lstadd_front(&f_list, ft_lstnew(f));
	printf("*the original list*\n");
	printf_list(f_list);
	s_list = ft_lstmap(f_list, &ft_useless, &ft_del);
	printf("*the created list*\n");
	printf_list(s_list);
}*/
