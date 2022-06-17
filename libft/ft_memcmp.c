/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: styes <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 13:15:55 by styes             #+#    #+#             */
/*   Updated: 2021/11/14 15:04:52 by styes            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*st1;
	unsigned char	*st2;
	size_t			i;

	if (!n)
		return (0);
	st1 = (unsigned char *)s1;
	st2 = (unsigned char *)s2;
	i = 0;
	while (st1[i] == st2[i] && i < n - 1)
		i++;
	return (st1[i] - st2[i]);
}
/*
int	main()
{
	printf("%d\n", memcmp("abc", "ABC", 4 ));
	printf("%d\n", ft_memcmp("abc", "ABC", 4));
}*/
