#include "push_swap.h"

/*
* create a node and assign to it: 
* data
* and index
*/
t_node	*create_node(int data, int index)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node->data = data;
	new_node->index = index;
	new_node->prev = new_node;
	new_node->next = new_node;
	return (new_node);
}

/*
* add new node at the end of circular doubly linked list 
* missing: special case handling/protection
*/
t_node	*add_node_end(t_node	**head, t_node	*new_node)
{
	t_node	*first_node;
	t_node	*last_node;

	first_node = *head;
	last_node = first_node->prev;
	
	new_node->next = *head;
	new_node->prev = last_node;
	last_node->next = new_node;
	first_node->prev = new_node;
	return (new_node);
}

/*
* add new node at the beginning of circular doubly linked list 
* missing: special case handling/protection
*/
t_node	*add_node_beg(t_node	**head, t_node	*new_node)
{
	t_node	*first_node;
	t_node	*last_node;


	first_node = *head;
	last_node = first_node->prev;

	new_node->next = first_node;
	new_node->prev = last_node;
	first_node->prev = new_node;
	last_node->next = new_node;
	*head = new_node;
	return (new_node);
}

/*
* print the data of a circular doubly linked list  
*/
void	print_list(t_node **head)
{
	t_node	*first_node;

	if (!*head)
	{
		printf("empty list\n");
		return ;
	}
	first_node = *head;
	printf("%d\n", first_node->data);
	first_node = first_node->next;
	while (first_node != *head)
	{
		printf("%d\n", first_node->data);
		first_node = first_node->next;
	}
}
