/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis_constructor.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: styes <styes@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 15:58:02 by styes             #+#    #+#             */
/*   Updated: 2022/07/30 20:47:45 by styes            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
* create an array of size: @size and fill it with @n
*/
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

void	fill_subsequ(int idx, int *prev, int *arr, int *seq)
{
	int	k;

	k = 2;
	while (idx != prev[idx])
	{
		idx = prev[idx];
		seq[k] = arr[idx];
		k++;
	}
}

/*
* return the Longest Increasing Subsequence of array @arr of size @size
* the LIS returned is reversed 
* it actually return the Longuest Descreasing Subsequence (starting from the end)
* the first element of the returned array is the lenght of the LIS
*/
int	*lis_constructp1(t_node **head, int size)
{
	int	*arr;
	int	*lis;
	int	*prev;
	int	i;
	int	j;

	arr = arr_smallest_on_top(head);
	lis = creat_fill(1, size);
	prev = creat_fill_indx(size);
	i = 0;
	while (++i < size)
	{
		j = -1;
		while (++j < i)
		{
			if (arr[i] > arr[j] && lis[i] < (lis[j] + 1))
			{
				lis[i] = lis[j] + 1;
				prev[i] = j;
			}
		}
	}
	return (lis_constructp2(lis, arr, prev, size));
}

int	*lis_constructp2(int *lis, int *arr, int *prev, int size)
{
	int	*seq;
	int	max;
	int	idx;
	int	i;

	i = -1;
	while (++i < size)
	{
		if (max < lis[i])
		{
			max = lis[i];
			idx = i;
		}
	}
	seq = (int *)malloc(sizeof(int) * (max + 1));
	if (!seq)
		return (NULL);
	seq[0] = max;
	seq[1] = arr[idx];
	fill_subsequ(idx, prev, arr, seq);
	free_3_arr(arr, lis, prev);
	return (seq);
}
