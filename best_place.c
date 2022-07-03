#include "push_swap.h"

/*
* check if num is in the part of the array starting at position: start
*/
bool	in_part_of_array(int *array, int num, int size, int start)
{
	while (start < size)
	{
		if (array[start] == num)
			return (true);
		start++;
	}
	return (false);
}
/*
* return the closest follower available in stack_a 
* sorted arr is stack A sorted with quicksort
*/
int	closest_follower(t_node	**head_a, int	num, int	*sorted_arr, int	size)
{
	int 	i;
	int		target_pos;
	int 	follower;
	t_node	*first_node;
	t_node	*last_node;
	int		best;
	int		in_this;

	
	best = INT_MAX;
	first_node = *head_a;
	last_node = first_node->prev;
	in_this = 0;
	i = 0;
	//here we find the position of the number we want to place 
	while (i < size)
	{
		if (sorted_arr[i] == num)
			target_pos = i;
		i++;
	}
	//here we find the most optimal follower
	while (first_node != last_node)
	{
		if (in_part_of_array(sorted_arr, first_node->data, size, target_pos))
			{
					in_this = 1;
					if (first_node->data <= best)
						best = first_node->data;
			}
		first_node = first_node->next;
	}
	if (in_part_of_array(sorted_arr, first_node->data, size, target_pos))
	{
		in_this = 1;
		if (first_node->data <= best)
			best = first_node->data;
	}
	if (!in_this)
		best = smallest(head_a);
	return (best);
}