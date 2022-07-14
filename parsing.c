
#include "push_swap.h"

/*
* check if str is a valid argument;
* allowed syntax: A, +A, -A (with A in [0, 9])
*/
int	valid_arg(char	*str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (ft_isdigit(str[i]) && str[i])
		i++;
	if (str[i] == '\0')
		return (1);
	return (0);
}

/*
* PARSING PROTOCOL:
* must be numeric
* no duplicate
* more than one paramater
* unsorted
* in INT range
*/
t_node	**parsing(int argc, char **argv)
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