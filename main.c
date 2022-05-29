#include "push_swap.h"
#define	N 3

int main()
{
	int a[N] = {1, 2, 3};
	int	i;
	t_node	*stack_a;
	t_node	*stack_b;
	i = 0;

	//stack_b = create_node(500, 0);
	stack_b = NULL;
	stack_a = create_node(a[i], i);
	i++;
	while (i < N)
	{
		if (identical_found(&stack_a, a[i]))
			{
				printf("found indentical\n");
				return (0);
			}
		add_node_end(&stack_a, create_node(a[i], i));
		i++;
	}
	printf("stack B before push------\n");
	print_list(&stack_b);
	stack_b = push(&stack_a, &stack_b);
	printf("stack B after push------\n");
	print_list(&stack_b);
	printf("stack A after push------\n");
	print_list(&stack_a);
}