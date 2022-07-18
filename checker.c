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
	stack_a = *(parsing(argc, argv));
	mv = (char	*)malloc(sizeof(char) * 150000);
	if (!mv)
		return (0);
	bzero(mv, 150000);
	
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
	mv = realloc(mv, len);
	//printf("%s\n", mv);
}