/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: styes <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 17:52:58 by styes             #+#    #+#             */
/*   Updated: 2021/11/14 11:41:16 by styes            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	size *= nmemb;
	ptr = malloc(size);
	if (!ptr)
		return (0);
	ft_bzero(ptr, size);
	return (ptr);
}
/*
int main()
{
	char *ptr;

	ptr = (char *)ft_calloc(1, 1);
	ptr[0] = 'b';
	printf("%c\n", ptr[0]);
}*/
