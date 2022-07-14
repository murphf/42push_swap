/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: styes <styes@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 22:08:17 by styes             #+#    #+#             */
/*   Updated: 2022/07/14 15:08:38 by styes            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sorting(t_node	**head_a, t_node **head_b, int size)
{
	if (size == 2)
		sort2(head_a);
	else if (size == 3)
		sort3(head_a);
	else if (size == 5)
		sort5(head_a, head_b);
	else
		best_element(head_a, head_b);
}

int	main(int argc, char **argv)
{
	t_node	*stack_a;
	t_node	*stack_b;
	int		len;

	len = argc - 1;
	stack_b = NULL;
	if (len <= 1)
		error(0, &stack_a);
	else
		stack_a = *(parsing(argc, argv));
	if (is_sorted(&stack_a))
		error(0, &stack_a);
	sorting(&stack_a, &stack_b, len);
	print_stacks(&stack_a, &stack_b);
}
