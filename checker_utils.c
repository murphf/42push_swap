/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: styes <styes@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 16:23:05 by styes             #+#    #+#             */
/*   Updated: 2022/07/19 19:18:54 by styes            ###   ########.fr       */
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
	if (valid_arg(argv[i]))
	{
		stack_a = create_node(ft_atoi(argv[i]));
		head_a = &stack_a;
		if (argc >= 3)
			num = ft_atoi(argv[++i]);
	}
	while (argc >= 3 && i < argc && valid_arg(argv[i]))
	{
		if (identical_found(&stack_a, num) || !is_int(num))
			{
				error(1, &stack_a);
				exit(EXIT_FAILURE);
			}
		add_node_end(&stack_a, create_node(num));
		if (++i == argc)
			break ;
		num = ft_atoi(argv[i]);
	}
	if (i != argc)
		{
			error(1, &stack_a);
			exit(EXIT_FAILURE);
		}
	return (head_a);
}

