/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utilities1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annlecre <annlecre@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 18:15:07 by annlecre          #+#    #+#             */
/*   Updated: 2026/06/16 11:00:24 by annlecre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printchar(char c)
{
	ft_putchar_fd(c, 2);
	return (1);
}

int	ft_printstr(const char *s)
{
	int	count;

	count = 0;
	if (!s)
	{
		write (2, "(null)", 6);
		return (6);
	}
	while (s[count] != '\0')
	{
		ft_putchar_fd(s[count], 2);
		count++;
	}
	return (count);
}

int	ft_printsnbr(int n)
{
	int	count;

	count = 0;
	if (n == -2147483648)
		count += ft_printstr("-2147483648");
	else if (n > -2147483648 && n < 0)
	{
		count += ft_printchar('-');
		n *= -1;
		count += ft_printsnbr(n);
	}
	else if (n >= 10)
	{
		count += ft_printsnbr(n / 10);
		count += ft_printchar(n % 10 + '0');
	}
	else
		count += ft_printchar(n + '0');
	return (count);
}

int	ft_printunbr(unsigned int n)
{
	long	nb;
	int		count;

	count = 0;
	nb = n;
	if (nb >= 10)
	{
		count += ft_printsnbr(n / 10);
		count += ft_printchar(n % 10 + '0');
	}
	else
		count += ft_printchar(n + '0');
	return (count);
}
