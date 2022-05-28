#include "push_swap.h"

/*
* check if the list's data is sorted or not
* returns:
* 		0 if unsorted
*		1 if sorted
*/
int	is_sorted(t_node **head)
{
	t_node	*first_node;
	t_node	*last_node;
	int		i;

	first_node = *head;
	last_node = first_node->prev;

	while (first_node != last_node)
	{
		if (first_node->data > first_node->next->data)
			return (0);
		i++;
		first_node = first_node->next;
	}
	return (1);
}

/*
* check if the int new_data is already in the list
* to make sure there is no identical numbers in the list
*/
int	identical_found(t_node	**head, int new_data)
{
	t_node	*first_node;
	t_node	*last_node;

	first_node = *head;
	last_node = first_node->prev;

	if (last_node->data == new_data)
		return (1);
	while (first_node != last_node)
	{
		if (first_node->data == new_data)
			return (1);
		first_node = first_node->next;
	}
	return (0);
}