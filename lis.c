#include "push_swap.h"

/*
* implementation of LIS from GFG
* temporary:
* circular doubly linked list -> array -> lenght of LIS -> LIS
* I should be able to extract the LIS directly from the linked list without converting it to an array  
*/
int _lis(int *arr, int n, int* max_ref)
{
    /* Base case */
    if (n == 1)
        return 1;
 
    // 'max_ending_here' is length of LIS ending with arr[n-1]
    int res, max_ending_here = 1;
 
    /* Recursively get all LIS ending with arr[0], arr[1] ...
       arr[n-2]. If   arr[i-1] is smaller than arr[n-1], and
       max ending with arr[n-1] needs to be updated, then
       update it */
    for (int i = 1; i < n; i++) {
        res = _lis(arr, i, max_ref);
        if (arr[i - 1] < arr[n - 1] && res + 1 > max_ending_here)
            max_ending_here = res + 1;
    }
 
    // Compare max_ending_here with the overall max. And
    // update the overall max if needed
    if (*max_ref < max_ending_here)
        *max_ref = max_ending_here;
 
    // Return length of LIS ending with arr[n-1]
    return max_ending_here;
}
 
// The wrapper function for _lis()
int lis(int *arr, int n)
{
    // The max variable holds the result
    int max = 1;
 
    // The function _lis() stores its result in max
    _lis(arr, n, &max);
 
    // returns max
    return max;
}

/*
* return length of longuest increasing susequence
*/
int lis_lenght(t_node   **head)
{
    int len;
    int *array;

    len = list_len(head);
    array = list_to_array(head);
    return (lis(array, len));
}

void    fill_arr_int(int    *arr, int   len)
{
    int i;

    i = 0;
    while (i < len)
        arr[i++] = 0;
}

t_node  *node_of_index(t_node   **head, int i)
{
    t_node  *first_node;
    int j;
    int len;

    first_node = *head;
    j = 0;
    len = list_len(head);
    while (j < len)
    {
        if (j == i)
            return(first_node);
        j++;
        first_node = first_node->next;
    }
    return (NULL);
}