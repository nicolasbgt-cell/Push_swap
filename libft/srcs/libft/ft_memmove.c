/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annlecre <annlecre@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 12:57:30 by annlecre          #+#    #+#             */
/*   Updated: 2026/05/02 10:02:03 by annlecre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*The  memmove()  function  copies n bytes from memory area src to memory 
area dest.  The memory areas may overlap: copying takes place as though 
the  bytes  in  src  are  first copied into a temporary array 
that does not overlap src or dest, and the bytes are then
copied from the temporary array to dest.*/

/*#include <stdio.h>*/
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*s;
	char	*d;

	s = (char *)src;
	d = (char *)dest;
	if ((d == s) || (n == 0))
		return (dest);
	else if (d > s)
	{
		while (n-- > 0)
			d[n] = s[n];
	}
	else
		ft_memcpy(dest, src, n);
	return (dest);
}
/*
int	main(void)
{
	char s1[10] = "abcdef";
	char s2[10] = "abcdef";
	char s3[10] = "abcdef";
	char s4[10] = "abcdef";
	ft_memmove(s1 + 2, s1, 5);
	memmove(s2 + 2, s2, 5);
	ft_memmove(s3, s3 + 2, 5);
	memmove(s4, s4 + 2, 5);
	printf("---MEMMOVE OVERLAP---\n");
	printf("ft: [%s]\n", s1);
	printf("og: [%s]\n", s2);
	printf("---MEMMOVE REVERSE OVERLAP---\n");
	printf("ft: [%s]\n", s3);
	printf("og: [%s]\n\n", s4);
}*/
