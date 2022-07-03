#include "push_swap.h"

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
	else if ( i == 3)
		printf("ALREADY SORTED!\n");
	exit(EXIT_FAILURE);
}

int main(int argc, char *argv[])
{
	t_node	*stack_a;
	t_node	*stack_b;
	int		i;
	int		len;
	long	num;

	i = 1;
	stack_b = NULL;
	/* INPUT ERROR CHECK*/
	if (argc < 2)
		error(0);
	else
	{
		len = argc - 1;
		if (valid_arg(argv[i]))
		{
			stack_a = create_node(ft_atoi(argv[i]), i - 1);
			if (argc >= 3)
			{
				i++;
				num = ft_atoi(argv[i]);
			}
		/*
		* this to prevent entering the next loop if there is only one number
		* is there a better way?
		*/
			else
				argc--; 
		}
		while (valid_arg(argv[i]) && i < argc && is_int(num))
		{
			if (identical_found(&stack_a, num))
				{
					delete_list(&stack_a);
					error(2);
				}
			add_node_end(&stack_a, create_node(num, i - 1));
			i++;
			if (i == argc)
				break;
			num = ft_atoi(argv[i]);
		}
		if (i != argc)
		{
			delete_list(&stack_a);
			error(1);
		}
	}
	/*--------------------*/
	//smallest_on_top(&stack_a);
	best_element(&stack_a, &stack_b);
	//int *a = quicksort__stack(&stack_a, 30);
	//printarray(a, 30);
	print_stacks(&stack_a, &stack_b);	
}