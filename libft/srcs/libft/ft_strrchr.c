/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annlecre <annlecre@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 11:54:37 by annlecre          #+#    #+#             */
/*   Updated: 2026/05/02 07:58:09 by annlecre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>*/
#include "libft.h"

/*The strrchr() function returns a pointer to the last occurrence of 
 * the character c in the string s.
 * The  strchr()  and strrchr() functions return a pointer to the matched 
 * character or NULL if the character is not found.
 * The terminating null byte is  considered  part of  the string,
 * so that if c is specified as '\0', these functions return a pointer
 * to the terminator.*/

char	*ft_strrchr(const char *s, int c)
{
	int	s_len;

	s_len = ft_strlen(s);
	s += s_len;
	while (s_len-- >= 0)
	{
		if (*s == (char)c)
			return ((char *)s);
		s--;
	}
	return (NULL);
}
/*
int	main(void)
{
	const char	*s = "Hello World!";
	int	c = 'o';
	printf("%s\n", ft_strrchr(s, c));
}*/
