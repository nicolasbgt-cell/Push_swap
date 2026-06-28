/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annlecre <annlecre@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 12:10:56 by annlecre          #+#    #+#             */
/*   Updated: 2026/06/16 14:25:05 by annlecre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

/*The  memcmp()  function  compares the first n bytes (each interpreted as 
 * unsigned char) of the memory areas s1 and s2.
 * The memcmp() function returns an integer less than, equal to, or greater 
 * than zero  if  the  first  n bytes  of  s1 is found, respectively, to be less
 * than, to match, or be greater than the first n bytes of s2.
 * For a nonzero return value, the sign is determined by the sign of the 
 * difference  between  the  first pair of bytes (interpreted as unsigned char)
 * that differ in s1 and s2.
 * If n is zero, the return value is zero.*/

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	if (!n)
		return (0);
	while (*str1 == *str2 && n-- > 1)
	{
		str1++;
		str2++;
	}
	return (*str1 - *str2);
}
/*
int	main(void)
{
	const void	*s1 = "test/0/0/0/0/0";
	const void	*s2 = "testttttt";
	printf("%d\n", ft_memcmp(s1, s2, 0));
	printf("%d\n", ft_memcmp(s1, s2, 7));
}*/
