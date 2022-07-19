#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>


void *ft_realloc(void *ptr, size_t size)
{
	char	*n_ptr;
	
	int		i;

	if (size == 0)
	{
		free(ptr);
		return (NULL);
	}
	n_ptr = (char *)malloc(size);
	if (!n_ptr)
		return (NULL);
	if (!ptr)
		return (n_ptr);
	i = -1;
	while (++i < size)
		n_ptr[i] = ((char *)ptr)[i];
	free(ptr);
	return ((void *)n_ptr);
}
/* Ptr to currently allocated block.  If
* it's 0, then this procedure behaves
* identically to malloc. */
/* Size of block after it is extended */
char *realloc(char *ptr, unsigned int newSize)
{
    unsigned int curSize;
    char *newPtr;

    if (ptr == 0) {
	return malloc(newSize);
    }
    curSize = Mem_Size(ptr);
    if (newSize <= curSize) {
	return ptr;
    }
    newPtr = malloc(newSize);
    bcopy(ptr, newPtr, (int) curSize);
    free(ptr);
    return(newPtr);
}
int main()
{

	char	*a;

	//int b[6] = {0, 1, 2, 3, 4, 5, 6};
	a = malloc(5);
	printf("%lu\n", sizeof(a));
	add(5, 5);
	//a = realloc(a, 17);
	//strcpy(a, "holla hhhhhhhhhh");
	//printf("%s\n", a);
	//a = ft_realloc(a, 9);
}