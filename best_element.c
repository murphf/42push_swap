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
	int		p_number_to_push; //store the position of the number to push
	t_node	*first_node;
	t_node	*last_node;

	smallest_on_top(head_a);
	first_node = *head_a;
	last_node = first_node->prev;
	lis = LIS_constructor(head_a); //should be returning array of LIS 
	lis_len = 6; //lenght of LIS
	/*
	* only letting the longuest incresing subsequence in STACK A
	*/
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
	moves_counter(head_b);
	moves_counter2(head_a, head_b);
	all_moves_stack_b(head_b);
	p_number_to_push = find_minimum_moves(head_b);
	printf("POS OF NUMBER TO PSUH = %d\n", p_number_to_push);
	//print_nb_of_moves(head_b);
}

/*
* fill moves[1] of numbers of STACK B
* how much for it to get on the top of stack B
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
		printf("num = %d | [0] = %d [1] = %d | total = %d\n",first_node->data, first_node->moves[0], first_node->moves[1], first_node->nb_moves);
		first_node = first_node->next;
	}
	printf("num = %d | [0] = %d [1] = %d | total = %d\n",first_node->data, first_node->moves[0], first_node->moves[1], first_node->nb_moves);
		//first_node = first_node->next;
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
* calculate how many moves we meed to position a number from the top of STACK B (num) in its position in stack A 
* apparently there's 4 cases.
*/
int	how_much_to_the_other_top(t_node	**head_a, int num)
{
	t_node	*first_node;
	t_node	*last_node;
	int		pos;
	int		mid;
	int		i;

	first_node = *head_a;
	last_node = first_node->prev;
	i = 0;

	if (in_range(num, first_node->data, last_node->data))
		return (0);
	while (first_node != last_node)
	{
		if (in_range(num, first_node->data, first_node->next->data))
		{
			pos = position(head_a, first_node->next->data);	
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

/*
* fill moves[0] of the numbers of STACK B
* how much for it to get in the righ position in STACK A (after getting in the top of STACK B)
*/
void	moves_counter2(t_node	**head_a, t_node	**head_b)
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
bool	same_sign(int	a, int	b)
{
	if ((a > 0 && b > 0) || (a < 0 && b < 0))
		return true;
	return false;
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
/*
* return position of number who needs the minimum moves
*/
int		find_minimum_moves(t_node	**head)
{
	t_node	*first_node;
	t_node	*last_node;
	int		min;
	int		pos;
	int		pos_m;

	first_node = *head;
	last_node = first_node->prev;
	min = first_node->nb_moves;
	pos = 0;
	pos_m = pos;
	while (first_node != last_node)
	{	
		if (first_node->nb_moves < min)
		{
			min = first_node->nb_moves;
			pos_m = pos;
		} 
		pos++;
		first_node = first_node->next;
	}
	if (first_node->nb_moves < min)
	{
		min = first_node->nb_moves;
		pos_m = pos;
	}
	return(pos_m);
}
void	push_the_elemnt_to_a(t_node	**head_a, t_node	**head_b)
{
	t_node	**first_node_b;
	int	pos;
	int	i;
	int	moves;
	int	ind;
	int	extra;

	ind = 0;
	first_node_b = *head_b;
	while (*head_b)
	{
		pos = find_minimum_moves(head_b);
		/*
		* when will we use rrr
		*/
		i = 0;
		if (abs(first_node_b->moves[1]) > abs(first_node_b->moves[0]))
			ind = 1;
		if (same_sign(first_node_b->moves[0], first_node_b->moves[1]))
		{
			if (first_node_b->moves[0] < 0)
			{
				moves = _min(abs(first_node_b->moves[0]), abs(first_node_b->moves[1]));
				extra = max(abs(first_node_b->moves[0]), abs(first_node_b->moves[1])) - moves; 
				while (i < moves)
				{
					i++;
					rrr(head_a, head_b);
				}
				i = 0;
				if (ind)
				{
					while(i < extra)
					{
						i++;
						rb(head_b);
					}
				}
				else
				{
					while(i < extra)
					{
						i++;
						rb(head_b);
					}
				}
			}
			else if (first_node_b->moves[0] > 0)
			{	
				moves = _min(first_node_b->moves[0], first_node_b->moves[1]);
				while (i < moves)
				{
					i++;
					rr(head_a, head_b);
				}
				i = 0;
				if (ind)
				{
					while(i < extra)
					{
						i++;
						rb(head_b);
					}
				}
				else
				{
					while(i < extra)
					{
						i++;
						rb(head_b);
					}
				}
			}
		}
	}

}