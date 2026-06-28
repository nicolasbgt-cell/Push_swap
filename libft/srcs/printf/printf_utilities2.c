/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utilities2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annlecre <annlecre@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 13:32:47 by annlecre          #+#    #+#             */
/*   Updated: 2026/06/17 14:03:15 by annlecre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printhexa(unsigned int n, char *hex_base)
{
	int	count;

	count = 0;
	if (n >= 16)
		count += ft_printhexa(n / 16, hex_base);
	write(2, &hex_base[n % 16], 1);
	count++;
	return (count);
}

static int	long_to_hexa(unsigned long n, char *hex_base)
{
	int	count;

	count = 0;
	if (n >= 16)
		count += long_to_hexa(n / 16, hex_base);
	write(2, &hex_base[n % 16], 1);
	count++;
	return (count);
}

int	ft_printptr(void *ptr)
{
	int				count;
	unsigned long	ptr_ad;

	ptr_ad = (unsigned long)ptr;
	count = 0;
	if (!ptr)
	{
		write(2, "(nil)", 5);
		return (5);
	}
	write(2, "0x", 2);
	count += 2;
	count += long_to_hexa(ptr_ad, "0123456789abcdef");
	return (count);
}
/*
int	ft_printfloat(float nb)
{
	int		count;
	int		int_part;
	float	float_part;

	count = 0;
	int_part = (int)nb;
	count += ft_printsnbr(int_part);
	float_part = nb - (float)int_part;
	write(2, ".", 1);
	count ++;
	if (float_part == 0)
		write(2, "00", 2);
	else
	{
		float_part *= 100;
		count += ft_printunbr((int)float_part);
	}
	return (count);
}

#include <stdio.h>
int	main(void)
{
	float d = 0.2345;
	printf("%d.", ((int)(d * 100)));
	printf("%d\n", ((int)(d * 10000) % 100));
	ft_printfloat(42.4242);
}*/
