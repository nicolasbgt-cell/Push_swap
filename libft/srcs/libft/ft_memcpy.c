/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annlecre <annlecre@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 10:09:07 by annlecre          #+#    #+#             */
/*   Updated: 2026/05/02 09:59:53 by annlecre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>*/
#include "libft.h"

/*The memcpy() function copies n bytes from memory area src to memory area dest
 * The memory areas must not overlap.
 * Use memmove(3) if the memory areas do overlap.*/

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	const char	*s;
	char		*d;
	size_t		i;

	d = (char *)dest;
	s = (const char *)src;
	i = 0;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}
/*
int	main(void)
{
	char src[] = "12345";
	char dst1[10] = "abcde";
	char dst2[10] = "abcde";
	ft_memcpy(dst1, src, 4);
	memcpy(dst2, src, 4);
	printf("---MEMCPY---\n");
	printf("ft: [%s]\n", dst1);
	printf("og: [%s]\n\n", dst2);

	return (0);
}*/
