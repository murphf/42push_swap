#include "push_swap.h"
#define	N 3

/*
* The different error message,
* add an option in makefile?
*/
void	error(int i)
{
	printf("error: \n");
	if (i == 0)
		printf("INVALID NUMBER OF ARGUMENTS\n");
	else if (i == 1)
		printf("INVALID ARGUMENT(S)\n");
	else if (i == 2)
		printf("FOUND DUPLICATES\n");
	exit(EXIT_FAILURE);
}

int main(int argc, char *argv[])
{
	t_node	*stack_a;
	int		i;
	int		len;

	i = 1;
	/* INPUT ERROR CHECK*/
	if (argc < 2)
		error(0);
	else
	{
		len = argc - 1;
		if (valid_arg(argv[i]))
		{
			stack_a = create_node(ft_atoi(argv[i]), i - 1);
			i++;
		}
		while (valid_arg(argv[i]) && i < argc)
		{
			if (identical_found(&stack_a, ft_atoi(argv[i])))
				{
					delete_list(&stack_a);
					error(2);
				}
			add_node_end(&stack_a, create_node(ft_atoi(argv[i]), i - 1));
			i++;
			if (i == argc)
				break;
		}
		if (i != argc)
		{
			delete_list(&stack_a);
			error(1);
		}
	}
	/*--------------------*/
	/* SORTING */

	print_list(&stack_a);
}