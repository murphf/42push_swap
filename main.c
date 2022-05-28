#include "push_swap.h"
#define	N 3

int main()
{
	int a[N] = {1, 2, 3};
	int	i;
	t_node	*stack_a;
	t_node	*stack_b;
	i = 0;

	stack_b = create_node(200, 0);
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
	//print_list(&stack_a);
	// printf("after swap------\n")
	// swap(&node);
	// printf("after rotate------\n");
	// rotate(&node);
	// printf("after reverse rotate-----\n");
	// rev_rotate(&node);
	// printf("after pop-----\n");
	// pop(&node);
	printf("stack before push------\n");
	print_list(&stack_b);
	//push(&stack_a, &stack_b);
	printf("stack after push------\n");
	print_list(&stack_b);
}