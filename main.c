/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: styes <styes@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 22:08:17 by styes             #+#    #+#             */
/*   Updated: 2022/07/14 07:24:12 by styes            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
* 2 types of error consequences
*/
void	error(int e, t_node	**stack_a)
{
	if (e)
		write(1, "\033[0;31mError\033[0m\n", 18);
	else
		delete_list(stack_a);
	exit(EXIT_FAILURE);
}

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

/*
* PARSING PROTOCOL:
* 
*/
t_node	**parsing(int argc, char **argv)
{
	int		i;
	int		num;
	t_node	*stack_a;
	t_node	**head_a;

	i = 1;
	if (valid_arg(argv[i]))
	{
		stack_a = create_node(ft_atoi(argv[i]));
		head_a = &stack_a;
		if (argc >= 3)
			num = ft_atoi(argv[++i]);
		else
			argc--;
	}
	while (valid_arg(argv[i]) && i < argc && is_int(num))
	{
		if (identical_found(&stack_a, num))
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
