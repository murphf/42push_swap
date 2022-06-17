/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: styes <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 12:22:22 by styes             #+#    #+#             */
/*   Updated: 2021/11/19 21:28:17 by styes            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

/*
 * copy n first bytes of the src into dest
 * prevent overlapping by comparing pointers (or through a temporary array)
 * if dest > src (the case where overlapping may occur) 
 * if start coping from the end of src
 */
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*dest0;
	unsigned char	*src0;

	dest0 = (unsigned char *)dest;
	src0 = (unsigned char *)src;
	if (dest > src)
		while (n--)
			dest0[n] = src0[n];
	else
		ft_memcpy (dest, src, n);
	return (dest);
}
/*
// driver program: a comparaison between (ft_)memmove and (ft_)memcpy 
int main()
{
	char a[20] = "this is an example";
	char b[20] = "this is an example";
	ft_memcpy (a + 8, a, 10);
	ft_memmove(b + 8, b, 10);
	printf("the result using ft__memcpy: %s\n", a);
	printf("the result using ft_memmove: %s\n", b);
	//memmove(NULL, NULL, 3);
	//ft_memmove(NULL, NULL, 3);
}*/
