#include "push_swap.h"

/*
# Dynamic programming Python implementation of LIS problem
# lis returns length of the longest increasing subsequence
# in arr of size n
def lis(arr):
    n = len(arr)

    # Declare the list (array) for LIS and initialize LIS
    # values for all indexes
    lis = [1]*n

    prev = [0]*n
    for i in range(0, n):
        prev[i] = i
---------------
    # Compute optimized LIS values in bottom up manner
    for i in range (1 , n):
        for j in range(0 , i):
            if arr[i] > arr[j] and lis[i]< lis[j] + 1:
                lis[i] = lis[j]+1
                prev[i] = j

    # Initialize maximum to 0 to get the maximum of all
    # LIS
    maximum = 0
    idx = 0

    # Pick maximum of all LIS values
    for i in range(n):
        if maximum < lis[i]:
            maximum = lis[i]
            idx = i

    seq = [arr[idx]]
    while idx != prev[idx]:
        idx = prev[idx]
        seq.append(arr[idx])

    return (maximum, reversed(seq))
# end of lis function
*/
/*
* fisrt I'll convert stack A to array A of lenght n
* n = argc - 1
*/
/* creat an array of size: size and fill it with n*/
int	*creat_fill(int n, int size)
{
	int	*array;
	int	i;

	i = 0;
	array = (int *)malloc(sizeof(int) * size);
	if (!array)
		return (NULL);
	while (i < size)
	{
		array[i] = n;
		i++;
	}
	return (array);
}

int	*lis_construct(int *arr, int	size)
{
	//int	*arr;
	int	*lis;
	int	*prev;
	int *seq;
	int	i;
	int max;
	int idx;

	i = 0;
	//arr= list_to_array(head);
	lis = creat_fill(1, size);
	prev = creat_fill(0, size);
	while (i < size)
	{
		prev[i] = i;
		i++; 
	}
	/*
	for i in range (1 , n):
        for j in range(0 , i):
            if arr[i] > arr[j] and lis[i]< lis[j] + 1:
                lis[i] = lis[j]+1
                prev[i] = j
	*/
	for (i = 1; i < size; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (arr[i] > arr[j] && lis[i] < (lis[j] + 1))
			{
				lis[i] = lis[j] + 1;
				prev[i] = j;
			}
		}
	}
	/*
	 # Initialize maximum to 0 to get the maximum of all
    # LIS
    maximum = 0
    idx = 0

    # Pick maximum of all LIS values
    for i in range(n):
        if maximum < lis[i]:
            maximum = lis[i]
            idx = i
	*/
	max = 0;
	idx = 0;
	for (i = 0; i < size; i++)
	{
		if (max < lis[i])
		{
			max = lis[i];
			idx = i;
		}
	}
	/*
	*
	 seq = [arr[idx]]
    while idx != prev[idx]:
        idx = prev[idx]
        seq.append(arr[idx])
    return (maximum, reversed(seq))
	*/

	int k = 0;
	seq = (int *)malloc(sizeof(int) * (max + 1));
	if (!seq)
		return (NULL);
	seq[k++] = max;
	seq[k++] = arr[idx];
	while (idx != prev[idx])
	{
		idx = prev[idx];
		seq[k] = arr[idx];
		k++;
	}
	//first element of seq contains the lenght of the longuest increasing subsequence
	//seq[k] = max;
	return (seq); //reverse
}