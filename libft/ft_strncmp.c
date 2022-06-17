/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: styes <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 11:13:03 by styes             #+#    #+#             */
/*   Updated: 2021/11/10 11:43:23 by styes            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//compares not more than n characters
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (!n)
		return (0);
	while (s1[i] == s2[i] && i < (n - 1) && s1[i] && s2[i])
		i++;
	return ((unsigned char)s1[i] - s2[i]);
}
/*int	main()
{
	printf("%d\n", ft_strncmp("blaabla", "blablab", 6));
	printf("%d\n", strncmp("blaabla", "blablab", 6));
}*/
