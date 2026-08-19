/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbigot <nbigot@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/19 00:00:00 by nbigot            #+#    #+#             */
/*   Updated: 2026/08/19 00:00:00 by nbigot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdarg.h>

static int	put_int(int n)
{
	char	c;
	int		len;

	len = 0;
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
		len++;
	}
	if (n >= 10)
		len += put_int(n / 10);
	c = '0' + (n % 10);
	write(1, &c, 1);
	return (len + 1);
}

int	ft_printf(const char *fmt, ...)
{
	va_list	args;
	int		i;
	int		len;

	va_start(args, fmt);
	i = 0;
	len = 0;
	while (fmt[i])
	{
		if (fmt[i] == '%' && fmt[i + 1])
		{
			i++;
			if (fmt[i] == 'd')
				len += put_int(va_arg(args, int));
			else if (fmt[i] == '%')
			{
				write(1, "%", 1);
				len++;
			}
		}
		else
		{
			write(1, &fmt[i], 1);
			len++;
		}
		i++;
	}
	va_end(args);
	return (len);
}
