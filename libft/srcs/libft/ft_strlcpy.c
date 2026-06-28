/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annlecre <annlecre@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 08:34:05 by annlecre          #+#    #+#             */
/*   Updated: 2026/05/02 08:35:15 by annlecre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*The  strlcpy()  and  strlcat()  functions copy and concatenate strings respec‐
tively.  They are designed to be safer, more consistent, and less error  prone
replacements for strncpy(3) and strncat(3).  Unlike those functions, strlcpy()
and strlcat() take the full size of the buffer (not just the length) and guar‐
antee to NUL-terminate the result (as long as size is larger than 0 or, in the
case  of  strlcat(), as long as there is at least one byte free in dst).  Note
that a byte for the NUL should be included in size.  Also note that  strlcpy()
and strlcat() only operate on true “C” strings.  This means that for strlcpy()
src must be NUL-terminated and for strlcat() both src and dst must be NUL-ter‐
minated.
The  strlcpy()  function  copies up to size - 1 characters from the NUL-termi‐
nated string src to dst, NUL-terminating the result.
The  strlcpy()  and  strlcat() functions return the total length of the string
they tried to create.  For strlcpy()  that  means  the  length  of  src.*/

/*#include <stdio.h>*/
#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	src_len;

	src_len = ft_strlen(src);
	if (size > 0)
	{
		while (--size && *src)
			*dst++ = *src++;
		*dst = '\0';
	}
	return (src_len);
}
/*
int	main(void)
{
	char	src[] = "coucou";
	char	dest[10]; memset(dest, 'A', 10);
	size_t	n;

	n = ft_strlcpy(dest, src, 1);
	printf("src_len = %lu, and dest[0] = %c and dest[1] = %c\n", 
			n, dest[0], dest[1]);
}*/
