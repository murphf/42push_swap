/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: styes <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 13:37:32 by styes             #+#    #+#             */
/*   Updated: 2021/11/08 18:23:45 by styes            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
 * locates the first occurrence of thestring needle
 * in the string haystack
 * no  more than len characters are searched 
 */
char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	len_s2;

	i = 0;
	len_s2 = ft_strlen(s2);
	if (s2[0] == '\0')
		return ((char *)s1);
	while (s1[i] && i + len_s2 <= n)
	{
		if (s1[i] == s2[0] && !ft_strncmp(s1 + i, s2, len_s2))
			return ((char *)(s1 + i));
		i++;
	}
	return (0);
}
/*
int	main()
{
	char a[] = "loki is nice";
	//printf("%s", strnstr(a, "is", 6));
	printf("%s\n", ft_strnstr("lorem ipsum dolor sit amet", "", 10));
	//printf("%s\n", ft_strnstr("lorem", "", 6));
}*/
