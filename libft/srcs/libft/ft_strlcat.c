/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annlecre <annlecre@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 10:01:41 by annlecre          #+#    #+#             */
/*   Updated: 2026/04/30 12:52:21 by annlecre         ###   ########.fr       */
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
they tried to create.  For strlcpy()  that  means  the  length  of  src.
Note, however, that if strlcat() traverses size  characters  without  finding
a  NUL,  the length  of  the string is considered to be size and the
destination string will not be NUL-terminated (since there was no space for
the NUL).  This keeps strlcat() from  running  off the  end  of a string.
In practice this should not happen (as it means that either size is incorrect
or that dst is not a proper “C” string).  The check exists to  prevent
potential security problems in incorrect code.*/

#include <stdio.h>
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	src_len;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (size <= dst_len)
		return (size + src_len);
	if (src_len < size - dst_len)
		ft_memcpy(dst + dst_len, src, src_len + 1);
	else
	{
		ft_memcpy(dst + dst_len, src, size - dst_len - 1);
		dst[size - 1] = '\0';
	}
	return (src_len + dst_len);
}
