#include "push_swap.h"
/*LONGUEST INCREASING SUBSEQUENCE*/



/*
* put smallest number on top of the stack (STACK A) 
*/
void	smallest_on_top(t_node	**head)
{
	int	small;
	int	pos;

	if (*head == NULL)
		return ;
	small = smallest(head);
	pos = position(head, small);
	wich_one_ra_rra(head, pos);
}

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
* 1- let the smallest be on top
* 2- let only the longuest increasing subsequence in stack A
* 3- iterate on stack B and store how much moves are needed for each element:  MOVES_COUNTER
*/
void	best_element(t_node	**head_a, t_node	**head_b)
{
	int		*lis;
	int		lis_len;
	int		pos;
	t_node	*first_node;
	t_node	*last_node;

	smallest_on_top(head_a);
	first_node = *head_a;
	last_node = first_node->prev;
	lis = LIS_constructor(head_a); //should be returning array of LIS 
	lis_len = 6; //lenght of LIS
	while (first_node != last_node)
	{
		if (in_array(lis, first_node->data, lis_len) == false)
		{
			pos = position(head_a, first_node->data);
			wich_one_ra_rra(head_a, pos);
			pb(head_a, head_b);
			first_node = *head_a;
			last_node = first_node->prev;
		}
		first_node = first_node->next;
	}
	if (in_array(lis, first_node->data, lis_len) == false)
	{
		pos = position(head_a, first_node->data);
		wich_one_ra_rra(head_a, pos);
		pb(head_a, head_b);
	}
}

/*
* count number of moves required to move each number from stack b to stack a (and put it in it's correct place)
*/
void	moves_counter(t_node	**head)
{
	t_node	*first_node;
	t_node	*last_node;
	int		pos0;
	int		pos1;

	first_node = *head;
	last_node = first_node->prev;

	while (first_node != last_node->prev)
	{
		pos0 = position(head, first_node->data);
		pos1 = position(head, last_node->data);
		first_node->moves[1] = how_much_to_the_top(head, pos0);
		last_node->moves[1] = how_much_to_the_top(head, pos1);
		first_node = first_node->next;
		last_node = last_node->prev;
	}
	//last_node = last_node->prev;
	pos0 = position(head, first_node->data);
	first_node->moves[1] = how_much_to_the_top(head, pos0);
	pos1 = position(head, last_node->data);
	last_node->moves[1] = how_much_to_the_top(head, pos1);
}

void	print_nb_of_moves(t_node	**head)
{
	t_node	*first_node;
	t_node	*last_node;

	first_node = *head;
	last_node = first_node->prev;
	while (first_node != last_node)
	{
		printf("[1] = %d\n", first_node->moves[1]);
		first_node = first_node->next;
	}
	printf("[1] = %d\n", first_node->moves[1]);
		first_node = first_node->next;
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

/*
* return how much rb are needed for the node to be on top (positive number)
* or how much rrb are needed.. (negative number) 
* DIDN'T COUNT PB
*/
int	how_much_to_the_top(t_node	**head, int pos)
{
	int	len;
	int mid;
	int	  x;
	int	  i;
	int	sign;

	i = 0;
	sign = 1;
	len = list_len(head);
	mid = len / 2;
	if (mid > 0)
	{
		if (pos && pos < mid)
		{
			sign = 1;
			while (i < pos)
				i++;
		}
		else if (pos && pos >= mid)
		{
			sign = -1;
			x = len - pos;
			while (i < x)
				i++;
		}
	}
	return (sign * i);
}

/*
* calculate how many moves we meed to position a number from the top of STACK B to 
* apparently there's 4 case:
* 
*/
// int	how_much_to_the_other_top(t_node	**head_a, t_node	**head_b)
// {
// 	t_node	*first_node;
// 	t_node	*last_node;
// 	int		pos;
// 	int		num;
// 	int		mid;
// 	int		i;

// 	first_node = *head_a;
// 	last_node = first_node->prev;
// 	num = (*head_b)->data;
// 	mid = list_len(head_a) / 2;
// 	i = 0;

// 	if (in_range(num, first_node->data, last_node->data))
// 		return (0);
// 	while (first_node != last_node)
// 	{
// 		if (in_range(num, first_node->data, first_node->next->data))
// 		{
// 			pos = position(head_a, first_node->next->data);	
// 			//wich_one_ra_rra(head_a, pos);
// 			i = how_much_to_the_other_top(head_a, pos);
// 			return (i); 
// 		}
// 		first_node = first_node->next;
// 	}
// 	if (num > biggest(head_a))
// 		{
// 			pos = position(head_a, biggest(head_a));
// 			i = how_much_to_the_other_top(head_a, pos);
// 			return (i);
// 		}
// 	return (-1);
// }
int	how_much_to_the_other_top(t_node	**head_a, int num)
{
	t_node	*first_node;
	t_node	*last_node;
	int		pos;
	//int		num;
	int		mid;
	int		i;

	first_node = *head_a;
	last_node = first_node->prev;
	//num = (*head_b)->data;
	i = 0;

	if (in_range(num, first_node->data, last_node->data))
		return (0);
	while (first_node != last_node)
	{
		//printf("aaaa\n");
		if (in_range(num, first_node->data, first_node->next->data))
		{
			pos = position(head_a, first_node->next->data);	
			//wich_one_ra_rra(head_a, pos);
			i = how_much_to_the_top(head_a, pos);
			return (i); 
		}
		first_node = first_node->next;
	}
	if (num > biggest(head_a))
		{
			pos = position(head_a, biggest(head_a));
			i = how_much_to_the_top(head_a, pos);
			return (i);
		}
	return (-1);
}