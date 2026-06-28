/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annlecre <annlecre@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 11:04:57 by annlecre          #+#    #+#             */
/*   Updated: 2026/05/02 09:58:32 by annlecre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h*/
#include "libft.h"

/*The  memchr()  function scans the initial n bytes of the memory area pointed
 to by s for the first instance of c.
  Both c and the bytes of the memory area pointed to  by  s  are
   interpreted as unsigned char.
  The  memchr()  and  memrchr() functions return a pointer to the matching byte 
  or NULL if the character does not occur in the given memory area.*/

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;

	str = (unsigned char *)s;
	while (n--)
	{
		if (*str == (unsigned char)c)
			return ((void *)str);
		str++;
	}
	return (NULL);
}
/*
int	main(void)
{
	const void	*s = "This is a test";
	printf("%s\n", (char *)ft_memchr(s, ' ', 8));
	return (0);
}*/
