/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: styes <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 18:50:45 by styes             #+#    #+#             */
/*   Updated: 2021/11/18 19:36:37 by styes            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Allocates and returns a string representing
 * the integer received as an argument.
 * Negative numbers must be handled
*/
static int	len_num(int n)
{
	int		i;
	long	n0;

	i = 1;
	n0 = (long)n;
	if (n0 < 0)
	{
		i++;
		n *= -1;
	}
	while (n0 / 10)
	{
		i++;
		n0 /= 10;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int		len;
	char	*string;
	long	n0;

	n0 = (long)n;
	len = len_num(n) - 1;
	string = (char *)malloc((len + 2) * sizeof(char));
	if (!string)
		return (NULL);
	if (n0 == 0)
		string[0] = '0';
	if (n0 < 0)
	{
		string[0] = '-';
		n0 *= -1;
	}
	while (n0)
	{
		string[len--] = (n0 % 10) + '0';
		n0 /= 10;
	}
	string[len_num(n)] = '\0';
	return (string);
}
/*
int	main()
{
	printf("%s\n", ft_itoa(2147483647));
	printf("%s\n", ft_itoa(-2147483648));
	printf("%s\n", ft_itoa(0));
	printf("%s\n", ft_itoa(-0));
	printf("%s\n", ft_itoa(-214748364899));
	printf("%s\n", ft_itoa(214748364899));
}*/
