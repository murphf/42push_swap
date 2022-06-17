/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: styes <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 11:33:48 by styes             #+#    #+#             */
/*   Updated: 2021/11/19 21:27:48 by styes            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
* copy n first bytes of the src into dest
* doesn't prevent overlapping
* overlapping: when the src is overwritten before getting read/copied
* overlapping (may) occure when dest and src points to the same array 
* and dest > src (depends on how many bytes you want to copy)
*/
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*dest0;
	unsigned char	*src0;

	dest0 = (unsigned char *)dest;
	src0 = (unsigned char *)src;
	if (!dest0 && !src0)
		return (NULL);
	i = 0;
	while (i < n)
	{
		dest0[i] = src0[i];
		i++;
	}
	return (dest);
}
/*
int	main()
{	
	int arr0[5] = {44, 55, 66, 77, 88};
	int arr1[5] = {1, 2, 3, 4, 5};
   	ft_memcpy(arr0, arr1, sizeof(int) * 5); //BYTE manipulation
	int i = 0;
	while (i < 5)
	{
		printf("%d ", arr0[i]);
		i++;
	}
	char	a[] = "blabla";
	char	b[] = "hey";
	printf ("%s\n", memcpy(NULL, NULL, 3));
	printf("%s\n", ft_memcpy(NULL, NULL, 3));
}*/
