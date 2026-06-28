/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annlecre <annlecre@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 09:32:09 by annlecre          #+#    #+#             */
/*   Updated: 2026/04/28 08:44:39 by annlecre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	char	*str;

	str = s;
	while (n)
	{
		*str = 0;
		str++;
		n--;
	}
}
/*
int	main(void)
{
	char	s[30] = "Hello, World!!!!!!!!!!";

	printf("Before ft_bzero(): %s\n", s);
	ft_bzero(s + 13, 9);
	printf("After ft_bzero(): %s\n", s);
	return (0);
}*/
