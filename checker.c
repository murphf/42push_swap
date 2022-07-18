#include "push_swap.h"

int main(int argc, char *argv[])
{
	t_node	*stack_a;
	t_node	*stack_b;
	char	c;
	int		r;
	char	*mv;
	int		len;
	int		i;

	stack_b = NULL;
	stack_a = *(parsing_check(argc, argv));
	mv = (char	*)malloc(sizeof(char) * 150000);
	if (!mv)
		return (0);
	ft_bzero(mv, 150000);
	
	i = 0;
	len = 0;
	r = read(1, &c, 1);
	while(r)
	{
		mv[i] = c;
		i++;
		r = read(1, &c, 1);
		len++;
	}
	len++;
	mv = realloc(mv, len);
	mv[len - 1] = '\0';
	i = 0;
	
	while (mv[i])
	{
		if (mv[i] != '\n')
		{
			if (ft_strncmp(&mv[i], "sa", 2) == 0)
				{
					swap(&stack_a);
					i += 3;
				}
			if (ft_strncmp(&mv[i], "sb", 2) == 0)
				{
					swap(&stack_b);
					i += 3;
				}
			if (ft_strncmp(&mv[i], "ss", 2) == 0)
				{
					swap(&stack_a);
					swap(&stack_b);
					i += 3;
				}
			if (ft_strncmp(&mv[i], "ra", 2) == 0)
				{
					rotate(&stack_a);
					i += 3;
				}
			if (ft_strncmp(&mv[i], "rb", 2) == 0)
				{
					rotate(&stack_b);
					i += 3;
				}
			if (ft_strncmp(&mv[i], "rr", 2) == 0)
				{
					rotate(&stack_a);
					rotate(&stack_b);
					i += 3;
				}
			if (ft_strncmp(&mv[i], "rra", 2) == 0)
				{
					rev_rotate(&stack_a);
					i += 4;
				}
			if (ft_strncmp(&mv[i], "rrb", 2) == 0)
				{
					rev_rotate(&stack_b);
					i += 4;
				}
			if (ft_strncmp(&mv[i], "rrr", 2) == 0)
				{
					rev_rotate(&stack_a);
					rev_rotate(&stack_b);
					i += 4;
				}
			if (ft_strncmp(&mv[i], "pb", 2) == 0)
				{
					push(&stack_a, &stack_b);
					i += 3;
				}
			if (ft_strncmp(&mv[i], "pa", 2) == 0)
				{
					push(&stack_b, &stack_a);
					i += 3;
				}
		}
		else if (mv[i] == '\n')
			i++;
		else
			printf("error\n");
	}
	if (is_sorted(&stack_a) && !stack_b)
		write(1, "OK\n", 4);
	else
		write(1, "KO\n", 4);
	//print_stacks(&stack_a, &stack_b);
}