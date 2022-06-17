/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: styes <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 21:45:04 by styes             #+#    #+#             */
/*   Updated: 2021/11/14 15:07:40 by styes            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

/*
 * return pointer to the first occurence of c in s
 * if c == 0 return nothing
 * if c isn't in the string return NULL
 */
char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i] != (char)c && s[i])
		i++;
	if (i == ft_strlen(s) && (char)c != '\0')
		return (NULL);
	return ((char *)(s + i));
}
/*
int	main()
{
	printf("%s\n", strchr("balaba", 'R'));
	printf("%s\n", ft_strchr("balaba", 'R'));
}*/
