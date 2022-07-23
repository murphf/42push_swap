/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: styes <styes@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 16:23:05 by styes             #+#    #+#             */
/*   Updated: 2022/07/22 23:26:12 by styes            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
* PARSING PROTOCOL:
* must be numeric
* no duplicate
* more than one paramater
* unsorted
* in INT range
*/
t_node	**parsing_check(int argc, char **argv)
{
	int			i;
	long		num;
	t_node		*stack_a;
	t_node		**head_a;

	i = 1;
	if (valid_arg(argv[i], &stack_a))
	{
		if (argv[i][0] == '\0')
			error(1, &stack_a);
		stack_a = create_node(ft_atoi(argv[i]));
		head_a = &stack_a;
		if (argc >= 3)
			num = ft_atoi(argv[++i]);
	}
	while (argc >= 3 && i < argc && valid_arg(argv[i], &stack_a))
	{
		if (argv[i][0] == '\0')
			error(1, &stack_a);
		if (identical_found(&stack_a, num) || !is_int(num))
				error(1, &stack_a);
		add_node_end(&stack_a, create_node(num));
		if (++i == argc)
			break ;
		num = ft_atoi(argv[i]);
	}
	if (i != argc)
			error(1, &stack_a);
	return (head_a);
}

int	_min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

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