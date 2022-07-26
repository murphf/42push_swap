/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: styes <styes@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 22:08:17 by styes             #+#    #+#             */
/*   Updated: 2022/07/26 23:39:58 by styes            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

/*
* hardcode for 3 elements sorting
* best element algorithm for the rest
*/
void	sorting(t_node	**head_a, t_node **head_b, int size)
{
	if (size == 3)
		sort3(head_a);	
	else
		only_lis(head_a, head_b);
}

int	main(int argc, char **argv)
{
	t_node	*stack_a;
	t_node	*stack_b;
	int		len;

	len = argc - 1;
	stack_b = NULL;
	stack_a = NULL;
	if (len < 1)
		error(0, &stack_a);
	else if (len == 1)
	{	
		stack_a = *(parsing(argc, argv));
		if (valid_arg(argv[1], &stack_a))
			error(0, &stack_a);
	}
	else
		stack_a = *(parsing(argc, argv));
	if (is_sorted(&stack_a))
		error(0, &stack_a);
	sorting(&stack_a, &stack_b, len);
	//print_stacks(&stack_a, &stack_b);
	//system("leaks push_swap");
}