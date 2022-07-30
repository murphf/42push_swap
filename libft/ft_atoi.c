/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: styes <styes@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 15:15:46 by styes             #+#    #+#             */
/*   Updated: 2022/07/30 02:52:35 by styes            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//check if c is a white space
static int	ft_isspace(int c)
{
	return ((c >= 9 && c <= 13) || c == ' ');
}

//convert a string to an int ( doesn't handle overflow if > MAX_LONG)
/*
* minor changes for push_swap
*/
long	ft_atoi(const char *str)
{
	int		sign;
	int		i;
	long	a;

	sign = 1;
	i = 0;
	a = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
		if (str[i] == '-')
			{
				sign *= -1;
				i++;
			}
	while (str[i] >= '0' && str[i] <= '9')
			a = (a * 10) + (str[i++] - '0');
	return (sign * a);
}