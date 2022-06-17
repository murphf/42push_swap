/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: styes <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 15:27:55 by styes             #+#    #+#             */
/*   Updated: 2021/11/23 00:42:28 by styes            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* 
 * @size: size of the destination buffer
 * copy up to size character from @src to @dst
 * null terminate the result ('\0' is included in @size)
 * return the lenght of @src
 * */
size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	slen;

	slen = ft_strlen(src);
	if (size <= 0)
		return (slen);
	size--;
	while (size-- && *src)
		*dst++ = *src++;
	*dst = '\0';
	return (slen);
}
/*
int main()
{
	char dest[6] = "ba";
	ft_strlcpy(dest, "hello", 6);
	printf("%s\n", dest);
   	printf("%zu\n", ft_strlcpy(dest, "hello", 6));	
}*/
