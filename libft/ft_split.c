/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: styes <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 17:15:49 by styes             #+#    #+#             */
/*   Updated: 2021/11/19 21:39:26 by styes            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

/*
 * Allocates (with malloc(3)) and returns an array
 * of strings obtained by splitting ’s’ using the
 * character ’c’ as a delimiter.  The array must be
 * ended by a NULL pointer.
*/
static int	slice_count(char const *s, char c)
{
	int	i;
	int	w;

	i = 0;
	w = 0;
	if (!s)
		return (-1);
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i] && s[i] != c)
			w++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (w);
}

static char	**freeall(char **s, int i)
{
	while (i-- >= 0)
		free (s[i]);
	free (s);
	return (NULL);
}

static char	*ft_strndup(const char *s1, size_t n)
{
	size_t	i;
	char	*ptr;

	ptr = (char *)malloc((n + 1) * sizeof(char));
	if (!ptr)
		return (0);
	i = 0;
	while (i < n && s1[i])
	{
		ptr[i] = s1[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

static int	len_word(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != c && s[i])
		i++;
	return (i);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		len;
	int		k;
	char	**ptr;

	k = 0;
	ptr = (char **)malloc((slice_count(s, c) + 1) * sizeof(char *));
	if (!ptr || !s)
		return (NULL);
	i = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		len = len_word(s + i, c);
		if (len > 0)
		{
			ptr[k++] = ft_strndup(s + i, len);
			if (!ptr[k - 1])
				return (freeall(ptr, k - 1));
		}
		i += len;
	}
	ptr[k] = NULL;
	return (ptr);
}
/*
int	main()
{
	char	**p;

	//p = ft_split("      split       this for   me  !       ",  ' ');
	//printf("%s\n", p[0]);
	printf("%d\n", word_count("", '\0'));
}*/
