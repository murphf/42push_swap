#include <stdio.h>
#include <stdlib.h>

/*
* function to swap elements
*/
void swap(int *a, int *b)
 {
  int t;
	
	t = *a;
	*a = *b;
	*b = t;
}

/*
* does this return the new pivot ?
* high being the highest index of array
* low being the lowest index of the array
*/
int	partition(int	*arr, int low, int high)
{
	int		pivot;
	int		i;
	int		j;

	pivot = arr[high];
	i = low - 1;
	j = low;
	while (j < high)
	{
		if (arr[j] <= pivot)
		{
			i++;
			swap(&arr[i], &arr[j]);
		}
		j++;
	}
	i++;
	swap(&arr[i], &arr[j]);
	return (i);
}

void	quicksort(int	*arr, int	low, int	high)
{
	if (low >= high)
		return ;
	int	new_piv;
	new_piv = partition(arr, low, high);
	quicksort(arr, low, new_piv - 1);
	quicksort(arr, new_piv + 1, high);
}



/*
* give the index of the target in the arr 
*/
int	indexof(int *arr, int target, int len)
{
	int i;
	i = 0;
	//printf("%d\n", len);
	while (i < len)
	{
		if (arr[i] == target)
			return (i);
		i++;
	}
	return (-1);
}