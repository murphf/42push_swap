/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: styes <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 10:42:18 by styes             #+#    #+#             */
/*   Updated: 2021/11/14 15:10:01 by styes            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * Allocates and returns a new
 * string, which is the result of the concatenation
 * of ’s1’ and ’s2’.
 */
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_str;
	int		bytes;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	bytes = (ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char);
	new_str = (char *)malloc(bytes);
	if (!new_str)
		return (0);
	i = 0;
	while (s1[i])
	{
		new_str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
		new_str[i++] = s2[j++];
	new_str[i] = '\0';
	return (new_str);
}
/*
int	main()
{
	char	*a = ft_strjoin("bla", "blax");
	printf("%s\n", a);
}*/
