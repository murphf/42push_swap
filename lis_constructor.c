/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_lis_constructor.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: styes <styes@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 15:58:02 by styes             #+#    #+#             */
/*   Updated: 2022/07/15 16:33:51 by styes            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
* create an array of size: $size and fill it with @n
0*/
int	*creat_fill(int n, int size)
{
	int	*array;
	int	i;

	i = 0;
	array = (int *)malloc(sizeof(int) * size);
	if (!array)
		return (NULL);
	while (i < size)
		array[i++] = n;
	return (array);
}

int	*creat_fill_indx(int size)
{
	int	*array;
	int	i;

	i = -1;
	array = (int *)malloc(sizeof(int) * size);
	if (!array)
		return (NULL);
	while (++i < size)
		array[i] = i;
	return (array);
}

/*
* return the Longest Increasing Subsequence of array @arr of size @size
* the LIS returned is reversed 
* it actually return the Longuest Descreasing Subsequence (starting from the end)
*/
int	*lis_construct(int *arr, int	size)
{
	int	*lis;
	int	*prev;
	int	*seq;
	int	i;
	int	max;
	int	idx;

	i = 0;
	lis = creat_fill(1, size);
	prev = creat_fill_indx(size);
	for (i = 1; i < size; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (arr[i] > arr[j] && lis[i] < (lis[j] + 1))
			{
				lis[i] = lis[j] + 1;
				prev[i] = j;
			}
		}
	}
	max = 0;
	idx = 0;
	for (i = 0; i < size; i++)
	{
		if (max < lis[i])
		{
			max = lis[i];
			idx = i;
		}
	}
	int k = 0;
	seq = (int *)malloc(sizeof(int) * (max + 1));
	if (!seq)
		return (NULL);
	seq[k++] = max;
	seq[k++] = arr[idx];
	while (idx != prev[idx])
	{
		idx = prev[idx];
		seq[k] = arr[idx];
		k++;
	}
	return (seq);
}
