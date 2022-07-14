/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: styes <styes@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 10:45:27 by styes             #+#    #+#             */
/*   Updated: 2022/07/14 14:56:46 by styes            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
* writes n zeroed bytes
*/
void	ft_bzero(void *s, size_t n)
{
	unsigned char	*s0;
	size_t			i;

	s0 = (unsigned char *) s;
	i = 0;
	while (i < n)
		s0[i++] = 0;
}
