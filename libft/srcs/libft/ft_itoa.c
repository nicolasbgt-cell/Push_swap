/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annlecre <annlecre@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 07:43:56 by annlecre          #+#    #+#             */
/*   Updated: 2026/04/30 09:37:46 by annlecre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

static int	int_len(long nbr)
{
	int	i;

	i = 0;
	if (nbr < 0)
	{
		nbr *= -1;
		i++;
	}
	if (nbr == 0)
		i++;
	while (nbr != 0)
	{
		nbr /= 10;
		i++;
	}
	return (i);
}

static void	get_nbr(char *res, long nbr, int len)
{
	int		i;

	i = len - 1;
	while (nbr != 0)
	{
		res[i] = (nbr % 10) + '0';
		nbr /= 10;
		i--;
	}
	res[len] = '\0';
}

char	*ft_itoa(int n)
{
	char	*res;
	int		len;
	long	nbr;

	nbr = n;
	len = int_len(nbr);
	(res = malloc(sizeof(char) * (len + 1)));
	if (!res)
		return (NULL);
	res[0] = '0';
	if (nbr < 0)
	{
		nbr = -nbr;
		res[0] = '-';
	}
	get_nbr(res, nbr, len);
	return (res);
}
/*
int	main(void)
{
	char	*s;

	s = ft_itoa(INT_MAX);
	printf("INT_MAX: %s\n", s);
	s = ft_itoa(INT_MIN);
	printf("INT_MIN:%s\n", s);
	s = ft_itoa(42);
	printf("42: %s\n", s);
	s = ft_itoa(-1);
	printf("-1: %s\n", s);
}*/
