/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: styes <styes@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 16:23:05 by styes             #+#    #+#             */
/*   Updated: 2022/07/24 23:04:34 by styes            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
* simulate the work of realloc if @ptr is a string ending wiyj \0
* if ptr is NULL, ft_realloc do malloc job
* if new_size = 0, ft_malloc dp free job
* otherwise if copy the content of @ptr to a new pointer of size @new_size
* then free @ptr 
*/
void	*ft_realloc(void *ptr, size_t new_size)
{
	size_t		i;
	size_t		old_size;
	size_t		size;
	char		*new_block;

	new_block = malloc(new_size);
	old_size = ft_strlen(ptr);
	size = _min(old_size, new_size);
	if (!new_block)
		return (NULL);
	if (!ptr)
		return ((void *)new_block);
	if (!new_size)
		{
			free (ptr);
			return (NULL);
		}
	i = 0;
	while (i < size)
	{
		new_block[i] = ((char *)ptr)[i];
		i++;
	}
	free (ptr);
	return ((void *)new_block);
}