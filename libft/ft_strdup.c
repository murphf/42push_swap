/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: styes <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 19:54:30 by styes             #+#    #+#             */
/*   Updated: 2021/11/14 15:08:18 by styes            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * allocates sufficient memory for a copy of the string s1
 * does the copy, and returns a pointer to it.
 */
char	*ft_strdup(const char *s)
{
	char	*ptr;
	int		i;
	int		slen;

	slen = ft_strlen(s);
	ptr = (char *)malloc((slen + 1) * sizeof(char));
	if (!ptr)
		return (0);
	i = 0;
	while (i < slen)
	{
		ptr[i] = (char)s[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
/*
int	main()
{
	char	*a = ft_strdup("hola");
	printf("%s\n", a);
}
*/
