/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annlecre <annlecre@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 13:17:40 by annlecre          #+#    #+#             */
/*   Updated: 2026/05/02 09:04:17 by annlecre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>*/
#include "libft.h"

/*The  strnstr()  function  locates  the  first  occurrence of the null-
 * terminated string little in the string big, where not more than 
 * len characters are searched.  Characters that  appear  after  a  ‘\0’
 * character  are  not searched.
 * Since the strnstr() function is a FreeBSD specific API, it should only
 * be used when portability is not a concern.
 * If little is an empty string, big is returned; if little occurs nowhere in
 * big NULL  is  returned;
 * otherwise a pointer to the first character of the first occurrence of little
 * is returned.*/

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	if (!*little)
		return ((char *)big);
	if (!*big)
		return (NULL);
	i = 0;
	while (i < len && big[i] != '\0')
	{
		j = 0;
		while ((i + j) < len && big[i + j] == little[j]
			&& little[j] != '\0')
		{
			j++;
			if (little[j] == '\0')
				return ((char *)big + i);
		}
		i++;
	}
	return (NULL);
}
