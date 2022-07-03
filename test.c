#include <stdlib.h>
#include <stdio.h>
int	main()
{
	int size;
	int	*a = malloc(sizeof(int) * 5);
	size = sizeof(a) / sizeof(a[0]);
	printf("%d", size);
}