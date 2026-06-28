/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annlecre <annlecre@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 12:41:12 by annlecre          #+#    #+#             */
/*   Updated: 2026/05/03 08:03:38 by annlecre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>*/
#include "libft.h"

/*allocates (with malloc(3)) and returns a copy of ’s1’
with the characters specified in ’set’ removed from
the beginning and the end of the string.*/

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*cpy;
	int		i;
	int		j;

	i = 0;
	while (ft_strchr(set, s1[i]))
		i++;
	j = ft_strlen(s1);
	while (ft_strchr(set, s1[j - 1]))
		j--;
	cpy = ft_substr(s1, i, (j - i));
	return (cpy);
}
/*
int	main(void)
{
	char	*s;

	s = ft_strtrim("", " \t\n");
	printf("strtrim: [%s]\n", s);
	free(s);
}*/
