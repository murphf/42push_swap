#include "push_swap.h"
/*
* MOVES[0] concern moves in STACK A
* MOVES[1] concern moves in STACK B
*/

/*
* put smallest number on top of the stack (STACK A) 
*/
void	smallest_on_top(t_node	**head)
{
	int	small;
	int	pos;

	if (*head == NULL)
		return;
	small = smallest(head);
	pos = position(head, small);
	wich_one_ra_rra(head, pos);
}

/*
* check if number nbr is in array
*/
bool	in_array(int	*array, int nbr, int len)
{
	int i;

	i = 0;
	while (i < len)
	{
		if (array[i] == nbr)
			return (true);
		i++;
	}
	return (false);
}
/*
* see if a and b 
* value 0 excluded
*/
bool	same_sign(int	a, int	b)
{
	if ((a > 0 && b > 0) || (a < 0 && b < 0))
		return true;
	return false;
}

/*
* return absolute value of n
*/
int	abs(int	n)
{
	if (n < 0)
		return (-n);
	return (n);
}