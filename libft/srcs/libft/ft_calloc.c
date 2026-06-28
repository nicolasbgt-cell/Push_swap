/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annlecre <annlecre@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 09:08:21 by annlecre          #+#    #+#             */
/*   Updated: 2026/05/02 10:08:03 by annlecre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*The  calloc() function allocates memory for an array of n elements of 
 * size bytes each and returns a pointer to the allocated memory.
 * The memory is set to zero.  If  n  or size  is  0,  then calloc() returns 
 * a unique pointer value that can later be successfully passed to free().
 * If the multiplication of n and size would result in integer overflow,  then
 * calloc() returns an error.
 * The  malloc(),  calloc(), realloc(), and reallocarray() functions return 
 * a pointer to the allocated memory, which is suitably aligned for any type 
 * that fits into  the  requested size or less.
 * On error, these functions return NULL and set errno.  Attempting to allocate 
 * more than PTRDIFF_MAX bytes is considered an error, as an object that large 
 * could cause later pointer subtraction to overflow.
 * calloc() can fail with the following error:
 * ENOMEM Out of memory.  Possibly, the application hit  the  RLIMIT_AS  or  
 * RLIMIT_DATA limit  described  in getrlimit(2).
 * Another reason could be that the number of mappings created by  the  caller
 * process  exceeded  the  limit  specified  by /proc/sys/vm/max_map_count.*/

void	*ft_calloc(size_t n, size_t size)
{
	unsigned char	*arr;
	size_t			i;

	i = 0;
	if (n && size > INT_MAX / n)
		return (NULL);
	arr = malloc(n * size);
	if (!arr)
		return (NULL);
	while (i < (n * size))
		arr[i++] = 0;
	return ((void *)arr);
}
