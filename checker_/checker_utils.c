/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: styes <styes@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 16:23:05 by styes             #+#    #+#             */
/*   Updated: 2022/07/30 02:33:47 by styes            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	read_until_no_more(void)
{
	char	c;

	c = 0;
	while (c != '\n')
		read(0, &c, 1);
}

void	error_check(t_node	**stack_a, t_node	**stack_b)
{
	read_until_no_more();
	write(2, "Error\n", 6);
	delete_list(stack_a);
	delete_list(stack_b);
	exit(EXIT_FAILURE);
}

void	instruction_2l(char *mv, t_node **stack_a, t_node	**stack_b)
{
	if (ft_strncmp(mv, "sa\n", 3) == 0)
		swap(stack_a);
	else if (ft_strncmp(mv, "sb\n", 3) == 0)
		swap(stack_b);
	else if (ft_strncmp(mv, "ss\n", 3) == 0)
	{
		swap(stack_a);
		swap(stack_b);
	}
	else if (ft_strncmp(mv, "pb\n", 3) == 0)
		push(stack_a, stack_b);
	else if (ft_strncmp(mv, "pa\n", 3) == 0)
		push(stack_b, stack_a);
	else if (ft_strncmp(mv, "ra\n", 3) == 0)
		rotate(stack_a);
	else if (ft_strncmp(mv, "rb\n", 3) == 0)
		rotate(stack_b);
	else if (ft_strncmp(mv, "rr\n", 3) == 0)
	{
		rotate(stack_a);
		rotate(stack_b);
	}
	else
		error_check(stack_a, stack_b);
}

void	instruction_3l(char *mv, t_node **stack_a, t_node	**stack_b)
{
	if (ft_strncmp(mv, "rra", 3) == 0)
		rev_rotate(stack_a);
	else if (ft_strncmp(mv, "rrb", 3) == 0)
		rev_rotate(stack_b);
	else if (ft_strncmp(mv, "rrr", 3) == 0)
	{
		rev_rotate(stack_a);
		rev_rotate(stack_b);
	}
	else
		error_check(stack_a, stack_b);
}

void	checker_resp(t_node **stack_a, t_node **stack_b)
{
	if (is_sorted(stack_a) && !*stack_b)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}
