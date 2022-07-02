#include "push_swap.h"
/*LONGUEST INCREASING SUBSEQUENCE*/

/*
* fill moves[1] of numbers of STACK B
* how much for it to get on the top of stack B
*/
void	moves_counter1(t_node	**head)
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
		printf("num = %d | [0] = %d [1] = %d | total = %d\n",first_node->data, first_node->moves[0], first_node->moves[1], first_node->nb_moves);
		first_node = first_node->next;
	}
	printf("num = %d | [0] = %d [1] = %d | total = %d\n",first_node->data, first_node->moves[0], first_node->moves[1], first_node->nb_moves);
		//first_node = first_node->next;
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
* calculate how many moves we meed to position a number from the top of STACK B (num) in its position in stack A 
* apparently there's 4 cases.
*/
/* THIS FUNTCION IS THE ROOT OF THE BUG*/
int	how_much_to_the_other_top0(t_node	**head_a, int num)
{
	t_node	*first_node;
	t_node	*last_node;
	int		pos;
	int		mid;
	int		i;

	first_node = *head_a;
	last_node = first_node->prev;
	i = 0;

	//if (in_range(num, first_node->data, last_node->data))
	 	//return (0);
	
	/*
	* 10
	* 0
	* 5
	* 9
	*/ 
	if (in_range(num, last_node->data, first_node->data))
			return (0);
	while (first_node != last_node)
	{
		if (in_range(num, first_node->data, first_node->next->data))
		{
			pos = position(head_a, first_node->data);	
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
	if (num < smallest(head_a))
	{
		pos = position(head_a, smallest(head_a)); 
		i = how_much_to_the_top(head_a, pos);
		return (i);
	}
	return (-1);
}
int last_node0(t_node	**head)
{
	t_node *first_node;
	first_node = *head;
	return(first_node->prev->data);
}
int	how_much_to_the_other_top(t_node	**head_a, int num)
{
	t_node	*first_node;
	t_node	*last_node;
	int		pos;
	int		mid;
	int		i;
	int 	best;
	int 	enter;

	first_node = *head_a;
	last_node = first_node->prev;
	i = 0;

	//if (in_range(num, first_node->data, last_node->data))
	 	//return (0);
	
	/*
	* 10
	* 0
	* 5
	* 9
	*/
	enter = 0;
	best = INT_MAX;
	if (in_range(num, last_node->data, first_node->data))
			return (0);
	while (first_node != last_node)
	{
		if (in_range(num, first_node->data, first_node->next->data))
		{
			if (first_node->next->data < best)
				{
					enter = 1;
					best = first_node->next->data;
				}
		}
		first_node = first_node->next;
	}
	if (enter)
	{
		pos = position(head_a, best);	
		i = how_much_to_the_top(head_a, pos);
		return (i);
	}
	if (num > biggest(head_a))//THIS
	{
		//pos = position(head_a, biggest(head_a)); 
		pos = list_len(head_a) - 1;
		i = how_much_to_the_top(head_a, pos);
		return (i);
	}
	if (num < smallest(head_a)) 
	{
		pos = position(head_a, smallest(head_a)); 
		i = how_much_to_the_top(head_a, pos);
		return (-1);
	}	
	return(-1);
}

/*
* fill moves[0] of the numbers of STACK B
* how much for it to get in the righ position in STACK A (after getting in the top of STACK B)
*/
void	moves_counter0(t_node	**head_a, t_node	**head_b)
{
	t_node	*first_node_b;
	t_node	*last_node_b;
	int		n_moves;

	first_node_b = *head_b;
	last_node_b = first_node_b->prev;
	while (first_node_b != last_node_b->prev)
	{
		first_node_b->moves[0] = how_much_to_the_other_top(head_a, first_node_b->data);
		last_node_b->moves[0] = how_much_to_the_other_top(head_a, last_node_b->data);
		first_node_b = first_node_b->next;
		last_node_b = last_node_b->prev;
	}
	first_node_b->moves[0] = how_much_to_the_other_top(head_a, first_node_b->data);
	last_node_b->moves[0] = how_much_to_the_other_top(head_a, last_node_b->data);
}

/*
* claculate the sum of moves needed for each number in stack B
* so we can compare them and chose the one with the least number
*/
void	all_moves_stack_b(t_node	**head)
{
	t_node	*first_node;
	t_node	*last_node;
	int		num;
	int		a;
	int		b;

	first_node = *head;
	last_node = first_node->prev;
	num = 0;
	while (first_node != last_node)
	{
		if (same_sign(first_node->moves[0], first_node->moves[1]))
		{
			a = first_node->moves[0];
			b = first_node->moves[1];
			first_node->nb_moves = _max(abs(a), abs(b));
		}
		else
		{
			a = first_node->moves[0];
			b = first_node->moves[1];
			first_node->nb_moves = abs(a) + abs(b);
		}
		first_node = first_node->next;
	}
	if (same_sign(first_node->moves[0], first_node->moves[1]))
		{
			a = first_node->moves[0];
			b = first_node->moves[1];
			first_node->nb_moves = _max(abs(a), abs(b));
		}
		else
		{
			a = first_node->moves[0];
			b = first_node->moves[1];
			first_node->nb_moves = abs(a) + abs(b);
		}
}
