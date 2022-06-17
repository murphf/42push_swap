/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strrchr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: styes <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 10:47:19 by styes             #+#    #+#             */
/*   Updated: 2021/11/23 00:42:57 by styes            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

//return a pointer to the last occurrence of c in the string
char	*ft_strrchr(const char *s, int c)
{
	size_t	len;

	len = ft_strlen(s);
	while (len > 0)
	{
		if (s[len] == (char)c)
			return ((char *)(s + len));
		len--;
	}
	if (s[0] == (char)c)
		return ((char *)s);
	return (NULL);
}

// int main()
// {
// 	char a[20] = "xhello lhosehrs";
// 	printf("%s\n", ft_strrchr(a, 'x'));
// 	printf("%s\n", strrchr(a, 'x'));
// }
