#include "push_swap.h"

/*
* check if the list's data is sorted or not
* returns
* 		false / 0 if unsorted
*		true / 1 if sorted
*/
bool	is_sorted(t_node **head)
{
	t_node	*first_node;
	t_node	*last_node;

	first_node = *head;
	last_node = first_node->prev;

	while (first_node != last_node)
	{
		if (first_node->data > first_node->next->data)
			return (false);
		first_node = first_node->next;
	}
	return (true);
}


/*
* check if the int new_data is already in the list
* to make sure there is no identical numbers in the list
*/
bool	identical_found(t_node	**head, int new_data)
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
			return (true);
		first_node = first_node->next;
	}
	return (false);
}