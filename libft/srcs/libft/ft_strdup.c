/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annlecre <annlecre@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 10:28:38 by annlecre          #+#    #+#             */
/*   Updated: 2026/05/02 09:11:46 by annlecre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>*/
#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		i;
	char	*dst;

	if (!s)
		return (NULL);
	dst = malloc(sizeof(char) * ft_strlen((char *)s) + 1);
	if (!dst)
		return (NULL);
	i = 0;
	while (s[i])
	{
		dst[i] = s[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
/*
int	main(void)
{
	const char	*src = "Hello this a test";
	char	*dst = NULL;

	if (src)
		printf("%s\n", ft_strdup(src));
	free(dst);
	return (0);
}*/
