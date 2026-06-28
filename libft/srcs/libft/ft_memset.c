/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annlecre <annlecre@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 08:40:21 by annlecre          #+#    #+#             */
/*   Updated: 2026/05/02 09:22:34 by annlecre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*#include <stdio.h>*/

void	*ft_memset(void *s, int c, size_t n)
{
	char	*str;

	str = s;
	while (n)
	{
		*str = c;
		str++;
		n--;
	}
	return (s);
}
/*
int	main(void)
{
	char str[30] = "This is a test";

	printf("Before ft_memset(): %s\n", str);
	ft_memset(str + 8, '!', 15);
	printf("After ft_memset(): %s\n", str);
	return (0);
}*/
