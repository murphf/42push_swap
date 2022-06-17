/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: styes <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 10:45:27 by styes             #+#    #+#             */
/*   Updated: 2021/11/14 15:01:49 by styes            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

//writes n zeroed bytes
void	ft_bzero(void *s, size_t n)
{
	unsigned char	*s0;
	size_t			i;

	s0 = (unsigned char *) s;
	i = 0;
	while (i < n)
		s0[i++] = 0;
}
/*
int main()
{
	char a[5];
	char b[5];
	ft_bzero(a, 5);
	//bzero(b, 5);
	printf("%s", a);
}*/
