/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: styes <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 17:53:48 by styes             #+#    #+#             */
/*   Updated: 2021/11/14 15:06:35 by styes            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

//set the value c from where b points up to len character position
void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*b0;

	b0 = (unsigned char *)b;
	i = 0;
	while (i < len)
	{
		b0[i] = (unsigned char)c;
		i++;
	}
	return (b);
}
/*
int main ()
{
	char a[12] = "hey ducker";
	printf("%s\n", memset("blabla", NULL, 0));
	printf("%s\n", ft_memset("blabla", NULL, 0));
}*/
