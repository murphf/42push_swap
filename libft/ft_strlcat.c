/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: styes <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 20:47:24 by styes             #+#    #+#             */
/*   Updated: 2021/11/24 16:33:00 by styes            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * Appends src to string dst of size siz (unlike strncat, siz is the
 * full size of dst, not space left).  At most siz-1 characters
 * will be copied.  Always NUL terminates (unless siz <= strlen(dst)).
 * Returns strlen(initial dst) + strlen(src); if retval >= siz,
 * truncation occurred.
 */
size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	char		*d;
	const char	*s;
	size_t		dlen;
	size_t		i;

	s = src;
	d = dst;
	i = size;
	while (i-- != 0 && *d)
		d++;
	dlen = d - dst;
	i = size - dlen;
	if (i == 0)
		return (dlen + ft_strlen(src));
	while (*s)
	{
		if (i != 1)
		{
				*d++ = *s;
				i--;
		}
		s++;
	}
	*d = '\0';
	return (dlen + (s - src));
}
/*
int	main()
{
	char a[8] = "blabla";
	ft_strlcat(NULL, "hh", 0);
	//strlcat (NULL, "NULL", 0);
}*/
