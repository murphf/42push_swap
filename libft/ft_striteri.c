/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: styes <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 14:24:10 by styes             #+#    #+#             */
/*   Updated: 2021/11/13 15:44:58 by styes            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	if (!s || !f)
		return ;
	i = 0;
	while (s[i])
	{
		(*f)(i, s + i);
		i++;
	}
}

/*
void	to(unsigned int a, char *c)
{
	(void) a;
	*c = 'a';
}
int	main()
{
	char	a[] = "hola";
	ft_striteri(a, &to);
	printf("%s\n", a);
}*/
