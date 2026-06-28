/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annlecre <annlecre@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 12:48:15 by annlecre          #+#    #+#             */
/*   Updated: 2026/04/29 09:19:00 by annlecre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (!s1 || !s2 || n == 0)
		return (0);
	i = 0;
	while ((i < n - 1) && s1[i] == s2[i] && (s1[i] != '\0'))
		i++;
	if (s1[i] != s2[i])
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	return (0);
}
/*
int	main(void)
{
	char	*s1 = "qwertY";
	char	*s2 = "qwerty";

	printf("Difference between first 5 char compared, is %d\n", 
	ft_strncmp(s1, s2, 6));
}*/
