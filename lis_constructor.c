/*
* something close to Longuest increasing subsequence
* first sort the stack with quicksort inside an array
* put smallest number on top of stack A
* search for the following number...
*/

#include "push_swap.h"
/*
* now this will sort the stack in an array
*/
int *quicksort__stack(t_node    **stack_a, int size)
{
    int *array;

    array = list_to_array(stack_a);
    quicksort(array, 0, size - 1);
    return (array);
}

/*this will let the longuest continous increasing subsequence in STACK A*/

/*
* the first element in stack A would be the smallest
*/
void    subseq(t_node   **stack_a, t_node   **stack_b, int  *sorted_arr)
{
    t_node  *first_node;
    int     i;
    int     pos;

    first_node = *stack_a;
    i = 0;
    //FUUUCK NEW REVELATION!!
    /*
    * understanding the mecanism of this loop
    * if first_node->next == *stack_a means first node become the last one
    * but the code in the loop won't get executed
    * so we'll need additional instructions for the last node
    */
    while (first_node->next != (*stack_a))
    {
        if (first_node->data == sorted_arr[i])
            i++;
        else
        {
            pos = position(stack_a, first_node->data);
            wich_one_ra_rra(stack_a, pos);
            pb(stack_a, stack_b);
        }
        first_node = first_node->next;
    }
    if (first_node->data != sorted_arr[i])
    {
            pos = position(stack_a, first_node->data);
            wich_one_ra_rra(stack_a, pos);
            pb(stack_a, stack_b);
    }
}