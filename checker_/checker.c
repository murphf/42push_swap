/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: styes <styes@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 23:05:08 by styes             #+#    #+#             */
/*   Updated: 2022/07/30 02:33:15 by styes            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char *argv[])
{
	t_node	*stack_a;
	t_node	*stack_b;
	char	mv[3];
	char	c;

	stack_b = NULL;
	if (argc == 1)
		exit(EXIT_FAILURE);
	stack_a = *(parsing(argc, argv));
	while (read(0, mv, 3))
	{
		if (mv[2] == '\n')
			instruction_2l(mv, &stack_a, &stack_b);
		else if (mv[2] == 'a' || mv[2] == 'b' || mv[2] == 'r')
		{
			instruction_3l(mv, &stack_a, &stack_b);
			read(0, &c, 1);
			if (c != '\n')
				error_check(&stack_a, &stack_b);
		}
		else
			error_check(&stack_a, &stack_b);
	}
	checker_resp(&stack_a, &stack_b);
}
