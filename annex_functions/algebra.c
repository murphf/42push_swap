/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algebra.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: styes <styes@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 15:30:57 by styes             #+#    #+#             */
/*   Updated: 2022/07/26 18:57:06 by styes            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
* see if a and b have the same sign 
* AND non null
*/
bool	same_sign(int a, int b)
{
	if ((a > 0 && b > 0) || (a < 0 && b < 0))
		return (true);
	return (false);
}

/*
* return absolute value of n
*/
int	abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

int	_min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

int	_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

/*
* check if a is in ]b, c[
*/
int	in_range(int a, int b, int	c)
{
	if (a > b && a < c)
		return (1);
	return (0);
}