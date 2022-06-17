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

# Driver program to test above function
arr = [10, 22, 9, 33, 21, 50, 41, 60]
ans = lis(arr)
print "Length of lis is", ans[0]
print "The longest sequence is", ", ".join(str(x) for x in ans[1])

TRANSLATE CODE TO C
*/

int	*fill_arr(int	*array, char *string, int	len)
{
	int		i;
	int		k;
	int 	l;
	char	num[10];

	i = 0;
	k = 0;
	ft_bzero(num, 10);
	while (string[i])
	{
		while (string[i] != ' ' && string[i])
			num[l++] = string[i++];
		l = 0;
		if (k < len)
			array[k] = ft_atoi(num);
		ft_bzero(num, 10);
		k++;
		while(string[i] == ' ')
			i++;
	}
	return (array);
}

/*
* supposedly return array containing the longuest increasing subsequence of stack_a
* now this only SIMULATE the right answer (that I can get from the python code)
* so I can code the other part of the algorithm before returning to constructing LIS
*/
int	*lis_constructor(t_node	**stack_a)
{
	/* for now only return the LIS of 0 4 6 1 2 10 7 3 8 9 
	(wainting for the code solution)
	which is  
	*/

	int	*lis;
	int	n;

	n = 6;
	lis = (int	*)malloc(sizeof(int) * n);
	if (lis == NULL)
		return (NULL);
	lis = fill_arr(lis, "0 1 2 3 8 9", n);
	return (lis);
}