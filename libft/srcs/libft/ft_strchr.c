/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annlecre <annlecre@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 11:04:53 by annlecre          #+#    #+#             */
/*   Updated: 2026/05/06 11:29:58 by annlecre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

/*The strchr() function returns a pointer to the first occurrence of
 * the character c in the string s.
 * the strchr() function returns a pointer to the matched character  or  NULL
 * if  the character is not found. 
 * The terminating null byte is considered part of the string, so that if c
 * is specified as '\0', these functions return a pointer to the terminator.*/

char	*ft_strchr(const char *s, int c)
{
	while (*s != (char)c)
	{
		if (*s == '\0')
			return (NULL);
		s++;
	}
	return ((char *)s);
}
/*
int	main(void)
{
	char	*s = "Hello World !";

	printf("return value is %c\n", *ft_strchr(s, 'W'));
}*/
