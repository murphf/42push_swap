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

/*
* return array containing longuest increasing subsequence 
*/
// int *return_lis(t_node  **head)
// {
//     int len_of_lis;
//     int len;
//     int *array;
//     int big;
//     t_node  *first_node;
//     t_node  *first_node_hold;
//     t_node  *next_hold;
//     t_node  *last_node;

//     first_node = *head;
//     first_node_hold = first_node;
//     next_hold = first_node->next;
//     last_node = first_node->prev;
//     len_of_lis = lis_lenght(head);
//     len = 0;
//     array = (int *)malloc(sizeof(int) * len);
//     if (array == NULL)
//         return (NULL);
//     fill_arr_int(array, len);

//     big = first_node_hold->data;
//     array[len] = big;
//     len++;
//     while (next_hold != last_node)
//     {
//         first_node = next_hold;
//         while (first_node != last_node)
//         {
//             if (first_node->data > big)
//             {
//                 array[len] = first_node->data;
//                 big = first_node->data;
//                 len++;
//                 if (len == len_of_lis)
//                     return(array);
//             }
//             first_node = first_node->next;
//         }
//         if (first_node->data > big)
//             {
//                 array[len] = first_node->data;
//                 big = first_node->data;
//                 len++;
//                 if (len == len_of_lis)
//                     return(array);
//             }
//         next_hold = next_hold->next;
//         len = 1;        
//         array[len] = next_hold->data;
//         big = next_hold->data;
//         len++;
//     }
//     return (array);
// }
/*
* return
*/
// int		lenght_lis(t_node **stack)
// {

// }

/*
* return node of index i
*/
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
int *return_lis(t_node **head)
{
    int len_LIS;
    int len_list;
    int *array;
    t_node  *first_node;
    int big;
    int big_hold;
    int i;
    int j;
    int k;
    int l;

    first_node = *head;
    len_list = list_len(head);
    len_LIS = lis_lenght(head);
    array = (int *)malloc(sizeof(int) * len_LIS);
    if (array == NULL)
        return (NULL);
    
    array[0] = first_node->data;
    big = first_node->data;
    big_hold = big;
    j = 1;
    l = 1;
    while (l < len_LIS)
    {
        while (j < len_list)
        {
            i = j;
            first_node = node_of_index(head, i);
            if (first_node == NULL)
                return (NULL);
            k = l;
            while (i < len_list)
            {
                if (first_node->data > array[k - 1])
                {
                    array[k] = first_node->data;
                    //printf("%d ", array[k]);   
                    big = first_node->data; 
                    if (k == 5)
                        return(array);
                    k++;
                }
                i++;
                first_node = first_node->next;
            }
            big = big_hold;
            j++;
        }
        l++;
    }
    return (NULL);
}