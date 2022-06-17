/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: styes <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 15:15:46 by styes             #+#    #+#             */
/*   Updated: 2021/11/19 21:19:16 by styes            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//check if c is a white space
static int	ft_isspace(int c)
{
	return ((c >= 9 && c <= 13) || c == ' ');
}

//convert a string to an int (handle overflow if > MAX_LONG)
int	ft_atoi(const char *str)
{
	int		sign;
	int		i;
	long	a;
	long	past_a;

	sign = 1;
	past_a = 0;
	i = 0;
	a = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			sign *= -1;
	while (str[i] >= '0' && str[i] <= '9')
	{
		a = (a * 10) + (str[i++] - '0');
		if (((a - str[i - 1] + '0') / 10) != past_a)
			return ((-sign - 1) / 2);
		past_a = a;
	}
	return (sign * a);
}
/*
int	main ()
{
	printf("%d\n", ft_atoi("92299999559999999999"));
	printf("%d\n", atoi("922999995599999999999"));
}*/
