/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annlecre <annlecre@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 07:24:02 by annlecre          #+#    #+#             */
/*   Updated: 2026/05/03 08:17:24 by annlecre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Applies the function ’f’ to each character of the
string ’s’, passing its index as the first argument
and the character itself as the second. A new string
is created (using malloc(3)) to collect the results
from the successive applications of ’f’.*/

#include "libft.h"
/*#include <stdio.h>

char	f(unsigned int i, char c)
{
	return (c = c + i);
}
*/
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*res;
	int		len;
	int		i;

	i = 0;
	if (s == NULL)
		return (NULL);
	len = ft_strlen(s);
	res = malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	res[len] = '\0';
	while (i < len)
	{
		res[i] = (*f)(i, s[i]);
		i++;
	}
	return (res);
}
/*
int	main(void)
{
	char	*s;
	const char	str[] = "abcd";

	s = ft_strmapi(str, f);
	printf("strmapi : [%s]\n", s);
	free (s);
	return (0);
}*/
