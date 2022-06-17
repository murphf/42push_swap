#include "push_swap.h"

/*
* convert circular doubly linked list to an array
*/
int	*list_to_array(t_node	**head)
{
	int	    len;
	int	    *array;
	int	    i;
	t_node	*first_node;
	t_node	*last_node;

    first_node = *head;
    last_node = first_node->prev;
	len = list_len(head);
	array = (int *)malloc(sizeof(int) * len);
	if (array == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		array[i] = first_node->data;
        first_node = first_node->next;
        i++;
	}
    return (array);
}

/*
* print content of array 
*/
void printarray(int *array, int size)
{
	int	i;

	i = 0;
	if (array == NULL)
		printf("NOTHING!\n");
	while (i < size)
		printf("%d ", array[i++]);
	printf("\n");
}