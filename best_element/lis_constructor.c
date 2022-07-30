/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis_constructor.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: styes <styes@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 15:58:02 by styes             #+#    #+#             */
/*   Updated: 2022/07/30 04:23:49 by styes            ###   ########.fr       */
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

void	free_3_arr(int	*a, int	*b, int	*c)
{
	free(a);
	free(b);
	free(c);
}

/*
* return the Longest Increasing Subsequence of array @arr of size @size
* the LIS returned is reversed 
* it actually return the Longuest Descreasing Subsequence (starting from the end)
*/
int	*lis_construct(t_node **head, int size)
{
	int	*lis;
	int	*prev;
	int	*seq;
	int	i;
	int	j;
	int	k;
	int	max;
	int	idx;
	int	*arr;

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
	max = 0;
	idx = 0;
	i = -1;
	while (++i < size)
	{
		if (max < lis[i])
		{
			max = lis[i];
			idx = i;
		}
	}
	k = 0;
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
	free_3_arr(arr, lis, prev);
	return (seq);
}
