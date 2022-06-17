/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: styes <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 22:48:02 by styes             #+#    #+#             */
/*   Updated: 2021/11/19 23:34:07 by styes            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	set_finder(char const *set, char c)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		e;
	int		k;
	char	*string;

	k = 0;
	i = 0;
	if (!s1 || !set)
		return (NULL);
	e = ft_strlen(s1) - 1;
	while (s1[i] && set_finder(set, s1[i]))
		i++;
	if (i == e + 1)
		return (ft_strdup(""));
	while (s1[e] && set_finder(set, s1[e]))
		e--;
	string = (char *)malloc(sizeof(char) * (e - i + 2));
	if (!string)
		return (NULL);
	while (s1[i] && i <= e)
		string[k++] = s1[i++];
	string[k] = '\0';
	return (string);
}
/*
int	main()
{
	char	*a = ft_strtrim("012332fuuuck4564564", "0123456789");
	printf("%s\n", a);
}*/
