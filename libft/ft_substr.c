/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: styes <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 21:01:10 by styes             #+#    #+#             */
/*   Updated: 2021/11/19 21:29:59 by styes            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * Allocates and returns a substring from the string ’s’.
 * The substring begins at index ’start’ and is of
 * maximum size ’len’.
*/
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	len_src;
	size_t	i;

	if (!s)
		return (NULL);
	len_src = ft_strlen(s);
	if (start >= len_src)
		return (ft_strdup(""));
	if (len > len_src - start)
		len = len_src - start;
	sub = (char *)malloc((len + 1) * sizeof(char));
	if (!sub)
		return (NULL);
	i = 0;
	while (i < len && s[start])
	{
		sub[i] = (char)s[start];
		i++;
		start++;
	}
	sub[i] = 0;
	return (sub);
}
