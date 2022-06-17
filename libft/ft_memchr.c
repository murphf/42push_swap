/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: styes <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 11:39:08 by styes             #+#    #+#             */
/*   Updated: 2021/11/14 15:14:20 by styes            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
* scans the initial n bytes of the memory area
* pointed to by s for the first instance of c
*/
void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*s0;

	i = 0;
	s0 = (unsigned char *)s;
	while (i < n)
		if (s0[i++] == (unsigned char)c)
			return ((void *)(s + i - 1));
	return (NULL);
}
/*
int	main()
{

	char	a[] = "mother mary";
	//char	b[] = "lxxxxxxxxxxx";
	printf("%s\n", ft_memchr(a, 'x', 12));
	printf("%s\n", memchr(a, 'x', 12));
}
*/