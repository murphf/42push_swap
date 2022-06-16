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

void	best_element(t_node	**head_a, t_node	**head_b)
{
	smallest_on_top(head_a);
}

t_edges	*allocate_edge(void)
{
	t_edges	*new;

	new = (t_edges *)malloc(sizeof(t_edges));
	if (new == NULL)
		return (NULL);
	return (new);
}


/*let's find the LIS*/

/*
* return the begining(min) and end(max) of the LONGUEST INCREASING SUBSEQUENCE
*/
t_edges	*lisi(t_node	**head)
{
	t_node	*first_node_hold;
	t_node	*first_node;
	t_node	*last_node;
	t_edges	*subsec = allocate_edge();
	t_edges	*long_subsec = allocate_edge();
	int		len;
	int		long_len;
	int		min;
	int 	max;
	int		big;

	first_node_hold = *head;
	first_node = *head;
	last_node = first_node->prev;
	long_len = 1;
	while (first_node_hold != last_node)
	{
		min = first_node->data;
		big = min;
		len = 1;
		subsec->max = first_node->data;
		//printf("%d ", subsec->max);
		while (first_node != last_node)
		{
			if (first_node->data > big)
				{
					len++;
					big = first_node->data;
					subsec->max = first_node->data;
					//printf("%d ", subsec->max);
				}
			first_node = first_node->next;
		}
		if (first_node->data > big)
			{
				len++;
				subsec->max = first_node->data;
			}
		//printf("%d ", subsec->max);
		//printf("| \n");
		first_node_hold = first_node_hold->next;
		first_node = first_node_hold;
		if (len > long_len)
		{
			long_len = len;
			subsec->min = min;
			long_subsec = subsec;
		}
	}
	return (long_subsec);
}

/*
* return the lenght og the LIS
*/
int len_lis(t_node	**head)
{
	t_node	*first_node_hold;
	t_node	*first_node;
	t_node	*last_node;
	int		len;
	int		long_len;
	int		big;
	int		min;
	int 	max;

	first_node_hold = *head;
	first_node = *head;
	last_node = first_node->prev;
	long_len = 1;
	len = 1;
	while (first_node_hold != last_node)
	{
		min = first_node->data;
		big = min;
		len = 1;
		while (first_node != last_node)
		{
			if (first_node->data > big)
				{
					len++;
					big = first_node->data;
				}
			first_node = first_node->next;
		}
		if (first_node->data > big)
			{
				len++;
			}
		if (len > long_len)
			long_len = len;
		first_node_hold = first_node_hold->next;
		first_node = first_node_hold;
	}
	return (long_len);
}

//DON't FORGET TO FREE THE ALLOCATED STRUCT