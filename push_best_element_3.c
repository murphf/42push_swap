#include "push_swap.h"

/* PSEUDOCODE
* 1- find the element with the least amount of moves
* 2- CASES:
	A- moves[0] && moves[1] have the same sign
		a- positive
			- rr time (min of both)
			- extra = max - min
			- if max is moves[0]
				-ra time (extra)
			- if max is moves[1]
				-rb time (extra)
		b- negative
			- rrr time (min of absolute value of both)
			- extra = max (of abs values) - min (of abs values)
			- if max id moves[0]:
				-rra time (extra)
			- if max is moves[1]:
				-rrb time (extra)
	B- moves[0] && moves[1] have different signs:
			-if moves[0] > 0:
				-ra time (abs(moves[0]))
			-if moves[0] < 0:
				-rra time (abs(moves[0]))
			-if moves[1] > 0:
				-rb time (abs(moves[1]))
			-if moves[1] < 0:
				-rrb time (abs(moves[1]))
VERY FUCKING BIG UGLY FUNCTION
*/

void	same_half(t_node	**head_a, t_node	**head_b, t_node	*node)
{
	int combo;
	int max;
	int extra;
	int	i;
	int	no_a;
	int	no_b;

	combo = _min(abs(node->moves[0]), abs(node->moves[1]));
	max = _max(abs(node->moves[0]), abs(node->moves[1]));
	extra = max - combo;
	i = 0;
	if (node->moves[0] > 0)
	{
			while (i < combo)
			{
				rr(head_a, head_b);
				i++;
			}
			i = 0;
			if (max == abs(node->moves[0]))
			{
				while (i < extra)
				{
					ra(head_a);
					i++;
				}
			}
			else if (max == abs(node->moves[1]))
			{
				while (i < extra)
				{
					rb(head_b);
					i++;
				}
			}
			pa(head_a, head_b);
	}
	else if (node->moves[0] < 0)
	{
		while (i < combo)
		{
			rrr(head_a, head_b);
			i++;
		}
		i = 0;
		if (max == abs(node->moves[0]))
		{
			while (i < extra)
			{
				rra(head_a);
				i++;
			}
		}
		else if (max == abs(node->moves[1]))
		{
			while (i < extra)
			{
				rrb(head_b);
				i++;
			}
		}
		pa(head_a, head_b);
	}
}

void	diff_halfs0(t_node	**head_a, t_node	**head_b, t_node	*node)
{
	int	combo;
	int	extra;
	int		i;

	combo = abs(node->moves[0]);
	extra = abs(node->moves[1]);
	i = 0;
	if (node->moves[0] >= 0)
	{
		while (i < combo)
		{
			ra(head_a);
			i++;
		}
	}
	else if (node->moves[0] < 0)
	{
		while (i < combo)
		{
			rra(head_a);
			i++;
		}
	}
	i = 0;
	if (node->moves[1] >= 0)
	{
		while (i < extra)
		{
			rb(head_b);
			i++;
		}
		pa(head_a, head_b);
	}
	else if (node->moves[1] < 0)
	{
		while (i < extra)
		{
			rrb(head_a);
			i++;
		}
		pa(head_a, head_b);
	}
}
void	diff_halfs(t_node	**head_a, t_node	**head_b, t_node	*node)
{
	int	combo;
	int	extra;
	int		i;

	combo = abs(node->moves[0]);
	extra = abs(node->moves[1]);
	i = 0;
	if (node->moves[0] >= 0)
	{
		while (i < combo)
		{
			ra(head_a);
			i++;
		}
	}
	else if (node->moves[0] < 0)
	{
		while (i < combo)
		{
			rra(head_a);
			i++;
		}
	}
	i = 0;
	if (node->moves[1] >= 0)
	{
		while (i < extra)
		{
			rb(head_b);
			i++;
		}
		pa(head_a, head_b);
	}
	else if (node->moves[1] < 0)
	{
		while (i < extra)
		{
			rrb(head_b);
			i++;
		}
		pa(head_a, head_b);
	}
}
void	push_the_elemnt_to_a(t_node	**head_a, t_node	**head_b)
{
	int		best_el_pos;
	t_node	*node_b;
	int		combo;
	int		extra;
	int		max;
	int		i;

	
	//while ( *head_b)
	
	i = 0;
	while (*head_b)
	{
		best_el_pos = find_minimum_moves(head_b);
		node_b = node_of_index(head_b, best_el_pos);
		
		//wich_one_ra_rra(head_b, best_el_pos);
		if (same_sign(node_b->moves[0], node_b->moves[1]))
			same_half(head_a, head_b, node_b);
		else
			diff_halfs(head_a, head_b, node_b);
		if (*head_b)
		{
			moves_counter1(head_b);
			moves_counter0(head_a, head_b);
			all_moves_stack_b(head_b);
		}
	}
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

	//smallest_on_top(head_a);
	//lis = LIS_constructor(head_a); //should be returning array of LIS 
	lis = lis_construct(head_a, list_len(head_a));
	lis_len = lis[0] + 1; //lenght of LIS
	first_node = *head_a;
	last_node = first_node->prev;
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
	moves_counter1(head_b);
	moves_counter0(head_a, head_b);
	all_moves_stack_b(head_b);
	push_the_elemnt_to_a(head_a, head_b);
	smallest_on_top(head_a);
}
/*
* return POSITION of the number who needs the minimum moves
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
			//pos_m = position(head, first_node->data);
			pos_m = pos;
		} 
		pos++;
		first_node = first_node->next;
	}
	if (first_node->nb_moves < min)
	{
		min = first_node->nb_moves;
		//pos_m = position(head, first_node->data);
		pos_m = pos;
	}
	return(pos_m);
}
